#define LESSON 52
#include <iostream>
using namespace std;
#if LESSON==41
/*==>OOP fundamentals
* 
* Abstraction:
*				- Abstraction focuses on important and necessary details
*				- Unwanted features are left out
*				- ex, name of a person without other details
*				- Helps focus on important characteristics
*				- used to represent real-life objects in sw without associated complexity
*				- Represented through class,struct,interface,union,enum
*
* Encapsulation:
*				- Next step after abstraction
*				- Hides the implemenation details of the class
*				- The class provides behaviour without revealing the implementation
*				- Objects of such class are easy to use
*				- The internal implementation can be changed without user's knowledge
*				- Implemented via Access modifiers 
* 
* Inheritance:
*				- Next step after Encapsulation
* 				- Represents a hierarchy of classes
* 				- The classes are related through is-a relationship
* 				- Ex, Dog is an animal
* 				- The behaviour and its implementation is inherited by the childern from the parent
* 				- The child classes may then reuse the behaviour with the same implementation or provide different implementation
* 				- promotes reuse and extensibility
* 
* Composition:
*				- has a or part of
* 
* Polymorphism

*/
#endif

#if LESSON==42
#include "Car.h"
/*==>Classes
* 
* class is blueprint/template/recipe
* class represents an abstraction
* every object is an instance of a class
* class can have multiple instances
* every object is independent
*/
int main()
{
	Car c{};
	c.DashBoard();
	c.FillFuel(12.3f);
	c.Accelerate();
	c.AddPassengers(12);
	c.DashBoard();
	return 0;
}
#endif

#if LESSON==43
#include "Car.h"
/*==> Constructors
* - Invoked automatically during instantiation
* - Used for initialization
* - Doesn't have any return type
* - Can be overloaded
*/

/*==>Default Constuructor
* no arguments
* Automatically synthesized by the compiler if no other user defined constructor exist
*/

/*==> Parameterized Constructor
* accept one or more argument
* used to initialize object with user defined values
* never synthesized by the compiler, hy3ml le any arguments bzbt ?
* blocks auto generation of default constructor 
*/

/*==> Destructor
* 
* Function that is invoked automatically when object is destroyed
* used for releasing resources that may have been allocated in the constructor
* cannot be oveloaded
* no arguments
* compiler synthesize one if required
*/


/*
	AUTO is not allowed inside classes
*/
int main()
{
	Car c{4.2};
	c.DashBoard();
	c.FillFuel(12.3f);
	c.Accelerate();
	c.AddPassengers(12);
	c.DashBoard();
	return 0;
}
#endif

#if LESSON==44
/*==>Struct
* 
* Create user-defined type through keyword struct
* similar to a class
* default access is public
* 
*/
typedef struct
{
	int x;
	int y;
}Point;

void Drawline(Point start, Point end)
{
	start.x = 10;
}
int main()
{

}
#endif

#if LESSON==45
#include "Car.h"
int main()
{
	Car c{ 4.2 };
	c.DashBoard();
	c.FillFuel(12.3f);
	c.Accelerate();
	c.AddPassengers(12);
	c.DashBoard();
	return 0;
}
#endif

#if LESSON==46
/*==>this pointer
* 
* a hidden pointer passed to member function
* points to the object that invoked the member function
* provided as a keyword that is meaningful only in member functions
*/


#include "Car.h"
int main()
{
	Car c{ 4.2 };
	c.DashBoard();
	c.FillFuel(12.3f);
	c.Accelerate();
	c.AddPassengers(12);
	c.DashBoard();
	return 0;
}
#endif

#if LESSON==47
#include "Car.h"
/*==> static members
* member variables qualified with static keyword
* not part of the object
* belong to the class
* only one copy exists
* shared between objects
* Cann't be initialized inside the class
*/
int main()
{
	Car::showcount();
	Car c{ 4.2 };
	Car::showcount();
	c.DashBoard();
	
	c.FillFuel(12.3f);
	c.Accelerate();
	c.AddPassengers(12);
	c.DashBoard();
	Car c2, c3;
	Car::showcount();
	c2.DashBoard();
	c3.DashBoard();
	return 0;
}
#endif

#if LESSON==48
/*==>constant member
* 
* qualified with const keyword
* both declaration and definition is qualified
* such functions cannot change the value of any member variables
* useful for creating read-only functions
* contsant objects can invole only constant member functions
*/


#include "Car.h"
int main()
{
    Car c{ 4.2 };
	c.DashBoard();
	c.FillFuel(12.3f);
	c.Accelerate();
	c.AddPassengers(12);
	c.DashBoard();
	return 0;
}
#endif

#if LESSON==49||LESSON==50
/*==> Copy Constructor
* 
* creates copy of the object's state in another object
* syntheszied automatically
* default implementation copies values
* user-defined implementation required for pointer members
*/


/*==>RULE OF 3
* 
* ALL should be defined if a user implements any of them:
*	1) Destructor
*   2) Copy Constructor
*   3) Copy assignment operator
* 
* This will be due to allocation of some resource in a constructor
*	1) Destructor will free the memory
*   2) Copy constructor will perform deep copy 
*   3) Copy assignment will also perfrom deep copy
* 
* not implementing user defined operations can lead to memory leak or shallow copy
*/
#include "Integer.h"
//void Print(Integer i)
//{
//
//}
//Integer Add(int x, int y)
//{
//	return Integer(x + y);
//}


int main()
{

	int* p1 = new int(5);
	int* p2 = p1;			//shallow copy
	int* p3 = new int(*p1); //Deep copy
	Integer i(5);
	Integer i2(i);
	std::cout << i.GetValue() << std::endl;
	i.SetValue(10);
	std::cout << i.GetValue() << std::endl;
	return 0;
}
#endif

#if LESSON==51
/*==>Delegating Constructor
* Allows a constructor to invoke another constructor
* replacement of common initializion
* reduces duplicates
* 
*/
#include "Car.h"
int main()
{
	Car c1{ };
	c1.DashBoard();
	return 1;
}
#endif

#if LESSON==52

class integer
{
private :
	int m_value{0};
public:
	//integer()//default constructor
	//{
	//	cout << "FUNC CALL: HELLO FROM " << "'Integer()' " << "THE DEFAULT CONSTRUCTOR" << endl;
	//	m_value=0;
	//}
	integer() = default; //the default constructor will be synthesized by the compiler
	integer(int value)//parameterized constructor
	{
		cout << "FUNC CALL: HELLO FROM " << "'Integer(int value)' " << "THE PARAMETERIZED CONSTRUCTOR" << endl;
		m_value = value;
	}
	//integer(const integer&) = default;//the copy constructor will be synthesized by the compiler
	integer(const integer&) = delete;//the delete constructor will not be synthesized by the compiler
	void SetValue(int value)
	{
		m_value = value;
	}
	void SetValue(float) = delete;//float is porhibted
};
int main()
{
	integer i1{};
	i1.SetValue(5);
	return 0;
}

#endif
