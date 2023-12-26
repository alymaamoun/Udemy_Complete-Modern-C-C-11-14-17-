#include <iostream>
#include "Integer.h"
#include <memory>
using namespace std;

/*==>Smart pointers
* 
* Smart pointers are used to solve memory leak by deleting themselves automatically after their life scope ends
* they have 4 forms
* 
* ()()() unique pointer:
*		- unique_ptr<TYPE> POINTER_NAME { INITIALIZATION};
*		- unique pointer is used to ensure it will not have any copy
*		- unique pointer is not copied , it only can be moved or referenced
*       - unique pointer shall not be used if it will be used via multiple sources
* 
* ()()() shared pointer:
*		- shared_ptr<TYPE> POINTER_NAME { INITIALIZATION};
*		- shared pointer can be used by many source it can be copied
*       - the instance of the shared pointer knows the number of it's copies 
*       - instance.use_count()
*       - the pointer will be destroyed when the number of instances is zero
*		- it can cause circular reference problem
* 
*[][][] circular reference problem:
*		- it's a problem in which a classes have shared pointer to each other
*		- this will prevent the counts of the copies to be zero
*       - this problem will be solved if one of the two classes let the ref to the another class to be a weak pointer
* 
* ()()() weak pointer:
*		- extension to the shared pointer
*       - the pointer is not destroyed if count is zero and there's still a weak ref to it
*       - many weak pointer can ref to the same 
*       - to use weak pointer you shall first check if it's not expired then lock on it

*/

#define LESSON 78

#if LESSON==72
void Display(Integer* p)
{
	if (p == nullptr)
	{
		return;
	}
	cout << p->GetValue()<< endl;
}
Integer* GetPointer(int value)
{
	Integer* p = new Integer{ value };//will call the parameterized constructor
	return p;//move ellision prevented move constructor
}
void Operate(int value)
{
	Integer* p = GetPointer(value);
	if (p == nullptr)
	{
		p = new Integer{};
	}
	p->SetValue(100);
	Display(p);
	delete p;//destructor
	p = nullptr;
	p = new Integer{};//default constructor
	*p = __LINE__;//__LINE__ will call parameterized constructor, after that; move assignment operator , as p is already created then the temp which carried __LINE__ will be deleted
	Display(p);
	delete p;//destructor
	p = nullptr;
}
int main()
{
	Operate(5);
	return 0;
}
/*==>Log
* Parameterized constructor: Integer(int val)
100
Destructor: ~Integer()
Default constructor: Integer()
Parameterized constructor: Integer(int val)
Move assignment: Integer::operator=(Integer&& val)
Destructor: ~Integer()
33
Destructor: ~Integer()
*/
#endif

#if LESSON==73
/*==>smart pointers
* 
* 
*()()()Unique pointer:
*		-used when this pointer not to be shared
*		-smart pointers in general delete them selfs after their life scope ends
*/
#define LOG 2
 #if LOG==1
void Display(const Integer* p)
{
	if (p == nullptr)
	{
		return;
	}
	cout << p->GetValue() << endl;
}
Integer* GetPointer(int value)
{
	Integer* p = new Integer{ value };//will call the parameterized constructor
	return p;//move ellision prevented move constructor
}
void Operate(int value)
{
	unique_ptr<Integer> p { GetPointer(value)};//Parameterized constructor: Integer(int val)
	if (p == nullptr)
	{
		
		p.reset(new Integer{value});//p = new Integer{};
	}
	p->SetValue(100);
	Display(p.get());//100
	//delete p;//destructor
	//p = nullptr;
	p.reset(new Integer{});//p = new Integer{};//default constructor
	*p = __LINE__;//__LINE__ will call parameterized constructor, after that; move assignment operator , as p is already created then the temp which carried __LINE__ will be deleted
	Display(p.get());
	//delete p;//destructor
	//p = nullptr;
}
int main()
{
	Operate(5);
	return 0;
}
/*==>LOG 1
Parameterized constructor: Integer(int val)
100
Default constructor: Integer()
Destructor: ~Integer()
Parameterized constructor: Integer(int val)
Move assignment: Integer::operator=(Integer&& val)
Destructor: ~Integer()
92
Destructor: ~Integer()

*/
#endif
 #if LOG==2
