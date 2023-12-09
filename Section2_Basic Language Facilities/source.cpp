
#define LESSON 35
#define ASSIGNMENT1 1001
#define ASSIGNEMNT2 1002

#if LESSON==12
//single line comment
/*
* multiple
* line
* comment
*/
#include <iostream> //<standard library>
//"not standard library"

int main()//called at startup
{
	//using namespace std;
	//cout << "hello "<<"C++"<<endl;
	std::cout << "hello" << "C++" << std::endl;
	return 0;
}
#endif

#if LESSON==13
/*
1-Preprocessor:
						resolves any # family
2-Compilation
3-Linking
*/

#include <iostream> //<standard library>
//"not standard library"

int main()//called at startup
{
	//using namespace std;
	//cout << "hello "<<"C++"<<endl;
	std::cout << "hello" << "C++" << std::endl;
	return 0;
}
#endif

#if LESSON==14
#include <iostream>

int main()
{
	int i;//declaration
	i = 10;//definition 
	int k1 = 1;
	int k2{ 1 };
	int l1[5] = { 1,2,3,4,5 };
	int l2[5]{ 1,2,3,4,5 };
}
#endif

#if LESSON==15
#include <iostream>

int main()
{
	using namespace std;
	cout << "Hello World\n" << 45 << 8.2f << endl;
	int age;
	char buff[512];
	cout << "tell me your name" << endl;
	cin.getline(buff, 64, '\n');
	cout << "Your name: " << buff << endl;
	cout << "tell me your age" << endl;
	cin >> age;
	cout << "your age= " << age<<endl;
	return 0;
}
#endif

#if LESSON==16
#include <iostream>
int add(int x, int y);//function prototype,declaration
int main()
{
	int x, y;
	std::cin >> x >> y;
	int result = add( x, y);
	std::cout << "Result: " << result << std::endl;
}
int add(int x, int y)//function definition
{
	int sum = x + y;
	return sum;
}
#endif

#if LESSON==17
#include <iostream>

int factorial(int x);
int main()
{
	int i = 5;
	int result = factorial(i);
	std::cout << "Factorial of: " << i << "is " << result << std::endl;
	return 0;
}
int factorial(int x)
{
	int result = 1;
	for (int i = 1; i < x; i++)
	{
		result* i;
	}
	return result;
}

#endif

#if LESSON==18
#include <iostream>
int main()
{
	int a1;								//uninitialized
	int a2 = 0;							//Copy initialization
	int a3(5);							//Direct initialization
	std::string s1;						//string is initialized not like int
	std::string s2("C++");				//Direct initialization

	char d1[8];							//uninitialized
	char d2[8] = { '\0' };				//Copy initialization
	char d3[8] = { 'a','b','c','d' };	//Aggregate initialization
	char d4[8] = { "abcd" };			//Copy initialization

	////////////////////////////////////////////////////
	//default value for all primitive types is zero
	int b1{};				//Value initialization , b1 now =0
	//int b2();				//Most vexing parse
	int b3{ 5 };			//Direct initialization
	int b4 = 0;				//Copy initialization
	char e1[8]{};			//will be assigned with default values of char
	char e2[8]{ "Hello" };	//Direct initialization

	int* p0 = new int;					//uninitialized
	int* p1 = new int{};				//value initilization default
	char* p2 = new char[8] {};			//value initilization default
	char* p3 = new char[8] {"abcd"};    //Direct initialization



	/*
	* 1- Value initialization	-> t obj{}
	* 2- Direct initialization	-> t obj{v}
	* 3- Copy initialization	-> t obj = v
	*/

	/*
	* why uniform initialization?
	* 1- it forces initialization
	* 2- you can use direct initialization with array types
	* 3- prevents narrowing conversion , may raise warning or error
	* 4- uniform syntax for all types 
	*/
}
#endif

