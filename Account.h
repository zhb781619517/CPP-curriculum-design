#pragma once

struct Account//�˺�����
{
	string accountnum;//�˺�
	string password;//����
	int wrongtimes;
	Account* next;
	Account();//���캯��
	int Verification();//�˺���֤
	void Addaccount();//����˺�
	void Subaccount();//ɾ���˺�
	void Changeaccount();//��������
	void Writein();//���˺�����д���ļ�
	void Readin();//���˺�������ļ���д��
};

Account::Account() {
	next = new Account;
	wrongtimes = 0;
}//���캯������wrongtimes��ʼ��Ϊ0

int Account::Verification()//�����˺���֤����
{
	string num;
	char password[30];
	Account* temp = this->next;
	char ch;
	int i;
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
				i -= 2;
			}
			else { i--; }
		}//��Ϊ�˸����δ���
		else {
			password[i] = ch;
			cout << '*';
		}//Ϊ�������ģ������'*'
	}
	password[i] = '\0';//�ַ���β����ֹ��
	cout << endl;
	if (num != "admin") {
		while (temp->next != NULL) {
			if (temp->accountnum == num) {
				if (password == temp->password) {
					cout << "��֤ͨ��" << endl;
					return 1;
				}
				else {
					if (temp->wrongtimes == 3) {
						cout << "����������Σ����˺��ѱ����٣�����ϵ����Ա����ע��" << endl;
						Account* tp = this->next;
						while (tp->next != temp) {
							tp = tp->next;
						}
						tp->next = temp->next;
						delete temp;
						break;
					}
					temp->wrongtimes++;
					cout << "�������" << endl;
					return 0;
				}
			}
			temp = temp->next;
		}
		if (temp->next == NULL) {
			cout << "δ�ҵ����˺�" << endl;
		}
		return 0;
	}//�������root�˺�
	else {
		string t;
		int wrot = 0;//��¼�������
		cout << "1111111111:";
		cin >> t;
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

void  Account::Addaccount()//��������˺ź���
{
	Account* temp = this->next, * p;
	while (temp->next != NULL) {
		temp = temp->next;
	}//�ҵ���β��
	p = new Account;
	cout << "������Ҫ��ӵ��˺ţ�";
	cin >> p->accountnum;
	cout << "����������˺ŵ����룺";
	cin >> p->password;
	temp->next = p;
	p->next = NULL;
	cout << "�ɹ���ӣ�����" << endl;
	Sleep(1000);
	system("cls");
}

void Account::Subaccount()//����ɾ���˺ź���
{
	string acot;//ɾ�����˺�
	cout << "������Ҫɾ�����˺ţ�" << endl;
	cin >> acot;
	Account* p = this->next;//��ѰҪɾ�����˺�
	Account* temp;
	//��ȱ��
	while (p->next != NULL) {
		if (p->next->accountnum == acot) {
			temp = p->next;
			p->next = temp->next;
			delete temp;//ɾ���ڵ�
		}
	}
}

void Account::Changeaccount()//����ı��������
{
	string acot;//Ҫ���ĵ��˺�
	cout << "������Ҫ���ĵ��˺ţ�" << endl;
	cin >> acot;
	Account* p = this->next;//��ѰҪ���ĵ��˺�
	while (p->next != NULL) {
		if (p->accountnum == acot) {
			string temp;
			cout << "�������µ����룺" << endl;
			cin >> temp;
			p->password = temp;//��������
		}
	}
}

void Account::Writein() {
	//TODO
}//���˺�����д���ļ�

void Account::Readin() {
	//TODO
}//���˺�������ļ���д��
