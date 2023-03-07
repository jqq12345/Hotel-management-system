
# include "additional.h"

#pragma warning(disable:4996)


int main1()
{
	drawmain2();
	return 0;
}
int main()
{
	ROOM GR[N];  //定义客房结构数组
	Member_Link ll; //定义会员链表指针
	FILE* fp1, * fp2; //fp1为指向客房文件指针，fp2为指向会员的文件指针
	Member_Node* p2, * r2; //定义会员记录指针变量
	int A, B, i;
	char ch,a; //保存（y,Y,n,N）
	int count1 = 0, count2 = 0; //分别保存客房文件或者会员文件中的记录条数
    //modeset(80, 35);  //显示系统主界面
	drawmain();
	/****************************打开客房文件ROOM，将其调入数组中存储************************************************/
	fp1 = fopen("E:\\room", "at+");//以追加方式打开一个二进制文件，可读可写，若此文件不存在，会创建此文件
	if (fp1 == NULL)
	{
		system("cls"); mainmenu(); gotoxy(2, 3);
		printf("\n=====>can not open file1!\n");
		exit(0);
	}
	while (!feof(fp1))
	{
		if (fread(&GR[count1], sizeof(ROOM), 1, fp1) == 1)//一次从文件中读出一条客房记录
		{
			count1++;
		}
	}fclose(fp1); //关闭文件
	/****************************打开客房文件MEMBER，将其调入数组中存储************************************************/
	ll = (Member_Node*)malloc(sizeof(Member_Node));
	if (!ll)
	{
		system("cls"); mainmenu(); gotoxy(2, 3); 
		printf("\n allocate memory failure");//如果没有申请到打印提示信息 
		return 0;//返回主界面 
	}
	ll->next = NULL;
	r2 = ll;
	fp2 = fopen("E:\\member", "at+");//以追加方式打开一个二进制文件，可读可写，若此文件不存在，会创建此文件
	if (fp2 == NULL)
	{
		system("cls"); mainmenu(); gotoxy(2, 3);
		printf("\n=====>can not open file2!\n");
		exit(0);
	}
	while (!feof(fp2))  /*feof()函数检测流上的文件结束符，若文件结束，则返回非零的值，否则返回零*/
	{
		p2 = (Member_Node*)malloc(sizeof(Member_Node));
		if (!p2)
		{
			system("cls"); mainmenu(); gotoxy(2, 3);
			printf("memory malloc failure!\n");//没有申请成功 
			exit(0); //退出 
		}
		if (fread(p2, sizeof(Member_Node), 1, fp2) == 1)//一次从文件中读取一条图书记录 
		{
			p2->next = NULL;
			r2->next = p2;
			r2 = p2;//r指针向后移一个位置 
			count2++;
		}
	}
	fclose(fp2);//关闭文件
	p2 = r2;
	while (1)
	{
		B = menuctrl();
		switch (B)
		{
		case ADD_ROOM:count1 = AddRoom(GR, count1);  break;//增加图书记录
		case QUERY_ROOM:QueryRoom(GR, count1); break;//删除图书记录
		case MODIFY_ROOM:ModifyRoom(GR,count1); break;//修改图数记录
		case DEL_ROOM:count1=DelRoom(GR,count1); break;//删除图书记录
		case SORT_ROOM:SortRoom(GR,count1); break;//排序图书记录
		case COUNT_ROOM:CountRoom(GR,count1); break;//统计图书记录
		case ADD_MEMBER:AddMember(ll); break;//增加读者记录
		case QUERY_MEMBER:QueryMember(ll); break;//查询读者记录
		case MODIFY_MEMBER:ModifyMember(ll); break;//修改读者记录
		case DEL_MEMBER:DelMember(ll); break;//删除读者记录
		case SORT_MEMBER:SortMember(ll); break;//排序读者记录
		case COUNT_MEMBER:CountMember(ll); break;//统计读者记录
		case REGISTER_ROOM:RegisterRoom(GR,count1,ll); break;//借书
		case RETURN_ROOM:ReturnRoom(GR, count1,ll); break;//还书
		case EXIT: //退出系统		
		{
			system("cls");  mainmenu(); gotoxy(3, 3);
			cprintf("====>Are you really exit the Room Management System?(y/n):");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				SaveRoom(GR,count1); SaveMember(ll); exit(0);
			}
		}
		}
		system("cls");
		drawmain();
	}
}

