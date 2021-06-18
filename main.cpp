#include<windows.h>
#include "GoodsManage.h"
#include "Account.h"
#include "Date.h"
#include "Goods.h"

using namespace std;

int main()//主函数
{
	char c;
	int i = 0;
	bool flag = 0;
	int limit = 0;//权限
	Account pm;//定义Account类对象
	GoodsManage bm;//定义GoodsManage类对象
	//TODO
	//读入之前存储过的Account
	//控制窗口大小颜色
	system("mode con cols=100 lines=36");
	system("color E0");//淡黄底黑字

	pm.Readout();//读出已存储的账号信息
	while(1){
		limit = pm.Verification();
		if (limit!=0) {
			break;
		}
		else {
			cout << "输入有误，请重新输入！！！" << endl;
			Sleep(1000);
			system("cls");
		}
	}
	system("cls");//清屏
	cout << endl << endl << endl << endl << endl << endl << "                  欢迎使用库存管理系统......系统正在加载中";
	Sleep(2000);//人为sleep
	system("cls");//清屏
	bm.ReadGoodsInfo();//读入之前存储的货物信息
	Sleep(3000);
	bm.DisplayMainMenu();
	for (;;)
	{
		do {
			cin >> c;
			if (c >= 'a' && c <= 'p')//判断用户输入编号是否存在
				flag = 1;
			else
			{
				cout << "您输入的编号不存在！" << endl;
				cout << "请选择相应的数字进行操作:" << endl;
			}
		} while (flag == 0);//输入编号存在时跳出循环进行相应操作
		system("cls");//清屏
		switch (c)
		{
		case'a':bm.AddGoodsInfo();
			break;
		case'b':bm.EditGoodsInfo();
			break;
		case'c':bm.DeleteGoodsInfo();
			break;
		case'd':bm.SearchByCode();
			break;
		case'e':bm.SearchByName();
			break;
		case'f':bm.SearchByType();
			break;
		case'g':bm.SearchByBrand();
			break;
		case'h':bm.SellGoodsInfo();
			break;
		case'i':bm.DisplayGoodsInfo();
			break;
		case'j':bm.SaveGoodsInfo();
			break;
		case'k':bm.DateRemind();
			break;
		case'l':bm.GoodsRemind();
			break;
		case'm':
			if (limit == 2) { pm.Addaccount(); }
			else {
				system("cls");
				cout << "权限不足，请使用root账号！！！" << endl;
				Sleep(1000);
			}
			break;
		case'n':
			if (limit == 2) { pm.Subaccount(); }
			else {
				system("cls");
				cout << "权限不足，请使用root账号！！！" << endl;
				Sleep(1000);
			}
			break;
		case'o':
			if (limit == 2) { pm.Changeaccount(); }
			else {
				system("cls");
				cout << "权限不足，请使用root账号！！！" << endl;
				Sleep(1000);
			}
			break;
		case'p':pm.Writein();
			exit(0);
			break;
		}
		//TODO
		//保质期不足3日提醒，存货量不足10提醒，若没有满足条件，则不提醒
		//bm.LowDateRemind();
		//bm.LowGoodsRemind();
		system("cls");
		bm.DisplayMainMenu();
	}
	return 0;
}
