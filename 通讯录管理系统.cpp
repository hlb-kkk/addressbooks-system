//��װ������ʾͨѶ¼����ϵͳ����
//��װ������ʾ�ý���
//��main�����е��÷�װ�õĺ���

#include <iostream>
#include <string>
#include <ctime>



using namespace std;
//constexpr auto Maxperson = 1000;

#define Maxperson 1000




//��ʾ�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�½���ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.���ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

//�Զ�����ϵ�˽ṹ��

struct Person
{
	string m_Name;
	int m_Sex; //1 man, 2 women
	int m_Age;
	string m_Phone;
	string m_Addr;

};

//���ͨѶ¼�ṹ�壬�����ϵ�ˣ����1000�ˣ�����ʾĿǰ���ж��ٸ���ϵ��

struct Addressbooks
{
	struct Person pArray[Maxperson];
	int m_Size;//ͨѶ¼���Ѵ���Ա����

};
//1.�����ϵ��
void addperson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == Maxperson)
	{
		cout << "ͨѶ¼�������޷�������ӡ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ�� �������Ա� ���䣬�绰����ַ
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->pArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
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
				cout << "������������������";
			}
		}

		//��������
		cout << "���������䣺 " << endl;
		int age;
		cin >> age;
		abs->pArray[abs->m_Size].m_Age = age;

		//������ϵ�绡
		cout << "������绰���룺 " << endl;
		string phone;
		cin >> phone;
		abs->pArray[abs->m_Size].m_Phone = phone;

		//	�����ͥסַ
		cout << "�����ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->pArray[abs->m_Size].m_Addr = address;


		abs->m_Size++;

		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");//��������


	}
}

void showperson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;

	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->pArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->pArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->pArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->pArray[i].m_Phone << "\t";
			cout << "��ͥ��ַ�� " << abs->pArray[i].m_Addr << "\t" << endl;
		}
	}

	system("pause");
	system("cls");

}

int isexit(Addressbooks* abs, string name)
{
	//���ȼ����ϵ���Ƿ����
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


//��ϵ��ɾ������
void deleteperson(Addressbooks * abs)
{
	cout << "��������ɾ������ϵ�ˣ� " << endl;
	string name;
	cin >> name;

	int ret = isexit(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->pArray[i] = abs->pArray[i + 1];//�ص�
		}

		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ����������룡" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ�˺���
void findperson(Addressbooks* abs)
{
	cout << "����������ҵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;

	int ret = isexit(abs, name);

	if (ret != -1)
	{
		cout << "������" << abs->pArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->pArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->pArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->pArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->pArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴��ˣ����������룡" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ�˺���

void modifyperson(Addressbooks * abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->pArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		//�Ա�
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->pArray[ret].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->pArray[ret].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->pArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}


void clearperson(Addressbooks* abs)
{
	cout << "�Ƿ�ȷ�������ϵ�ˣ�1:�� 0����" << endl;
	int yon;
	cin >> yon;
	switch (yon)
	{
	case 1:
		abs->m_Size = 0;
		cout << "������" << endl;
		
	case 0:
		cout << "δ���ͨѶ¼��" << endl;
		break;

	default:
		cout << "δ���ͨѶ¼��" << endl;
		break;
	}
}

int main()
{

	//������ʵͨѶ¼
	Addressbooks abs;
	//��ʼ����ǰ��Ա����
	abs.m_Size = 0;

	
	//���ݲ�ͬѡ����벻ͬ����
	int select = 0;

	while (true)
	{
		showMenu();//��ʾ�˵�
		cout << "ѡ������ʵ�ֵĹ��ܣ� ";
		cin >> select;

		switch (select)
		{
		case 1: //�����ϵ��
			addperson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2: //��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4: //������ϵ��
			findperson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6: //�����ϵ��
			clearperson(&abs);
			break;
		case 0: //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
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