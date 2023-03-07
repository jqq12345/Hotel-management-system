#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include <Windows.h>
#include<graphics.h>
# include "conio.h" //��Ļ����������
#include <time.h>
#include<string.h>
//�밴���йصĺ궨��
#define LEFT 65 //�������
#define RIGHT 68 //�������
#define DOWN 83 //�������
#define UP 87 //�������
#define ESC 27 //Esc����ȡ���˵��򿪲���
#define H 72 // F1�������ļ��˵�
#define J 74//F2�����򿪱༭�˵�
#define K 75//F3�����򿪰����˵�
#define ENTER 13 //�س���������
//��˵�ѡ���йصĺ궨��
#define ADD_ROOM 100
#define QUERY_ROOM 101
#define MODIFY_ROOM 102
#define DEL_ROOM 103
#define SORT_ROOM 104
#define COUNT_ROOM 105
#define ADD_MEMBER 200
#define QUERY_MEMBER 201
#define MODIFY_MEMBER 202
#define DEL_MEMBER 203
#define SORT_MEMBER 204
#define COUNT_MEMBER 205
#define REGISTER_ROOM 300
#define RETURN_ROOM 301
#define EXIT 302


#define N 200 //����Ƶ�ͷ����������

/*������Room��¼��ʽ������йصĺ궨��*/
#define HEADER1 "| Number | Price | E_F | C_Name |       C_IC         |    Date    | CNum | C_AP | \n"
#define FORMAT1 "| %-5s | %5d | %3d | %-6s | %18s | %4d-%2d-%2d | %4d | %4d | \n"
#define DATA1 lll->num,lll->price,lll->empty_flag,lll->client_name,lll->client_ic,\
lll->client_date.year,lll->client_date.mon,lll->client_date.day,lll->client_totaldays,lll->client_ap
#define HEADER2 "|Number|  Name  | Sex | Age |           IC       |     Tele    | \n"
#define FORMAT2 "| %-4s | %-6s | %-3s | %3d | %18s | %11s | \n"
#define DATA2 lll->data.num,lll->data.name,lll->data.sex,lll->data.age,lll->data.ic,lll->data.tele
typedef struct date
{
	int year;
	int mon;
	int day;
};

typedef struct room
{
	char num[15];         //�ͷ����
	int price;            //�۸�
	int empty_flag;       //���б��
	char client_name[15]; //�˿�����
	char client_ic[20];   //�˿����֤��
	struct date client_date;//�˿���ס����
	int client_totaldays; //�˿���ס����
	int client_ap;         //�˿�Ԥ����
}ROOM;

typedef struct member
{
	char num[15];        //��Ա���
	char name[15];       //����
	char sex[4];         //�Ա�
	int age;             //����
	char ic[20];         //���֤��
	char tele[15];       //��ϵ��ʽ
};

typedef struct member_node {
	struct member data;
	struct member_node* next;
}*Member_Link, Member_Node;//*Member_LinkΪMember_Node���ͽṹ���ָ��H
/*����������صĺ���������*/
void insline();
void insline1();
void gotoxy(int x, int y);
int wherex();
int wherey();
void mainmenu();
void drawmain();
int menuctrl();
/*�����ݽṹ�߼���صĺ�������*/
void modeset(int w, int h);
int AddRoom(ROOM tp[], int n);//��ӿͷ���¼
void AddMember(Member_Link l);//��ӻ�Ա��¼
int DelRoom(ROOM tp[], int n);//ɾ���ͷ���¼
void DelMember(Member_Link l);//ɾ����Ա��¼
void SaveRoom(ROOM tp[], int n);//�˳�ϵͳʱ����ͷ���¼
void SaveMember(Member_Link l);//�˳�ϵͳʱ�����Ա��¼
void QueryRoom(ROOM tp[], int n);//��ѯ�ͷ���¼
void QueryMember(Member_Link l);//��ѯ��Ա��¼
void ModifyRoom(ROOM tp[], int n);//�޸Ŀͷ���¼
void ModifyMember(Member_Link l);//�޸Ļ�Ա��¼
void SortRoom(ROOM tp[], int n);//����ͷ���¼
void SortMember(Member_Link l);//�����Ա��¼
void CountRoom(ROOM tp[], int n);//ͳ�ƿͷ���¼
void CountMember(Member_Link l);//ͳ�ƻ�Ա��¼
void RegisterRoom(ROOM tp[], int n, Member_Link ll);//�Ǽ���ס
void ReturnRoom(ROOM tp[], int n, Member_Link ll);//�˷�
void drawmain2();

static int saveflag = 0; //�Ƿ���Ҫ���̵�ȫ�ֱ���
/*���ڱ���ϵͳ�ĵ�ǰʱ��*/
 static int currentYear;
static int currentMonth;
static int currentDay;




