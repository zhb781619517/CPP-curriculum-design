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

struct Account//�˺�����
{
	string accountnum;//�˺�
	string password;//����
	int wrong;//Ȩ��
	Account* next;
	Account();//���캯��
	int Verification();//�˺���֤
	void Addaccount();//����˺�
	void Subaccount();//ɾ���˺�
	void Changeaccount();//��������
	void Writein();//���˺�����д���ļ�
	void Readout();//���˺��������
};
