#include "Goods.h"

using namespace std;

void Goods::HeadPrint() {
	cout << setiosflags(ios::left) << setw(10) << "���" << setw(16) << "����" << setw(10) << "��������" << setw(10) << "�۸�" << setw(10) <<
		"��Ʒ���" << setw(10) << "����" << setw(16) << "���ʱ��" << setw(10) << "������" << endl;
}

void Goods::Goodprint() {
	cout << setiosflags(ios::left) << setw(10) << code << setw(16) << name;
	cout << setw(10) << brand << setw(10) << price << setw(10) << type;
	cout << setw(10) << num << setw(4) << date.year << "/" << setw(2) << date.month << "/" << setw(2) << date.day;
	cout << setw(6) << "" << setw(10) << expiradate << endl;
}