#if LESSON==19
#include <iostream>
int main()
{
	int x = 10;
	std::cout << &x<< std::endl;
	int* ptr = &x;
	std::cout << ptr << std::endl;
	*ptr = 5;
	std::cout << x<<std::endl;
	return 0;
}
#endif

#if LESSON==ASSIGNMENT1
#include <iostream>
int Add(int* a, int* b);    //Add two numbers and return the sum
void AddVal(int* a, int* b, int* result); //Add two numbers and return the sum through the third pointer argument
void Swap(int* a, int* b);  //Swap the value of two integers
void Factorial(int* a, int* result);       //Generate the factorial of a number and return that through the second pointer argument
int main()
{
	int a1{ 2 }, b1{ 5 };				//a1=2 b1=5 a2=x  b2=x  r1=x  r2=x  r3=x 
	int result1{ Add(&a1,&b1) };		//a1=2 b1=5 a2=x  b2=x  r1=7  r2=x  r3=x 
	int a2{ 3 }, b2{ 6 }, result2{};	//a1=2 b1=5 a2=3  b2=6  r1=7  r2=0  r3=x 
	AddVal(&a2, &b2, &result2);			//a1=2 b1=5 a2=3  b2=6  r1=7  r2=9  r3=x 
	Swap(&a1, &b1);						//a1=5 b1=2 a2=3  b2=6  r1=7  r2=9  r3=x 
	Swap(&a2, &b2);						//a1=5 b1=2 a2=6  b2=3  r1=7  r2=9  r3=x
	int result3{};						//a1=5 b1=2 a2=6  b2=3  r1=7  r2=9  r3=0
	Factorial(&b2, &result3);			//a1=5 b1=2 a2=6  b2=3  r1=7  r2=9  r3=6
	std::cout << "a1= " << a1 << " b1= " << b1 << " a2= " << a2 << " b2= " << b2 << " result 1= " << result1 << " result2= " << result2 << " result3= " << result3 << std::endl;
}
int Add(int* a, int* b)
{
	return *a + *b;
}
void AddVal(int* a, int* b, int* result)
{
	*result = *a + *b;
}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Factorial(int* a, int* result)
{
	*result = 1;
	for (int i = 1; i <= *a; i++)
	{
		*result *= i;
	}
}
#endif

#if LESSON==22
/*
*						REF												PTR
*		Always needs an initializer				|			Initializer is optional
*		Initializer should be l-value			|			Initializer need not be l-value
*		Cannot be nullptr						|			can be nullptr
*		bound to its referent					|			can point to other variables
*		no storage is required					|			has it's own storage 
*		no dereference is required				|			derefenece is requried
*/



#include <iostream>
int main()
{
	using namespace std;
	//Referenet
	int x = 10;
	//Reference
	int& ref = x;
	cout << "x= "<<x << endl;
	cout << "ref= " << ref << endl;
	int y{6};
	ref = y;
	cout << "x= " << x << endl;
	cout << "ref= " << ref << endl;
}
#endif

#if LESSON==ASSIGNEMNT2
#include <iostream>
void Add(int a, int b, int& result);    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int& result);    //Find factorial of a number and return that through a reference parameter
void Swap(int& a, int& b);            //Swap two numbers through reference arguments
int main()
{
	int a{ 3 }, b{ 4 }, result{};

	Add(a, b, result);
	std::cout << result << std::endl;
	Factorial(a, result);
	std::cout << result << std:: endl;
	Swap(a, b);
	std::cout << a<<b << std::endl;
	return 0;
}
void Add(int a, int b, int& result)
{
	result = a + b;
}
void Factorial(int a, int& result)
{
	result = 1;
	for (int i{ 1 }; i <= a; i++)
	{
		result *= i;
	}
}
void Swap(int& a, int& b)
{
	int temp{ a };
	a = b;
	b = temp;
}
#endif

