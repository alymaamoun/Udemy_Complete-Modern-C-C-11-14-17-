#include "Integer.h"
#include <iostream>
#include <string>
Integer::Integer()
{
	std::cout << "Default constructor: Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int val)
{
	std::cout << "Parameterized constructor: Integer(int val)" << std::endl;
	m_pInt = new int(val);
}

Integer::Integer(const Integer& val)
{
	std::cout << "copy constructor: Integer(const Integer& val)" << std::endl;
	m_pInt = new int(*val.m_pInt);
}

Integer::Integer(Integer&& val)noexcept
{
	std::cout << "Move constructor: Integer(Integer&& val)" << std::endl;
	m_pInt = val.m_pInt;
	val.m_pInt = nullptr;
}

Integer::~Integer()
{
	std::cout << "Destructor: ~Integer()" << std::endl;
	delete m_pInt;
}

int Integer::GetValue(void)const
{
	return *m_pInt;
}

void Integer::SetValue(int val)
{
	*m_pInt = val;
}

Integer& Integer::operator=(const Integer& val)
{
	std::cout << "Copy assignment: Integer::operator=(const Integer& val)" << std::endl;
	if (this != &val)
	{
		delete m_pInt;
		this->m_pInt = new int(*val.m_pInt);
	}
	return *this;
}

Integer& Integer::operator=(Integer&& val) noexcept
{
	std::cout << "Move assignment: Integer::operator=(Integer&& val)" << std::endl;
	if (this != &val)
	{
		delete m_pInt;
		this->m_pInt =val.m_pInt;
		val.m_pInt = nullptr;
	}
	return *this;
}

Integer Integer::operator+(const Integer& val) const
{
	std::cout << " start Add operator" << std::endl;
	Integer temp;
	std::cout << "this.GetValue()= " << *this->m_pInt << " val.GetValue()= " << *val.m_pInt << std::endl;
	*temp.m_pInt = *this->m_pInt + *val.m_pInt;
	std::cout << "temp.GetValue()= " << *temp.m_pInt << std::endl;
	std::cout << " end Add operator" << std::endl;
	return temp;
}

Integer& Integer::operator++()
{
	std::cout << "start Prefix increment operator" << std::endl;
	++(*m_pInt);
	std::cout << "end Prefix increment operator" << std::endl;
	return *this;
}

Integer Integer::operator++(int)
{
	std::cout << "start postfix increment operator" << std::endl;
	Integer temp(*this);
	++(*m_pInt);
	std::cout << "end postfix increment operator" << std::endl;
	return temp;
}

bool Integer::operator==(const Integer& val)const
{
	return *this->m_pInt==*val.m_pInt;
}

void Integer::operator()()
{
	std::cout << *m_pInt << std::endl;
}

Integer::operator int()
{
	return *m_pInt;
}

Integer::operator string()
{
	return to_string(*this);
}

std::ostream& operator << (std::ostream& out, const Integer& a)
{
	out << a.GetValue();
	return out;
}
std::istream& operator >> (std::istream& in, Integer& a)
{
	int temp;
	in >> temp;
	a.SetValue(temp);
	return in;
}

