#include "Pay_INclass.h"

string way_to_PayIn="PayIn.txt";

Pay_IN::Pay_IN()
{

}

Pay_IN::Pay_IN(MyData D, double S, Way_to_pay_in W)
{
	this->day_note = D;

	this->sum = S;

	this->Mean = W;
}

double Pay_IN::Get_Sum()
{
	return this->sum;
}

MyData Pay_IN::Get_Data()
{
	return this->day_note;
}

Way_to_pay_in Pay_IN::Get_Mean()
{
	return this->Mean;
}

istream & operator>>(istream & is, Pay_IN & obj)
{
	int prov;

	is >> obj.day_note>> prov >> obj.sum;


	switch (prov)
	{
	case 1:
	{
		obj.Mean = Way_to_pay_in::Sells_car;

		break;
	}
	case 2:
	{
		obj.Mean = Way_to_pay_in::Sells_bus;

		break;
	}
	case 3:
	{
		obj.Mean = Way_to_pay_in::Sells_microbus;

		break;
	}
	case 4:
	{
		obj.Mean = Way_to_pay_in::Sells_trains;

		break;
	}
	case 5:
	{
		obj.Mean = Way_to_pay_in::investments;

		break;
	}
	case 6:
	{
		obj.Mean = Way_to_pay_in::Sells_ditails;

		break;
	}
	}


	return is;

}

ostream & operator<<(ostream & os, Pay_IN & obj)
{
	os << obj.day_note << " " << (int)obj.Mean << " " << obj.sum << endl;

	return os;
}

istream & operator>(istream & is, Pay_IN & obj)
{
	obj.sum = Inp_doubl_in();

	obj.day_note = Inp_Data_in();

	obj.Mean = Inp_Mean_in();

	system("cls");

	return is;
}

ostream & operator<(ostream & os, Pay_IN & obj)
{
	cout << "Запись создана " << obj.Get_Data().Get_Day() << " числа " << obj.Get_Data().Get_Month() << " месяца " << obj.Get_Data().Get_Year() << " года" << endl;

	switch (obj.Get_Mean())
	{
	case Way_to_pay_in::investments:
	{
		cout << "Значение : Доход от инвестиций и различных процентных ставок" << endl;

		break;
	}
	case Way_to_pay_in::Sells_bus:
	{
		cout << "Значение : Доход от продаж автобусов" << endl;

		break;
	}
	case Way_to_pay_in::Sells_car:
	{
		cout << "Значение : Доход от продаж автомобилей" << endl;

		break;
	}
	case Way_to_pay_in::Sells_ditails:
	{
		cout << "Значение : Доход от продаж деталей " << endl;

		break;
	}
	case Way_to_pay_in::Sells_microbus:
	{
		cout << "Значение : Доход от продаж микроавтобусов" << endl;

		break;
	}
	case Way_to_pay_in::Sells_trains:
	{
		cout << "Значение : Доход от продаж вагонов" << endl;

		break;
	}
	
	}

	cout << "Сумма : +" << obj.Get_Sum() << " $" << endl << endl;

	return os;
}

double Inp_doubl_in()
{
	system("cls");
	double i;
	while (true)
	{
		cout << "Введите сумму денег в $" << endl;
		cin >> i;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Неверный ввод, повторите" << endl;
		cin.ignore(10, '\n');
	}
	return i;
}

MyData Inp_Data_in()
{
	system("cls");

	int y, m, d;

	do {
		while (true)
		{
			cout << "Введите год оплаты (>2000г)" << endl;
			cin >> y;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "Неверный ввод" << endl;
			cin.ignore(10, '\n');
		}
	} while (y < 2000);

	do {
		while (true)
		{
			cout << "Введите месяц оплаты" << endl;
			cin >> m;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "Неверный ввод" << endl;
			cin.ignore(10, '\n');
		}
	} while (m > 12);



	do {
		while (true)
		{
			cout << "Введите день оплаты" << endl;
			cin >> d;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "Неверный ввод" << endl;
			cin.ignore(10, '\n');
		}
	} while (d > 31);
	return MyData(d, m, y);
}

Way_to_pay_in Inp_Mean_in()
{
	Way_to_pay_in ret; char ch;

	do {
		system("cls");

		cout << "Нажмите 1- Продажи автомобилей" << endl;
		cout << "Нажмите 2- Продажи автобусов" << endl;
		cout << "Нажмите 3- Продажи микроавтобусов" << endl;
		cout << "Нажмите 4- Продажи вагонов" << endl;
		cout << "Нажмите 5- Прибыль от инвестиций" << endl;
		cout << "Нажмите 6- Продажи деталей" << endl;

		ch = _getch();

	} while (((int)ch < 49) || ((int)ch > 54));

	switch (ch)
	{
	case '1':
	{
		ret = Way_to_pay_in::Sells_car;

		break;
	}
	case '2':
	{
		ret = Way_to_pay_in::Sells_bus;

		break;
	}
	case '3':
	{
		ret = Way_to_pay_in::Sells_microbus;

		break;
	}
	case '4':
	{
		ret = Way_to_pay_in::Sells_trains;

		break;
	}
	case '5':
	{
		ret = Way_to_pay_in::investments;

		break;
	}
	case '6':
	{
		ret = Way_to_pay_in::Sells_ditails;

		break;
	}
	default:
		break;
	}

	return ret;
}
