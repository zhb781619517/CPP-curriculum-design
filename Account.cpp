#include "Account.h"

Account::Account() {
	next = NULL;
	wrong = 0;
}//���캯������wrongtimes��ʼ��Ϊ0

int Account::Verification()//�����˺���֤����
{
	int flag = 0;
	string num;
	char pswd[30];
	memset(pswd, '\0', sizeof(pswd));
	Account* temp = next;
	char ch;//��ת
	int i;
	cout << "�������˺����루���30λ��" << endl;
	cout << "�������˺ţ�";
	cin >> num;
	cout << "���������룺";
	for (i = 0; i < 29; i++) {
		ch = _getch();//����vs2019��˵ǰ����Ҫ��һ��С�»��ߣ�����������IDE����ȥ��
		if (ch == 13) {
			cout << endl;
			break;
		}//��Ϊ�س������
		else if (ch == 8) {
			if (i > 0) {
				cout << ch;
				cout << ' ';
				cout << ch;
				i -= 2;
			}
			else { i--; }
		}//��Ϊ�˸����δ���
		else {
			pswd[i] = ch;
			cout << '*';
		}//Ϊ�������ģ������'*'
	}
	pswd[i] = '\0';//�ַ���β����ֹ��
	//���벿�ֽ���
	string t1 = "admin";
	string t2 = "password";
	if (num == t1) {
		if (pswd == t2) {
			return 2;
		}
	}
	while (temp != NULL) {
		if (temp->accountnum == num) {
			if (temp->password == pswd) {
				return 1;
			}
		}
		temp = temp->next;
	}
	return 0;
}

void  Account::Addaccount()//��������˺ź���
{
	//�ж��˺��Ƿ��ظ�
	Account* temp = this, * p;
	char c;
	do
	{
		int flag = 0;
		p = new Account;
		temp = this;
		cout << "������Ҫ��ӵ��˺ţ�";
		cin >> p->accountnum;
		//����
		do
		{
			while (temp != NULL) {
				if (temp->accountnum == p->accountnum) {
					//TODO
					cout << "���˺��Ѵ��ڣ����������룡" << endl;
					break;
				}
				temp = temp->next;
			}
			if (temp == NULL) { flag = 1; }
			else {
				cout << "������Ҫ��ӵ��˺ţ�";
				cin >> p->accountnum;
				temp = this;//��ʼ��ָ��
			}
		} while (flag == 0);
		temp = this;
		while (temp->next != NULL) {
			temp = temp->next;
		}//�ҵ���β��
		cout << "����������˺ŵ����룺";
		cin >> p->password;
		temp->next = p;
		p->next = NULL;
		cout << "�˺���ӳɹ�����������������(y/n):" << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣�������<������y/n>" << endl;
			cout << "�˺���ӳɹ������������������(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "�����˺������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void Account::Subaccount()//����ɾ���˺ź���
{
	string acot;//ɾ�����˺�
	Account* p = this;//��ѰҪɾ�����˺�
	Account* temp;
	char c;
	//��ȱ��
	do
	{
		cout << "������Ҫɾ�����˺ţ�" << endl;
		cin >> acot;
		while (p->next != NULL) {
			if (p->next->accountnum == acot) {
				temp = p->next;
				p->next = temp->next;
				//delete temp;//ɾ���ڵ�
				cout << "�����˺�ɾ���ɹ�����" << endl;
				cout << "������Ϣ������ϡ���" << endl;
				break;
			}
			p = p->next;
		}
		if (p->next == NULL) {
			cout << "�˺Ų����ڣ����������룡����" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		cout << "�˺�ɾ���ɹ������������ɾ����(y/n):" << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣�������<������y/n>" << endl;
			cout << "�˺�ɾ���ɹ������������ɾ����(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "�����˺�ɾ����ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void Account::Changeaccount()//����ı��������
{
	string acot;//Ҫ���ĵ��˺�
	Account* p = next;//��ѰҪ���ĵ��˺�
	char c;
	do
	{
		cout << "������Ҫ���ĵ��˺ţ�" << endl;
		cin >> acot;
		while (p != NULL) {
			if (p->accountnum == acot) {
				string temp;
				cout << "�������µ����룺" << endl;
				cin >> temp;
				p->password = temp;//��������
				break;
			}
			p = p->next;
		}
		if (p == NULL) { 
			cout << "�˺Ų����ڣ����������룡" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		cout << "���ĳɹ������������������(y/n):" << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "ָ����󣡣�������<������y/n>" << endl;
			cout << "������ĳɹ������������������(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "��������������ϡ���" << endl;
	cout << "������������������˵�����" << endl;
	getchar();
	getchar();
}

void Account::Writein() {
	ofstream out("Account.dat", ios::out | ios::binary);
	Account* a = next;
	while (a != NULL) {
		out.write((char*)a, sizeof(Account));
		a = a->next;
	}
}//���˺�����д��dat

void Account::Readout() {
	ifstream in("Account.dat", ios::in | ios::binary);
	if (!in) { return; }
	Account* a = this;
	in.seekg(0, ios::beg);
	while (in.peek() != EOF) {
		Account* temp = new Account;
		in.read((char*)temp, sizeof(Account));
		a->next = temp;
		a = a->next;
	}
	a->next = NULL;//βָ��ָ���
	cout << "�����������ݳɹ�����" << endl;
	Sleep(1000);
	system("cls");
}//���˺��������ϵͳ
