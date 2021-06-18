#pragma once

#include<Windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <iomanip>
#include <conio.h>

using namespace std;

struct Account//账号密码
{
	string accountnum;//账号
	string password;//密码
	int wrong;//权限
	Account* next;
	Account();//构造函数
	int Verification();//账号验证
	void Addaccount();//添加账号
	void Subaccount();//删除账号
	void Changeaccount();//更改密码
	void Writein();//将账号密码写入文件
	void Readout();//将账号密码读出
};
