#pragma once

#include "Date.h"
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

enum GoodsType//��Ʒ���
{
	Food = 1,//ʳƷ
	Cosmetic,//��ױƷ
	Commodity,//����Ʒ
	Drink//����
};

struct Goods//��Ʒ������Ϣ
{
	string code;//��Ʒ���
	string name;//��Ʒ����
	string brand;//��������
	double price;//��Ʒ�۸�
	int num;//��Ʒ����
	GoodsType type;//��Ʒ���
	Date date;//���ʱ��
	int expiradate;//������
	Goods* next;
	void HeadPrint();//��������ͷ
	void Goodprint();//������������Ϣ
};
