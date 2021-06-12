#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;

enum GoodsType//��Ʒ���
{
	Food = 1,//ʳƷ
	Cosmetic,//��ױƷ
	Commodity,//����Ʒ
	Drink//����
};

struct Account//�˺�����
{
	string accountnum;//�˺�
	string password;//����
	int wrongtimes;
	Account* next;
	Account();//���캯��
	void Writein();//���˺�����д���ļ�
};

Account::Account() {
	wrongtimes = 0;
}//���캯������wrongtimes��ʼ��Ϊ0

void Account::Writein() {

}

struct Date//����
{
	int year;
	int month;
	int day;
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
	void Goodprint();//������������Ϣ
};

void Goods::Goodprint() {
	cout << setiosflags(ios::left) << setw(10) << "���" << setw(16) << "����" << setw(10) << "��������" << setw(10) << "�۸�" << setw(10) <<
		"��Ʒ���" << setw(10) << "����" << setw(10) << "���ʱ��" << endl;
	cout << setiosflags(ios::left) << setw(10) << code << setw(16) << name;
	cout << setw(10) << brand << setw(10) << price << setw(10) << type;
	cout << setw(16) << num << date.year << "/" << date.month << "/" << date.day;
	cout << setw(10) << expiradate;
}


class GoodsManage//��Ʒ����
{
public:
	GoodsManage();
	~GoodsManage() {}
	int Verification();//�˺���֤
	void Addaccount();//����˺�
	void Subaccount();//ɾ���˺�
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
	void Coutexpired();//�����Ʒ��������
private:
	int amount;//��Ʒ��
	int DeleteAmount;
	Goods* head;
	Goods* DeleteHead;
	Account* hd = new Account;
	Account* ed;
};

GoodsManage::GoodsManage()//���幹�캯��
{
	amount = 0;
	DeleteAmount = 0;
	head = new Goods;
	head->next = NULL;
	hd = new Account;
	hd->next = NULL;
	DeleteHead = new Goods;
	DeleteHead->next = NULL;
	ed = new Account;
	ed->next = NULL;
}

//GoodsManage::~GoodsManage()//������������
//{
//	// Account
//}

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
	cout << " ��                        ������˺š���(l)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��ɾ���˺š���(m)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���������롿��(n)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                          �˳�ϵͳ��(o)                         ��\n";
	cout << "\n                      ��������Ҫ���еĲ������:";
}

int GoodsManage::Verification()//�����˺���֤����
{
	string num;
	char password[30];
	Account* temp = hd;
	char ch;
	int i, wrot = 0;
	cout << "�������˺����루���30λ��" << endl;
	cout << "�������˺ţ�";
	cin >> num;
	cout << "���������룺";
	for (i = 0; i < 29; i++) {
		ch = _getch();//����vs2019��˵ǰ����Ҫ��һ��С�»��ߣ�����������IDE����ȥ��
		if (ch == 13) {
			break;
		}//��Ϊ�س������
		else if (ch == 8) {
			if (i > 0) {
				cout << ch;
				cout << ' ';
				cout << ch;
				i-=2;
			}
			else { i--; }
		}//��Ϊ�˸����δ���
		else {
			password[i] = ch;
			cout << '*';
		}//Ϊ�������ģ������'*'
	}
	password[i] = '\0';
	cout << endl;
	if (num != "root") {
		while (temp->next != NULL) {
			if (temp->accountnum == num) {
				if (password == temp->password) {
					cout << "��֤ͨ��" << endl;
					return 1;
				}
				else {
					if (temp->wrongtimes == 3) {
						cout << "����������Σ����˺��ѱ����٣�����ϵ����Ա����ע��" << endl;
						break;
					}
					temp->wrongtimes++;
					cout << "�������" << endl;
					return 0;
				}
			}
			temp = temp->next;
		}
		cout << "δ�ҵ����˺�" << endl;
		return 0;
	}//�������root�˺�
	else {
		string t = "password";
		if (password == t) {
			cout << "you are right" << endl;
			return 1;
		}
		else {
			if (wrot == 3) {
				cout << "����������Σ�����" << endl;
				exit(1);
			}
			wrot++;
		}
	}
	return 0;
}

void  GoodsManage::Addaccount()//��������˺ź���
{
	Account* temp = hd, * p;
	while (temp->next != NULL) {
		temp = temp->next;
	}//�ҵ���β��
	p = new Account;
	cout << "������Ҫ��ӵ��˺ţ�";
	cin >> p->accountnum;
	cout << "����������˺ŵ����룺";
	cin >> p->password;
	cout << "�ɹ���ӣ�����" << endl;
	Sleep(1000);
	system("cls");
}

