#include "Account.h"

using namespace std;

Account::Account() {
	next = NULL;
	wrongtimes = 0;
}//构造函数，将wrongtimes初始化为0

int Account::Verification()//定义账号验证函数
{
	string num;
	char password[30];
	memset(password, '\0', sizeof(password));
	Account* temp = this->next;
	char ch;//中转
	int i;
	cout << "请输入账号密码（最多30位）" << endl;
	cout << "请输入账号：";
	cin >> num;
	cout << "请输入密码：";
	for (i = 0; i < 29; i++) {
		ch = _getch();//对于vs2019来说前面需要加一个小下划线，对于其他的IDE可以去掉
		if (ch == 13) {
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
			password[i] = ch;
			cout << '*';
		}//为密码正文，则输出'*'
	}
	password[i] = '\0';//字符串尾部终止符
	cout << endl;
	if (num != "admin") {
		while (temp->next != NULL) {
			if (temp->accountnum == num) {
				if (password == temp->password) {
					cout << "验证通过" << endl;
					return 1;
				}
				else {
					if (temp->wrongtimes == 3) {
						cout << "输入错误三次，该账号已被销毁，请联系管理员重新注册" << endl;
						Account* tp = this->next;
						while (tp->next != temp) {
							tp = tp->next;
						}
						tp->next = temp->next;
						delete temp;
						break;
					}
					temp->wrongtimes++;
					cout << "密码错误" << endl;
					return 0;
				}
			}
			temp = temp->next;
		}
		if (temp->next == NULL) {
			cout << "未找到该账号" << endl;
		}
		return 0;
	}//如果不是root账号
	else {
		string t;
		int wrot = 0;//记录错误次数
		cout << "1111111111:";
		cin >> t;
		if (password == t) {
			cout << "you are right" << endl;

			return 1;
		}
		else {
			if (wrot == 3) {
				cout << "输入错误三次！！！" << endl;
				exit(1);
			}
			wrot++;
		}
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
	cout << "……信息处理完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void Account::Subaccount()//定义删除账号函数
{
	string acot;//删除的账号
	cout << "请输入要删除的账号：" << endl;
	cin >> acot;
	Account* p = this->next;//找寻要删除的账号
	Account* temp;
	//有缺陷
	while (p->next != NULL) {
		if (p->next->accountnum == acot) {
			temp = p->next;
			p->next = temp->next;
			delete temp;//删除节点
		}
	}
}

void Account::Changeaccount()//定义改变密码操作
{
	string acot;//要更改的账号
	cout << "请输入要更改的账号：" << endl;
	cin >> acot;
	Account* p = this->next;//找寻要更改的账号
	while (p->next != NULL) {
		if (p->accountnum == acot) {
			string temp;
			cout << "请输入新的密码：" << endl;
			cin >> temp;
			p->password = temp;//更改密码
		}
	}
}

void Account::Writein() {
	//TODO
}//将账号密码写入文件

void Account::Readin() {
	//TODO
}//将账号密码从文件中写入
