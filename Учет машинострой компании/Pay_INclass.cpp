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
	cout << "������ ������� " << obj.Get_Data().Get_Day() << " ����� " << obj.Get_Data().Get_Month() << " ������ " << obj.Get_Data().Get_Year() << " ����" << endl;

	switch (obj.Get_Mean())
	{
	case Way_to_pay_in::investments:
	{
		cout << "�������� : ����� �� ���������� � ��������� ���������� ������" << endl;

		break;
	}
	case Way_to_pay_in::Sells_bus:
	{
		cout << "�������� : ����� �� ������ ���������" << endl;

		break;
	}
	case Way_to_pay_in::Sells_car:
	{
		cout << "�������� : ����� �� ������ �����������" << endl;

		break;
	}
	case Way_to_pay_in::Sells_ditails:
	{
		cout << "�������� : ����� �� ������ ������� " << endl;

		break;
	}
	case Way_to_pay_in::Sells_microbus:
	{
		cout << "�������� : ����� �� ������ ��������������" << endl;

		break;
	}
	case Way_to_pay_in::Sells_trains:
	{
		cout << "�������� : ����� �� ������ �������" << endl;

		break;
	}
	
	}

	cout << "����� : +" << obj.Get_Sum() << " $" << endl << endl;

	return os;
}

double Inp_doubl_in()
{
	system("cls");
	double i;
	while (true)
	{
		cout << "������� ����� ����� � $" << endl;
		cin >> i;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "�������� ����, ���������" << endl;
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
			cout << "������� ��� ������ (>2000�)" << endl;
			cin >> y;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "�������� ����" << endl;
			cin.ignore(10, '\n');
		}
	} while (y < 2000);

	do {
		while (true)
		{
			cout << "������� ����� ������" << endl;
			cin >> m;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "�������� ����" << endl;
			cin.ignore(10, '\n');
		}
	} while (m > 12);



	do {
		while (true)
		{
			cout << "������� ���� ������" << endl;
			cin >> d;
			if (cin.good()) {
				cin.ignore(10, '\n');
				break;
			}
			cin.clear();
			cout << "�������� ����" << endl;
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

		cout << "������� 1- ������� �����������" << endl;
		cout << "������� 2- ������� ���������" << endl;
		cout << "������� 3- ������� ��������������" << endl;
		cout << "������� 4- ������� �������" << endl;
		cout << "������� 5- ������� �� ����������" << endl;
		cout << "������� 6- ������� �������" << endl;

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