void Display(const Integer* p)
{
	if (p == nullptr)
	{
		return;
	}
	cout << p->GetValue() << endl;
}
Integer* GetPointer(int value)
{
	Integer* p = new Integer{ value };//will call the parameterized constructor
	return p;//move ellision prevented move constructor
}
void Store(unique_ptr<Integer> &p)
{
	cout << "storing data into a file: " << p->GetValue() << endl;
}
void Operate(int value)
{
	unique_ptr<Integer> p { GetPointer(value)};//Parameterized constructor: Integer(int val)
	if (p == nullptr)
	{

		p.reset(new Integer{ value });//p = new Integer{};
	}
	p->SetValue(100);
	Display(p.get());//100
	//delete p;//destructor
	//p = nullptr;
	p.reset(new Integer{});//p = new Integer{};//default constructor
	*p = __LINE__;//__LINE__ will call parameterized constructor, after that; move assignment operator , as p is already created then the temp which carried __LINE__ will be deleted
	Display(p.get());
	Store(p);//Store(move(p));
	//delete p;//destructor
	//p = nullptr;
}
int main()
{
	Operate(5);
	return 0;
}
/*==>LOG 2
Parameterized constructor: Integer(int val)
100
Default constructor: Integer()
Destructor: ~Integer()
Parameterized constructor: Integer(int val)
Move assignment: Integer::operator=(Integer&& val)
Destructor: ~Integer()
147
storing data into a file: 147
Destructor: ~Integer()
*/
#endif
#endif

#if LESSON==74

class Project
{
	string m_Name;
public:
	void SetName(const string& name)
	{
		m_Name = name;
	}
	void ShowProjectDetails()const
	{
		cout << "[ProjectName]: " << m_Name << endl;
	}
};
class Employee
{
	Project* m_pProject{};
public:
	void SetProject(Project* prj)
	{
		m_pProject = prj;
	}
	const Project* getProject()const
	{
		return m_pProject;
	}
};
void ShowInfo(const Employee* E)
{
	cout << "EMPLOYEE DETAILS:::  " << endl;
	E->getProject()->ShowProjectDetails();
}
int main()
{

	Project* prj = new Project{};
	Employee* e1 = new Employee{};
	Employee* e2 = new Employee{};
	Employee* e3 = new Employee{};
	prj->SetName("Video Decoder");
	e1->SetProject(prj);
	e2->SetProject(prj);
	e3->SetProject(prj);
	cout << "MAIN;;;PRJ: " << endl;
	prj->ShowProjectDetails();
	cout << "MAIN;;;e1: " << endl;
	ShowInfo(e1);
	cout << "MAIN;;;e2: " << endl;
	ShowInfo(e2);	
	cout << "MAIN;;;e3: " << endl;
	ShowInfo(e3);
	delete prj;
	delete e1;
	delete e2;
	delete e3;
	return 0;
}
#endif

#if LESSON==75
#define UNIQUE 1
#define SHARED 2
#define SMARTPOINTER_TYPE SHARED

	#if SMARTPOINTER_TYPE == UNIQUE
//failue
class Project
{
	string m_Name;
public:
	void SetName(const string& name)
	{
		m_Name = name;
	}
	void ShowProjectDetails()const
	{
		cout << "[ProjectName]: " << m_Name << endl;
	}
};
class Employee
{
	unique_ptr<Project> m_pProject{};
public:
	void SetProject(unique_ptr<Project>& prj)
	{
		m_pProject = move(prj);
		
	}
	const unique_ptr<Project>& getProject()const
	{
		return m_pProject;
	}
};
void ShowInfo(const unique_ptr<Employee>& E)
{
	cout << "EMPLOYEE DETAILS:::  " << endl;

	E->getProject()->ShowProjectDetails();
}
int main()
{

	unique_ptr<Project> prj { new Project{}};
	unique_ptr<Employee> e1 { new Employee{}};
	unique_ptr<Employee> e2 { new Employee{}};
	unique_ptr<Employee> e3 { new Employee{}};
	prj->SetName("Video Decoder");
	e1->SetProject(prj);
	e2->SetProject(prj);
	e3->SetProject(prj);
	cout << "MAIN;;;PRJ: " << endl;
	prj->ShowProjectDetails();
	cout << "MAIN;;;e1: " << endl;
	ShowInfo(e1);
	cout << "MAIN;;;e2: " << endl;
	ShowInfo(e2);
	cout << "MAIN;;;e3: " << endl;
	ShowInfo(e3);

	return 0;
}
	#endif

	#if SMARTPOINTER_TYPE == SHARED
