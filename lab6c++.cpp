#include <sys/types.h>
#include <fcntl.h> 
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Car 
{
	string name;
	string manufacturer;
	string type;
	int price;
	int year;
};

void task1()
{
	cout << "Size of Car struct: " << sizeof(Car) << " bytes";
	string namesExamples[] = { "Chery", "BMW", "Ford", "Ferrari" };
	string types[] = { "Hatchback", "Sedan    ", "Crossover", "Sportcar" };
	string manuf[] = { "China","Germany","USA","Italy" };
	const int N = 4;
	Car* car = new Car[N];
	char path[] = "db.bin";

	cout << endl << endl << "Information:" << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << (car[i].name = namesExamples[i]) << "\t"<<(car[i].manufacturer = manuf[i]) << "\t" << (car[i].price = 6000 + rand() % 100000) << "$\t" << (car[i].type = types[i])<< "\t"<< (car[i].year = 2010 + rand() % 10) << endl;
	}

	FILE* f_out, * f_in;
	f_out = fopen(path, "wb");
	fwrite(car, sizeof(Car), N, f_out);
	fclose(f_out);

	delete[] car;
	car = nullptr;

	cout << endl << endl << "Information from file:" << endl;
	Car* restoredDB = new Car[N];
	f_in = fopen(path, "rb");
	fread(restoredDB, sizeof(Car), N, f_in);
	fclose(f_in);
	
	for (size_t i = 0; i < N; i++)
	{
		if ((restoredDB[i].year) > 2015 &&(restoredDB[i].manufacturer)!= "China")
		{
			cout << restoredDB[i].name << "\t" << restoredDB[i].manufacturer << "\t" << restoredDB[i].price << "$\t" << restoredDB[i].type << "\t" << restoredDB[i].year << endl;
		}		
	}
}

struct Hotel
{
	string name{"Hotel A"};
	string typeOfNumber;
	int price;
	int countOfFreePlaces;
	int applications;
	int countOfDays;
};

void task2()
{
	cout << "Size of Hotel struct: " << sizeof(Hotel) << " bytes";
	string types[] = { "Single Number", "Double Number", "Multi Number"};
	const int N = 3;
	Hotel* hotel = new Hotel[N];
	char path[] = "bd.bin";

	cout << endl << endl << "Information of Hotel A: " << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << (hotel[i].typeOfNumber = types[i]) << endl;
		if (hotel[i].typeOfNumber == "Single Number")
		{
			cout <<"Price: "<< (hotel[i].price = 150) << "$ |";
			cout <<"Available rooms: " <<(hotel[i].countOfFreePlaces = 10 + rand() % 5) << "| Count of applications for accommodation:" << (hotel[i].applications = 15 + rand() % 8)<<"| Number of days pre-paid per room:" << (hotel[i].countOfDays = 22) << endl;
		}
		else if ((hotel[i].typeOfNumber == "Double Number"))
		{
			cout << "Price: " << (hotel[i].price = 200) << "$ |";
			cout << "Available rooms: " << (hotel[i].countOfFreePlaces = 10 + rand() % 5) << "| Count of applications for accommodation:" << (hotel[i].applications = 15 + rand() % 8) << "| Number of days pre-paid per room:" << (hotel[i].countOfDays = 20) << endl;
		}
		else if ((hotel[i].typeOfNumber == "Multi Number"))
		{
			cout << "Price: " << (hotel[i].price = 300) << "$ |";
			cout << "Available rooms: " << (hotel[i].countOfFreePlaces = 10 + rand() % 5) << "| Count of applications for accommodation:" << (hotel[i].applications = 15 + rand() % 8) << "| Number of days pre-paid per room:" << (hotel[i].countOfDays = 10) << endl;
		}
		cout << endl;
	}

	FILE* f_out, * f_in;
	f_out = fopen(path, "wb");
	fwrite(hotel, sizeof(Hotel), N, f_out);
	fclose(f_out);

	delete[] hotel;
	hotel = nullptr;

	cout << endl << endl << "Information from file:" << endl;
	Hotel* restoredBD = new Hotel[N];
	f_in = fopen(path, "rb");
	fread(restoredBD, sizeof(Hotel), N, f_in);
	fclose(f_in);

	for (size_t i = 0; i < N; i++)
	{
		if ((restoredBD[i].countOfDays) == 10)
		{
			cout << (restoredBD[i].typeOfNumber = types[i]) << endl;
			if (restoredBD[i].typeOfNumber == "Single Number")
			{
				cout << "Price: " << (restoredBD[i].price = 150 - (150*5/100)) << "$ |";
				cout << "Available rooms: " << restoredBD[i].countOfFreePlaces << "| Count of applications for accommodation:" << restoredBD[i].applications << "| Number of days pre-paid per room:" << restoredBD[i].countOfDays << endl;
			}
			else if ((restoredBD[i].typeOfNumber == "Double Number"))
			{
				cout << "Price: " << (restoredBD[i].price = 200 - (200 * 5 / 100)) << "$ |";
				cout << "Available rooms: " << restoredBD[i].countOfFreePlaces << "| Count of applications for accommodation:" << restoredBD[i].applications << "| Number of days pre-paid per room:" << restoredBD[i].countOfDays << endl;
			}
			else if ((restoredBD[i].typeOfNumber == "Multi Number"))
			{
				cout << "Price: " << (restoredBD[i].price = 300 - (300 * 5 / 100)) << "$ |";
				cout << "Available rooms: " << restoredBD[i].countOfFreePlaces << "| Count of applications for accommodation:" << restoredBD[i].applications << "| Number of days pre-paid per room:" << restoredBD[i].countOfDays << endl;
			}
		}
		if ((restoredBD[i].countOfDays) > 10)
		{
			cout << (restoredBD[i].typeOfNumber = types[i]) << endl;
			if (restoredBD[i].typeOfNumber == "Single Number")
			{
				cout << "Price: " << (restoredBD[i].price = 150 - (150 * 10 / 100)) << "$ |";
				cout << "Available rooms: " << restoredBD[i].countOfFreePlaces << "| Count of applications for accommodation:" << restoredBD[i].applications << "| Number of days pre-paid per room:" << restoredBD[i].countOfDays << endl;
			}
			else if ((restoredBD[i].typeOfNumber == "Double Number"))
			{
				cout << "Price: " << (restoredBD[i].price = 200 - (200 * 10 / 100)) << "$ |";
				cout << "Available rooms: " << restoredBD[i].countOfFreePlaces << "| Count of applications for accommodation:" << restoredBD[i].applications << "| Number of days pre-paid per room:" << restoredBD[i].countOfDays << endl;
			}
			else if ((restoredBD[i].typeOfNumber == "Multi Number"))
			{
				cout << "Price: " << (restoredBD[i].price = 300 - (300 * 10 / 100)) << "$ |";
				cout << "Available rooms: " << restoredBD[i].countOfFreePlaces << "| Count of applications for accommodation:" << restoredBD[i].applications << "| Number of days pre-paid per room:" << restoredBD[i].countOfDays << endl;
			}
		}
	}
}

int main()
{
	setlocale(0, "");
	cout << "Задание 1. Вывести сведения обо всех автомобилях, срок выпуска которых не менее 5 лет и произведенных не в Китае" << endl << endl;
	task1();
	cout << endl << "Задание 2. переписать информмацию в бмнарный файл так, чтобы стоимость номера снизить на 5% если количество дней по предварительной оплате = 10, и на 10%  если количество дней по предварительной оплате больше 20" << endl << endl;
	task2();
}