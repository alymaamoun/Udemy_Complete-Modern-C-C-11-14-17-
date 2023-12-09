#include "Car.h"
#include <iostream>
int Car::count = 0;
Car::Car():Car(0)
{
	count++;
	std::cout << "FUNCTION CALL: HELLO FROM OUR DEFAULT CONSTRUCTOR (Car())" << std::endl;
}
Car::Car(float amount):Car(amount,0)
{
	
	this->fuel = amount;
	std::cout << "FUNCTION CALL: HELLO FROM OUR PARAMETERIZED CONSTRUCTOR (Car(float amount))" << std::endl;
}
Car::Car(float amount, int passenger)
{
	count++;
	std::cout << "FUNCTION CALL: HELLO FROM OUR PARAMETERIZED CONSTRUCTOR + DELEGATING CONSTRUCTOR (Car(float amount, int passenger))" << std::endl;
	fuel = amount;
	this->passengers = passenger;
}
Car::~Car()
{
	count--;
	std::cout << "FUNCTION CALL: HELLO FROM OUR DEFAULT DESTRUCTOR (~Car())" << std::endl;
}
void Car::FillFuel		(float amount)
{
	this->fuel = amount;
}

void Car::Accelerate	(void)
{
	this->speed++;
	this->fuel -= 0.5f;
}

void Car::Brake			(void)
{
	this->speed = 0;
}

void Car::AddPassengers	(int amount)
{
	this->passengers = amount;
}

void Car::DashBoard		(void)
{
	std::cout << "Passengers= " << this->passengers << std::endl;
	std::cout << "Fuel      = " << this->fuel << std::endl;
	std::cout << "Speed     = " << speed << std::endl;
	
}

void Car::showcount(void)
{
	std::cout << "Count     = " << count << std::endl;
}
