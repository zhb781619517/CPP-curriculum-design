#pragma once

#include "Goods.h"
#include "Account.h"
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<Windows.h>

using namespace std;

class GoodsManage//��Ʒ����
{
public:
	GoodsManage();
	~GoodsManage();
	void Changeaccount();//��������
	void DisplayMainMenu();//���˵���ʾ
	void AddGoodsInfo();//�����Ʒ��Ϣ
	void DisplayGoodsInfo();//�����Ʒ��Ϣ
	void SearchByCode();//������Ʒ���������Ʒ��Ϣ
	void SearchByName();//������Ʒ����������Ʒ��Ϣ
	void SearchByType();//������Ʒ���������Ʒ��Ϣ
	void SearchByBrand();//������ƷƷ��������Ʒ��Ϣ
	void EditGoodsInfo();//�༭��Ʒ��Ϣ
	void DeleteGoodsInfo();//ɾ����Ʒ��Ϣ
	void SellGoodsInfo();//������Ʒ��Ϣ
	void SaveGoodsInfo();//������Ʒ��Ϣ
	void ReadGoodsInfo();//������Ʒ��Ϣ
	void DateRemind();//����������
	void GoodsRemind();//�������
	void LowDateRemind();//��������
	void LowGoodsRemind();//�Ϳ������
private:
	int amount;//��Ʒ��
	int DeleteAmount;
	Goods* head;
	Goods* DeleteHead;
};
