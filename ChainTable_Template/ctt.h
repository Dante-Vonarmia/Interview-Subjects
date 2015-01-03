#ifndef CCT_H
#define CCT_H

#include "iostream"
using namespace std;

template<class T>
class LinkedList
{
public:
	LinkedList(void): m_pHead(NULL), m_pTail(NULL) {}	// 构造函数，初始化 m_pHead, m_pTail
	LinkedList(const T& tData) : m_pHead(new Node(tData)), m_pTail(m_pHead) {}	// 复制构造函数，引用对象 tData 
	~LinkedList(void)
	{
		for(Node* pNode = m_pHead, *pNext; pNode; pNode = pNext) // 清空链表
		{
			pNext = pNode -> m_pNext;
			delete pNode;
		}
		m_pHead = NULL;
		m_pTail = NULL;
	}

	LinkedList(const LinkedList& ll) : m_pHead(NULL), m_pTail(NULL)
	{
		for (Node* pNode = ll.m_pHead; pNode; pNode = pNode->m_pNext)
		{
			AddToTail(pNode->m_tData);
		}
	}

	LinkedList& operator= (const LinkedList& ll)	// 重载＝
	{
		if (&ll != this)
		{
			for (Node* pNode = m_pHead, *pNext; pNode; pNode = pNext)
			{
				pNext = pNode -> m_pNext;
				delete pNode;
			}
			m_pHead = NULL;
			m_pTail = NULL;

			for (Node* pNode = ll.m_pHead; pNode; pNode = pNode -> m_pNext)
			{
				AddToTail(pNode -> m_tData);
			}
		}
		return *this;
	}

	// 从尾部增加
	void AddToTail(const T& tData)
	{
		m_pTail = new Node (tData, m_pTail);

		if (m_pTail -> m_pPrev)
		{
			m_pTail -> m_pPrev -> m_pNext = m_pTail;
		}
		else
		{
			m_pHead = m_pTail;
		}
	}

	// 从首部删除
	bool RemoveFirst(const T& tData)
	{
		for (Node* pFind = m_pHead; pFind; pFind = pFind -> m_pNext)
		{
			if (Equal(pFind->m_tData, tData))
			{
				if (pFind -> m_pPrev)
				{
					pFind -> m_pPrev -> m_pNext = pFind -> m_pNext;
				}
				else
				{
					m_pHead = pFind ->m_pNext;
				}
				if (pFind -> m_pNext)
				{
					pFind -> m_pNext -> m_pPrev = pFind -> m_pPrev;
				}
				else
				{
					m_pTail = pFind ->m_pPrev;
				}
				delete pFind;

				return true;
			}
		}
		return false;
	}

	// 重载输出符
	friend ostream& operator<< (ostream& os, const LinkedList& lst)
	{
		for (Node* pNode = lst.m_pHead; pNode; pNode = pNode -> m_pNext)
		{
			os << pNode << endl;
		}
		return os;
	}
private:
	class Node
	{
	public:
		// 构造函数 Node，初始化列表 m_tData, m_pPrev, m_pNext。
		Node(const T& tData, Node* pPrev = NULL, Node* pNext = NULL) : m_tData(tData), m_pPrev(pPrev), m_pNext(pNext) {}
		// 友元函数重载 <<
		friend ostream& operator<< (ostream& os, const Node* pNode)
		{
			return os << pNode -> m_tData;
		}

		T m_tData;
		Node* m_pPrev;	// 上一节点
		Node* m_pNext;	// 下一节点
	};
 
	bool Equal (const T& tData1, const T& tData2) const
	{
		return tData1 == tData2;
	}

	Node* m_pHead;	// 头节点
	Node* m_pTail;	// 尾节点
};

// 针对 char* 的链表模板成员函数特化
template<>
bool LinkedList<const char*>::Equal (const char* const& pszData1, const char* const& pszData2) const
{
	return strcmp(pszData1, pszData2) == 0;
}
#endif