void stringinput(char* t, int lens, const char* notice,int flag)
{
	char n[225];
	int x=0, y=0,i=0;
	do {
		if(x&&i)
		{
			gotoxy(x + 2, y-2);insline1();
			gotoxy(x + 2, y-1);insline1();
			i--;
			gotoxy(x + 2, y-2);
		}
		printf(notice);
		scanf("%s", n);
	   if(flag==2&&strlen(n)!=lens)
	   {
		   		x = wherex();
			    y = wherey();
				gotoxy(x + 2,y-1); printf("please input the 11 digits Telephone correctly\n");i++;getchar();getchar();
				continue;
	    }
	   	if(flag==3&&strlen(n)!=lens)
	   {
		   		x = wherex();
			    y = wherey();
				gotoxy(x + 2,y-1); printf("please input the 18 digits ID num correctly\n");i++;getchar();getchar();
				continue;
	    }
		if(flag==4&&strlen(n)!=lens&&strcmp(n,"0"))
	   {
		   		x = wherex();
			    y = wherey();
				gotoxy(x + 2,y-1); printf("please input the 3 digits num correctly\n");i++;getchar();getchar();
				continue;
	    }
	   if(flag==1&&strcmp(n,"男")&&strcmp(n,"女"))
	   {
		   		x = wherex();
			    y = wherey();
				gotoxy(x + 2, y-1); printf("please input '男' or '女'\n");i++;getchar();getchar();
				continue;
	   }
		if (strlen(n) > lens)
		{
			x = wherex();
			y = wherey();
			gotoxy(x + 2, y-1); printf("exceed the required length!\n");i++;getchar();getchar();
		}/*进行长度校验，如果超出len长度，从新输入*/
	} while (strlen(n)>lens||((flag==3||flag==2)&&strlen(n)!=lens)||flag==1&&strcmp(n,"男")&&strcmp(n,"女")||flag==4&&strlen(n)!=lens&&strcmp(n,"0"));
	strcpy(t, n);/*将输入的字符串复制到字符串t中*/
}
int LocateRoom(ROOM tp[],int n, char findmess[], char nameornum[])//图书定位 
/**********************************************************************************
作用：用于定位链表中符合要求的节点，并返回指向该节点的指针
参数：findmess[]保存要查找的具体内容；nameornum[]保存按什么查找；
************************************************************************************/
{
	int i=0;
	if (strcmp(nameornum, "num") == 0)//按图书编号查询
	{
		while (i<n)
		{
			if (strcmp(tp[i].num, findmess) == 0)//若找到findmess值的图书编号
				return i;
			i++;
		}
	}
	else if (strcmp(nameornum, "name") == 0)//按图书名查询
	{
		while (i<n)
		{
			if (strcmp(tp[i].client_name, findmess) == 0)//若找到findmess值的图书名
				return i;
			i++;
		}
	}
	return -1;//若未找到，返回一个空指针 
}
Member_Node* LocateMember(Member_Link l, char findmess[], char nameornum[])//会员定位 
{
    Member_Node* r;
	if (strcmp(nameornum, "num") == 0)//按会员编号查询
	{
		r = l->next;
		while (r)
		{
			if (strcmp(r->data.num, findmess) == 0)//若找到findmess值的会员编号
				return r;
			r = r->next;
		}
	}
	else if (strcmp(nameornum, "name") == 0)//按会员姓名查询
	{
		r = l->next;
		while (r)
		{
			if (strcmp(r->data.name, findmess) == 0)//若找到findmess值的会员
				return r;
			r = r->next;
		}
	}
	return 0;//若未找到，返回一个空指针 
}

