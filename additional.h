#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include <Windows.h>
#include<graphics.h>
# include "conio.h" //屏幕操作函数库
#include <time.h>
#include<string.h>
//与按键有关的宏定义
#define LEFT 65 //光标左移
#define RIGHT 68 //光标右移
#define DOWN 83 //光标下移
#define UP 87 //光标上移
#define ESC 27 //Esc键：取消菜单打开操作
#define H 72 // F1键：打开文件菜单
#define J 74//F2键：打开编辑菜单
#define K 75//F3键：打开帮助菜单
#define ENTER 13 //回车键：换行
//与菜单选项有关的宏定义
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


#define N 200 //定义酒店客房的最大数量

/*定义与Room记录格式化输出有关的宏定义*/
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
	char num[15];         //客房编号
	int price;            //价格
	int empty_flag;       //空闲标记
	char client_name[15]; //顾客姓名
	char client_ic[20];   //顾客身份证号
	struct date client_date;//顾客入住日期
	int client_totaldays; //顾客入住天数
	int client_ap;         //顾客预付款
}ROOM;

typedef struct member
{
	char num[15];        //会员编号
	char name[15];       //姓名
	char sex[4];         //性别
	int age;             //年龄
	char ic[20];         //身份证号
	char tele[15];       //联系方式
};

typedef struct member_node {
	struct member data;
	struct member_node* next;
}*Member_Link, Member_Node;//*Member_Link为Member_Node类型结构体的指针H
/*与界面控制相关的函数的声明*/
void insline();
void insline1();
void gotoxy(int x, int y);
int wherex();
int wherey();
void mainmenu();
void drawmain();
int menuctrl();
/*与数据结构逻辑相关的函数声明*/
void modeset(int w, int h);
int AddRoom(ROOM tp[], int n);//添加客房记录
void AddMember(Member_Link l);//添加会员记录
int DelRoom(ROOM tp[], int n);//删除客房记录
void DelMember(Member_Link l);//删除会员记录
void SaveRoom(ROOM tp[], int n);//退出系统时保存客房记录
void SaveMember(Member_Link l);//退出系统时保存会员记录
void QueryRoom(ROOM tp[], int n);//查询客房记录
void QueryMember(Member_Link l);//查询会员记录
void ModifyRoom(ROOM tp[], int n);//修改客房记录
void ModifyMember(Member_Link l);//修改会员记录
void SortRoom(ROOM tp[], int n);//排序客房记录
void SortMember(Member_Link l);//排序会员记录
void CountRoom(ROOM tp[], int n);//统计客房记录
void CountMember(Member_Link l);//统计会员记录
void RegisterRoom(ROOM tp[], int n, Member_Link ll);//登记入住
void ReturnRoom(ROOM tp[], int n, Member_Link ll);//退房
void drawmain2();

static int saveflag = 0; //是否需要存盘的全局变量
/*用于保存系统的当前时间*/
 static int currentYear;
static int currentMonth;
static int currentDay;




