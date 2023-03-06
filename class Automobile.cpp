// class Automobile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
Используя множественное наследование, разработать класс “Автомобиль”.
Автомобиль будет потомком для классов “Колеса”, “Двигатель”, “Двери”.
*/

class Door             // класс дверь, базовый
{
protected:
	int num_of_doors;  // кол-во дверей
public:
	Door() : num_of_doors{ 0 } {}                         // конструктор без параметров	
	Door(int n) : num_of_doors{ n }                       // конструктор с параметром
	{
		try
		{
			if (n != 2 && n != 4)  // может быть только 2-ух или 4-ех дверный авто
			{
				// гененируем исключение
				throw "\nNumber of doors must be 2 or 4 only!!!\n";
			}
		}
		catch (const char* s)
		{
			std::cout << "\n Error!!!" << s << "\n\n";
		}
		std::cout << "Door constructor with param\n";
	}

	void Show()       // ф-ия вывода на экран в зависимости от кол-ва дверей
	{
		num_of_doors == 4  // если кол-во дверей = 4
			? std::cout << "\tThe four-door car" << std::endl
			: (num_of_doors == 2) 
			   ? std::cout << "\tThe two-door car" << std::endl  // если кол-во дверей = 2
			   : std::cout << "\terror number of doors!!!" << std::endl;  // // если кол-во дверей !=2 && !=4

	}
	~Door()  // деструктор 
	{
		std::cout << "Door destructor\n";
	}
};

class Engine       // класс двигатель, базовый
{
protected:
	double power;  // мощность двигателя
public:
	Engine() : power{ 0 } {}     // конструктор без параметров	
	Engine(double p) : power(p)  // конструктор с параметром
	{
		std::cout << "Engine constructor with param\n";
	}
	~Engine()  // деструктор
	{
		std::cout << "Engine destructor\n";
	}
};

class Wheel          // класс колесо, базовый
{
protected:
	float diameter;  // диаметр
public:
	Wheel() : diameter{ 0 } {}      // конструктор без параметров
	Wheel(float d) : diameter{ d }  // конструктор с параметром
	{
		std::cout << "Wheel constructor with param\n";
	}
	~Wheel()  // деструктор
	{
		std::cout << "Wheel destructor\n";
	}
};

class Car : public Door, public Engine, public Wheel  // класс Авто - наследних пред.трех классов
{
	std::string name;           // название авто
public:
	Car() : name{ nullptr } {}  // конструктор без параметров

	Car(int Num_of_door, double Power, float Diameter, std::string Name)
		: Door{ Num_of_door }, Engine{ Power }, Wheel{ Diameter }  // конструктор с параметрами
	{
		std::cout << "Car constructor with param\n";
		name = Name;
	}
	~Car()  // деструктор
	{
		std::cout << "Car destructor\n";
	}

	void Show()  // ф-ия Вывод на экран характеристик авто
	{
		std::cout << "\n\tCar characteristic:\n";
		std::cout << "\t" << name << std::endl;
		Door::Show();  // вызов ф-ии вывод на экран из класса Дверь
		std::cout << "\tEngine power: " << power << std::endl;
		std::cout << "\tWheel diameter: " << diameter << std::endl;
		std::cout << std::endl;

	}
};

int main()
{
	Car obj{ 4, 350, 35, "BMW" };  // создание объекта типа Car
	obj.Show();  // вызов ф-ии Вывод на экран характеристик авто

	return 0;
}

/*
	Подскажите, правильно ли я использовала исключение?	
*/