//添加记录
int AddRoom(ROOM tp[], int n)
{
	char ch, flag = 0,num[15];
	int i;
	system("cls");
	while (1)
	{
		while (1)
		{
			system("cls");
			mainmenu();
			gotoxy(3, 4);
			stringinput(num, 3, "input room number(press '0'return menu):",4);
			flag = 0;
			if (strcmp(num, "0") == 0)
			{
				return n;
			}
			i = 0;
			while (i < n)
			{
				if (strcmp(tp[i].num, num) == 0)
				{
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 1)
			{
				gotoxy(3, 5);
				getchar();
				printf("====>The number %s is existing,please try again(Y/N)?", num);
				scanf("%c", &ch);
				if (ch == 'Y' || ch == 'y') 
					continue;
				else 
					return n;
			}
			else break;
		}
		/*给客房记录赋值*/
		strcpy(tp[n].num, num); /*将字符串num复制到tp[n].num中*/
		gotoxy(3,6); printf("Room Price:"); scanf("%d", &tp[n].price);
		tp[n].empty_flag = 1; /*客房空闲标记，1表示空闲，0表示未空闲*/
		strcpy(tp[n].client_name, ""); /*顾客姓名*/
		strcpy(tp[n].client_ic,""); /*顾客身份证号*/
		tp[n].client_date.year = 0;
		tp[n].client_date.mon = 0;
		tp[n].client_date.day = 0;
		tp[n].client_totaldays = 0;
		tp[n].client_ap = 0;
		saveflag = 1;
		n++;
		gotoxy(3,9); printf(">>>>press any key to start next record!");
		getchar(); getchar();
	}
	return n;
}
void AddMember(Member_Link l)
{
	Member_Node* p, * r, * s;//实现添加操作的临时的结构体指针变量
	char ch, flag = 0, num[10];
	int temp;
	r = l;
	s = l->next;
	system("cls");
	while (r->next != NULL)
		r = r->next;//将指针移至于链表最末尾，准备添加记录
	while (1)//一次可输入多条记录，直至输入会员编号为0的记录结点添加操作
	{
		while (1)//输入会员编号，保证该编号没有被使用，若输入编号为0，则退出添加记录操作
		{
			system("cls");
			mainmenu();
			gotoxy(3, 4);
			stringinput(num, 3, "input member number(press '0' return menu):",4);//格式化输入会员编号并检验
			flag = 0;
			if (strcmp(num, "0") == 0)//输入为0，则退出添加操作，返回主界面
			{
				return;
			}
			s = l->next;
			while (s)//查询该会员编号是否已经存在，若存在则要求重新输入一个未被占用的编号
			{
				if (strcmp(s->data.num, num) == 0)
				{
					flag = 1;
					break;
				}
				s = s->next;
			}
			if (flag == 1)//提示用户是否重新输入
			{
				gotoxy(3, 5);
				getchar();
				printf("====>The number %s is existing,please try again(y/n)?", num);
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
					continue;
				else
					return;
			}
			else
			{
				break;
			}
		}
		p = (Member_Node*)malloc(sizeof(Member_Node));//申请内存空间
		if (!p)
		{
			printf("\n allocate memory failure ");//如没有申请到，打印提示信息
			return;
		}
		//给图书记录赋值
		strcpy(p->data.num, num);//将字符串num复制到p->data.num中
		gotoxy(3, 5); stringinput(p->data.name, 15, "Member Name:",0);
		gotoxy(3, 6); stringinput(p->data.sex, 15, "Member Sex:",1);
		gotoxy(3, 7); stringinput(p->data.tele, 11, "Member Tele:",2);
		gotoxy(3, 8); printf("Member Age:"); scanf("%d", &temp);
		p->data.age = temp;
		gotoxy(3, 9); stringinput(p->data.ic, 18, "Member ic:",3);
		gotoxy(3, 10); printf(">>>>press any key to start next record!");
		getchar(); getchar();
		p->next = NULL;//表明这是链表的尾部结点
		r->next = p;//将新建的结点加入链表尾部中
		r = p;
		saveflag = 1;
	}
	return;
}

//删除记录
int DelRoom(ROOM tp[], int n)
{
	int i = 0, p = 0;
	char findmess[20];
	if (n < 0)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n====>No room record!\n");
		getchar();
		return 0;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	stringinput(findmess, 10, "input the existing room number:",0);
	p = LocateRoom(tp, n, findmess, "num");
	if (p !=-1)
	{
		for (i = p + 1; i < n; i++) //删除此记录，后面记录向前移
		{
			strcpy(tp[i - 1].num, tp[i].num);
			tp[i - 1].price = tp[i].price;
			tp[i - 1].empty_flag = tp[i].empty_flag;
			strcpy(tp[i - 1].client_name, tp[i].client_name);
			strcpy(tp[i - 1].client_ic, tp[i].client_ic);
			tp[i - 1].client_date.year = tp[i].client_date.year;
			tp[i - 1].client_date.mon = tp[i].client_date.mon;
			tp[i - 1].client_date.day = tp[i].client_date.day;
			tp[i - 1].client_totaldays = tp[i].client_totaldays;
			tp[i - 1].client_ap = tp[i].client_ap;
		}
		gotoxy(3, 9);
		printf("=====>delete success!\n");
		getchar(); getchar();
		saveflag = 1;
		n--;
	}
	else{
			gotoxy(3, 9); printf("=====>Not find this book!\n");
			getchar(); getchar();
			return n;
	}
}
void DelMember(Member_Link l)
{
	int sel;
	Member_Node* p, * r;
	char findmess[20];
	if (!l->next)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n====>No Reader record!\n");
		getchar();
		return;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	printf("=====>l Delete by Member number		=====>2 Delete by Member name");
	gotoxy(3, 6);
	printf("please choice[1,2]:");
	scanf("%d", &sel);
	if (sel == 1)
	{
		gotoxy(3, 7);
		stringinput(findmess, 10, "input the existing member number:",0);
		p = LocateMember(l, findmess, "num");
		if (p)//p!=NULL
		{
			r = l;
			while (r->next != p)
				r = r->next;
			r->next = p->next;//将p所指节点从链表中去除 
			free(p);//释放内存空间
			gotoxy(3, 9);
			printf("=====>delete success!");
			getchar(); getchar();
			saveflag = 1;
		}
		else
		{
			gotoxy(3, 9); printf("=====>Not find this Member!\n");
			getchar(); getchar();
		}
	}
	else if (sel == 2)//先按顾客名查询到该记录所在的节点
	{
		stringinput(findmess, 15, "input the existing member name:",0);
		p = LocateMember(l, findmess, "name");
		if (p)
		{
			r = l;
			while (r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			gotoxy(3, 9);
			printf("=====>delete success!\n");
			getchar(); getchar();
			saveflag = 1;
		}
		else
		{
			gotoxy(3, 9); printf("=====>Not find this Member!\n");
			getchar(); getchar();
		}
	}
	else
	{
		gotoxy(3, 9); printf("*****Error:input has wrong! press any key to continue******");
		getchar(); getchar();
	}
}

//保存记录
void SaveRoom(ROOM tp[],int n )
{
	FILE* fp;
	int i=0;
	int count = 0;
	mainmenu();
	fp = fopen("E:\\room", "wt");//以只写方式打开二进制文件
	if (fp == NULL)//打开文件失败
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("=====>open file error!\n");
		getchar();
		return;
	}
	i = 0;
	while (i<n)
	{
		if (fwrite(&tp[i], sizeof(ROOM), 1, fp) == 1)//每次写一条记录或一个节点信息至文件
		{
			count++;
			i++;
			continue;
		}
		else
		{
			break;
		}
	}
	if (count > 0)
	{
		gotoxy(3, 8);
		printf("=====>save book,total saved record number is:%d\n", count);
		getchar();
		saveflag = 0;
	}
	else
	{
		system("cls");
		mainmenu();
		gotoxy(3, 10);
		printf("the current room link is empty,no record is saved!\n");
		getchar();
	}
	fclose(fp);//关闭book文件 

}
void SaveMember(Member_Link l)
{
	FILE* fp;
	Member_Node* p;
	int count = 0;
	mainmenu();
	fp = fopen("E:\\member", "wb");//以只写方式打开二进制文件
	if (fp == NULL)//打开文件失败
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("=====>open file error!\n");
		getchar();
		return;
	}
	p = l->next;
	while (p)
	{
		if (fwrite(p, sizeof(Member_Node), 1, fp) == 1)//每次写一条记录或一个节点信息至文件
		{
			p = p->next;
			count++;
		}
		else
		{
			break;
		}
	}
	if (count > 0)
	{
		gotoxy(3, 9);
		printf("=====>save member,total saved record number is:%d\n", count);
		getchar();
		saveflag = 0;
	}
	else
	{
		system("cls");
		mainmenu();
		gotoxy(3, 10);
		printf("the current member link is empty,no record is saved!\n");
		getchar();
	}
	fclose(fp);//关闭reader文件 
}

