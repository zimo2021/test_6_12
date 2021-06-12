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
		printf("\t\t\t微信用户管理系统\n");
		printf("\t\t\t1.登录\n");
		printf("\t\t\t2.关于我们\n");
		printf("\t\t\t3.退出\n");
		printf("***********************************************************\n");
		printf("请输入选项:(1,2,3)\n");
		scanf("%d", &i);
		fflush(stdin);
		switch (i) {
		case 1:
			read1();
			if (login())
			{
				read();
				printf("登录成功！\n");
				printf("数据已加载！\n");
				system("pause");
				menu();
			}
			else
			{
				color(4);
				printf("三次错误，请重新登录！\n");
				color(7);
				system("pause");
			}
			break;
		case 2:
			aboutus();
			break;
		case 3:
			if (logout() == 1) {
				printf("退出成功！\n");
				PlaySound(NULL, NULL, SND_FILENAME);
				system("pause");
				exit(1);
			}
			printf("取消退出！\n");
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
	printf("亲,你真的要退出吗?(y for yes n for no)\n");
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
	_getch();//从键盘随便输入一个数 
}

void aboutus() {
	printf("***********************************************************\n");
	printf("\t\t\t这是一个小项目:\n");
	printf("\t\t\t这是周传,李欧杰，朱辉共同制作\n");
	printf("\t\t\t这是关于消费者的消费情况的一个程序\n");
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
		printf("请输入用户名：");
		scanf("%s", uname);
		fflush(stdin);
		printf("请输入密码：");
		hidden_input(uword);
		printf("\n");
		printf("请输入验证码(%d):", num);
		scanf("%d", &pro);
		if (strcmp(uname, username) == 0 && strcmp(uword, passwords) == 0 && pro == num)
		{
			return 1;
		}
		if (pro != num)
		{
			color(4);
			printf("验证码错误！请重新输入：\n");
			color(7);
			i--;
			continue;
		}
		color(4);
		printf("用户名或密码错误，请重新输入：\n");
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
	fflush(stdin);//清除输入缓存
				  //密码显示*号且支持退格  
	while ((input_char = _getch()) != '\r') {//换行符 
		if (input_char == '\b') {//退格键 
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
	pwd[index] = '\0';//结束符 
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
		//		printf("欢迎您：%s,今天是：%s \n",username,str);
		printf("**********************************************\n");
		printf("\t\t微信用户消费管理系统欢迎您\n");
		printf("\t\t1.添加用户\n");
		printf("\t\t2.删除用户\n");
		printf("\t\t3.查看所有用户信息\n");
		printf("\t\t4.修改用户信息\n");
		printf("\t\t5.按消费总金额排序\n");
		printf("\t\t6.修改用户名和密码\n");
		printf("\t\t7.注销并保存\n");
		printf("**********************************************\n");
		printf("请输入你的选项(1,2,3,4,5,6,7):\n");
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
			printf("排序成功！\n");
			system("pause");
			break;
		case 6:
			if (login())
			{
				printf("验证用户信息成功！\n");
				Modify();
				printf("修改用户名和密码成功！请重新登录！\n");
				system("pause");
				flag = 0;
			}
			break;
		case 7:
			save();
			printf("退出成功，数据已保存！\n");
			system("pause");
			flag = 0;
			break;
		default:
			printf("没有这个选项，请确认后重新输入.\n");
		}
	} while (flag);
}

void add() {
	char ch;
	int count = 0;
	do {
		count++;
		printf("请输入第%d个用户的消费情况:\n", (num + 1));
		printf("请输入用户的id:");
		scanf("%d", &users[num].sid);
		printf("输入用户姓名:");
		scanf("%s", users[num].name);
		fflush(stdin);
		printf("消费类型(家居，吃饭，旅游):");
		scanf("%s", users[num].type);
		printf("输入金额:");
		fflush(stdin);
		scanf("%lf", &users[num].money);
		num++;
		printf("继续输入下一个用户的消费情况吗？(y/n)\n");
		fflush(stdin);
		scanf("%c", &ch);
		if (ch != 'y')
		{
			printf("\n添加学生信息结束\n");
			printf("本次新增%d个学生，总共有%d个学生\n", count, num);
			system("pause");
			break;
		}
	} while (1);
}

void show() {
	system("cls");
	int i;
	double maxMoney, minMoney;
	double sumMoney = 0;//总消费 
	struct user usermaxMoney = users[0];
	if (num == 0) {
		printf("系统中还没有消费者...\n");
		return;
	}
	maxMoney = users[0].money;
	minMoney = users[0].money;
	printf("微信用户消费情况如下：\n");
	printf("%-8s\t%-8s\t%-8s\t%-8s\n", "用户id", "姓名", "消费类别", "消费金额");
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
	printf("统计如下：\n");
	printf("微信用户平均消费为：%.1lf,最高消费为：%.2lf,最低消费为：%.2lf,消费最高的是：%s\n", sumMoney / num, maxMoney, minMoney, usermaxMoney.name);
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
		printf("没有这个文件...\n");
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
	printf("请输入要删除的消费者id：");
	scanf("%d", &sid);
	index = findStudent(sid);
	if (index<0) {
		printf("查无此学号%d用户，无法删除...\n", sid);
		system("pause");
		return;
	}
	//循环数组，后一个覆盖前一个 
	for (i = index; i<num - 1; i++)
	{
		users[i] = users[i + 1];
	}
	num--;
	printf("删除%d学号用户成功\n", sid);
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
	printf("请输入要修改的消费者id：");
	scanf("%d", &sid);
	index = findStudent(sid);
	if (index<0) {
		printf("查无此学号%d用户，无法修改...\n", sid);
		system("pause");
		return;
	}
	printf("原消费者信息如下：\n");
	printf("%-8s\t%-8s\t%-8s\t%-8s\n", "用户id", "姓名", "消费类别", "消费金额");
	printf("%-8d\t%-8s\t%-8s\t%-8.2lf\n", users[index].sid, users[index].name, users[index].type, users[index].money);
	printf("输入新用户姓名:");
	scanf("%s", users[index].name);
	fflush(stdin);
	printf("新的消费类型(家居，吃饭，旅游):");
	scanf("%s", users[index].type);
	printf("输入新的金额:");
	fflush(stdin);
	scanf("%lf", &users[index].money);
	printf("修改%d学号用户成功\n", sid);
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
	printf("请输入新的用户名：");
	scanf("%s", uname);
	printf("请输入新的密码：");
	scanf("%s", uword);
	fwrite(uname, 20, 1, pf);
	fwrite(uword, 20, 1, pf);
	fclose(pf);
	pf = NULL;
}
