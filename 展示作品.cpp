#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#define MAX 1000
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
HANDLE hout;
color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

typedef struct user {
	int sid;
	char name[20];
	char type[20];
	double money;
}user;
user users[MAX];
int num = 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int logout();
int login();
void pressanykey();
void aboutus();
void read1();
void hidden_input(char* pwd);
void menu();
void add();
void show();
void save();
void read();
void del();
void update();
void sortinmoney();
void Modify();
int findStudent(int sid);
char username[20];
char passwords[20];
int main() {
	int i;
	PlaySound(TEXT("1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	do {
		system("cls");
		printf("***********************************************************\n");
		printf("\t\t\t΢���û�����ϵͳ\n");
		printf("\t\t\t1.��¼\n");
		printf("\t\t\t2.��������\n");
		printf("\t\t\t3.�˳�\n");
		printf("***********************************************************\n");
		printf("������ѡ��:(1,2,3)\n");
		scanf("%d", &i);
		fflush(stdin);
		switch (i) {
		case 1:
			read1();
			if (login())
			{
				read();
				printf("��¼�ɹ���\n");
				printf("�����Ѽ��أ�\n");
				system("pause");
				menu();
			}
			else
			{
				color(4);
				printf("���δ��������µ�¼��\n");
				color(7);
				system("pause");
			}
			break;
		case 2:
			aboutus();
			break;
		case 3:
			if (logout() == 1) {
				printf("�˳��ɹ���\n");
				PlaySound(NULL, NULL, SND_FILENAME);
				system("pause");
				exit(1);
			}
			printf("ȡ���˳���\n");
			system("pause");
			break;
		}
	} while (1);

	system("pause");
	pressanykey();
	return 0;
}
int logout() {
	char ch;
	int i;
	color(4);
	printf("��,�����Ҫ�˳���?(y for yes n for no)\n");
	color(7);
	scanf("%c", &ch);
	if (ch == 'y') {
		for (i = 0; i<3; i++) {
			printf("%c", 7);
			printf(".....");
			Sleep(1000);
		}
		printf("\n");
		return 1;
	}
	return 0;
}
void pressanykey() {
	printf("\n=============\n");
	printf("\npress any key to continue\n");
	printf("\n=============\n");
	_getch();//�Ӽ����������һ���� 
}

void aboutus() {
	printf("***********************************************************\n");
	printf("\t\t\t����һ��С��Ŀ:\n");
	printf("\t\t\t�����ܴ�,��ŷ�ܣ���Թ�ͬ����\n");
	printf("\t\t\t���ǹ��������ߵ����������һ������\n");
	printf("***********************************************************\n");
	pressanykey();
}

int login()
{
	int i = 3;
	while (i)
	{
		int pro;
		char uname[20];
		char uword[20];
		srand((unsigned int)time(NULL));
		int x = (rand() % 9) + 1;
		int y = rand() % 10;
		int z = rand() % 10;
		int num = x * 100 + y * 10 + z;
		fflush(stdin);
		printf("�������û�����");
		scanf("%s", uname);
		fflush(stdin);
		printf("���������룺");
		hidden_input(uword);
		printf("\n");
		printf("��������֤��(%d):", num);
		scanf("%d", &pro);
		if (strcmp(uname, username) == 0 && strcmp(uword, passwords) == 0 && pro == num)
		{
			return 1;
		}
		if (pro != num)
		{
			color(4);
			printf("��֤��������������룺\n");
			color(7);
			i--;
			continue;
		}
		color(4);
		printf("�û���������������������룺\n");
		color(7);
		i--;
	}
	return 0;
}
void read1()
{
	FILE* pf = fopen("loge.txt", "r");
	fread(username, 20, 1, pf);
	fread(passwords, 20, 1, pf);
	fclose(pf);
}

void hidden_input(char* pwd) {
	char input_char;
	int index = 0;
	fflush(stdin);//������뻺��
				  //������ʾ*����֧���˸�  
	while ((input_char = _getch()) != '\r') {//���з� 
		if (input_char == '\b') {//�˸�� 
			if (index < 0)
				continue;
			if (index > 0) {
				putchar('\b');
				putchar(' ');
				putchar('\b');
				index--;
			}
		}
		else {
			printf("*");
			pwd[index++] = input_char;
		}
	}
	pwd[index] = '\0';//������ 
}
void menu() {
	//	struct tm *ptr;
	//	int choice,flag=1;
	//	time_t  t=time(0);
	//	char str[80];
	//	ptr=localtime(&t);
	int choice, flag = 1;
	do {
		system("cls");
		//		strftime(str,sizeof(str),"%Y/%m%d  %X %A",ptr);
		//		printf("��ӭ����%s,�����ǣ�%s \n",username,str);
		printf("**********************************************\n");
		printf("\t\t΢���û����ѹ���ϵͳ��ӭ��\n");
		printf("\t\t1.����û�\n");
		printf("\t\t2.ɾ���û�\n");
		printf("\t\t3.�鿴�����û���Ϣ\n");
		printf("\t\t4.�޸��û���Ϣ\n");
		printf("\t\t5.�������ܽ������\n");
		printf("\t\t6.�޸��û���������\n");
		printf("\t\t7.ע��������\n");
		printf("**********************************************\n");
		printf("���������ѡ��(1,2,3,4,5,6,7):\n");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice) {
		case 1:add();
			break;
		case 2:
			del();
			break;
		case 3:
			show();
			break;
		case 4:
			update();
			break;
		case 5:
			sortinmoney();
			printf("����ɹ���\n");
			system("pause");
			break;
		case 6:
			if (login())
			{
				printf("��֤�û���Ϣ�ɹ���\n");
				Modify();
				printf("�޸��û���������ɹ��������µ�¼��\n");
				system("pause");
				flag = 0;
			}
			break;
		case 7:
			save();
			printf("�˳��ɹ��������ѱ��棡\n");
			system("pause");
			flag = 0;
			break;
		default:
			printf("û�����ѡ���ȷ�Ϻ���������.\n");
		}
	} while (flag);
}