//查询记录
void QueryRoom(ROOM tp[],int n)//按图书编号或图书书名查询
{
	int select;//1:按客房编号查 2：按顾客名查，其他：返回主界面 
	char searchinput[20];//保存用户输入的查询内容
    int  p=0;
	if (n<0)//若链表为空
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n====>No Room Record!\n");
		getchar(); getchar();
		return;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	printf("=====>l Search by Room number		=====>2 Search by client name");
	gotoxy(3, 6);
	printf("please choice[1,2]:");
	scanf("%d", &select);
	if (select == 1)//按客房编号查询
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing room number:",0);
		p = LocateRoom(tp,n,searchinput,"num");
		//在l中查找客房编号为searchinput值的节点，并返回节点的指针
		if (p!=-1)//若p!=NULL
		{
			gotoxy(3, 8); printf("------------------------------------------------------");
			gotoxy(3, 9); printf("Room Number:%s", tp[p].num);
			gotoxy(3, 10); printf("Room  Price:%d", tp[p].price);
			gotoxy(3, 11); printf("Room  Empty_flag(1:Empty):%d", tp[p].empty_flag);
			gotoxy(3, 12); printf("Client_name:%s", tp[p].client_name);
			gotoxy(3, 13); printf("Client_ic:%s", tp[p].client_ic);
			gotoxy(3, 14); printf("Client_date,%d-%d-%d", tp[p].client_date.year,tp[p].client_date.mon,tp[p].client_date.day);
			gotoxy(3, 15); printf("Client_totaldays:%d",tp[p].client_totaldays);
			gotoxy(3, 16); printf("Client_ap:%d",tp[p].client_ap);
			gotoxy(3, 17); printf("------------------------------------------------------");
			gotoxy(3, 18); printf("press any key to return");
			getchar(); getchar();
		}
		else
		{
			gotoxy(3, 8); printf("====>Not find this room!\n");
			getchar(); getchar();
		}
	}
	else if (select == 2)//按图书名查询
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing room name:",0);
		p = LocateRoom(tp, n, searchinput,"name");    /*用户选择2，通过名字查找，即在name字段中查找*/
		if (p!=-1)
		{
			gotoxy(3, 8); printf("------------------------------------------------------");
			gotoxy(3, 9); printf("Room Number:%s", tp[p].num);
			gotoxy(3, 10); printf("Room  Price:%d", tp[p].price);
			gotoxy(3, 11); printf("Room  Empty_flag(1:Empty):%d", tp[p].empty_flag);
			gotoxy(3, 12); printf("Client_name:%s", tp[p].client_name);
			gotoxy(3, 13); printf("Client_ic:%s", tp[p].client_ic);
			gotoxy(3, 14); printf("Client_date,%d-%d-%d", tp[p].client_date.year, tp[p].client_date.mon, tp[p].client_date.day);
			gotoxy(3, 15); printf("Client_totaldays:%d", tp[p].client_totaldays);
			gotoxy(3, 16); printf("Client_ap:%d", tp[p].client_ap);
			gotoxy(3, 17); printf("------------------------------------------------------");
			gotoxy(3, 18); printf("press any key to return");
			getchar(); getchar();
		}
		else
		{
			gotoxy(3, 8); printf("====>Not find this room!\n");
			getchar(); getchar();
		}
	}
	else
	{
		gotoxy(3, 8); printf("*****Error:input has wrong! press any key to continue******");
		getchar(); getchar();
	}
}
void QueryMember(Member_Link l)
{
	int select;//1:按图书编号查 2：按图书名查，其他：返回主界面 
	char searchinput[20];//保存用户输入的查询内容
	Member_Node* p;
	if (!l->next)//若链表为空
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n====>No Member Record!\n");
		getchar(); getchar();
		return;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	printf("=====>l Query by Member number		=====>2 Query by Member name");
	gotoxy(3, 6);
	printf("please choice[1,2]:");
	scanf("%d", &select);
	if (select == 1)//按读者编号查询
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing reader number:",0);
		p = LocateMember(l, searchinput, "num");
		//在l中查找图书编号为searchinput值的节点，并返回节点的指针
		if (p)//若p!=NULL
		{
			gotoxy(3, 8); printf("------------------------------------------------------");
			gotoxy(3, 9); printf("Member Number:%s", p->data.num);
			gotoxy(3, 10); printf("Member Name:%s", p->data.name);
			gotoxy(3, 11); printf("Member IC:", p->data.ic);
			gotoxy(3, 12); printf("Member Sex:%s", p->data.sex);
			gotoxy(3, 13); printf("Member Age:%d", p->data.age);
			gotoxy(3, 14); printf("Member Tele:%s", p->data.tele);
			gotoxy(3, 15); printf("------------------------------------------------------");
			gotoxy(3, 18); printf("press any key to return");
			getchar(); getchar();
		}
		else
		{
			gotoxy(3, 8); printf("====>Not find this Member!\n");
			getchar(); getchar();
		}
	}
	else if (select == 2)//按读者名查询
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing reader name:",0);
		p = LocateMember(l, searchinput, "name");
		if (p)
		{
			gotoxy(3, 8); printf("------------------------------------------------------");
			gotoxy(3, 9); printf("Member Number:%s", p->data.num);
			gotoxy(3, 10); printf("Member Name:%s", p->data.name);
			gotoxy(3, 11); printf("Member IC", p->data.ic);
			gotoxy(3, 12); printf("Member Sex:%s", p->data.sex);
			gotoxy(3, 13); printf("Member Age:%d", p->data.age);
			gotoxy(3, 14); printf("Member Tele:%s", p->data.tele);
			gotoxy(3, 15); printf("------------------------------------------------------");
			gotoxy(3, 18); printf("press any key to return");
			getchar(); getchar();
		}
		else
		{
			gotoxy(3, 8); printf("====>Not find this Member!\n");
			getchar(); getchar();
		}
	}
	else
	{
		gotoxy(3, 8); printf("*****Error:input has wrong! press any key to continue******");
		getchar(); getchar();
	}
}