class Project
{
	string m_Name;
public:
	void SetName(const string& name)
	{
		m_Name = name;
	}
	void ShowProjectDetails()const
	{
		cout << "[ProjectName]: " << m_Name << endl;
	}
};
class Employee
{
	shared_ptr<Project> m_pProject{};
public:
	~Employee()
	{
		cout << "Current number of shares is:" << m_pProject.use_count() << endl;
	}
	void SetProject(shared_ptr<Project>& prj)
	{
		m_pProject = (prj);
		cout << "Current number of shares is:" << m_pProject.use_count() << endl;

	}
	const shared_ptr<Project>& getProject()const
	{
		return m_pProject;
	}
};
void ShowInfo(const unique_ptr<Employee>& E)
{
	cout << "EMPLOYEE DETAILS:::  " << endl;

	E->getProject()->ShowProjectDetails();

	
}
int main()
{

	shared_ptr<Project> prj { new Project{}};
	prj->SetName("Video Decoder");
	unique_ptr<Employee> e1 { new Employee{}};
	e1->SetProject(prj);
	unique_ptr<Employee> e2 { new Employee{}};
	e2->SetProject(prj);
	unique_ptr<Employee> e3 { new Employee{}};
	e3->SetProject(prj);
	
	
	
	cout << "MAIN;;;PRJ: " << endl;
	prj->ShowProjectDetails();
	cout << "MAIN;;;e1: " << endl;
	ShowInfo(e1);
	cout << "MAIN;;;e2: " << endl;
	ShowInfo(e2);
	cout << "MAIN;;;e3: " << endl;
	ShowInfo(e3);

	return 0;
}
	#endif

#endif

#if LESSON==76
class Project
{
	string m_Name;
public:
	void SetName(const string& name)
	{
		m_Name = name;
	}
	void ShowProjectDetails()const
	{
		cout << "[ProjectName]: " << m_Name << endl;
	}
};
class Employee
{
	shared_ptr<Project> m_pProject{};
public:
	~Employee()
	{
		cout << "Current number of shares is:" << m_pProject.use_count() << endl;
	}
	void SetProject(shared_ptr<Project>& prj)
	{
		m_pProject = (prj);
		cout << "Current number of shares is:" << m_pProject.use_count() << endl;

	}
	const shared_ptr<Project>& getProject()const
	{
		return m_pProject;
	}
};
void ShowInfo(const unique_ptr<Employee>& E)
{
	cout << "EMPLOYEE DETAILS:::  " << endl;

	E->getProject()->ShowProjectDetails();


}
int main()
{

	shared_ptr<Project> prj { new Project{}};
	prj->SetName("Video Decoder");
	unique_ptr<Employee> e1 { new Employee{}};
	e1->SetProject(prj);
	unique_ptr<Employee> e2 { new Employee{}};
	e2->SetProject(prj);
	unique_ptr<Employee> e3 { new Employee{}};
	e3->SetProject(prj);



	cout << "MAIN;;;PRJ: " << endl;
	prj->ShowProjectDetails();
	cout << "MAIN;;;e1: " << endl;
	ShowInfo(e1);
	cout << "MAIN;;;e2: " << endl;
	ShowInfo(e2);
	cout << "MAIN;;;e3: " << endl;
	ShowInfo(e3);

	return 0;
}
#endif

#if LESSON==77

class Printer
{
	shared_ptr<int> m_pValue{};
public:
	void SetValue(shared_ptr<int> p)
	{
		m_pValue = p;
	}
	void print()const
	{
		cout << "Value is: " << *m_pValue << endl;
	}
};


int main()
{
	Printer prn;
	int num{};
	cin >> num;
	shared_ptr<int> p{ new int{ num } };
	prn.SetValue(p);
	if (*p > 13)
	{
		p = nullptr;
	}
	prn.print();
	return 0;
}
#endif

#if LESSON==78

class Printer
{
	weak_ptr<int> m_pValue{};
public:
	void SetValue(weak_ptr<int> p)
	{
		m_pValue = p;
	}
	void print()const
	{
		if (m_pValue.expired())
			cout << "EXPIRED" << endl;
		else
		{
			auto sp = m_pValue.lock();
			cout << "Value is: " << *sp << endl;
		}
		
	}
};


int main()
{
	Printer prn;
	int num{};
	cin >> num;
	shared_ptr<int> p{ new int{ num } };
	prn.SetValue(p);
	if (*p > 13)
	{
		p = nullptr;
	}
	prn.print();
	return 0;
}
#endif
