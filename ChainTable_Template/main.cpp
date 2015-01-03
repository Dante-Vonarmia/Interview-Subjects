/**************/
/* Excerise 2 */
/**************/
// 链表模板
#include "ctt.h"

int main(int argc, char const *argv[])
{
	char szLondon[] = "London";
	char szBerlin[] = "Berlin";

	LinkedList<string> lst_str(szLondon);
	lst_str.AddToTail(szBerlin);
	lst_str.RemoveFirst("London");
	cout << lst_str << endl;

	LinkedList<const char*> lst_psz(szLondon);
	lst_psz.AddToTail(szLondon);
	lst_psz.RemoveFirst("London");
	cout << lst_psz << endl;

	return 0;
}