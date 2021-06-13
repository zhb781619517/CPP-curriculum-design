#include "Goods.h"
#include "Account.h"
#include "GoodsManage.h"
#include<fstream>
#include<conio.h>


GoodsManage::GoodsManage()//���幹�캯��
{
	amount = 0;
	DeleteAmount = 0;
	head = new Goods;//ͷ��㲻��data
	head->next = NULL;
	DeleteHead = new Goods;//ͷ��㲻��data
	DeleteHead->next = NULL;
}

GoodsManage::~GoodsManage()//������������
{
	Goods* q, * p;
	//����head
	q = head->next;
	p = q->next;
	while (p != NULL) {
		delete q;
		q = p;
		p = p->next;
	}
	delete head;
	//����DeleteHead
	q = DeleteHead->next;
	p = q->next;
	while (p != NULL) {
		delete q;
		q = p;
		p = p->next;
	}
	//�������
}

void GoodsManage::DisplayMainMenu()//�������˵�����
{
	cout << " ��                                                                ��\n";
	cout << " ��                   ��ӭʹ����Ʒ������ϵͳ                     ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����Ʒ��������(a)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����Ʒ�༭����(b)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����Ʒɾ������(c)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                     �� �����ձ�Ų�ѯ����(d)                    ��\n";
	cout << " ��                     ��                                          ��\n";
	cout << " ��                     �� ���������Ʋ�ѯ����(e)                    ��\n";
	cout << " ��         ����Ʒ��ѯ����                                          ��\n";
	cout << " ��                     �� ����������ѯ����(f)                    ��\n";
	cout << " ��                     ��                                          ��\n";
	cout << " ��                     �� ������Ʒ�Ʋ�ѯ����(g)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����Ʒ��������(h)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����Ʒͳ�ơ���(i)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����Ϣ���桿��(j)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        �������ڲ�ѯ����(k)                     ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���Ϳ�����ѡ���(l)                     ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ������˺š���(m)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��ɾ���˺š���(n)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���������롿��(o)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                          �˳�ϵͳ��(p)                         ��\n";
	cout << "\n                      ��������Ҫ���еĲ������:";
}

