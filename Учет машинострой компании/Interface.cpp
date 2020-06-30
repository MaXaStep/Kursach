#pragma once
#include "Interface.h"

using namespace std;

vector<account> List_of_acc;

vector<Pay_IN> Vec_IN;
vector<Pay_OUT> Vec_OUT;

account Now_Use;

void Admin_Menu()
{
	char ch;
	do 
	{


		system("cls");

		cout << "Нажмите 1- Добавить запись в базу" << endl;
		cout << "Нажмите 2- Удалить запись из базы" << endl;
		cout << "Нажмите 3- Просмотреть внесенные записи" << endl;
		cout << "Нажмите 4- Вывести результаты продаж за месяц" << endl;
		cout << "Нажмите 5- Вывести результаты продаж за год" << endl;
		cout << "Нажмите 6- Вернуться к выбору пользователя" << endl;

		ch = _getch();

	} while (((int)ch < 49) || ((int)ch > 54));

	switch (ch) {
	case '1':
	{
		add_note();

		break;
	}
	case '2':
	{
		del_note();

		break;
	}
	case '3':
	{
		show_notes();

		break;
	}
	case '4':
	{
		output_res_sells_month();

		break;
	}
	case '5':
	{
		output_res_sells_year();

		break;
	}
	case '6':
	{
		back_to_choise_acc();

		break;
	}
	}
}

void User_Menu()
{
	char ch;
		do
		{
			system("cls");

			cout << "Нажмите 1- Просмотреть внесенные записи" << endl;
			cout << "Нажмите 2- Вывести результаты продаж за месяц" << endl;
			cout << "Нажмите 3- Вывести результаты продаж за год" << endl;
			cout << "Нажмите 4- Вернуться к выбору пользователя" << endl;

			ch = _getch();

		} while (((int)ch < 49) || ((int)ch > 52));

		switch (ch) {

		case '1':
		{
			show_notes();

			break;
		}
		case '2':
		{
			output_res_sells_month();

			break;
		}
		case '3':
		{
			output_res_sells_year();

			break;
		}
		case '4':
		{
			back_to_choise_acc();

			break;
		}
		}

}

void Input_Log_Pass()
{
	char choise;

	List_of_acc.clear();

	Acc_from_file(List_of_acc);

	do {
		system("cls");

		cout << "Нажмите 1 - войти в учетную запись" << endl;

		cout << "Нажмите 2 - создать учетную запись" << endl;

		cout << "Нажмите 3 - выйти из программы" << endl;

		choise = _getche();

	} while (((int)choise<49) || ((int)choise>51));

	if (choise == '1') 
	{
		Enter_Acc();

	}
	else if (choise == '2') 
	{
		Create_Acc();
	}
	else 
	{
		Exit_Prog();
	}

}

void Acc_from_file(vector<account>& all_accs)
{
	ifstream file;

	account counter;

	file.open(way_to_acc);

	while (!file.eof())
	{
		file >> counter;

		all_accs.push_back(counter);

	}
}

void Acc_in_file(account & ac) 
{
	ofstream file;

	file.open(way_to_acc, ios::app);

	file << ac;

}

void Admin_or_User()
{
	if (Now_Use.Get_Access() == 1)
	{
		Admin_Menu();
	}
	else
	{
		User_Menu();
	}
}

void Enter_Acc()
{
	system("cls");

	std::string Login_IN, Pass_IN;
	vector<account> To_prov = List_of_acc;

	if (List_of_acc.empty()==1) 
	{
		system("cls");

		cout << "Не существует аккаунтов.Введите новый" << endl;

		Input_Log_Pass();
	}
	
	int Exist_acc=0;

	cout << "Введите логин:"; cin >> Login_IN;
	cout << "Введите пароль:"; cin >> Pass_IN;

	/*while (!To_prov.empty()) 
	{
		if (To_prov.data()->Get_Login() == Login_IN && To_prov.data()->Get_Pass() == Pass_IN) {

			Exist_acc = 1;

			account Inputed(To_prov.data()->Get_Login(), To_prov.data()->Get_Pass(), To_prov.data()->Get_Access());

			Now_Use = Inputed;

			break;
		}
		
		To_prov.pop_back();
	}*/

	for (int i = 0; i < To_prov.size(); i++) {

		if (To_prov[i].Get_Login() == Login_IN && To_prov[i].Get_Pass() == Pass_IN) {

			Exist_acc = 1;

			account Inputed(To_prov[i].Get_Login(), To_prov[i].Get_Pass(), To_prov[i].Get_Access());

			Now_Use = Inputed;

			break;
		}

	}
	if (Exist_acc == 0) 
	{
		system("cls");

		cout << "Введен неверный логин или пароль" << endl;

		Input_Log_Pass();
	}
	else  
	{
		Admin_or_User();

	}
}

