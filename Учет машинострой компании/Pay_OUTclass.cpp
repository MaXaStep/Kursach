#include "Pay_OUTclass.h"

string way_to_PayOut = "PayOut.txt";

Pay_OUT::Pay_OUT()
{

}

Pay_OUT::Pay_OUT(MyData D, double S, Way_to_pay_out W)
{
	this->day_note = D;

	this->Mean = W;

	this->Sum = S;
}

double Pay_OUT::Get_Sum()
{
	return this->Sum;
}

MyData Pay_OUT::Get_Data()
{
	return this->day_note;
}

Way_to_pay_out Pay_OUT::Get_Mean()
{
	return this->Mean;
}

istream & operator>>(istream & is, Pay_OUT & obj)
{
	int prov;
	is >> obj.day_note >> prov >> obj.Sum;
	
	switch (prov) {
	case 1:
	{
		obj.Mean = Way_to_pay_out::Stock;

		break;
	}
	case 2:
	{
		obj.Mean = Way_to_pay_out::Salaries;

			break;
	}
	case 3:
	{
		obj.Mean = Way_to_pay_out::Utility;

			break;
	}
	case 4:
	{
		obj.Mean = Way_to_pay_out::Bills;

			break;
	}
	case 5:
	{
		obj.Mean = Way_to_pay_out::Defect;

			break;
	}
	case 6:
	{
		obj.Mean = Way_to_pay_out::Marketing;

			break;
	}
	case 7:
	{
		obj.Mean = Way_to_pay_out::Taxes;

			break;
	}
	case 8:
	{
		obj.Mean = Way_to_pay_out::Logistics;

			break;
	}
	}

	return is;
}

ostream & operator<<(ostream & os, Pay_OUT & obj)
{
	os << obj.day_note << " " << (int)obj.Mean << " " << obj.Sum << endl;

	return os;
}

istream & operator>(istream & is, Pay_OUT & obj)
{
	obj.Sum = Inp_doubl();

	obj.day_note = Inp_Data();

	obj.Mean = Inp_Mean();

	system("cls");

	return is;

}

ostream & operator<(ostream & os, Pay_OUT & obj)
{
	cout << "Запись создана " << obj.Get_Data().Get_Day() << " числа " << obj.Get_Data().Get_Month() << " месяца " << obj.Get_Data().Get_Year()<<" года" << endl;

	switch (obj.Get_Mean()) 
	{
	case Way_to_pay_out::Bills:
	{
		cout << "Значение : Выплаты по взаимопроектам" << endl;

		break;
	}
	case Way_to_pay_out::Defect:
	{
		cout << "Значение : Дополнительные убытки по причине бракованых деталей" << endl;

		break;
	}
	case Way_to_pay_out::Logistics:
	{
		cout << "Значение : Выплаты на отправку товаров по местам получателей" << endl;

		break;
	}
	case Way_to_pay_out::Marketing:
	{
		cout << "Значение : Выплаты маркетинговым компаниям " << endl;

		break;
	}
	case Way_to_pay_out::Salaries:
	{
		cout << "Значение : Выплаты зарплат сотрудникам" << endl;

		break;
	}
	case Way_to_pay_out::Stock:
	{
		cout << "Значение : Выплаты компаниям по доставке сырья" << endl;

		break;
	}
	case Way_to_pay_out::Taxes:
	{
		cout << "Значение : Выплаты налогов" << endl;

		break;
	}
	case Way_to_pay_out::Utility:
	{
		cout << "Значение : Выплаты по комунальным услугам" << endl;

		break;
	}
	}

	cout << "Сумма : -" << obj.Get_Sum() << " $" << endl << endl;

	return os;
}

double Inp_doubl()
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

MyData Inp_Data()
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
	} while (m> 12);

	

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
	return MyData(d,m,y);
}

Way_to_pay_out Inp_Mean()
{
	Way_to_pay_out ret;
	char ch;
	do
	{
		system("cls");

		cout << "Нажмите 1- Затраты на сырье" << endl;
		cout << "Нажмите 2- Выплаты зарплат сотрудникам" << endl;
		cout << "Нажмите 3- Выплаты по комунальным услугам" << endl;
		cout << "Нажмите 4- Выплаты по взаимопроектам" << endl;
		cout << "Нажмите 5- Дополнительный ущерб от бракованных деталей и транспорта" << endl;
		cout << "Нажмите 6- Выплаты маркетинговым агенствам" << endl;
		cout << "Нажмите 7- Оплата налогов" << endl;
		cout << "Нажмите 8- Затраты на логистику предприятия" << endl;
		ch = _getch();

	} while (((int)ch < 49) || ((int)ch > 56));

	switch (ch) {
	case '1':
	{
		ret = Way_to_pay_out::Stock;

		break;
	}
	case '2':
	{
		ret = Way_to_pay_out::Salaries;

		break;
	}
	case '3':
	{
		ret = Way_to_pay_out::Utility;

		break;
	}
	case '4':
	{
		ret = Way_to_pay_out::Bills;

		break;
	}
	case '5':
	{
		ret = Way_to_pay_out::Defect;

		break;
	}
	case '6':
	{
		ret = Way_to_pay_out::Marketing;

		break;
	}
	case '7':
	{
		ret = Way_to_pay_out::Taxes;

		break;
	}
	case '8':
	{
		ret = Way_to_pay_out::Logistics;

		break;
	}

	
	}
	return ret;
}