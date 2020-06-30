#pragma once
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

extern string way_to_acc;

class account {
public:
	string Get_Login();
	string Get_Pass();
	account();
	account(string log,string pass);
	account(string log, string pass, int Root);
	int Get_Access();
	friend istream& operator>>(istream& is,account& acc);
	friend ostream& operator<<(ostream& os, account& acc);

private:

	std::string Login;

	std::string Password;

	int Access =0;
};