void Create_Acc()
{
	system("cls");

	std::string Login_IN, Pass_IN;

	cout << "Введите логин:"; cin >> Login_IN;
	cout << "Введите пароль:"; cin >> Pass_IN;

	account In_file(Login_IN,Pass_IN);

	Now_Use = In_file;

	Acc_in_file(In_file);

	Admin_or_User();

}

void Exit_Prog()
{
	exit(0);
}
int Get_Num_String_File_in() 
{
	ifstream file; char buffer[1200]; int i = 0;

	file.open(way_to_PayIn);

	while (!file.eof())
	{
		file.getline(buffer, 1200, '\n');
		i++;
	}
	file.close();

	return i - 1;
}

void show_one_note_in()
{
	system("cls");

	clear_and_write_Vec_in();

	Pay_IN counter;

	MyData date; int coun = 0;

	date = Inp_Data();

	for (int i = 0; i < Vec_OUT.size(); i++) {

		if (Vec_IN[i].Get_Data() == date)
		{
			cout < Vec_IN[i];

			coun = 1;

			break;
		}

	}
	if (coun)
	{
		char back;

		do
		{
			cout << "Нажмите 1- Вернуться к меню " << endl;

			back = _getch();

		} while (back != '1');

		Admin_or_User();
	}
	else
	{
		cout << "Неправильный ввод данных" << endl;

		Sleep(1000);

		Admin_or_User();
	}

}

void show_all_note_in()
{
	system("cls");

	clear_and_write_Vec_in(); char back;

	Pay_IN counter;

	for (int i = 0; i < Vec_IN.size(); i++) {

		cout < Vec_IN[i];

	}

	cout << "Выполнено успешно" << endl;

	Sleep(1000);

	do
	{
		cout << "Нажмите 1- Вернуться к меню " << endl;

		back = _getch();

	} while (back != '1');

	Admin_or_User();
}

int InpMonth()
{
	int m;
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

	return m;
}

int InpYear()
{
	int y;
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



	return y;
}

void Clear_and_write_Vec_Out()
{
	Vec_OUT.clear();

	Pay_OUT counter;

	ifstream file;

	int Numb_Strings= Get_Num_String_File();

	file.open(way_to_PayOut);

	for (int i=0;i<Numb_Strings;i++)
	{
		file >> counter;

		Vec_OUT.push_back(counter);
	}


	/*while (file) {

		file >> counter;

		Vec_OUT.push_back(counter);
	}*/

}

int Get_Num_String_File()
{
	ifstream file; char buffer[1200]; int i = 0;

	file.open(way_to_PayOut);

	while (!file.eof()) 
	{
		file.getline(buffer, 1200, '\n');
		i++;
	}
	file.close();

	return i-1;
}

void show_one_note()
{
	system("cls");

	Clear_and_write_Vec_Out();

	Pay_OUT counter;
	
	MyData date; int coun=0;

	date = Inp_Data();

	for (int i = 0; i < Vec_OUT.size();i++) {

		if (Vec_OUT[i].Get_Data() == date)
		{
			cout < Vec_OUT[i];

			coun = 1;

			break;
		}

	}
	if(coun)
	{
		char back;

		do
		{
			cout << "Нажмите 1- Вернуться к меню " << endl;

			back = _getch();

		} while (back != '1');

		Admin_or_User();
	}
	else
	{
		cout << "Неправильный ввод данных" << endl;

		Sleep(1000);

		Admin_or_User();
	}

}

void show_all_note()
{
	system("cls");

	Clear_and_write_Vec_Out(); char back;

	Pay_OUT counter;

	for (int i = 0; i < Vec_OUT.size(); i++) {

		cout < Vec_OUT[i];

	}

	cout << "Выполнено успешно" << endl;

	Sleep(1000);

	
	do 
	{
		cout << "Нажмите 1- Вернуться к меню " << endl;

		back = _getch();

	} while (back != '1');

	Admin_or_User();

}

void clear_and_write_Vec_in()
{
	Vec_IN.clear();

	Pay_IN counter;

	ifstream file;

	int Numb_Strings = Get_Num_String_File_in();

	file.open(way_to_PayIn);

	for (int i = 0; i < Numb_Strings; i++)
	{
		file >> counter;

		Vec_IN.push_back(counter);
	}
}

