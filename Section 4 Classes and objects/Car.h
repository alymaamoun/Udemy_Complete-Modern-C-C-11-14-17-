#pragma once
class Car
{
private:
	float fuel{0};
	float speed{ 0 };
	int passengers{ 0 };
	static int count;
	/*
	AUTO is not allowed inside classes
	*/
public:
	Car();//Default constructor , now the compiler will not generate his default constructor
	Car(float amount);//parameterized constructor , now the compiler will not generate his default constructor
	Car(float amount, int passenger);//parameterized constructor + delegating constructor
	~Car();//Default destructor, compiler doesn't have to generate his default one
	void FillFuel			(float amount);
	void Accelerate			(void);
	void Brake				(void);
	void AddPassengers		(int amount);
	void DashBoard			(void);
	static void showcount	(void);
};

