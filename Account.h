#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

struct Account//�˺�����
{
	string accountnum;//�˺�
	string password;//����
	int wrongtimes;
	Account* next;
	Account();//���캯��
	int Verification();//�˺���֤
	void Addaccount();//����˺�
	void Subaccount();//ɾ���˺�
	void Changeaccount();//��������
	void Writein();//���˺�����д���ļ�
	void Readin();//���˺�������ļ���д��
};
