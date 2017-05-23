#include <iostream>
#include <conio.h>
#include "SortTable.h"
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	TTable table1(10);
	
	TRecord r1("Литова", 5);
	TRecord r2("Петрова", 4);
	TRecord r3("Лебедев", 5);
	TRecord r4("Акушев", 3);
	TRecord r5("Якимов", 2);
	TRecord r6("Сорокин", 5);
	TRecord r7("Окунева", 3);
	TRecord r8("Якимова", 2);
	TRecord r9("Акушева", 5);
	TRecord r10("Соловьев", 5);
	TRecord r11("Соловушкина", 5);



	cout << "Добавление записей в таблицу: " << endl;
	cout << setw(10) << "ФИО" << " Оценка" << endl;
	table1.AddRecord(r1);
	table1.Print();
	cout << endl;
	table1.AddRecord(r2);
	table1.Print();
	cout << endl;
	table1.AddRecord(r3);
	table1.Print();
	cout << endl;
	table1.AddRecord(r4);
	table1.AddRecord(r5);
	table1.AddRecord(r6);
	table1.AddRecord(r7);
	table1.AddRecord(r8);
	table1.Print();
	cout << endl;
	table1.AddRecord(r7);
	table1.AddRecord(r9);
	table1.AddRecord(r10);	
	table1.Print();
	table1.AddRecord(r11);
	cout << endl;
	
	cout << endl << "Удаление записи из таблицы по ключу Лебедев:"<<endl;
	table1.DelRecord("Лебедев");
	
	table1.Print();

	cout << endl<<"Поиск записи по ключу Литова: "<< table1.SeachRecord("Литова")<<endl;
	cout << endl << "Поиск записи по ключу Овечкин: " << table1.SeachRecord("Овечкин") + 1 << endl;

	_getch();
	return 0;
}