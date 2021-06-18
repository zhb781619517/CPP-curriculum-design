#pragma once

#include "Goods.h"
#include "Account.h"
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<Windows.h>

using namespace std;

class GoodsManage//商品管理
{
public:
	GoodsManage();
	~GoodsManage();
	void Changeaccount();//更改密码
	void DisplayMainMenu();//主菜单显示
	void AddGoodsInfo();//添加商品信息
	void DisplayGoodsInfo();//浏览商品信息
	void SearchByCode();//按照商品编号搜索商品信息
	void SearchByName();//按照商品名称搜索商品信息
	void SearchByType();//按照商品类别搜索商品信息
	void SearchByBrand();//按照商品品牌搜索商品信息
	void EditGoodsInfo();//编辑商品信息
	void DeleteGoodsInfo();//删除商品信息
	void SellGoodsInfo();//出售商品信息
	void SaveGoodsInfo();//保存商品信息
	void ReadGoodsInfo();//读入商品信息
	void DateRemind();//保质期提醒
	void GoodsRemind();//库存提醒
	void LowDateRemind();//过期提醒
	void LowGoodsRemind();//低库存提醒
private:
	int amount;//商品量
	int DeleteAmount;
	Goods* head;
	Goods* DeleteHead;
};