void GoodsManage::Subaccount()//����ɾ���˺ź���
{

}

void GoodsManage::Changeaccount()
{

}

void GoodsManage::AddGoodsInfo()//���������Ʒ��Ϣ����
{
	char c, c1;
	Goods* tail = head, * p;
	bool flag;
	cout << "          ����������ڽ�����Ʒ��Ϣ����ӡ������          " << endl;
	while (tail->next != NULL)
		tail = tail->next;//��tailָ�����������һ���ڵ�
	do
	{
		flag = 0;
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
			if (q == NULL)//��pָ��NNULL�ұ�Ų��ظ�ʱ
				flag = 1;
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
	cout << setiosflags(ios::left) << setw(10) << "���" << setw(16) << "����" << setw(10) << "��������" << setw(10) << "�۸�" << setw(10) <<
		"��Ʒ���" << setw(10) << "����" << setw(10) << "���ʱ��" << setw(10) << "������" << endl;
	while (p->next != NULL)//ֱ��pָ�����������һ�����
	{
		p = p->next;
		cout << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;
		cout << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		cout << setw(10) << p->num << p->date.year << "/" << p->date.month << "/" << p->date.day << setw(10) << p->expiradate << endl;
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
			flag = 1;
			p->Goodprint();
		}

		else if (FoundType == 2 && p->type == Cosmetic)
		{
			flag = 1;
			p->Goodprint();
		}
		else if (FoundType == 3 && p->type == Commodity)
		{
			flag = 1;
			p->Goodprint();
		}
		else if (FoundType == 4 && p->type == Drink)
		{
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
	cout << setiosflags(ios::left) << setw(10) << "���" << setw(16) << "����" << setw(10) << "��������" << setw(10) << "�۸�" << setw(10) <<
		"��Ʒ���" << setw(10) << "����" << setw(10) << "���ʱ��" << endl;
	output << "��Ʒ����Ϊ: " << amount << "\n";
	output << setiosflags(ios::left) << setw(10) << "���" << setw(16) << "����" << setw(10) << "��������" << setw(10) << "�۸�" << setw(10) <<
		"��Ʒ���" << setw(10) << "����" << setw(10) << "���ʱ��" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		cout << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;
		cout << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		cout << setw(10) << p->num << p->date.year << "/" << p->date.month << "/" << p->date.day << endl;
		output << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;//���ļ�����ʾ��Ӧ��Ʒ��Ϣ
		output << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		output << setw(10) << p->num << p->date.year << "/" << p->date.month << "/" << p->date.day << endl;
	}
	cout << endl;
	cout << "�ɹ���������Ϣ���浽<������Ϣ.txt>" << endl;
	cout << "������Ϣ������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
	output.close();//�ر�����ļ�
}


void GoodsManage::Coutexpired()//�����Ʒ��������
{

}

int main()//������
{
	char c;
	int i = 0;
	bool flag = 0;
	GoodsManage bm;//����GoodsManage�����
	//���ƴ��ڴ�С��ɫ
	system("mode con cols=100 lines=34");
	system("color E0");//���Ƶ׺���
	while (bm.Verification() != 1) { Sleep(1000); system("cls"); }//��֤�˺�
//	cout << endl << endl << endl << endl << endl << endl << "                  ��ӭʹ�ÿ�����ϵͳ......ϵͳ���ڼ�����";
//	Sleep(2000);//��Ϊsleep
	system("cls");//����
	bm.DisplayMainMenu();
	for (;;)
	{
		do{
			cin >> c;
			if (c >= 'a' && c <= 'o')//�ж��û��������Ƿ����
				flag = 1;
			else
			{
				cout << "������ı�Ų����ڣ�" << endl;
				cout << "��ѡ����Ӧ�����ֽ��в���:" << endl;
			}
		} while (flag == 0);//�����Ŵ���ʱ����ѭ��������Ӧ����
		system("cls");//����
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
		case'k':bm.Coutexpired();
			break;
		case'l':bm.Addaccount();
			break;
		case'm':bm.Subaccount();
			break;
		case'n':bm.Changeaccount();
			break;
		case'o':exit(0);
			break;
		}
		system("cls");
		bm.DisplayMainMenu();
	}
	return 0;
}
