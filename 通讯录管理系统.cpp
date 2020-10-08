//封装函数显示通讯录管理系统界面
//封装函数显示该界面
//在main函数中调用封装好的函数

#include <iostream>
#include <string>
#include <ctime>



using namespace std;
//constexpr auto Maxperson = 1000;

#define Maxperson 1000




//显示菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.新建联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.提出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

//自定义联系人结构体

struct Person
{
	string m_Name;
	int m_Sex; //1 man, 2 women
	int m_Age;
	string m_Phone;
	string m_Addr;

};

//设计通讯录结构体，存放联系人，最多1000人，并显示目前已有多少个联系人

struct Addressbooks
{
	struct Person pArray[Maxperson];
	int m_Size;//通讯录中已存人员个数

};
//1.添加联系人
void addperson(Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size == Maxperson)
	{
		cout << "通讯录已满，无法继续添加。" << endl;
		return;
	}
	else
	{
		//添加具体联系人 姓名，性别， 年龄，电话，地址
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->pArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入";
			}
		}

		//输入年龄
		cout << "请输入年龄： " << endl;
		int age;
		cin >> age;
		abs->pArray[abs->m_Size].m_Age = age;

		//输入联系电弧
		cout << "请输入电话号码： " << endl;
		string phone;
		cin >> phone;
		abs->pArray[abs->m_Size].m_Phone = phone;

		//	输入家庭住址
		cout << "输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->pArray[abs->m_Size].m_Addr = address;


		abs->m_Size++;

		cout << "添加成功！" << endl;
		system("pause");
		system("cls");//清屏操作


	}
}

void showperson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;

	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->pArray[i].m_Name << "\t";
			cout << "性别： " << (abs->pArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->pArray[i].m_Age << "\t";
			cout << "电话： " << abs->pArray[i].m_Phone << "\t";
			cout << "家庭地址： " << abs->pArray[i].m_Addr << "\t" << endl;
		}
	}

	system("pause");
	system("cls");

}

int isexit(Addressbooks* abs, string name)
{
	//首先检测联系人是否存在
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->pArray[i].m_Name == name)
		{
			return i;
			break;
		}
	}

	return -1;
	
 }


//联系人删除函数
void deleteperson(Addressbooks * abs)
{
	cout << "输入你想删除的联系人： " << endl;
	string name;
	cin >> name;

	int ret = isexit(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->pArray[i] = abs->pArray[i + 1];//重点
		}

		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人函数
void findperson(Addressbooks* abs)
{
	cout << "输入你想查找的联系人： " << endl;
	string name;
	cin >> name;

	int ret = isexit(abs, name);

	if (ret != -1)
	{
		cout << "姓名：" << abs->pArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->pArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->pArray[ret].m_Age << "\t";
		cout << "电话：" << abs->pArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->pArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人函数

void modifyperson(Addressbooks * abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->pArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->pArray[ret].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->pArray[ret].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->pArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


void clearperson(Addressbooks* abs)
{
	cout << "是否确定清空联系人？1:是 0：否" << endl;
	int yon;
	cin >> yon;
	switch (yon)
	{
	case 1:
		abs->m_Size = 0;
		cout << "清除完毕" << endl;
		
	case 0:
		cout << "未清除通讯录！" << endl;
		break;

	default:
		cout << "未清除通讯录！" << endl;
		break;
	}
}

int main()
{

	//创建真实通讯录
	Addressbooks abs;
	//初始化当前人员个数
	abs.m_Size = 0;

	
	//根据不同选择进入不同功能
	int select = 0;

	while (true)
	{
		showMenu();//显示菜单
		cout << "选择你想实现的功能： ";
		cin >> select;

		switch (select)
		{
		case 1: //添加联系人
			addperson(&abs);//利用地址传递可以修饰实参
			break;
		case 2: //显示联系人
			showperson(&abs);
			break;
		case 3: //删除联系人
			deleteperson(&abs);
			break;
		case 4: //查找联系人
			findperson(&abs);
			break;
		case 5: //修改联系人
			modifyperson(&abs);
			break;
		case 6: //清空联系人
			clearperson(&abs);
			break;
		case 0: //退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
		
	}

	system("pause");
	return 0;
}