//修改记录
void ModifyRoom(ROOM tp[],int n)
{
	int p = 0;
	char findmess[20];
	if (n<0)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n=====>No room record!\n");
		getchar();
		return;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	stringinput(findmess, 10, "input the existing room number；",0);//输入并检验该图书编号
	p = LocateRoom(tp, n,findmess, "num");//查询该节点
	if (p)//若p!=NULL,表明已经找到该节点
	{
		gotoxy(3, 6); printf("------------------------------------------------------");
		gotoxy(3, 7); printf("Room Number:%s", tp[p].num);
		gotoxy(3, 8); printf("Room  Price:%d", tp[p].price);
		gotoxy(3, 9); printf("Room  Empty_flag(1:Empty):%d", tp[p].empty_flag);
		gotoxy(3, 10); printf("Client_name:%s", tp[p].client_name);
		gotoxy(3, 11); printf("Client_ic:%s", tp[p].client_ic);
		gotoxy(3, 12); printf("Client_date:%d-%d-%d",tp[p].client_date.year, tp[p].client_date.mon, tp[p].client_date.day);
		gotoxy(3, 13); printf("Client_totaldays:%d", tp[p].client_totaldays);
		gotoxy(3, 14); printf("Client_ap:%d", tp[p].client_ap);
		gotoxy(3, 15); printf("------------------------------------------------------");
		getchar(); getchar();
		gotoxy(3, 16); printf("please modify room recorder:");
		gotoxy(3, 17); printf("Room Number:%s", tp[p].num);
		gotoxy(3, 18); printf("Room  Price:"); scanf("%d", &tp[p].price);
		if (tp[p].empty_flag == 0)
		{
			gotoxy(3,19); stringinput(tp[p].client_name, 15, "Client_name:",0);
			gotoxy(3, 20); stringinput(tp[p].client_ic, 20, "Client_ic",3);
			gotoxy(3, 21); printf("Client_Register_Date:%d-%d-%d", tp[p].client_date.year, tp[p].client_date.mon, tp[p].client_date.day);
			gotoxy(3, 22); printf("Client_totaldays:"); scanf("%d", &tp[p].client_totaldays);
			gotoxy(3, 23); printf("Client_ap(>=%d):", tp[p].price * tp[p].client_totaldays + 100); scanf("%d", &tp[p].client_ap);
			gotoxy(3, 24); printf("=====> Modify success!"); getchar(); getchar();
			saveflag = 1;
		}
		else {
			gotoxy(3, 19); printf("------------------------------------------------------");
			gotoxy(3, 20); printf("=====> Modify success!"); getchar(); getchar();

		}
		
	}
	else
	{
		gotoxy(3, 6); printf("=====>Not find this room!\n"); getchar(); getchar();
	}

}
void ModifyMember(Member_Link l)
{
	Member_Node* p;
	char findmess[20];
	int temp;
	if (!l->next)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n=====>No Reader record!\n");
		getchar();
		return;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	stringinput(findmess, 10, "input the existing Reader number；",0);//输入并检验该读者编号
	p = LocateMember(l, findmess, "num");//查询该节点
	if (p)//若p!=NULL,表明已经找到该节点
	{
		gotoxy(3, 6); printf("------------------------------------------------------");
		gotoxy(3, 9); printf("Member Number:%s", p->data.num);
		gotoxy(3, 10); printf("Member Name:%s", p->data.name);
		gotoxy(3, 11); printf("Member Sex:%s", p->data.sex);
		gotoxy(3, 12); printf("Member Age:%d", p->data.age);
		gotoxy(3, 13); printf("Member Tele:%s", p->data.tele);
		gotoxy(3, 14); printf("------------------------------------------------------");
		gotoxy(3, 15); printf("please modify Member recorder:");
		gotoxy(3, 16); stringinput(p->data.name, 15, "Member Name:",0);
		gotoxy(3, 17); stringinput(p->data.sex, 15, "Member Sex:",1);
		gotoxy(3, 18); printf("Member Age:"); scanf("%d", &temp); p->data.age = temp;
		gotoxy(3, 19); stringinput(p->data.tele, 11, "Member Tele:",2);
		gotoxy(3, 20); printf("------------------------------------------------------");
		gotoxy(3, 21); printf("=====>modify success!"); getchar(); getchar();
		saveflag = 1;
	}
	else
	{
		gotoxy(3, 6); printf("=====>Not find this Member!\n"); getchar(); getchar();

	}
}

//排序图书记录
void SortRoom(ROOM tp[],int n) //利用直接选择排序法实现按客房价格字段的升序排序，从低到高
{
	int i = 0, j = 0, k = 0, flag = 0;
	int x, y;//保存当前光标所在位置的坐标值
	ROOM newinfo;
	ROOM* lll;
	system("cls");
	if (n<=0)
	{
		system("cls"); 
		mainmenu();
		gotoxy(3, 5);
		printf("=====>Not roomrecord!");
		getchar();
		return;
	}
	//显示排序前的所有记录
	system("cls");
	mainmenu();
	gotoxy(3, 4);
	printf(HEADER1);
	gotoxy(3, 4);
	x = wherex(); y = wherey(); k = 0; i = 0;
	while (i<n)
	{
		k++;
		gotoxy(x,k+y);//换行
		lll = &tp[i];
		printf(FORMAT1, DATA1);//见头部宏定义 
		i++;
	}	
	getchar(); getchar();
	gotoxy(3, y + i+2);
	y=y + i+2;
	printf("=====>sort by price..............");
	//排序
	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1; j++)
			if ((tp[j].price > tp[j + 1].price))
			{
				flag = 1;
				strcpy(newinfo.num, tp[j].num);
				newinfo.price = tp[j].price;
				newinfo.empty_flag = tp[j].empty_flag;
				strcpy(newinfo.client_name, tp[j].client_name);
				strcpy(newinfo.client_ic, tp[j].client_ic);
				newinfo.client_date.year = tp[j].client_date.year;
				newinfo.client_date.mon = tp[j].client_date.mon;
				newinfo.client_date.day = tp[j].client_date.day;
				newinfo.client_totaldays = tp[j].client_totaldays;
				newinfo.client_ap = tp[j].client_ap;
				strcpy(tp[j].num, tp[j + 1].num);
				tp[j].price=tp[j + 1].price;
				tp[j].empty_flag=tp[j + 1].empty_flag;
				strcpy(tp[j].client_name, tp[j + 1].client_name);
				strcpy(tp[j].client_ic, tp[j + 1].client_ic);;
				tp[j].client_date.year = tp[j + 1].client_date.year;
				tp[j].client_date.mon = tp[j + 1].client_date.mon;
				tp[j].client_date.mon = tp[j + 1].client_date.mon;
				tp[j].client_totaldays = tp[j + 1].client_totaldays;
				tp[j].client_ap = tp[j + 1].client_ap;
				strcpy(tp[j + 1].num, newinfo.num);
				tp[j + 1].price = newinfo.price;
				tp[j + 1].empty_flag = newinfo.empty_flag;
				strcpy(tp[j + 1].client_name, newinfo.client_name);
				strcpy(tp[j + 1].client_ic, newinfo.client_ic);
				tp[j + 1].client_date.year = newinfo.client_date.year;
				tp[j + 1].client_date.mon = newinfo.client_date.mon;
				tp[j + 1].client_date.mon = newinfo.client_date.day;
				tp[j + 1].client_totaldays = newinfo.client_totaldays;
				tp[j + 1].client_ap = newinfo.client_ap;
			}
		if (flag == 0) break;

	}
