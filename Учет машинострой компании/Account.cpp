#include "Account.h"

std::string way_to_acc = "File_Acc.txt";

string account::Get_Login()
{
	return this->Login;

}

string account::Get_Pass()
{
	return this->Password;
}

account::account()
{
}

account::account(string log, string pass)
{
	this->Login = log;

	this->Password = pass;
}

account::account(string log, string pass, int Root)
{
	this->Login = log;

	this->Password = pass;
	
	this->Access = Root;
}

int account::Get_Access()
{
	return this->Access;
}


istream & operator>>(istream & is, account & acc)
{

	is >> acc.Login;

	is >> acc.Password;

	is >> acc.Access;

	return is;
}

ostream & operator<<(ostream& os, account & acc)
{
	os << acc.Login << " " << acc.Password << " " << acc.Access << endl;

	return os;

}
