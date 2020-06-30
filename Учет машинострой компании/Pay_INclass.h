#pragma once
#include"DataClass.h"

extern string way_to_PayIn;
enum Way_to_pay_in{Sells_car=1,Sells_bus=2,Sells_microbus=3,Sells_trains=4,investments=5,Sells_ditails=6 };


class Pay_IN {
public:
	Pay_IN();
	Pay_IN(MyData D, double S, Way_to_pay_in W);
	double Get_Sum();
	MyData Get_Data();
	Way_to_pay_in Get_Mean();
	friend istream& operator>>(istream& is, Pay_IN &obj);
	friend ostream& operator<<(ostream& os, Pay_IN &obj);
	friend istream& operator>(istream& is, Pay_IN &obj);
	friend ostream& operator<(ostream& os, Pay_IN &obj);

private:

	MyData day_note;

	double sum;

	Way_to_pay_in Mean;

};

double Inp_doubl_in();

MyData Inp_Data_in();

Way_to_pay_in Inp_Mean_in();