k=0;i=0;
	while (i<n)
	{
		k++;
		gotoxy(3,y+k+1);
		lll = &tp[i];
		printf(FORMAT1, DATA1);
		i++;
	};
	saveflag = 1;
	gotoxy(3,y+k+3);
	printf("=====>sort complete!");
	getchar(); getchar();
	return;
}
void SortMember(Member_Link l)
{
	Member_Link lll;//临时指针
	Member_Node* p, * q, * r, * s, * h1;//临时指针
	int x, y;//保存当前光标所在位置的坐标值
	int i = 0;
	if (l->next == NULL)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("\n=====>Not Member record!");
		getchar();
		return;
	}
	h1 = p = (Member_Node*)malloc(sizeof(Member_Node));//用于创建新的头节点
	if (!p)
	{
		gotoxy(3, 5);
		printf("allocate memory failure");//如果没有申请到打印信息
		return;//返回主界面 
	}
	//显示排序前的所有记录
	system("cls");
	mainmenu();
	gotoxy(3, 4);
	printf(HEADER2);
	lll = l->next;
	x = wherex(); y = wherey(); i = 0;
	while (lll != NULL)//当p不为空时，进行下列操作
	{
		gotoxy(3, i + y);//换行
		i++;
		printf(FORMAT2, DATA2);//见头部宏定义 
		lll = lll->next;//指针后移 
	}
	getchar(); getchar();
	gotoxy(3, y + i+1);y=y+i+1;
	printf("=====>sort by number..............\n");
	//排序
	p->next = l->next;//l所指节点为不存有任何记录的节点，下一个节点才有图书记录
	while (p->next != NULL)//外层循环决定待排序位置
	{
		q = p->next;
		r = p;
		while (q->next != NULL)//内部循环找到当前关键字最小节点
		{
			if (strlen(q->next->data.num) < strlen(r->next->data.num))
			{
				r = q; q = q->next;
			}//移至下一个节点 
			else if (strlen(q->next->data.num) == strlen(r->next->data.num) && strcmp(q->next->data.num, r->next->data.num) < 0)
			{
				r = q; q = q->next;
			}//移至下一个节点 
			else q = q->next;


		}
		if (r != p)//表示原来的第一个节点不是关键字最小的节点，改变指针关系，将关键字最小的节点与本轮循环的首节点进行位置互换
		{
			s = r->next;//s指向最小节点
			r->next = s->next;//r的指针域指向最小节点的下一个节点
			s->next = p->next;//s的指针域指向当前p指针所指的下一个节点
			p->next = s;//p的指针域指向本次循环结束后关键字最小的节点 
		}
		p = p->next;//移至下一个节点 
	}
	l->next = h1->next;//将排序好的链表首节点地址赋给原来链表的指针域
	lll = l->next;
    i=0;
	while (lll != NULL)//当p不为空时，进行下列操作
	{
		i++;
		gotoxy(3, y+i+1); 
		printf(FORMAT2, DATA2);
		lll = lll->next;//指针后移 
	}
	free(h1);
	saveflag = 1;
	gotoxy(3, y+i+3);
	printf("=====>sort complete!");
	getchar(); getchar();
	return;
}