void add() {
	char ch;
	int count = 0;
	do {
		count++;
		printf("�������%d���û����������:\n", (num + 1));
		printf("�������û���id:");
		scanf("%d", &users[num].sid);
		printf("�����û�����:");
		scanf("%s", users[num].name);
		fflush(stdin);
		printf("��������(�Ҿӣ��Է�������):");
		scanf("%s", users[num].type);
		printf("������:");
		fflush(stdin);
		scanf("%lf", &users[num].money);
		num++;
		printf("����������һ���û������������(y/n)\n");
		fflush(stdin);
		scanf("%c", &ch);
		if (ch != 'y')
		{
			printf("\n���ѧ����Ϣ����\n");
			printf("��������%d��ѧ�����ܹ���%d��ѧ��\n", count, num);
			system("pause");
			break;
		}
	} while (1);
}

void show() {
	system("cls");
	int i;
	double maxMoney, minMoney;
	double sumMoney = 0;//������ 
	struct user usermaxMoney = users[0];
	if (num == 0) {
		printf("ϵͳ�л�û��������...\n");
		return;
	}
	maxMoney = users[0].money;
	minMoney = users[0].money;
	printf("΢���û�����������£�\n");
	printf("%-8s\t%-8s\t%-8s\t%-8s\n", "�û�id", "����", "�������", "���ѽ��");
	for (i = 0; i<num; i++) {
		struct user  s = users[i];
		printf("%-8d\t%-8s\t%-8s\t%-8.2lf\n", s.sid, s.name, s.type, s.money);
		sumMoney += s.money;
		if (s.money>maxMoney) {
			maxMoney = s.money;
			usermaxMoney = s;
		}
		if (s.money<minMoney) {
			minMoney = s.money;
		}
	}
	printf("ͳ�����£�\n");
	printf("΢���û�ƽ������Ϊ��%.1lf,�������Ϊ��%.2lf,�������Ϊ��%.2lf,������ߵ��ǣ�%s\n", sumMoney / num, maxMoney, minMoney, usermaxMoney.name);
	system("pause");
}

void save() {
	FILE* fp = fopen("date2.txt", "w");
	fwrite(users, sizeof(struct user), num, fp);
	fclose(fp);
	fp = NULL;
}

void read() {

	FILE *fp = fopen("date2.txt", "r");
	if (fp == NULL) {
		printf("û������ļ�...\n");
		_getch();
		return;
	}
	while (fread(&users[num], sizeof(struct user), 1, fp)) {
		num++;
	}
	fclose(fp);
	fp = NULL;
}

void del() {
	system("cls");
	int i;
	int sid;
	int index;
	printf("������Ҫɾ����������id��");
	scanf("%d", &sid);
	index = findStudent(sid);
	if (index<0) {
		printf("���޴�ѧ��%d�û����޷�ɾ��...\n", sid);
		system("pause");
		return;
	}
	//ѭ�����飬��һ������ǰһ�� 
	for (i = index; i<num - 1; i++)
	{
		users[i] = users[i + 1];
	}
	num--;
	printf("ɾ��%dѧ���û��ɹ�\n", sid);
	system("pause");
}
int findStudent(int sid)
{
	int i;
	for (i = 0; i<num; i++)
	{
		if (users[i].sid == sid)
		{
			return i;
		}
	}
	return -1;
}


void update()
{
	system("cls");
	int sid;
	int index;
	printf("������Ҫ�޸ĵ�������id��");
	scanf("%d", &sid);
	index = findStudent(sid);
	if (index<0) {
		printf("���޴�ѧ��%d�û����޷��޸�...\n", sid);
		system("pause");
		return;
	}
	printf("ԭ��������Ϣ���£�\n");
	printf("%-8s\t%-8s\t%-8s\t%-8s\n", "�û�id", "����", "�������", "���ѽ��");
	printf("%-8d\t%-8s\t%-8s\t%-8.2lf\n", users[index].sid, users[index].name, users[index].type, users[index].money);
	printf("�������û�����:");
	scanf("%s", users[index].name);
	fflush(stdin);
	printf("�µ���������(�Ҿӣ��Է�������):");
	scanf("%s", users[index].type);
	printf("�����µĽ��:");
	fflush(stdin);
	scanf("%lf", &users[index].money);
	printf("�޸�%dѧ���û��ɹ�\n", sid);
	system("pause");
}

void sortinmoney()
{
	int i, j;
	for (i = 0; i<num - 1; i++)
	{
		for (j = 0; j<num - 1 - i; j++)
		{
			if (users[j].money>users[j + 1].money)
			{
				user tmp = users[j];
				users[j] = users[j + 1];
				users[j + 1] = tmp;
			}
		}
	}
}

void Modify()
{
	FILE* pf = fopen("loge.txt", "w");
	char uname[20];
	char uword[20];
	printf("�������µ��û�����");
	scanf("%s", uname);
	printf("�������µ����룺");
	scanf("%s", uword);
	fwrite(uname, 20, 1, pf);
	fwrite(uword, 20, 1, pf);
	fclose(pf);
	pf = NULL;
}
