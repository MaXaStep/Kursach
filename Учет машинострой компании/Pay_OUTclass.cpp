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
	cout << "������ ������� " << obj.Get_Data().Get_Day() << " ����� " << obj.Get_Data().Get_Month() << " ������ " << obj.Get_Data().Get_Year()<<" ����" << endl;

	switch (obj.Get_Mean()) 
	{
	case Way_to_pay_out::Bills:
	{
		cout << "�������� : ������� �� ��������������" << endl;

		break;
	}
	case Way_to_pay_out::Defect:
	{
		cout << "�������� : �������������� ������ �� ������� ���������� �������" << endl;

		break;
	}
	case Way_to_pay_out::Logistics:
	{
		cout << "�������� : ������� �� �������� ������� �� ������ �����������" << endl;

		break;
	}
	case Way_to_pay_out::Marketing:
	{
		cout << "�������� : ������� ������������� ��������� " << endl;

		break;
	}
	case Way_to_pay_out::Salaries:
	{
		cout << "�������� : ������� ������� �����������" << endl;

		break;
	}
	case Way_to_pay_out::Stock:
	{
		cout << "�������� : ������� ��������� �� �������� �����" << endl;

		break;
	}
	case Way_to_pay_out::Taxes:
	{
		cout << "�������� : ������� �������" << endl;

		break;
	}
	case Way_to_pay_out::Utility:
	{
		cout << "�������� : ������� �� ����������� �������" << endl;

		break;
	}
	}

	cout << "����� : -" << obj.Get_Sum() << " $" << endl << endl;

	return os;
}

double Inp_doubl()
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

MyData Inp_Data()
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
	} while (m> 12);

	

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
	return MyData(d,m,y);
}

Way_to_pay_out Inp_Mean()
{
	Way_to_pay_out ret;
	char ch;
	do
	{
		system("cls");

		cout << "������� 1- ������� �� �����" << endl;
		cout << "������� 2- ������� ������� �����������" << endl;
		cout << "������� 3- ������� �� ����������� �������" << endl;
		cout << "������� 4- ������� �� ��������������" << endl;
		cout << "������� 5- �������������� ����� �� ����������� ������� � ����������" << endl;
		cout << "������� 6- ������� ������������� ���������" << endl;
		cout << "������� 7- ������ �������" << endl;
		cout << "������� 8- ������� �� ��������� �����������" << endl;
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