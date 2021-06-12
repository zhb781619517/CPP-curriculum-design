#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;

enum GoodsType//商品类别
{
	Food = 1,//食品
	Cosmetic,//化妆品
	Commodity,//日用品
	Drink//饮料
};

struct Account//账号密码
{
	string accountnum;//账号
	string password;//密码
	int wrongtimes;
	Account* next;
	Account();//构造函数
	void Writein();//将账号密码写入文件
};

Account::Account() {
	wrongtimes = 0;
}//构造函数，将wrongtimes初始化为0

void Account::Writein() {

}

struct Date//日期
{
	int year;
	int month;
	int day;
};

struct Goods//商品基本信息
{
	string code;//商品编号
	string name;//商品名称
	string brand;//生产厂家
	double price;//商品价格
	int num;//商品数量
	GoodsType type;//商品类别
	Date date;//入库时间
	int expiradate;//保质期
	Goods* next;
	void Goodprint();//输出货物相关信息
};

void Goods::Goodprint() {
	cout << setiosflags(ios::left) << setw(10) << "编号" << setw(16) << "名称" << setw(10) << "生产厂家" << setw(10) << "价格" << setw(10) <<
		"商品类别" << setw(10) << "数量" << setw(10) << "入库时间" << endl;
	cout << setiosflags(ios::left) << setw(10) << code << setw(16) << name;
	cout << setw(10) << brand << setw(10) << price << setw(10) << type;
	cout << setw(16) << num << date.year << "/" << date.month << "/" << date.day;
	cout << setw(10) << expiradate;
}


class GoodsManage//商品管理
{
public:
	GoodsManage();
	~GoodsManage() {}
	int Verification();//账号验证
	void Addaccount();//添加账号
	void Subaccount();//删除账号
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
	void Coutexpired();//输出商品过期日期
private:
	int amount;//商品量
	int DeleteAmount;
	Goods* head;
	Goods* DeleteHead;
	Account* hd = new Account;
	Account* ed;
};

GoodsManage::GoodsManage()//定义构造函数
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

//GoodsManage::~GoodsManage()//定义析构函数
//{
//	// Account
//}

void GoodsManage::DisplayMainMenu()//定义主菜单函数
{
	cout << " ┋                                                                ┋\n";
	cout << " ┋                   欢迎使用商品库存管理系统                     ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【商品进货】…(a)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【商品编辑】…(b)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【商品删除】…(c)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                     ┋ 【按照编号查询】…(d)                    ┋\n";
	cout << " ┋                     ┋                                          ┋\n";
	cout << " ┋                     ┋ 【按照名称查询】…(e)                    ┋\n";
	cout << " ┋         【商品查询】┋                                          ┋\n";
	cout << " ┋                     ┋ 【按照类别查询】…(f)                    ┋\n";
	cout << " ┋                     ┋                                          ┋\n";
	cout << " ┋                     ┋ 【按照品牌查询】…(g)                    ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【商品出货】…(h)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【商品统计】…(i)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【信息保存】…(j)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【保质期查询】…(k)                     ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【添加账号】…(l)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【删除账号】…(m)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【更改密码】…(n)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                          退出系统…(o)                         ┋\n";
	cout << "\n                      请输入你要进行的操作编号:";
}

