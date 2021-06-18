#include "Account.h"

Account::Account() {
	next = NULL;
	wrong = 0;
}//构造函数，将wrongtimes初始化为0

int Account::Verification()//定义账号验证函数
{
	int flag = 0;
	string num;
	char pswd[30];
	memset(pswd, '\0', sizeof(pswd));
	Account* temp = next;
	char ch;//中转
	int i;
	cout << "请输入账号密码（最多30位）" << endl;
	cout << "请输入账号：";
	cin >> num;
	cout << "请输入密码：";
	for (i = 0; i < 29; i++) {
		ch = _getch();//对于vs2019来说前面需要加一个小下划线，对于其他的IDE可以去掉
		if (ch == 13) {
			cout << endl;
			break;
		}//若为回车则结束
		else if (ch == 8) {
			if (i > 0) {
				cout << ch;
				cout << ' ';
				cout << ch;
				i -= 2;
			}
			else { i--; }
		}//若为退格符如何处理
		else {
			pswd[i] = ch;
			cout << '*';
		}//为密码正文，则输出'*'
	}
	pswd[i] = '\0';//字符串尾部终止符
	//输入部分结束
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

void  Account::Addaccount()//定义添加账号函数
{
	//判断账号是否重复
	Account* temp = this, * p;
	char c;
	do
	{
		int flag = 0;
		p = new Account;
		temp = this;
		cout << "请输入要添加的账号：";
		cin >> p->accountnum;
		//判重
		do
		{
			while (temp != NULL) {
				if (temp->accountnum == p->accountnum) {
					//TODO
					cout << "该账号已存在，请重新输入！" << endl;
					break;
				}
				temp = temp->next;
			}
			if (temp == NULL) { flag = 1; }
			else {
				cout << "请输入要添加的账号：";
				cin >> p->accountnum;
				temp = this;//初始化指针
			}
		} while (flag == 0);
		temp = this;
		while (temp->next != NULL) {
			temp = temp->next;
		}//找到最尾部
		cout << "请输入添加账号的密码：";
		cin >> p->password;
		temp->next = p;
		p->next = NULL;
		cout << "账号添加成功！！！想继续添加吗(y/n):" << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！！！<请输入y/n>" << endl;
			cout << "账号添加成功！！！想继续输入吗(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "……账号添加完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void Account::Subaccount()//定义删除账号函数
{
	string acot;//删除的账号
	Account* p = this;//找寻要删除的账号
	Account* temp;
	char c;
	//有缺陷
	do
	{
		cout << "请输入要删除的账号：" << endl;
		cin >> acot;
		while (p->next != NULL) {
			if (p->next->accountnum == acot) {
				temp = p->next;
				p->next = temp->next;
				//delete temp;//删除节点
				cout << "……账号删除成功……" << endl;
				cout << "……信息处理完毕……" << endl;
				break;
			}
			p = p->next;
		}
		if (p->next == NULL) {
			cout << "账号不存在，请重新输入！！！" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		cout << "账号删除成功！！！想继续删除吗(y/n):" << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！！！<请输入y/n>" << endl;
			cout << "账号删除成功！！！想继续删除吗(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "……账号删除完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void Account::Changeaccount()//定义改变密码操作
{
	string acot;//要更改的账号
	Account* p = next;//找寻要更改的账号
	char c;
	do
	{
		cout << "请输入要更改的账号：" << endl;
		cin >> acot;
		while (p != NULL) {
			if (p->accountnum == acot) {
				string temp;
				cout << "请输入新的密码：" << endl;
				cin >> temp;
				p->password = temp;//更改密码
				break;
			}
			p = p->next;
		}
		if (p == NULL) { 
			cout << "账号不存在，请重新输入！" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		cout << "更改成功！！！想继续更改吗(y/n):" << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！！！<请输入y/n>" << endl;
			cout << "密码更改成功！！！想继续更改吗(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "……更改密码完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
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
}//将账号密码写入dat

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
	a->next = NULL;//尾指针指向空
	cout << "……读入数据成功……" << endl;
	Sleep(1000);
	system("cls");
}//将账号密码读入系统
