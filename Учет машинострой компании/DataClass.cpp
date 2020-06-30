#include "DataClass.h"


MyData::MyData()
{
}

MyData::MyData(int D, int M, int Y)
{
	this->Day = D;

	this->Month = M;

	this->Year = Y;
}

int MyData::Get_Year()
{
	return this->Year;
}

int MyData::Get_Month()
{
	return this->Month;
}

int MyData::Get_Day()
{
	return this->Day;
}

istream & operator>>(istream & is, MyData & obj)
{
	char temp;

	is >> obj.Day >> temp >> obj.Month >> temp >> obj.Year;

	return is;
}

ostream & operator<<(ostream & os, MyData & obj)
{
	os << obj.Day << " . " << obj.Month << " . " << obj.Year;

		return os;

}

bool operator==(MyData a, MyData b)
{
	if (a.Get_Day() == b.Get_Day() && a.Get_Month() == b.Get_Month() && a.Get_Year() == b.Get_Year())
	{
		return true;
	}
	else
	{
		return false;
	}
}
