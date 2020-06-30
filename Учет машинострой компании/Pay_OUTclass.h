#pragma once
#include"DataClass.h"

extern string way_to_PayOut;
enum Way_to_pay_out {Stock=1 , Salaries=2,Utility=3,Bills=4,Defect=5,Marketing=6,Taxes=7,Logistics=8};


class Pay_OUT {
public:
	Pay_OUT();
	Pay_OUT(MyData D,double S, Way_to_pay_out W);
	double Get_Sum();
	MyData Get_Data();
	Way_to_pay_out Get_Mean();
	friend istream& operator>>(istream& is,Pay_OUT &obj);
	friend ostream& operator<<(ostream& os, Pay_OUT &obj);
	friend istream& operator>(istream& is, Pay_OUT &obj);
	friend ostream& operator<(ostream& os, Pay_OUT &obj);


private:

	Way_to_pay_out Mean;

	double Sum;

	MyData day_note;

};

double Inp_doubl();

MyData Inp_Data();

Way_to_pay_out Inp_Mean();