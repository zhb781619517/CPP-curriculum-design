#pragma once

#include "Date.h"
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

enum GoodsType//商品类别
{
	Food = 1,//食品
	Cosmetic,//化妆品
	Commodity,//日用品
	Drink//饮料
};

struct Goods//商品基本信息
{
	string code;//商品编号
	string name;//商品名称
	string brand;//生产厂家
	double price;//商品价格
	int num;//商品数量
	GoodsType type;//商品类别
	Date date;//入库时间
	int expiradate;//保质期
	Goods* next;
	void HeadPrint();//输出货物表头
	void Goodprint();//输出货物相关信息
};

void Goods::HeadPrint() {
	cout << setiosflags(ios::left) << setw(10) << "编号" << setw(16) << "名称" << setw(10) << "生产厂家" << setw(10) << "价格" << setw(10) <<
		"商品类别" << setw(10) << "数量" << setw(16) << "入库时间" << setw(10) << "保质期" << endl;
}

void Goods::Goodprint() {
	cout << setiosflags(ios::left) << setw(10) << code << setw(16) << name;
	cout << setw(10) << brand << setw(10) << price << setw(10) << type;
	cout << setw(10) << num << setw(4) << date.year << "/" << setw(2) << date.month << "/" << setw(2) << date.day;
	cout << setw(6) << "" << setw(10) << expiradate << endl;
}