void add_note()
{
	system("cls");

	char ch2;
	do
	{
		cout << "Нажмите 1- Добавить запись об расходах" << endl;

		cout << "Нажмите 2- Добавить запись об доходах" << endl;

		ch2 = _getch();

	} while (((int)ch2 < 49) || ((int)ch2 > 50));

	switch (ch2)
	{
	case '1':
	{

		ofstream file;

		Pay_OUT add;

		file.open(way_to_PayOut, ios::app);

		cin > add;

		file << add;

		file.close();

		cout << "Запись добавлена" << endl;

		Sleep(1000);

		Admin_Menu();

		break;
	}
	case '2':
	{
		ofstream file;

		Pay_IN add;

		file.open(way_to_PayIn,ios::app);

		cin > add;

		file << add;
		
		file.close();

		cout << "Запись добавлена" << endl;

		Sleep(1000);

		Admin_Menu();

		break;
	}
	}
}

void del_note()
{

	system("cls");

	char ch2;
	do
	{
		cout << "Нажмите 1- Удалить запись об расходах" << endl;

		cout << "Нажмите 2- Удалить запись об доходах" << endl;

		ch2 = _getch();

	} while (((int)ch2 < 49) || ((int)ch2 > 50));

	switch (ch2)
	{
	case '1':
	{

		Clear_and_write_Vec_Out(); MyData Date_F; int counter_prov = 0;

		cout << "Введите дату записи, которую хотите удалить" << endl;

		Date_F = Inp_Data();

		for (int i = 0; i < Vec_OUT.size(); i++)
		{
			if (Vec_OUT[i].Get_Data() == Date_F)
			{
				counter_prov = 1;

				ofstream file;

				file.open(way_to_PayOut);

				file.clear();

				for (int j = 0; j < Vec_OUT.size(); j++) {

					if (i == j) { continue; }

					file << Vec_OUT[j];
				}

				break;
			}
		}
		if (counter_prov == 1)
		{
			cout << "Выполнено успешно" << endl;

			Sleep(1000);

			Admin_Menu();
		}

		cout << "Нету записи с такой датой" << endl;

		Sleep(1000);

		Admin_Menu();

	}
	case '2':
	{
		clear_and_write_Vec_in(); MyData Date_F; int counter_prov = 0;

		cout << "Введите дату записи, которую хотите удалить" << endl;

		Date_F = Inp_Data();

		for (int i = 0; i < Vec_IN.size(); i++)
		{
			if (Vec_IN[i].Get_Data() == Date_F)
			{
				counter_prov = 1;

				ofstream file;

				file.open(way_to_PayIn);

				file.clear();

				for (int j = 0; j < Vec_IN.size(); j++) {

					if (i == j) { continue; }

					file << Vec_IN[j];
				}

				break;
			}
		}
		if (counter_prov == 1)
		{
			cout << "Выполнено успешно" << endl;

			Sleep(1000);

			Admin_Menu();
		}

		cout << "Нету записи с такой датой" << endl;

		Sleep(1000);

		Admin_Menu();

	}

	
	default:
		break;
	}
	
}

void show_notes()
{
	system("cls");

	char ch,ch2;

	do
	{
		cout << "Нажмите 1- Просмотреть записи об расходах" << endl;

		cout << "Нажмите 2- Просмотреть записи об доходах" << endl;

		ch2 = _getch();

	} while (((int)ch2 < 49) || ((int)ch2 > 50));

	switch (ch2)
	{
	case '1':
	{
		do
		{
			cout << "Нажмите 1- Просмотреть одну запись" << endl;

			cout << "Нажмите 2- Просмотреть все записи" << endl;

			ch = _getch();

		} while (((int)ch < 49) || ((int)ch > 50));

		if (ch == '1') {
			show_one_note();
		}
		else if (ch == '2')
		{
			show_all_note();
		}
	}
	case '2':
	{
		do
		{
			cout << "Нажмите 1- Просмотреть одну запись" << endl;

			cout << "Нажмите 2- Просмотреть все записи" << endl;

			ch = _getch();

		} while (((int)ch < 49) || ((int)ch > 50));

		if (ch == '1') 
		{
			show_one_note_in();
		}
		else if (ch == '2')
		{
			show_all_note_in();
		}
	}
	

	default:
		break;
	}

	
}

