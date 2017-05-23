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
	
	TRecord r1("������", 5);
	TRecord r2("�������", 4);
	TRecord r3("�������", 5);
	TRecord r4("������", 3);
	TRecord r5("������", 2);
	TRecord r6("�������", 5);
	TRecord r7("�������", 3);
	TRecord r8("�������", 2);
	TRecord r9("�������", 5);
	TRecord r10("��������", 5);
	TRecord r11("�����������", 5);



	cout << "���������� ������� � �������: " << endl;
	cout << setw(10) << "���" << " ������" << endl;
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
	
	cout << endl << "�������� ������ �� ������� �� ����� �������:"<<endl;
	table1.DelRecord("�������");
	
	table1.Print();

	cout << endl<<"����� ������ �� ����� ������: "<< table1.SeachRecord("������")<<endl;
	cout << endl << "����� ������ �� ����� �������: " << table1.SeachRecord("�������") + 1 << endl;

	_getch();
	return 0;
}