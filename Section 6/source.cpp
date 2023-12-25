
#include <iostream>
using namespace std;


#include "Integer.h"
/*== notes
* Copy assignemnet: 
					-allocate new memory with the value of the copied item
					-delete the old memory to prevent memory leakage
					-check first that the two instances aren't the same to prevent wrong delete;
						-ex a=a , if the code doesn't handle this case, the memory allocated for a will be deleted
*if the object is not created yet, the copy constructor will be called not the copy assignment operator
*		ex: Integer A=b; ==> Copy constructor
*	                A=c; ==> Copy Assignment
* 
* both copy assignment and move assignment returns left value reference as they return *this which is not a temporary value
* you can return normal Integer it will work but not efficient like left value reference for memory effciency
* 
* add operator is returning Integer as it returns temporary ,we can't assign it to "this" pointer as it will effect the left hand side;
*		-ex: sum = a+b ; a will equal a+b as well as sum
* 
* prefix operator: we can return left value reference as we will increment in the object itself and return the object so there's no temp return
* 
* postfix operator: unlike the prefix operator, we increment the object but returns the object before increment , this old version is saved in temp and the temp will be returned
* 
* const keyword is used for the functions that accept const Integer so that we can access the function, unclear right?
*		suppose the function "Integer operator+(const Integer& val)const"
*		we can't use the function GetValue if it's not declared as const
		this is not big problem in the scope of member function because we can access the m_pInt directly
		but if we have global function which accepts const Integer so we can't access the m_pInt as it's private member
		we have to use the getter function, but if that getter function isn't declared as const , we can't use it also
*
* friend keyword is used to access all the members it can be used for limited functions or the whole class
*	if it's used for a function, so this function can access all the members of the class
* 
*/


int main()
{
	Integer a{ 1 }, b{ 3 };
	Integer sum = a + b;
	cout << sum << endl;
	Integer A{};
	cout << "Line 17" << endl;
	cout << (++A) << endl;
	cout << "Line 19" << endl;
	cout << (A++)<< endl;
	cout << "Line 21" << endl;
	cout << (A++) << endl;
	Integer B = A;
	B = b;
	cout << B << endl;
	return 0;
}



