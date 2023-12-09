#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define LESSON 39

#if LESSON==36

int main()
{
	int* Pmalloc = (int*)malloc(sizeof(int));
	*Pmalloc = 5;
	int* Pcalloc = (int*)calloc(sizeof(int) , 6);
	if (Pmalloc == NULL || Pcalloc == NULL)
	{
		std::cout << "edotna storage baaaaa!!!" << std::endl;
		return -1;
	}
	int* Pcalloc_base = Pcalloc;
	for (int i{}; i < 6; i++)
	{
		(*Pcalloc++) = i;
	}
	Pcalloc = Pcalloc_base;
	for (int i{}; i < 6; i++)
	{
		std::cout << (*Pcalloc++) << std::endl;
	}
	printf("%d", *Pmalloc);
	free(Pmalloc);
	Pmalloc = NULL;
	return 0;
}
#endif

#if LESSON==37
/*==>Dynamic memory allocation
*	
*	new: operator that allocate memory on the heap
*	delete: deallocates memory
*/

/*					MALLOC								NEW
*			
*				   Function				|		      Operator
*       Requires size during allocation |    Size is Ascertained from the type
*		Cannot initialize memory		|         Can initialize memory
*		  Cannot call constructor       |         Can Call Constructor
*			return void pointer			|       return the correct pointer
*			Cannot be customized		|			Can be overloaded
*			malloc,calloc,realloc       |			different forms
*			Return NULL on failure      |         throws exception on failure

*/
void New();
void Malloc();
int main()
{

}
void New()
{
	//new not only allocates but initialize not like malloc which allocates only
	//when new can't reserve memory it throughs an exception
	int* p = new int(5);

	std::cout << *p << std::endl;
	delete p;
}
void Malloc()
{
	int* Pmalloc = (int*)malloc(sizeof(int));
	*Pmalloc = 5;
	
	if (Pmalloc == NULL)
	{
		std::cout << "edotna storage baaaaa!!!" << std::endl;
		return ;
	}
	printf("%d", *Pmalloc);
	free(Pmalloc);
	Pmalloc = NULL;
}
#endif

#if LESSON==38
/*==>Dynamic Array
* 
*	Another form of new
*	written as new[]
*   <type> * <variable_name>=new<type>[size]
*	int* p = new int[5]{1,2,3,4,5};
*	int* p = new int[5];
*	for(int i{};i<5;i++)
*		p[i]=i
*   delete[]<varibale_name>
*/
int main()
{
	int* p = new int[5]{1,2,3,4,5};
	std::cout << p[0];
	delete[]p;
	p = nullptr;
	char* str = new char[4];
	strcpy_s(str, 4,"c++");
	std::cout << str << std::endl;
	delete[]str;
}
#endif

#if LESSON==39
/*==>2D dynamic array
*/

int main()
{
	int* row = new int[3];
	int* column = new int[3];
	int** _2D = new int* [2];
	_2D[0] = row;
	_2D[1] = column;


	for (int i{}; i < 2; i++)
	{
		for (int j{}; j < 3; j++)
		{
			_2D[i][j] = i * 3 + j;
		}
	}
	for (int i{}; i < 2; i++)
	{
		for (int j{}; j < 3; j++)
		{
			std::cout << _2D[i][j] << std::endl;
		}
	}
	delete[]row;
	delete[]column;
	delete[]_2D;
}
#endif