void output_res_sells_month()
{
	system("cls");

	clear_and_write_Vec_in(); Clear_and_write_Vec_Out();

	double Sum_In = 0, Sum_Out = 0, Sum_Res = 0;

	double Big_In = 0, Big_Out = 0;
	
	int Count_In = -1, Count_Out = -1;

	int Month, Year;

	cout << "Введите данные месяца и года для анализа доходов и расходов" << endl;

	Month = InpMonth();

	Year = InpYear();

	cout << "Доходы данного месяца" << endl;

	for (int i = 0; i < Vec_IN.size(); i++)
	{
		if (Vec_IN[i].Get_Data().Get_Month()==Month&&Vec_IN[i].Get_Data().Get_Year()==Year) 
		{
			if (Big_In<Vec_IN[i].Get_Sum()) 
			{
				Big_In = Vec_IN[i].Get_Sum();

				Count_In = i;
			}

			cout < Vec_IN[i];

			Sum_In += Vec_IN[i].Get_Sum();
		}
	}

	cout << "Расходы данного месяца" << endl;

	for (int i = 0; i < Vec_OUT.size(); i++)
	{

		if (Vec_OUT[i].Get_Data().Get_Month() == Month && Vec_OUT[i].Get_Data().Get_Year() == Year) 
		{
			if (Big_Out < Vec_OUT[i].Get_Sum())
			{
				Big_Out= Vec_OUT[i].Get_Sum();

				Count_Out = i;
			}

			cout < Vec_OUT[i];

			Sum_Out += Vec_OUT[i].Get_Sum();
		}
	}

	cout << "Общие результаты данного месяца :" << endl;

	Sum_Res = Sum_In - Sum_Out;

	if (Sum_Res>0) 
	{
		cout << "-----------------" << endl;
		cout << "Месяц оказался прибыльным с чистым доп. доходом :" << Sum_Res <<" $"<< endl;
		cout << "-----------------" << endl;
	}
	else
	{
		cout << "-----------------" << endl;
		cout << "Месяц оказался убыточным с расходом :" << Sum_Res << " $" << endl << endl;
		cout << "-----------------" << endl;
	}
	cout << "Самый большой доход за месяц :"<<Big_In<<" $" << endl;
	
	if (Count_In > -1)
	{
		cout << endl;

	cout < Vec_IN[Count_In];
	}
	
	cout << endl;

	cout << "Самый большой расход за месяц :" << Big_Out << " $" << endl;

	if (Count_Out > -1) 
	{
		cout << endl;

	cout < Vec_OUT[Count_Out];
	}
	
	cout << endl << endl;

	char prov;
	do
	{
		cout << "Введите 1, чтобы вернуться в меню" << endl;

		prov = _getch();

	} while (prov!='1');

	Admin_or_User();
}

void output_res_sells_year()
{
	system("cls");

	clear_and_write_Vec_in(); Clear_and_write_Vec_Out();

	double Sum_In = 0, Sum_Out = 0, Sum_Res = 0;

	double Big_In = 0, Big_Out = 0;

	int Count_In = -1, Count_Out = -1;

	int  Year;

	cout << "Введите  года для анализа доходов и расходов" << endl;

	Year = InpYear();

	cout << "Доходы данного года :" << endl;

	for (int i = 0; i < Vec_IN.size(); i++)
	{
		if ( Vec_IN[i].Get_Data().Get_Year() == Year)
		{
			if (Big_In < Vec_IN[i].Get_Sum())
			{
				Big_In = Vec_IN[i].Get_Sum();

				Count_In = i;
			}

			cout < Vec_IN[i];

			Sum_In += Vec_IN[i].Get_Sum();
		}
	}
	Sleep(5000);

	cout << "Расходы данного года :" << endl;

	for (int i = 0; i < Vec_OUT.size(); i++)
	{

		if ( Vec_OUT[i].Get_Data().Get_Year() == Year)
		{
			if (Big_Out < Vec_OUT[i].Get_Sum())
			{
				Big_Out = Vec_OUT[i].Get_Sum();

				Count_Out = i;
			}

			cout < Vec_OUT[i];

			Sum_Out += Vec_OUT[i].Get_Sum();
		}
	}

	cout << "Общие результаты данного месяца :" << endl;

	Sum_Res = Sum_In - Sum_Out;

	if (Sum_Res > 0)
	{
		cout << "-----------------" << endl;
		cout << "Год оказался прибыльным с чистым доп. доходом :" << Sum_Res << " $" << endl;
		cout << "-----------------" << endl;
	}
	else
	{
		cout << "-----------------" << endl;
		cout << "Год оказался убыточным с расходом :" << Sum_Res << " $" << endl << endl;
		cout << "-----------------" << endl;
	}

	cout << "Самый большой доход за год :" << Big_In << " $" << endl;

	if (Count_In > -1)
	{
		cout << endl;

		cout < Vec_IN[Count_In];
	}

	cout << endl;

	cout << "Самый большой расход за год :" << Big_Out << " $" << endl;

	if (Count_Out > -1)
	{
		cout << endl;

		cout < Vec_OUT[Count_Out];
	}

	cout << endl << endl;

	char prov;
	do
	{
		cout << "Введите 1, чтобы вернуться в меню" << endl;

		prov = _getch();

	} while (prov != '1');

	Admin_or_User();

}

void back_to_choise_acc()
{
	Input_Log_Pass();
}