void GoodsManage::AddGoodsInfo()//���������Ʒ��Ϣ����
{
	char c, c1;
	Goods* tail = head, * p;
	int flag = 0;
	cout << "          ����������ڽ�����Ʒ��Ϣ����ӡ������          " << endl;
	while (tail->next != NULL)
		tail = tail->next;//��tailָ�����������һ���ڵ�
	do
	{
		p = new Goods;
		cout << "��ѡ����Ʒ���:" << endl;
		cout << "1.ʳƷ 2.��ױƷ 3.����Ʒ 4.����" << endl;
		cout << "��������Ӧ���:";
		do
		{
			cin >> c1;
			if (c1 >= '1' && c1 <= '4')//�ж��û��������Ƿ����
				flag = 1;
			else
			{
				cout << "������ı�Ų����ڣ�" << endl;
				cout << "��ѡ����ȷ����Ʒ���:" << endl;
			}
		} while (flag == 0);//�����Ŵ���ʱ����ѭ��
		flag = 0;//��������
		if (c1 == '1')p->type = Food;
		if (c1 == '2')p->type = Cosmetic;
		if (c1 == '3')p->type = Commodity;
		if (c1 == '4')p->type = Drink;
		cout << "��Ʒ���(" << p->type << ")" << endl;//��ʾ��Ʒ���
		cout << "��������Ʒ���: ";
		cin >> p->code;
		do
		{
			Goods* q = head->next;
			while (q != NULL && q->code != p->code)//��qָ��NULL������ı����֮ǰ����ظ�ʱ����ѭ��
				q = q->next;
			if (q == NULL)//��pָ��NULL�ұ�Ų��ظ�ʱ
			{
				flag = 1;
			}
			else//����ظ�ʱ
			{
				cout << "���ڸñ�ŵĻ���!!!������������:";
				cin >> p->code;
			}
		} while (flag == 0);
		cout << "��������Ʒ���ƣ�";
		cin >> p->name;
		cout << "�������������ң�";
		cin >> p->brand;
		cout << "��������Ʒ�۸�";
		cin >> p->price;
		cout << "��������Ʒ������";
		cin >> p->num;
		cout << "���������ʱ�䣨��/��/�գ���";
		cin >> p->date.year >> p->date.month >> p->date.day;
		cout << "�����뱣���ڣ�";
		cin >> p->expiradate;
		tail->next = p;//��p��������
		p->next = NULL;
		tail = p;
		amount++;//��Ʒ����һ
		cout << "��������ɹ�����������������(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣�������<������y/n>" << endl;
			cout << "������ӳɹ������������������(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::DisplayGoodsInfo()//������Ʒ��Ϣ�������
{
	Goods* p = head;
	cout << "          ����������ڽ�����Ʒ��Ϣ������������          " << endl;
	p->HeadPrint();
	while (p->next != NULL)//ֱ��pָ�����������һ�����
	{
		p = p->next;
		cout << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;
		cout << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		cout << setw(10) << p->num << setw(4) << p->date.year << "/" << setw(2) << p->date.month << "/" << setw(2) << p->date.day;
		cout << setw(6) << "" << setw(10) << p->expiradate << endl;
	}
	cout << endl;
	cout << "������Ϣͳ����ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByCode()//������Ʒ��Ų�����Ʒ��Ϣ
{
	Goods* p;
	bool flag;
	string FoundCode;
	cout << "          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          " << endl;
	p = head;
	flag = 0;
	cout << "��������Ҫ���ҵ���Ʒ��ţ�";
	cin >> FoundCode;
	while (p->next != NULL)
	{

		p = p->next;
		if (p->code == FoundCode)//�ҵ���Ӧ��ŵ���Ʒ
		{
			if (flag == 0) {
				p->HeadPrint();
			}
			flag = 1;
			p->Goodprint();
			break;
		}
	}
	if (flag == 0)
	{
		cout << "�Բ�������ѯ����Ʒ�����ڣ�����" << endl;
	}
	cout << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByName()//������Ʒ���Ʋ�����Ʒ��Ϣ
{
	Goods* p;
	bool flag;
	string FoundName;
	cout << "          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          " << endl;
	p = head;
	flag = 0;
	cout << "��������Ҫ���ҵ���Ʒ���ƣ�";
	cin >> FoundName;
	while (p->next != NULL)
	{

		p = p->next;
		if (p->name == FoundName)//�ҵ���Ӧ���Ƶ���Ʒ
		{
			if (flag == 0) {
				p->HeadPrint();
			}
			flag = 1;
			p->Goodprint();
			break;
		}
	}
	if (flag == 0)
	{
		cout << "�Բ�������ѯ����Ʒ�����ڣ�����" << endl;
	}
	cout << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByType()//������Ʒ��������Ʒ��Ϣ
{

	Goods* p;
	bool flag;
	int FoundType;
	cout << "          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          " << endl;

	p = head;
	flag = 0;
	cout << "��������Ҫ���ҵ���Ʒ���";
	cin >> FoundType;
	while (p->next != NULL)
	{

		p = p->next;
		if (FoundType == 1 && p->type == Food)
		{
			if (flag == 0) { p->HeadPrint(); }
			flag = 1;
			p->Goodprint();
		}

		else if (FoundType == 2 && p->type == Cosmetic)
		{
			if (flag == 0) { p->HeadPrint(); }
			flag = 1;
			p->Goodprint();
		}
		else if (FoundType == 3 && p->type == Commodity)
		{
			if (flag == 0) { p->HeadPrint(); }
			flag = 1;
			p->Goodprint();
		}
		else if (FoundType == 4 && p->type == Drink)
		{
			if (flag == 0) { p->HeadPrint(); }
			flag = 1;
			p->Goodprint();
		}
	}
	if (flag == 0)
	{
		cout << "�Բ�������ѯ����Ʒ�����ڣ�����" << endl;
	}
	cout << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByBrand()//�����������Ҳ�����Ʒ��Ϣ
{

	Goods* p;
	bool flag;
	string FoundBrand;
	cout << "          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          " << endl;
	p = head;
	flag = 0;
	cout << "��������Ҫ���ҵ���ƷƷ�ƣ�";
	cin >> FoundBrand;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->brand == FoundBrand)//�ҵ���Ӧ������������Ӧ����Ʒ
		{
			if (flag == 0) { p->HeadPrint(); }
			flag = 1;
			p->Goodprint();
		}
	}
	if (flag == 0)
	{
		cout << "�Բ�������ѯ����Ʒ�����ڣ�����" << endl;
	}
	cout << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::EditGoodsInfo()//����༭��Ʒ��Ϣ����
{
	char c;
	Goods* p;
	bool flag = 0;
	string EditCode;
	cout << "          ����������ڽ�����Ʒ��Ϣ�ı༭�������          " << endl;
	do
	{
		p = head->next;//��pָ��head��һ���ڵ�
		flag = 0;
		cout << "��������Ҫ�޸ĵĻ����ţ�";
		cin >> EditCode;
		while (p->next != NULL && p->code != EditCode)//ֱ��pָ�����������һ���ڵ��ҵ���Ӧ��ŵ���Ʒʱ����ѭ��
			p = p->next;
		if (p->code == EditCode)
		{
			flag = 1;
			p->Goodprint();
			cout << "ȷ���޸���<y/n>";
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "ָ����󣡣�����<������y/n>:";
				cin >> c;
			}
			if (c == 'y')
			{
				cout << "��������Ʒ���ƣ�";
				cin >> p->name;
				cout << "�������������ң�";
				cin >> p->brand;
				cout << "��������Ʒ�۸�";
				cin >> p->price;
				cout << "��������Ʒ������";
				cin >> p->num;
				cout << "���������ʱ�䣨��/��/�գ���";
				cin >> p->date.year >> p->date.month >> p->date.day;
				cout << "�����뱣���ڣ�";
				cin >> p->expiradate;
				cout << "�޸ĳɹ���" << endl;
			}
			else cout << "ȡ���ɹ���" << endl;
		}
		if (flag == 0)
		{
			cout << "�Բ������޸ĵĻ��ﲻ���ڣ���" << endl;

		}
		cout << "����Ҫ�����޸���(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣���<������y/n>:" << endl;
			cout << "����Ҫ�����޸���(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "������Ϣ�༭��ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::DeleteGoodsInfo()//������Ʒ��Ϣɾ������
{
	Goods* q = head, * p, * tail = DeleteHead;
	p = new Goods;
	char c;
	string Dename;
	//	bool flag = 0;
	while (tail->next != NULL)//��tailָ�����������һ���ڵ�
		tail = tail->next;
	cout << "          ����������ڽ�����Ʒ��Ϣ��ɾ���������          " << endl;
	do
	{
		cout << "��������Ҫɾ������Ʒ���ƣ�";
		cin >> Dename;
		while (q->next != NULL && q->next->name != Dename)//ֱ��qָ�����������һ���ڵ�����ҵ���Ӧ���Ƶ���Ʒʱ����ѭ��
			q = q->next;
		if (q->next != NULL)//�ҵ���Ӧ���Ƶ���Ʒ
		{
			//			flag = 1;
			cout << "ȷ��ɾ����<y/n>";
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "ָ����󣡣�����<������y/n>:";
				cin >> c;
			}
			if (c == 'y')
			{
				p = q->next;
				q->next = q->next->next;//q����һ���ڵ�ָ�����Ľڵ�
				tail->next = p;
				tail = p;
				tail->next = NULL;//��������ɾ��ָ���ڵ�
				DeleteAmount++;
				amount--;//��Ʒ����һ
				cout << "ɾ���ɹ�����" << endl;
			}
			else cout << "ȡ���ɹ�������" << endl;
		}
		else
		{
			cout << "�Բ�����ɾ������Ʒ�����ڣ�����" << endl;
		}
		cout << "����Ҫ����ɾ����(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣���<������y/n>:" << endl;
			cout << "����Ҫ����ɾ����(y/n):";
			cin >> c;
		}
		q = head;//��qָ�������е�һ������ٴ�������Ӧ���Ƶ���Ʒ
	} while (c == 'y');
	cout << endl;
	cout << "������Ϣɾ����ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::SellGoodsInfo()//������Ʒ���⺯��
{
	int sellNum, year, month, day;
	double sellPrice, sum = 0.0, profit = 0.0;
	char c;
	Goods* p;
	bool flag = 0;
	string SellName;
	cout << "          ����������ڽ�����Ʒ�ĳ��ۡ������          " << endl;
	do
	{
		p = head->next;
		flag = 0;
		cout << "��������Ҫ���۵���Ʒ���ƣ�";
		cin >> SellName;
		while (p->next != NULL && p->name != SellName)
			p = p->next;
		if (p->name == SellName)
		{
			//������ڣ��򲻳���
			//TODO
			flag = 1;
			p->Goodprint();
			cout << "\nȷ�ϳ�����<y/n>";
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "ָ����󣡣�����<������y/n>:";
				cin >> c;
			}
			if (c == 'y')
			{
				cout << "��������۵���Ʒ������";
				cin >> sellNum;
				if (sellNum <= p->num)//���������
				{
					p->num = p->num - sellNum;//������Ʒ�������Ʒ�Ŀ����
					cout << "��������۵���Ʒ�۸�";
					cin >> sellPrice;
					cout << "������������ڣ�";
					cin >> year >> month >> day;
					sum = sellNum * sellPrice;//�������۽��
					profit = sellNum * (sellPrice - p->price);//��������
					cout << "�˴����۶�Ϊ�� " << sum << endl;
					cout << "�˴�����Ϊ�� " << profit << endl;
					cout << "��������Ϊ��" << year << "/" << month << "/" << day << endl;
				}
				else
				{
					cout << "��治�㣡����ʧ�ܣ�" << endl;
				}
			}
			else cout << "ȡ���ɹ���" << endl;
		}
		if (flag == 0)
		{
			cout << "�Բ��������۵Ļ��ﲻ���ڣ���" << endl;
		}
		cout << "����Ҫ����������(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣���<������y/n>:" << endl;
			cout << "����Ҫ����������(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "����������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::SaveGoodsInfo()//������Ʒ��Ϣ���溯��
{
	Goods* p = head;
	cout << "          ����������ڽ�����Ʒ��Ϣ�ı���������          " << endl;
	ofstream output("������Ϣ.txt", ios::out);//��������ļ�"������Ϣ.txt"
	if (!output)
	{
		cerr << "���ļ�<������Ϣ.txt>ʧ�ܣ�����" << endl;
	}
	p->HeadPrint();
	output << "��Ʒ����Ϊ: " << amount << "\n";
	output << setiosflags(ios::left) << setw(10) << "���" << setw(16) << "����" << setw(10) << "��������" << setw(10) << "�۸�" << setw(10) <<
		"��Ʒ���" << setw(10) << "����" << setw(16) << "���ʱ��" << setw(10) << "������" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		p->Goodprint();
		//���ļ�����ʾ��Ӧ��Ʒ��Ϣ
		output << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;
		output << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		output << setw(10) << p->num << setw(4) << p->date.year << "/" << setw(2) << p->date.month << "/" << setw(2) << p->date.day;
		output << setw(6) << "" << setw(10) << p->expiradate << endl;
	}
	cout << endl;
	cout << "�ɹ���������Ϣ���浽<������Ϣ.txt>" << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
	output.close();//�ر�����ļ�
}

void GoodsManage::ReadGoodsInfo()//������Ʒ��Ϣ
{

}

void GoodsManage::DateRemind()//�����Ʒ��������
{
	cout << "�����뱣����ʣ��������";
	int value, flag = 0;
	cin >> value;
	cout << "���²�Ʒ������С��" << value << endl;
	Goods* q = head->next;
	while (q != NULL) {
		if (q->expiradate <= value) {
			if (flag == 0) { q->HeadPrint(); }
			flag = 1;
			q->Goodprint();
		}
		q = q->next;
	}
	cout << endl;
	cout << "������������ʾ��ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::GoodsRemind()//�������
{
	//��������10��ʱ������ѣ�ÿһ�β��Һ�����ѵͿ��
	cout << "�������������";
	int value, flag = 0;
	cin >> value;
	cout << "���²�Ʒ��滹��" << value << endl;
	Goods* q = head->next;
	while (q != NULL) {
		if (q->num <= value) {
			if (flag == 0) { q->HeadPrint(); }
			flag = 1;
			q->Goodprint();
		}
		q = q->next;
	}
	cout << endl;
	cout << "���������ʾ��ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void GoodsManage::LowDateRemind()//����������
{
	system("cls");
	int flag = 0;
	cout << "���²�Ʒ�����ڻ���3���뼰ʱ����������" << endl;
	Goods* q = head->next;
	while (q != NULL) {
		if (q->expiradate <= 3) {
			if (flag == 0) { q->HeadPrint(); }
			flag = 1;
			q->Goodprint();
		}
		q = q->next;
	}
	if (flag != 0) {
		cout << endl;
		cout << "����������������ϡ���" << endl;
		cout << "����������Զ��������˵�����" << endl;
		Sleep(3000);
	}
}
void GoodsManage::LowGoodsRemind()//�������
{
	//��������10��ʱ������ѣ�ÿһ�β��Һ�����ѵͿ��
	system("cls");
	int flag = 0;
	cout << "���²�Ʒ���С�ڵ���10�뼰ʱ���䣡����" << endl;
	Goods* q = head->next;
	while (q != NULL) {
		if (q->num <= 10) {
			if (flag == 0) { q->HeadPrint(); }
			flag = 1;
			q->Goodprint();
		}
		q = q->next;
	}
	if (flag != 0) {
		cout << endl;
		cout << "�����Ϳ��������ϡ���" << endl;
		cout << "����������Զ��������˵�����" << endl;
		Sleep(3000);
	}
}
