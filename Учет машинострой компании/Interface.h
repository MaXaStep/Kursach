#pragma once
#include"Account.h"
#include"Pay_INclass.h"
#include"Pay_OUTclass.h"
#include<fstream>
#include<ctime>
#include<Windows.h>
#include<vector>

using namespace std;

extern vector<account> List_of_acc;
extern account Now_Use;
extern vector<Pay_IN> Vec_IN;
extern vector<Pay_OUT> Vec_OUT;


void Acc_in_file(account& ac);
void Admin_or_User();
void Admin_Menu();
void User_Menu();
void Input_Log_Pass();
void Acc_from_file(vector<account>&);
void Enter_Acc();
void Create_Acc();
void Exit_Prog();
void Clear_and_write_Vec_Out();
int Get_Num_String_File();
void show_one_note();
void show_all_note();
void clear_and_write_Vec_in();
int Get_Num_String_File_in();
void show_one_note_in();
void show_all_note_in();
int InpMonth();
int InpYear();

////menu admin and user
void add_note();
void del_note();
void show_notes();
void output_res_sells_month();
void output_res_sells_year();
void back_to_choise_acc();