//统计记录
int isLeapyear(int year) /*判断是否是闰年*/
{
	if (year % 4 == 0 && year % 100 || year % 400 == 0)
		return 1;
	else
		return 0;
}
void CountRoom(ROOM tp[], int n)
{
	int i = 0, j = 0, k = 0, year = 0, month = 0, leapFlag = 0;
	int totalday = 0;
	int count500 = 0, count200 = 0, count0 = 0;
	int count500e = 0, count200e = 0, count0e = 0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	char roomnum[300];
	char dot[4];

	time_t timep;
	struct tm* p;
	time(&timep);
    p=gmtime(&timep);
	system("cls");
	if (n <= 0)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("=====>Not room record!");
		getchar();
		return;
	}
	/*以当前系统时间重新赋值*/
	currentYear = 1900 + p->tm_year;
	currentMonth = 1 + p->tm_mon;
	currentDay = p->tm_mday;
	int current_sec = p->tm_sec; /*获取当前秒*/
	int current_min = p->tm_min;/*获取当前分*/
	int current_hour = 8 + p->tm_hour;/*获取当前时*/
	i = 0;
	while (i < n) /*统计各档次客房的总数*/
	{
		if (tp[i].price >= 500) { count500++; i++; continue; }
		if (tp[i].price >= 200) { count200++; i++; continue; }
		if (tp[i].price < 200) { count0++; i++; continue; }
	}
	i = 0;
	while (i < n)/*统计各档次客房的总数空闲值*/
	{
		if (tp[i].price >= 500 && tp[i].empty_flag == 1) { count500e++; i++; continue; }
		if (tp[i].price >= 200 && tp[i].empty_flag == 1) { count200e++; i++; continue; }
		if (tp[i].price < 200 && tp[i].empty_flag == 1) { count0e++; i++; continue; }
		i++;
	}
	i = 0; strcpy(dot, ";"); strcpy(roomnum, " ");
	while (i < n)/*统计入住天数超期的客房号*/
	{
		if (tp[i].empty_flag == 0)
		{
			year = currentYear - tp[i].client_date.year;
			if (year != 0)
			{
				for (j = 2; j <= year; j++)
				{
					leapFlag = isLeapyear(tp[i].client_date.year + j - 1);/*判断是否是闰年*/
					if (leapFlag == 1)
						for (k = 1; k <= 12; k++) { totalday = totalday + b[k]; }
					else
						for (k = 1; k <= 12; k++) { totalday = totalday + a[k]; }
				}
				leapFlag = isLeapyear(tp[i].client_date.year);
				if (leapFlag == 1)
					for (k = 12; k <= tp[i].client_date.mon; k--) { totalday = totalday + b[k]; }
				else
					for (k = 12; k <= tp[i].client_date.mon; k--) { totalday = totalday + a[k]; }

				totalday = totalday - tp[i].client_date.day;
				leapFlag = isLeapyear(currentYear);
				if (leapFlag == 1)
					for (k = 1; k <= currentMonth; k++) { totalday = totalday + b[k]; }
				else
					for (k = 1; k <= currentMonth; k++) { totalday = totalday + a[k]; }
				totalday = totalday + tp[i].client_date.day;
			}
			else
			{
				month = currentMonth - tp[i].client_date.mon;
				if (month != 0)
				{
					for (j = 2; j <= month; j++)
					{
						leapFlag = isLeapyear(tp[i].client_date.year + j - 1);
						if (leapFlag == 1)
						{
							totalday = totalday + b[tp[i].client_date.mon + j - 1];
						}
						else
						{
							totalday = totalday + a[tp[i].client_date.mon + j - 1];
						}
					}
					leapFlag = isLeapyear(tp[i].client_date.year);
					if (leapFlag == 1)
					{
						totalday = totalday + b[tp[i].client_date.mon] - tp[i].client_date.day;
					}
					else
					{
						totalday = totalday + a[tp[i].client_date.mon] - tp[i].client_date.day;
					}
					totalday = totalday + currentDay;
				}
				else { totalday = currentDay - tp[i].client_date.day; }
			}
			if (totalday > tp[i].client_totaldays)
			{
				strcpy(roomnum, strcat(roomnum, tp[i].num)); strcat(roomnum, dot);
			}
		}
		i++;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5); printf("-----the statistics result of Room-----");
	gotoxy(3, 6); printf("Total number of rooms:%d", n);
	gotoxy(3, 7); printf("Total number of price>=500:%d empty:%d", count500, count500e);
	gotoxy(3, 8); printf("Total number of 200<=price<500:%d empty:%d", count200, count200e);
	gotoxy(3, 9); printf("Total number of price<200:%d empty:%d", count0, count0e);
	gotoxy(3,10);printf("List of room number exceeding the prospective day:%s",roomnum);
	gotoxy(3, 11); printf("---------------------------------------");
	getchar(); getchar();
}
void CountMember(Member_Link l)//总数量、男性顾客数量、女性顾客数量
{
	Member_Node* r = l->next;
	int countc = 0, countm = 0, countf = 0, counte = 0;
	char Readername[15];
	if (!r)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		printf("=====>Not Member record!");
		getchar();
		return;
	}
	strcpy(Readername, r->data.name);
	while (r)
	{
		countc++;//统计住客数量
		if (strcmp(r->data.sex, "男") == 0) countm++;//统计男性
		else countf++;//统计女性数量
		r = r->next;
	}
	system("cls");
	mainmenu();
	gotoxy(3, 5);
	printf("-----------------------the statistics result--------------------------");
	gotoxy(3, 6); printf("Total number of Members:%d", countc);
	gotoxy(3, 7); printf("Total number of male Members:%d", countm);
	gotoxy(3, 8); printf("Total number of female Members:%d", countf);
	gotoxy(3, 10); printf("-------------------------------------------------------------------");
	getchar(); getchar();
}


