#pragma once
#include <iostream>
class Integer
{

	int* m_pInt;
public:
	//defualt constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//copy constructor
	Integer(const Integer& obj);
	//Move constructor
	Integer(Integer&& obj)noexcept;
	//Getter function for const data
	int GetValue()const;
	//Setter function
	void SetValue(int value);
	//Destructor
	~Integer();
};

