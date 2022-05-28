/*David Cohen ID:311209142
The program build a tree for all type and than build a string class and oporat the tree in strings values */
#include <iostream>
#include<string>
using namespace std;
#include "SearchTree.h"
#include"Student.h"
enum {
	A ='a',B,C,D,E
};
int main()
{
	SearchTree<Student>Ts;
	Student stu;
	char choise = 'a';
	while (choise != E)
	{
		cout << "enter a-e\n";
		cin >> choise;
		switch (choise)
		{
		case A:
			cout << "enter a student:\n";
			cin >> stu;
			Ts.add(stu);
			break;
		case B:
			cout << "enter a student:\n";
			cin >> stu;
			if (Ts.search(stu))
				Ts.remove(stu);
			else
				cout << "not exist\n";
			break;
		case C:
			cout << "enter a student:\n";
			cin >> stu;
			if (Ts.search(stu))
				cout << "exist\n";
			else
				cout << "not exist\n";
			break;
		case D:
			Ts.inOrder();
			break;
		case E:
			break;
		default:
			cout<<"ERROR\n";
		}
	}

	return 0;
}
/*
enter a-e
a
enter a student:
2 b b
enter a-e
a
enter a student:
5 e e
enter a-e
a
enter a student:
1 a a
enter a-e
a
enter a student:
4 d d
enter a-e
a
enter a student:
7 g g
enter a-e
a
enter a student:
3 c c
enter a-e
b
enter a student:
5 e e
enter a-e
d
1 a a 
2 b b 
3 c c 
4 d d 
7 g g
enter a-e
e
*/