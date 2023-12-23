
#include <iostream>
using namespace std;

#define LESSON 55

#if LESSON==53
/*
*				L-Value						|			R-Value
*											|
				Has a name					|		Doesn't have a name
											|
		All variables are L-Value			|      R-Value are temporary value
											|
		Can be assigned values				|		cann't be assigned values
											|
	Some expressions returns L-Value		|  Some expressions returns R-Value
											|
	Functions that return by referenece		| functions that return by value
		 returns l-value					| 		return r-value
*/

/*==> R-Value References
* a reference created to a temporary
* represents a temporary
* Created with && operator
* cannot point to l-value
* 

*/


//Return R-Value
int Add(int x, int y)
{
	return x + y;
}
//Return L-Value
int& transform(int& x)
{
	x *= x;
	return x;
}

void Print(int& x)
{
	cout<<"Print(int & x)" << endl;
}
void Print(const int& x)
{
	cout << "Print(const int& x)" << endl;
}
void Print(int&& x)
{
	cout << "Print(int && x)" << endl;
}

int main()
{
	//X: L-value, 5: R-value
	int x = 5;
	//y: L-value, 10: R-value
	int y = 10;
	//z: L-value, 8: R-value
	int z = 8;
	//result: L-value, (x+y)*z: R-value expression
	int result = (x + y) * z;
	//++x: L-value expression , 6: R-value
	++x = 6;
	

	int&& R_Value_ref1 = 10;
	int&& R_Value_ref2 = Add ( 3, 2 );
	int & L_Value_ref1 = transform ( x );
	const int& L_Value_ref2 = 3;
	Print(x);
	Print(L_Value_ref2);
	Print(R_Value_ref2);
	Print(3);
}

#endif

#if LESSON==54
#include "Integer.h"
Integer Add(const Integer& a, const Integer& b)
{
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue());
	return temp;
}
int main()
{
	Integer a(1), b(2);
	a.SetValue(Add(a, b).GetValue());
	return 0;
}
#endif

#if LESSON==55
/*==> Resource Management
* Some classes own a resource
* this resource may be a pointer,file handle, socket,etc
* such resources maybe aquired in the constructor
* you have to decide the action in case objects of such classes are copied, moved or destroyed
* on destruction, the resource must be released to avoid leaks
*/

/*==> Rule Of 5
* if the class has ownership semantics then you must provide a user-defined:
* 1) Destructor
* 2) Copy Constructor
* 3) Copy assignment operator
* 4) Move Constructor
* 5) Move assignment operator
*/

/*==> Rule Of 0
* if the class doens't have any ownership semantics then you don't have to  provide any user-defined:
*/

#include "Integer.h"

class Number {
	Integer m_Value{};
public:
	Number(int value):m_Value{ value }{
	}
	
};
/*
* any customze implementation of the 5 function the move (constructor and assignment will be delete)
* customze move constructor will delete move assignment and copy assignment and copy constructor and the destructor will call the default
* 
*/
Number CreateNumber(int num)
{
	Number n{ num };
	return n;
}
int main()
{
	Number n1{ 1 };
	auto n2{ n1 };
	n2 = n1;//check in section 6
	auto n3{ CreateNumber(3) };//move constructor //check in section 6
	n3 = CreateNumber(3);//move assignment //check in section 6
	Integer A{ 1 };
	cout << A.GetValue() << endl;


	return 0;
}

#endif