//登记入住
void RegisterRoom(ROOM tp[], int n, Member_Link ll)
{
	Member_Node* p2;  /*定义会员记录指针变量*/
	ROOM* lll;
	char membernum[15], roomnum[15], ch;
	int flag = 0, i, x, y, k, client_price, staydays, ad_pay, suffix = 0, ans = 0;
	p2 = ll->next;
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);

	system("cls");
	mainmenu();
	gotoxy(3, 5);
	printf("please input your upper limit of room price:");/*输入想要房间的价位*/
	scanf("%d", &client_price);
	gotoxy(3, 5);
	printf(HEADER1);
	gotoxy(3, 6);
	x = wherex(); y = wherey();
	k = 0; i = 0;
	while (i < n)
	{
		if (tp[i].empty_flag == 1 && tp[i].price <= client_price)\
		{
			k++;
			gotoxy(3, k + y);
			lll = &tp[i];
			printf(FORMAT1, DATA1);
			flag = 1;
			suffix = i;/*保存最后一条符合记录的客房记录的下标值，准备分配给客户*/
		}
		i++;
	}
	if (flag == 0)
	{
		system("cls");
		mainmenu();
		gotoxy(3, 5);
		cprintf("=====>Sorry ,there is no empty room your wanted!");
		getchar(); getchar();
		return;
	}
	getchar();
	gotoxy(3, y + k + 2); x = wherex(); y = wherey();
	flag = 0;
	while (1)
	{
		if (!ans)
		{
			cprintf("=====>Are you the member of hotel?(y/n):");
		}
		else
		{
			gotoxy(3, y - 1);insline1();
			gotoxy(3, y - 1);cprintf("=====>Are you the member of hotel?(Please input y/n):");
			ans--;
		}
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y')
		{
			gotoxy(3, y + 1);
			stringinput(membernum, 3, "Member Number:", 4);
			while (p2)/*查询该会员编号是否已经存在，若不存在则不允许执行会员登记住宿操作*/
			{
				if (strcmp(p2->data.num, membernum) == 0)
				{
					flag = 1;
					break;
				}
				p2 = p2->next;
			}
			if (flag == 0)
			{
				gotoxy(3, y + 2);
				printf("The Member Num %s is not existing!", membernum);
				getchar(); getchar();
				return;
			}
			gotoxy(3, y + 2);
			printf("The days of your stay:");
			scanf("%d", &staydays);
			gotoxy(3, y + 3);
			printf("Please input advance payment[>=%d]:", tp[suffix].price * staydays + 100);
			scanf("%d", &ad_pay);
			getchar(); getchar();
			/*******************将会员资料填入客房记录中**********************/
			tp[suffix].empty_flag = 0;
			strcpy(tp[suffix].client_name, p2->data.name);
			strcpy(tp[suffix].client_ic, p2->data.ic);
			tp[suffix].client_totaldays = staydays;
			tp[suffix].client_ap = ad_pay;
			/********************处理日期***************************/
			currentYear = p->tm_year+1900;
			currentMonth = p->tm_mon+1;
			currentDay = p->tm_mday;
			tp[suffix].client_date.year = currentYear;
			tp[suffix].client_date.mon = currentMonth;
			tp[suffix].client_date.day = currentDay;
			saveflag = 1;
			gotoxy(3, y + 4);
			printf("Register OK! Room %s is distributed to %s", tp[suffix].num, tp[suffix].client_name);
			getchar(); getchar();
			break;
		}
		else if (ch == 'n' || ch == 'N')/**********************非会员*******************/
		{
			gotoxy(3, y + 1); stringinput(tp[suffix].client_name, 15, "Client_name:", 0);
			gotoxy(3, y + 2); stringinput(tp[suffix].client_ic, 18, "Client_ic:", 3);
			gotoxy(3, y + 3); printf("The days of your stay:"); scanf("%d", &staydays);
			gotoxy(3, y + 4); printf("Please input advance payment[>=%d]:", tp[suffix].price * staydays + 100); scanf("%d", &ad_pay);
			tp[suffix].empty_flag = 0;
			tp[suffix].client_totaldays = staydays;
			tp[suffix].client_ap = ad_pay;
			/******************处理日期********************/
			currentYear = p->tm_year+1900;
			currentMonth = p->tm_mon+1;
			currentDay = p->tm_mday;
			tp[suffix].client_date.year = currentYear;
			tp[suffix].client_date.mon = currentMonth;
			tp[suffix].client_date.day = currentDay;
			saveflag = 1;
			gotoxy(3, y + 6);
			printf("Register OK! Room %s is distributed to %s", tp[suffix].num, tp[suffix].client_name);
			getchar(); getchar();
			break;
		}
		else
		{
			ans++;
		}
	}
	return;
}
//退房
void ReturnRoom(ROOM tp[], int n, Member_Link ll)
{
	Member_Node* p2;
	ROOM* lll;
	char membernum[15], roomnum[15], clientname[15], ch;
	int flag = 0, i, x, y, dtaydays, suffix = -1,ans=0;
	float return_pay;
	p2 = ll->next;
	system("cls");
	mainmenu();
	gotoxy(3, 5); printf("Please input your number of returned room:");
	scanf("%s", &roomnum);
	i = 0;
	while (i < n)
	{
		if (strcmp(tp[i].num, roomnum) == 0)
		{
			suffix = i; break;
		}
		i++;
	}
	if (suffix == -1)
	{
		gotoxy(3, 6); printf("Room %s is not existing!", roomnum); getchar(); getchar();
		return;
	}
	if (tp[suffix].empty_flag == 1)
	{
		gotoxy(3, 6); printf("Room %s is empty!"); getchar(); getchar();
		return;
	}
	getchar(); gotoxy(3, 6);
	y = wherey();
	flag = 0;
	while (1)
	{
		if (!ans)
		{
			cprintf("=====>Are you the member of hotel?(y/n):");
		}
		else
		{
			gotoxy(3, y - 1); insline1();
			gotoxy(3, y - 1); cprintf("=====>Are you the member of hotel?(Please input y/n):");
			ans--;
		}
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y')
		{
			gotoxy(3, y + 1);
			stringinput(membernum, 3, "Member Number:", 4);
			while (p2)/*查询该会员是否已经存在，若不存在则不允许执行会员退房操作*/
			{
				if (strcmp(p2->data.num, membernum) == 0)
				{
					flag = 1;
					break;
				}
				p2 = p2->next;
			}
			if (flag == 0)
			{
				gotoxy(3, y + 2); printf("The Member %s is not existing!", membernum);
				getchar(); getchar(); return;
			}
			/*结账退房*/
			gotoxy(3, y + 2);
			printf("The days of your stay:%d,price:%d", tp[suffix].client_totaldays, tp[suffix].price);
			gotoxy(3, y + 3);
			return_pay = tp[suffix].client_ap - tp[suffix].client_totaldays * tp[suffix].price * 0.9;/*会员九折优惠*/
			printf("Advance payment:%d,Return payment:%.2f", tp[suffix].client_ap, return_pay);
			getchar(); getchar();
			strcpy(clientname, tp[suffix].client_name);
			break;
		}
		else if (ch == 'n' || ch == 'N')/*****************非会员***********************/
		{
			/*结账退房*/
			gotoxy(3, y + 2);
			printf("The days of your stay:%d,price:%d", tp[suffix].client_totaldays, tp[suffix].price);
			gotoxy(3, y + 3);
			return_pay = tp[suffix].client_ap - tp[suffix].client_totaldays * tp[suffix].price;
			printf("Advance payment:%d,Return payment:%.2f", tp[suffix].client_ap, return_pay);
			getchar(); getchar();
			strcpy(clientname, tp[suffix].client_name);
			getchar(); getchar();
			break;
		}
		else
		{
			ans++;
		}
	}
	/*****************将客房记录置空******************/
	tp[suffix].empty_flag = 1;
	strcpy(tp[suffix].client_name, " ");
	strcpy(tp[suffix].client_ic, " ");
	tp[suffix].client_totaldays = 0;
	tp[suffix].client_ap = 0;
	/*****************处理日期***********************/
	tp[suffix].client_date.year = 0;
	tp[suffix].client_date.mon = 0;
	tp[suffix].client_date.day = 0;
	saveflag = 1;
	gotoxy(3, y + 4); printf("Room %s is returned bu %s successfully!", tp[suffix].num, clientname);
	getchar(); getchar();
	return;
}