#if LESSON==24
#include <iostream>
using namespace std;
void swapL(int x, int y);
void swapP(int* x, int* y);
void swapR(int & x, int & y);
int main()
{	
	
	int a{ 5 }, b{ 4 };
	swapL(a, b);
	cout << "a=" << a << " b=" << b << endl;
	swapP(&a, &b);
	cout << "a=" << a << " b=" << b << endl;
	swapR(a, b);
	cout << "a=" << a << " b=" << b << endl;
}
void swapL(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
void swapP(int* x, int* y)
{
	int temp =* x;
	*x = *y;
	*y = temp;
}
void swapR(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
#endif

#if LESSON==25
#include <iostream>
using namespace std;
/*==CONST QUALIFIER
1- Creates variable that is constant
2- Value can't be modified
3- Attempt to modify will cause compilation error
4- Qualified to declaration, initialization is a must
5- better than macros , as macros doesn't have scope, not type safe, hard in debugging
6- commonly used with references 
*/
int main()
{
	float const PI = 3.14f;
	float radius{ 0 };
	cin >> radius;
	float area = PI * radius * radius;
	float circumeference = PI * 2 * radius;
	cout << "Area is " << area << endl;
	cout << "circumeference is " << circumeference << endl;

}

#endif

#if LESSON==26
#include <iostream>
using namespace std;
void Print( const int& ref)
{
	cout << ref << endl;
}

int main()
{
	int x = 5;
	Print(1);
	return 1;
}
#endif

#if LESSON==28
#include <iostream>
using namespace std;
/*==AUTO Keyword
	indicates storage class of a variable
	came from B language
	auto <identifir> = <initializer>
*/
int main()
{
	auto i1{ 10 };
	auto falawet{ 1.4f };
	auto i2{ 13 };
	auto sumi{ i1 + i2 };
	auto sumf{ falawet + i2 };

	const int x = 5;
	auto y = x;			//y now is int not const int
	const auto y1 = x;	//y now is const int not int
	auto& y2 = x;		//y now is const int not int
	auto* y3 = &x;		//const also
	//array with auto
	auto k{ 1 };	   //works
	//auto k2{ 1,2,3 };// doesn't work
	return 0;
}
#endif

#if LESSON==29
#include <iostream>
using namespace std;
/*==>Range based for loop
* Allow iteration over arrays and containers
* Doesn't need index variable
* each iteration returns an element from the container
* can be used with any object that behaves like a range
*/

int main()
{
	int arr[]{ 1,2,3,4,5 };
	cout << "Not range based for loop" << endl;
	for (int i{}; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "Range based for loop" << endl;
	for (auto & x : arr)
	{
		//why reference?
		//do modify elements inside array
		cout << x << endl;
	}
	cout << "Range based for loop" << endl;
	for (auto x : { 1,2,3,4 })
	{
		cout << x << endl;
	}
	return 0;
}
#endif

#if LESSON==30
#include <iostream>
using namespace std;
/*==>Range based for loop
* Allow iteration over arrays and containers
* Doesn't need index variable
* each iteration returns an element from the container
* can be used with any object that behaves like a range
*/

int main()
{
	int arr[]{ 1,2,3,4,5 };
	//int* beg = &arr[0];
	//int* beg = std::begin(arr);
	//int* end = &arr[5];
	//int* end = std::end(arr);

	auto range = arr;
	auto beg = std::begin(arr);
	auto end = std::end(arr);
	for (; beg != end; beg++)
	{
		auto V = *beg;
		cout << V << endl;

	}
	//while (beg != end)
	//{
	//	cout << *beg << endl;
	//	beg++;
	//}

	return 0;
}
#endif

#if LESSON==31
#include <iostream>
using namespace std;
/*==> Function Overloading
* Two or more functions declared with the same name:
  -Arguments should differ in type and/or number
  -For pointers & reference arguments,qualifiers pariticipate in overload
  -Return type is ignored
  - for member functions,qualifires participate in overload
* Different implemenations of the same behaviour
* The correct implemenation is chosen based on the arguemnts
* This is resolved at compile-time:
									- static polymorphism
* Convience for the caller
*/

/*==>Name mangling
* unique name generated by compiler for functions
* Allows linker to link the call with the correct overload function
* Name mangling algo varies from compiler to compiler
* depends on number of overloading
*/

/*==>Extern C
*Compiler directive applied on global functions and variables
* Suppresses name mangling of the type on which it is applied
* can be applied only to one function in a set of overloaded functions
* Allows C++ functions to be called from c or other languages
*/
int Add(int a, int b);
double Add(double a, double b);
extern "C" void Print(int& x);
void Print(const int& x);

int main()
{
	int result = Add(3, 5);
	cout << "int result= " << result << endl;
	double result2 = Add(3.4, 5.2);
	cout << "double result= " << result2 << endl;
	Print(result2);
	Print(4);
	return 0;
}
int Add(int a, int b)
{
	cout << "hello from int Add(int a, int b)" << endl;
	return a + b;
}
double Add(double a, double b)
{
	cout << "hello from double Add(double a, double b)" << endl;
	return a + b;
}
extern "C" void Print(int& x)
{
	cout << "hello from Print(int& x)" << endl;
	cout << x << endl;
}
void Print(const int& x)
{
	cout << "hello from Print(const int& x)" << endl;
	cout << x << endl;
}
#endif

#if LESSON==32
#include <iostream>
using namespace std;
void CreateWindoW(const char* title, int x = -1, int y = -1, int width = -1, int height = -1);
int main()
{
	CreateWindoW("Notepad");
	return 0;
}
void CreateWindoW(const char* title, int x , int y , int width , int height )
{
	cout << "Title : " << title << endl;
	cout << "x     : " << x << endl;
	cout << "y     : " << y << endl;
	cout << "width : " << width << endl;
	cout << "height: " << height << endl;
}
#endif

#if LESSON==33
#include <iostream>

/*==>Inline Function
*A function that is marked with inline keyword
*such function is defined in a header file
*request the compiler to replace the call with the function body
*the overhead of the function call is avoided
* -stack memory for the arguments is not required
* -No need for context switch
* may improve performence of the code
* certain functions may not be inlined:
* -large functions
* - functions having too many conditional statements
* - recursive functions
* - functions invoked through pointers
* modern compilers may automatically inline uninlined functions
* 
*/
using namespace std;
//int square(int x);
inline int square(int x)
{
	return x * x;
}
//#define square(x) ((x)*(x))
int main()
{
	int val = 5;
	int result = square(val);
	cout << result << endl;
	return 0;
}

#endif
#if LESSON==34
#include <iostream>

/*==>Function Pointer
*
* Pointer that holds the address of the function
* the type is same as the signature of the function (return type and arguments)
* can be used to indirectly invoke the function even if the function name is not known
* used by algos and classes for customization
*/
using namespace std;
void Print(int count, char ch)
{
	for (int i{}; i < count; i++)
	{
		cout << ch;
	}
	cout << endl;
}
void EndMessage()
{
	cout << "End of program" << endl;
}
int main()
{

	Print(5, '#');
	void(*pfn)(int, char) = Print;
	pfn(5, '#');
	atexit(EndMessage);
	return 0;
}

#endif

#if LESSON==35
#include <iostream>

/*==>Namespaces
*
* Named declarative region used for declaring types
* the types are not visible outside namespace
* standard library is in std namespace
* prevents name clashes
* Help modularize code
* 
*/

/*==>Namespaces Access
*
* Types inside a namespace have a scope
* cannot be accessed outside the namespace
*/
using namespace std;

namespace avg
{
	float Calculate(float x, float y)
	{
		return (x + y) / 2;
	}
}

namespace basic
{
	float Calculate(float x, float y)
	{
		return x + y;
	}
}
int main()
{
	float y=basic::Calculate(1.2, 34.3);
	return 0;
}

#endif
