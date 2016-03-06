#include <iostream>
using namespace std;
#include "StackImpl.h"
int main()
{
	Stack s1;
	s1.push(4);
	s1.push(5);
	s1.push(1);
	s1.push(3);
	s1.push(2);
	s1.display();
	s1.sort();
	s1.display();
}
