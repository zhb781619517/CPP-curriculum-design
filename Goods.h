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
