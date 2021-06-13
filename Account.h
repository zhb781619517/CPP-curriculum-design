#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

struct Account//账号密码
{
	string accountnum;//账号
	string password;//密码
	int wrongtimes;
	Account* next;
	Account();//构造函数
	int Verification();//账号验证
	void Addaccount();//添加账号
	void Subaccount();//删除账号
	void Changeaccount();//更改密码
	void Writein();//将账号密码写入文件
	void Readin();//将账号密码从文件中写入
};