int GoodsManage::Verification()//定义账号验证函数
{
	string num;
	char password[30];
	Account* temp = hd;
	char ch;
	int i, wrot = 0;
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
				i-=2;
			}
			else { i--; }
		}//若为退格符如何处理
		else {
			password[i] = ch;
			cout << '*';
		}//为密码正文，则输出'*'
	}
	password[i] = '\0';
	cout << endl;
	if (num != "root") {
		while (temp->next != NULL) {
			if (temp->accountnum == num) {
				if (password == temp->password) {
					cout << "验证通过" << endl;
					return 1;
				}
				else {
					if (temp->wrongtimes == 3) {
						cout << "输入错误三次，该账号已被销毁，请联系管理员重新注册" << endl;
						break;
					}
					temp->wrongtimes++;
					cout << "密码错误" << endl;
					return 0;
				}
			}
			temp = temp->next;
		}
		cout << "未找到该账号" << endl;
		return 0;
	}//如果不是root账号
	else {
		string t = "password";
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

void  GoodsManage::Addaccount()//定义添加账号函数
{
	Account* temp = hd, * p;
	while (temp->next != NULL) {
		temp = temp->next;
	}//找到最尾部
	p = new Account;
	cout << "请输入要添加的账号：";
	cin >> p->accountnum;
	cout << "请输入添加账号的密码：";
	cin >> p->password;
	cout << "成功添加！！！" << endl;
	Sleep(1000);
	system("cls");
}

void GoodsManage::Subaccount()//定义删除账号函数
{

}

void GoodsManage::Changeaccount()
{

}

void GoodsManage::AddGoodsInfo()//定义添加商品信息函数
{
	char c, c1;
	Goods* tail = head, * p;
	bool flag;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的添加☆☆☆☆☆☆          " << endl;
	while (tail->next != NULL)
		tail = tail->next;//令tail指向链表中最后一个节点
	do
	{
		flag = 0;
		p = new Goods;
		cout << "请选择商品类别:" << endl;
		cout << "1.食品 2.化妆品 3.日用品 4.饮料" << endl;
		cout << "请输入相应编号:";
		do
		{
			cin >> c1;
			if (c1 >= '1' && c1 <= '4')//判断用户输入编号是否存在
				flag = 1;
			else
			{
				cout << "您输入的编号不存在！" << endl;
				cout << "请选择正确的商品类别:" << endl;
			}
		} while (flag == 0);//输入编号存在时跳出循环
		if (c1 == '1')p->type = Food;
		if (c1 == '2')p->type = Cosmetic;
		if (c1 == '3')p->type = Commodity;
		if (c1 == '4')p->type = Drink;
		cout << "商品类别(" << p->type << ")" << endl;//表示商品类别
		cout << "请输入商品编号: ";
		cin >> p->code;
		do
		{
			Goods* q = head->next;
			while (q != NULL && q->code != p->code)//当q指向NULL或输入的编号与之前编号重复时跳出循环
				q = q->next;
			if (q == NULL)//当p指向NNULL且编号不重复时
				flag = 1;
			else//编号重复时
			{
				cout << "存在该编号的货物!!!请重新输入编号:";
				cin >> p->code;
			}
		} while (flag == 0);
		cout << "请输入商品名称：";
		cin >> p->name;
		cout << "请输入生产厂家：";
		cin >> p->brand;
		cout << "请输入商品价格：";
		cin >> p->price;
		cout << "请输入商品数量：";
		cin >> p->num;
		cout << "请输入入库时间（年/月/日）：";
		cin >> p->date.year >> p->date.month >> p->date.day;
		cout << "请输入保质期：";
		cin >> p->expiradate;
		tail->next = p;//将p插入链表
		p->next = NULL;
		tail = p;
		amount++;//商品量加一
		cout << "数据输入成功！！！想继续添加吗(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！！！<请输入y/n>" << endl;
			cout << "数据添加成功！！！想继续输入吗(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "……信息处理完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void GoodsManage::DisplayGoodsInfo()//定义商品信息浏览函数
{
	Goods* p = head;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的浏览☆☆☆☆☆☆          " << endl;
	cout << setiosflags(ios::left) << setw(10) << "编号" << setw(16) << "名称" << setw(10) << "生产厂家" << setw(10) << "价格" << setw(10) <<
		"商品类别" << setw(10) << "数量" << setw(10) << "入库时间" << setw(10) << "保质期" << endl;
	while (p->next != NULL)//直到p指向链表中最后一个结点
	{
		p = p->next;
		cout << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;
		cout << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		cout << setw(10) << p->num << p->date.year << "/" << p->date.month << "/" << p->date.day << setw(10) << p->expiradate << endl;
	}
	cout << endl;
	cout << "……信息统计完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}



void GoodsManage::SearchByCode()//按照商品编号查找商品信息
{
	Goods* p;
	bool flag;
	string FoundCode;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          " << endl;
	p = head;
	flag = 0;
	cout << "请输入您要查找的商品编号：";
	cin >> FoundCode;
	while (p->next != NULL)
	{

		p = p->next;
		if (p->code == FoundCode)//找到相应编号的商品
		{
			flag = 1;
			p->Goodprint();
			break;
		}
	}
	if (flag == 0)
	{
		cout << "对不起，您查询的商品不存在！！！" << endl;
	}
	cout << endl;
	cout << "……信息查找完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByName()//按照商品名称查找商品信息
{
	Goods* p;
	bool flag;
	string FoundName;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          " << endl;
	p = head;
	flag = 0;
	cout << "请输入您要查找的商品名称：";
	cin >> FoundName;
	while (p->next != NULL)
	{

		p = p->next;
		if (p->name == FoundName)//找到相应名称的商品
		{
			flag = 1;
			p->Goodprint();
			break;
		}
	}
	if (flag == 0)
	{
		cout << "对不起，您查询的商品不存在！！！" << endl;
	}
	cout << endl;
	cout << "……信息查找完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByType()//按照商品类别查找商品信息
{

	Goods* p;
	bool flag;
	int FoundType;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          " << endl;

	p = head;
	flag = 0;
	cout << "请输入您要查找的商品类别：";
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
		cout << "对不起，您查询的商品不存在！！！" << endl;
	}
	cout << endl;
	cout << "……信息查找完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void GoodsManage::SearchByBrand()//按照生产厂家查找商品信息
{

	Goods* p;
	bool flag;
	string FoundBrand;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          " << endl;
	p = head;
	flag = 0;
	cout << "请输入您要查找的商品品牌：";
	cin >> FoundBrand;
	while (p->next != NULL)
	{

		p = p->next;
		if (p->brand == FoundBrand)//找到相应生产厂家所对应的商品
		{
			flag = 1;
			p->Goodprint();
		}
	}
	if (flag == 0)
	{
		cout << "对不起，您查询的商品不存在！！！" << endl;
	}
	cout << endl;
	cout << "……信息查找完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}

void GoodsManage::EditGoodsInfo()//定义编辑商品信息函数
{
	char c;
	Goods* p;
	bool flag = 0;
	string EditCode;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的编辑☆☆☆☆☆☆          " << endl;
	do
	{
		p = head->next;//令p指向head下一个节点
		flag = 0;
		cout << "请输入您要修改的货物编号：";
		cin >> EditCode;
		while (p->next != NULL && p->code != EditCode)//直到p指向链表中最后一个节点找到相应编号的商品时跳出循环
			p = p->next;
		if (p->code == EditCode)
		{
			flag = 1;
			p->Goodprint();
			cout << "确认修改吗？<y/n>";
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "指令错误！！！！<请输入y/n>:";
				cin >> c;
			}
			if (c == 'y')
			{
				cout << "请输入商品名称：";
				cin >> p->name;
				cout << "请输入生产厂家：";
				cin >> p->brand;
				cout << "请输入商品价格：";
				cin >> p->price;
				cout << "请输入商品数量：";
				cin >> p->num;
				cout << "请输入入库时间（年/月/日）：";
				cin >> p->date.year >> p->date.month >> p->date.day;
				cout << "修改成功！" << endl;
			}
			else cout << "取消成功！" << endl;
		}
		if (flag == 0)
		{
			cout << "对不起，您修改的货物不存在！！" << endl;

		}
		cout << "您想要继续修改吗？(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！<请输入y/n>:" << endl;
			cout << "您想要继续修改吗？(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "……信息编辑完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}


void GoodsManage::DeleteGoodsInfo()//定义商品信息删除函数
{
	Goods* q = head, * p, * tail = DeleteHead;
	p = new Goods;
	char c;
	string Dename;
//	bool flag = 0;
	while (tail->next != NULL)//令tail指向链表中最后一个节点
		tail = tail->next;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的删除☆☆☆☆☆☆          " << endl;
	do
	{

		cout << "请输入您要删除的商品名称：";
		cin >> Dename;
		while (q->next != NULL && q->next->name != Dename)//直到q指向链表中最后一个节点或者找到相应名称的商品时跳出循环
			q = q->next;
		if (q->next != NULL)//找到相应名称的商品
		{
//			flag = 1;
			cout << "确认删除吗？<y/n>";
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "指令错误！！！！<请输入y/n>:";
				cin >> c;
			}
			if (c == 'y')
			{
				p = q->next;
				q->next = q->next->next;//q的下一个节点指向其后的节点
				tail->next = p;
				tail = p;
				tail->next = NULL;//在链表中删除指定节点
				DeleteAmount++;
				amount--;//商品量减一
				cout << "删除成功！！" << endl;
			}
			else cout << "取消成功！！！" << endl;

		}
		else
		{
			cout << "对不起，您删除的商品不存在！！！" << endl;

		}
		cout << "您想要继续删除吗？(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！<请输入y/n>:" << endl;
			cout << "您想要继续删除吗？(y/n):";
			cin >> c;
		}
		q = head;//令q指向链表中第一个结点再次搜索相应名称的商品

	} while (c == 'y');
	cout << endl;
	cout << "……信息删除完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
}


void GoodsManage::SellGoodsInfo()//定义商品出库函数
{
	int sellNum, year, month, day;
	double sellPrice, sum = 0.0, profit = 0.0;
	char c;
	Goods* p;
	bool flag = 0;
	string SellName;
	cout << "          ☆☆☆☆☆☆现在进行商品的出售☆☆☆☆☆☆          " << endl;
	do
	{
		p = head->next;
		flag = 0;
		cout << "请输入您要出售的商品名称：";
		cin >> SellName;
		while (p->next != NULL && p->name != SellName)
			p = p->next;
		if (p->name == SellName)
		{
			flag = 1;
			p->Goodprint();
			cout << "\n确认出售吗？<y/n>";
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "指令错误！！！！<请输入y/n>:";
				cin >> c;
			}
			if (c == 'y')
			{

				cout << "请输入出售的商品数量：";
				cin >> sellNum;
				if (sellNum <= p->num)//库存量充足
				{
					p->num = p->num - sellNum;//计算商品出库后商品的库存量
					cout << "请输入出售的商品价格：";
					cin >> sellPrice;
					cout << "请输入出货日期：";
					cin >> year >> month >> day;
					sum = sellNum * sellPrice;//计算销售金额
					profit = sellNum * (sellPrice - p->price);//计算利润
					cout << "此次销售额为： " << sum << endl;
					cout << "此次利润为： " << profit << endl;
					cout << "出货日期为：" << year << "/" << month << "/" << day << endl;
				}
				else
				{
					cout << "库存不足！出库失败！" << endl;
				}
			}
			else cout << "取消成功！" << endl;
		}
		if (flag == 0)
		{
			cout << "对不起，您出售的货物不存在！！" << endl;

		}
		cout << "您想要继续出售吗？(y/n):";
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "指令错误！！！<请输入y/n>:" << endl;
			cout << "您想要继续出售吗？(y/n):";
			cin >> c;
		}
	} while (c == 'y');
	cout << endl;
	cout << "……出库完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();

}


void GoodsManage::SaveGoodsInfo()//定义商品信息保存函数
{
	Goods* p = head;
	cout << "          ☆☆☆☆☆☆现在进行商品信息的保存☆☆☆☆☆☆          " << endl;
	ofstream output("货物信息.txt", ios::out);//定义输出文件"货物信息.txt"
	if (!output)
	{
		cerr << "打开文件<货物信息.txt>失败！！！" << endl;
	}
	cout << setiosflags(ios::left) << setw(10) << "编号" << setw(16) << "名称" << setw(10) << "生产厂家" << setw(10) << "价格" << setw(10) <<
		"商品类别" << setw(10) << "数量" << setw(10) << "入库时间" << endl;
	output << "商品总量为: " << amount << "\n";
	output << setiosflags(ios::left) << setw(10) << "编号" << setw(16) << "名称" << setw(10) << "生产厂家" << setw(10) << "价格" << setw(10) <<
		"商品类别" << setw(10) << "数量" << setw(10) << "入库时间" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		cout << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;
		cout << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		cout << setw(10) << p->num << p->date.year << "/" << p->date.month << "/" << p->date.day << endl;
		output << setiosflags(ios::left) << setw(10) << p->code << setw(16) << p->name;//在文件中显示相应商品信息
		output << setw(10) << p->brand << setw(10) << p->price << setw(10) << p->type;
		output << setw(10) << p->num << p->date.year << "/" << p->date.month << "/" << p->date.day << endl;
	}
	cout << endl;
	cout << "成功将货物信息保存到<货物信息.txt>" << endl;
	cout << "……信息保存完毕……" << endl;
	cout << "……按任意键返回主菜单……" << endl;
	getchar();
	getchar();
	output.close();//关闭输出文件
}


void GoodsManage::Coutexpired()//输出商品过期日期
{

}

int main()//主函数
{
	char c;
	int i = 0;
	bool flag = 0;
	GoodsManage bm;//定义GoodsManage类对象
	//控制窗口大小颜色
	system("mode con cols=100 lines=34");
	system("color E0");//淡黄底黑字
	while (bm.Verification() != 1) { Sleep(1000); system("cls"); }//验证账号
//	cout << endl << endl << endl << endl << endl << endl << "                  欢迎使用库存管理系统......系统正在加载中";
//	Sleep(2000);//人为sleep
	system("cls");//清屏
	bm.DisplayMainMenu();
	for (;;)
	{
		do{
			cin >> c;
			if (c >= 'a' && c <= 'o')//判断用户输入编号是否存在
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
