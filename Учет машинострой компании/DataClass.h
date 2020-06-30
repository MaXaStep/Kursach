#pragma once

#include<fstream>
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

class MyData {
public:
	MyData();
	MyData(int, int, int);
	friend istream & operator>>(istream& is, MyData & obj);
	friend ostream & operator<<(ostream& os, MyData & obj);
	friend bool operator==(MyData,MyData);
	int Get_Year();
	int Get_Month();
	int Get_Day();

private:
	int Year;
	int Month;
	int Day;

};