#pragma once
class Integer
{
private:
	int* m_pInt;
public:
	Integer();//defualt constructor
	Integer(int value);//Parameterized constructor
	Integer(const Integer &obj);
	~Integer();
	int GetValue()const;//Getter function for const data
	void SetValue(int value);//Setter function

};

