#include "Integer.h"
#include <iostream>
Integer::Integer()
{
    std::cout << "Integer()" << std::endl;
    m_pInt = new int(0);
}

Integer::~Integer()
{
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}

Integer::Integer(int value)
{
    std::cout << "Integer(int value)" << std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer& obj)
{
    std::cout << "Integer(Integer& obj)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer&& obj)
{
    std::cout << "Integer(Integer&& obj)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}





int Integer::GetValue() const
{
    std::cout << "GetValue() const" << std::endl;
    return *m_pInt;
}

void Integer::SetValue(int value)
{
    std::cout << "SetValue(int value)" << std::endl;
    *m_pInt = value;
}
