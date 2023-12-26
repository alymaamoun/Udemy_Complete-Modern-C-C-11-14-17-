#pragma once
#include <iostream>
using namespace std;
class Integer
{

	int* m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int val);
	//Copy constructor
	Integer(const Integer& val);
	//Move constructor
	Integer(Integer&& val)noexcept;
	//Destructor
	~Integer();


	//getter
	int GetValue(void)const;
	//setter
	void SetValue(int val);


	//Copy assignment operator
	Integer& operator=(const Integer& val);
	//move assignment operator
	Integer& operator=(Integer&& val)noexcept;
	//add operator
	Integer operator+(const Integer& val)const;
	//prefix increment operator
	Integer& operator++();
	//postfix increment 
	Integer operator++(int);
	//compare operator
	bool operator==(const Integer& val)const;
	//arguments operator
	void operator ()();
	friend std::ostream& operator << (std::ostream& out, const Integer& a);
	friend std::istream& operator >> (std::istream& in, Integer& a);
    
	//type conversion
	operator int();
	operator string();
	
};


