#include "Goods.h"

using namespace std;

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

