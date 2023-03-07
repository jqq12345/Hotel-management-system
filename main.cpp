
# include "additional.h"

#pragma warning(disable:4996)


int main1()
{
	drawmain2();
	return 0;
}
int main()
{
	ROOM GR[N];  //����ͷ��ṹ����
	Member_Link ll; //�����Ա����ָ��
	FILE* fp1, * fp2; //fp1Ϊָ��ͷ��ļ�ָ�룬fp2Ϊָ���Ա���ļ�ָ��
	Member_Node* p2, * r2; //�����Ա��¼ָ�����
	int A, B, i;
	char ch,a; //���棨y,Y,n,N��
	int count1 = 0, count2 = 0; //�ֱ𱣴�ͷ��ļ����߻�Ա�ļ��еļ�¼����
    //modeset(80, 35);  //��ʾϵͳ������
	drawmain();
	/****************************�򿪿ͷ��ļ�ROOM��������������д洢************************************************/
	fp1 = fopen("E:\\room", "at+");//��׷�ӷ�ʽ��һ���������ļ����ɶ���д�������ļ������ڣ��ᴴ�����ļ�
	if (fp1 == NULL)
	{
		system("cls"); mainmenu(); gotoxy(2, 3);
		printf("\n=====>can not open file1!\n");
		exit(0);
	}
	while (!feof(fp1))
	{
		if (fread(&GR[count1], sizeof(ROOM), 1, fp1) == 1)//һ�δ��ļ��ж���һ���ͷ���¼
		{
			count1++;
		}
	}fclose(fp1); //�ر��ļ�
	/****************************�򿪿ͷ��ļ�MEMBER��������������д洢************************************************/
	ll = (Member_Node*)malloc(sizeof(Member_Node));
	if (!ll)
	{
		system("cls"); mainmenu(); gotoxy(2, 3); 
		printf("\n allocate memory failure");//���û�����뵽��ӡ��ʾ��Ϣ 
		return 0;//���������� 
	}
	ll->next = NULL;
	r2 = ll;
	fp2 = fopen("E:\\member", "at+");//��׷�ӷ�ʽ��һ���������ļ����ɶ���д�������ļ������ڣ��ᴴ�����ļ�
	if (fp2 == NULL)
	{
		system("cls"); mainmenu(); gotoxy(2, 3);
		printf("\n=====>can not open file2!\n");
		exit(0);
	}
	while (!feof(fp2))  /*feof()����������ϵ��ļ������������ļ��������򷵻ط����ֵ�����򷵻���*/
	{
		p2 = (Member_Node*)malloc(sizeof(Member_Node));
		if (!p2)
		{
			system("cls"); mainmenu(); gotoxy(2, 3);
			printf("memory malloc failure!\n");//û������ɹ� 
			exit(0); //�˳� 
		}
		if (fread(p2, sizeof(Member_Node), 1, fp2) == 1)//һ�δ��ļ��ж�ȡһ��ͼ���¼ 
		{
			p2->next = NULL;
			r2->next = p2;
			r2 = p2;//rָ�������һ��λ�� 
			count2++;
		}
	}
	fclose(fp2);//�ر��ļ�
	p2 = r2;
	while (1)
	{
		B = menuctrl();
		switch (B)
		{
		case ADD_ROOM:count1 = AddRoom(GR, count1);  break;//����ͼ���¼
		case QUERY_ROOM:QueryRoom(GR, count1); break;//ɾ��ͼ���¼
		case MODIFY_ROOM:ModifyRoom(GR,count1); break;//�޸�ͼ����¼
		case DEL_ROOM:count1=DelRoom(GR,count1); break;//ɾ��ͼ���¼
		case SORT_ROOM:SortRoom(GR,count1); break;//����ͼ���¼
		case COUNT_ROOM:CountRoom(GR,count1); break;//ͳ��ͼ���¼
		case ADD_MEMBER:AddMember(ll); break;//���Ӷ��߼�¼
		case QUERY_MEMBER:QueryMember(ll); break;//��ѯ���߼�¼
		case MODIFY_MEMBER:ModifyMember(ll); break;//�޸Ķ��߼�¼
		case DEL_MEMBER:DelMember(ll); break;//ɾ�����߼�¼
		case SORT_MEMBER:SortMember(ll); break;//������߼�¼
		case COUNT_MEMBER:CountMember(ll); break;//ͳ�ƶ��߼�¼
		case REGISTER_ROOM:RegisterRoom(GR,count1,ll); break;//����
		case RETURN_ROOM:ReturnRoom(GR, count1,ll); break;//����
		case EXIT: //�˳�ϵͳ		
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
	   if(flag==1&&strcmp(n,"��")&&strcmp(n,"Ů"))
	   {
		   		x = wherex();
			    y = wherey();
				gotoxy(x + 2, y-1); printf("please input '��' or 'Ů'\n");i++;getchar();getchar();
				continue;
	   }
		if (strlen(n) > lens)
		{
			x = wherex();
			y = wherey();
			gotoxy(x + 2, y-1); printf("exceed the required length!\n");i++;getchar();getchar();
		}/*���г���У�飬�������len���ȣ���������*/
	} while (strlen(n)>lens||((flag==3||flag==2)&&strlen(n)!=lens)||flag==1&&strcmp(n,"��")&&strcmp(n,"Ů")||flag==4&&strlen(n)!=lens&&strcmp(n,"0"));
	strcpy(t, n);/*��������ַ������Ƶ��ַ���t��*/
}
int LocateRoom(ROOM tp[],int n, char findmess[], char nameornum[])//ͼ�鶨λ 
/**********************************************************************************
���ã����ڶ�λ�����з���Ҫ��Ľڵ㣬������ָ��ýڵ��ָ��
������findmess[]����Ҫ���ҵľ������ݣ�nameornum[]���水ʲô���ң�
************************************************************************************/
{
	int i=0;
	if (strcmp(nameornum, "num") == 0)//��ͼ���Ų�ѯ
	{
		while (i<n)
		{
			if (strcmp(tp[i].num, findmess) == 0)//���ҵ�findmessֵ��ͼ����
				return i;
			i++;
		}
	}
	else if (strcmp(nameornum, "name") == 0)//��ͼ������ѯ
	{
		while (i<n)
		{
			if (strcmp(tp[i].client_name, findmess) == 0)//���ҵ�findmessֵ��ͼ����
				return i;
			i++;
		}
	}
	return -1;//��δ�ҵ�������һ����ָ�� 
}
Member_Node* LocateMember(Member_Link l, char findmess[], char nameornum[])//��Ա��λ 
{
    Member_Node* r;
	if (strcmp(nameornum, "num") == 0)//����Ա��Ų�ѯ
	{
		r = l->next;
		while (r)
		{
			if (strcmp(r->data.num, findmess) == 0)//���ҵ�findmessֵ�Ļ�Ա���
				return r;
			r = r->next;
		}
	}
	else if (strcmp(nameornum, "name") == 0)//����Ա������ѯ
	{
		r = l->next;
		while (r)
		{
			if (strcmp(r->data.name, findmess) == 0)//���ҵ�findmessֵ�Ļ�Ա
				return r;
			r = r->next;
		}
	}
	return 0;//��δ�ҵ�������һ����ָ�� 
}

//��Ӽ�¼
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
		/*���ͷ���¼��ֵ*/
		strcpy(tp[n].num, num); /*���ַ���num���Ƶ�tp[n].num��*/
		gotoxy(3,6); printf("Room Price:"); scanf("%d", &tp[n].price);
		tp[n].empty_flag = 1; /*�ͷ����б�ǣ�1��ʾ���У�0��ʾδ����*/
		strcpy(tp[n].client_name, ""); /*�˿�����*/
		strcpy(tp[n].client_ic,""); /*�˿����֤��*/
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
	Member_Node* p, * r, * s;//ʵ����Ӳ�������ʱ�Ľṹ��ָ�����
	char ch, flag = 0, num[10];
	int temp;
	r = l;
	s = l->next;
	system("cls");
	while (r->next != NULL)
		r = r->next;//��ָ��������������ĩβ��׼����Ӽ�¼
	while (1)//һ�ο����������¼��ֱ�������Ա���Ϊ0�ļ�¼�����Ӳ���
	{
		while (1)//�����Ա��ţ���֤�ñ��û�б�ʹ�ã���������Ϊ0�����˳���Ӽ�¼����
		{
			system("cls");
			mainmenu();
			gotoxy(3, 4);
			stringinput(num, 3, "input member number(press '0' return menu):",4);//��ʽ�������Ա��Ų�����
			flag = 0;
			if (strcmp(num, "0") == 0)//����Ϊ0�����˳���Ӳ���������������
			{
				return;
			}
			s = l->next;
			while (s)//��ѯ�û�Ա����Ƿ��Ѿ����ڣ���������Ҫ����������һ��δ��ռ�õı��
			{
				if (strcmp(s->data.num, num) == 0)
				{
					flag = 1;
					break;
				}
				s = s->next;
			}
			if (flag == 1)//��ʾ�û��Ƿ���������
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
		p = (Member_Node*)malloc(sizeof(Member_Node));//�����ڴ�ռ�
		if (!p)
		{
			printf("\n allocate memory failure ");//��û�����뵽����ӡ��ʾ��Ϣ
			return;
		}
		//��ͼ���¼��ֵ
		strcpy(p->data.num, num);//���ַ���num���Ƶ�p->data.num��
		gotoxy(3, 5); stringinput(p->data.name, 15, "Member Name:",0);
		gotoxy(3, 6); stringinput(p->data.sex, 15, "Member Sex:",1);
		gotoxy(3, 7); stringinput(p->data.tele, 11, "Member Tele:",2);
		gotoxy(3, 8); printf("Member Age:"); scanf("%d", &temp);
		p->data.age = temp;
		gotoxy(3, 9); stringinput(p->data.ic, 18, "Member ic:",3);
		gotoxy(3, 10); printf(">>>>press any key to start next record!");
		getchar(); getchar();
		p->next = NULL;//�������������β�����
		r->next = p;//���½��Ľ���������β����
		r = p;
		saveflag = 1;
	}
	return;
}

//ɾ����¼
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
		for (i = p + 1; i < n; i++) //ɾ���˼�¼�������¼��ǰ��
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
			r->next = p->next;//��p��ָ�ڵ��������ȥ�� 
			free(p);//�ͷ��ڴ�ռ�
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
	else if (sel == 2)//�Ȱ��˿�����ѯ���ü�¼���ڵĽڵ�
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

//�����¼
void SaveRoom(ROOM tp[],int n )
{
	FILE* fp;
	int i=0;
	int count = 0;
	mainmenu();
	fp = fopen("E:\\room", "wt");//��ֻд��ʽ�򿪶������ļ�
	if (fp == NULL)//���ļ�ʧ��
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
		if (fwrite(&tp[i], sizeof(ROOM), 1, fp) == 1)//ÿ��дһ����¼��һ���ڵ���Ϣ���ļ�
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
	fclose(fp);//�ر�book�ļ� 

}
void SaveMember(Member_Link l)
{
	FILE* fp;
	Member_Node* p;
	int count = 0;
	mainmenu();
	fp = fopen("E:\\member", "wb");//��ֻд��ʽ�򿪶������ļ�
	if (fp == NULL)//���ļ�ʧ��
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
		if (fwrite(p, sizeof(Member_Node), 1, fp) == 1)//ÿ��дһ����¼��һ���ڵ���Ϣ���ļ�
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
	fclose(fp);//�ر�reader�ļ� 
}

//��ѯ��¼
void QueryRoom(ROOM tp[],int n)//��ͼ���Ż�ͼ��������ѯ
{
	int select;//1:���ͷ���Ų� 2�����˿����飬���������������� 
	char searchinput[20];//�����û�����Ĳ�ѯ����
    int  p=0;
	if (n<0)//������Ϊ��
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
	if (select == 1)//���ͷ���Ų�ѯ
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing room number:",0);
		p = LocateRoom(tp,n,searchinput,"num");
		//��l�в��ҿͷ����Ϊsearchinputֵ�Ľڵ㣬�����ؽڵ��ָ��
		if (p!=-1)//��p!=NULL
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
	else if (select == 2)//��ͼ������ѯ
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing room name:",0);
		p = LocateRoom(tp, n, searchinput,"name");    /*�û�ѡ��2��ͨ�����ֲ��ң�����name�ֶ��в���*/
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
	int select;//1:��ͼ���Ų� 2����ͼ�����飬���������������� 
	char searchinput[20];//�����û�����Ĳ�ѯ����
	Member_Node* p;
	if (!l->next)//������Ϊ��
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
	if (select == 1)//�����߱�Ų�ѯ
	{
		gotoxy(3, 7);
		stringinput(searchinput, 15, "input the existing reader number:",0);
		p = LocateMember(l, searchinput, "num");
		//��l�в���ͼ����Ϊsearchinputֵ�Ľڵ㣬�����ؽڵ��ָ��
		if (p)//��p!=NULL
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
	else if (select == 2)//����������ѯ
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

//�޸ļ�¼
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
	stringinput(findmess, 10, "input the existing room number��",0);//���벢�����ͼ����
	p = LocateRoom(tp, n,findmess, "num");//��ѯ�ýڵ�
	if (p)//��p!=NULL,�����Ѿ��ҵ��ýڵ�
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
	stringinput(findmess, 10, "input the existing Reader number��",0);//���벢����ö��߱��
	p = LocateMember(l, findmess, "num");//��ѯ�ýڵ�
	if (p)//��p!=NULL,�����Ѿ��ҵ��ýڵ�
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

//����ͼ���¼
void SortRoom(ROOM tp[],int n) //����ֱ��ѡ������ʵ�ְ��ͷ��۸��ֶε��������򣬴ӵ͵���
{
	int i = 0, j = 0, k = 0, flag = 0;
	int x, y;//���浱ǰ�������λ�õ�����ֵ
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
	//��ʾ����ǰ�����м�¼
	system("cls");
	mainmenu();
	gotoxy(3, 4);
	printf(HEADER1);
	gotoxy(3, 4);
	x = wherex(); y = wherey(); k = 0; i = 0;
	while (i<n)
	{
		k++;
		gotoxy(x,k+y);//����
		lll = &tp[i];
		printf(FORMAT1, DATA1);//��ͷ���궨�� 
		i++;
	}	
	getchar(); getchar();
	gotoxy(3, y + i+2);
	y=y + i+2;
	printf("=====>sort by price..............");
	//����
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
	Member_Link lll;//��ʱָ��
	Member_Node* p, * q, * r, * s, * h1;//��ʱָ��
	int x, y;//���浱ǰ�������λ�õ�����ֵ
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
	h1 = p = (Member_Node*)malloc(sizeof(Member_Node));//���ڴ����µ�ͷ�ڵ�
	if (!p)
	{
		gotoxy(3, 5);
		printf("allocate memory failure");//���û�����뵽��ӡ��Ϣ
		return;//���������� 
	}
	//��ʾ����ǰ�����м�¼
	system("cls");
	mainmenu();
	gotoxy(3, 4);
	printf(HEADER2);
	lll = l->next;
	x = wherex(); y = wherey(); i = 0;
	while (lll != NULL)//��p��Ϊ��ʱ���������в���
	{
		gotoxy(3, i + y);//����
		i++;
		printf(FORMAT2, DATA2);//��ͷ���궨�� 
		lll = lll->next;//ָ����� 
	}
	getchar(); getchar();
	gotoxy(3, y + i+1);y=y+i+1;
	printf("=====>sort by number..............\n");
	//����
	p->next = l->next;//l��ָ�ڵ�Ϊ�������κμ�¼�Ľڵ㣬��һ���ڵ����ͼ���¼
	while (p->next != NULL)//���ѭ������������λ��
	{
		q = p->next;
		r = p;
		while (q->next != NULL)//�ڲ�ѭ���ҵ���ǰ�ؼ�����С�ڵ�
		{
			if (strlen(q->next->data.num) < strlen(r->next->data.num))
			{
				r = q; q = q->next;
			}//������һ���ڵ� 
			else if (strlen(q->next->data.num) == strlen(r->next->data.num) && strcmp(q->next->data.num, r->next->data.num) < 0)
			{
				r = q; q = q->next;
			}//������һ���ڵ� 
			else q = q->next;


		}
		if (r != p)//��ʾԭ���ĵ�һ���ڵ㲻�ǹؼ�����С�Ľڵ㣬�ı�ָ���ϵ�����ؼ�����С�Ľڵ��뱾��ѭ�����׽ڵ����λ�û���
		{
			s = r->next;//sָ����С�ڵ�
			r->next = s->next;//r��ָ����ָ����С�ڵ����һ���ڵ�
			s->next = p->next;//s��ָ����ָ��ǰpָ����ָ����һ���ڵ�
			p->next = s;//p��ָ����ָ�򱾴�ѭ��������ؼ�����С�Ľڵ� 
		}
		p = p->next;//������һ���ڵ� 
	}
	l->next = h1->next;//������õ������׽ڵ��ַ����ԭ�������ָ����
	lll = l->next;
    i=0;
	while (lll != NULL)//��p��Ϊ��ʱ���������в���
	{
		i++;
		gotoxy(3, y+i+1); 
		printf(FORMAT2, DATA2);
		lll = lll->next;//ָ����� 
	}
	free(h1);
	saveflag = 1;
	gotoxy(3, y+i+3);
	printf("=====>sort complete!");
	getchar(); getchar();
	return;
}

//ͳ�Ƽ�¼
int isLeapyear(int year) /*�ж��Ƿ�������*/
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
	/*�Ե�ǰϵͳʱ�����¸�ֵ*/
	currentYear = 1900 + p->tm_year;
	currentMonth = 1 + p->tm_mon;
	currentDay = p->tm_mday;
	int current_sec = p->tm_sec; /*��ȡ��ǰ��*/
	int current_min = p->tm_min;/*��ȡ��ǰ��*/
	int current_hour = 8 + p->tm_hour;/*��ȡ��ǰʱ*/
	i = 0;
	while (i < n) /*ͳ�Ƹ����οͷ�������*/
	{
		if (tp[i].price >= 500) { count500++; i++; continue; }
		if (tp[i].price >= 200) { count200++; i++; continue; }
		if (tp[i].price < 200) { count0++; i++; continue; }
	}
	i = 0;
	while (i < n)/*ͳ�Ƹ����οͷ�����������ֵ*/
	{
		if (tp[i].price >= 500 && tp[i].empty_flag == 1) { count500e++; i++; continue; }
		if (tp[i].price >= 200 && tp[i].empty_flag == 1) { count200e++; i++; continue; }
		if (tp[i].price < 200 && tp[i].empty_flag == 1) { count0e++; i++; continue; }
		i++;
	}
	i = 0; strcpy(dot, ";"); strcpy(roomnum, " ");
	while (i < n)/*ͳ����ס�������ڵĿͷ���*/
	{
		if (tp[i].empty_flag == 0)
		{
			year = currentYear - tp[i].client_date.year;
			if (year != 0)
			{
				for (j = 2; j <= year; j++)
				{
					leapFlag = isLeapyear(tp[i].client_date.year + j - 1);/*�ж��Ƿ�������*/
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
void CountMember(Member_Link l)//�����������Թ˿�������Ů�Թ˿�����
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
		countc++;//ͳ��ס������
		if (strcmp(r->data.sex, "��") == 0) countm++;//ͳ������
		else countf++;//ͳ��Ů������
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


//�Ǽ���ס
void RegisterRoom(ROOM tp[], int n, Member_Link ll)
{
	Member_Node* p2;  /*�����Ա��¼ָ�����*/
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
	printf("please input your upper limit of room price:");/*������Ҫ����ļ�λ*/
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
			suffix = i;/*�������һ�����ϼ�¼�Ŀͷ���¼���±�ֵ��׼��������ͻ�*/
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
			while (p2)/*��ѯ�û�Ա����Ƿ��Ѿ����ڣ���������������ִ�л�Ա�Ǽ�ס�޲���*/
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
			/*******************����Ա��������ͷ���¼��**********************/
			tp[suffix].empty_flag = 0;
			strcpy(tp[suffix].client_name, p2->data.name);
			strcpy(tp[suffix].client_ic, p2->data.ic);
			tp[suffix].client_totaldays = staydays;
			tp[suffix].client_ap = ad_pay;
			/********************��������***************************/
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
		else if (ch == 'n' || ch == 'N')/**********************�ǻ�Ա*******************/
		{
			gotoxy(3, y + 1); stringinput(tp[suffix].client_name, 15, "Client_name:", 0);
			gotoxy(3, y + 2); stringinput(tp[suffix].client_ic, 18, "Client_ic:", 3);
			gotoxy(3, y + 3); printf("The days of your stay:"); scanf("%d", &staydays);
			gotoxy(3, y + 4); printf("Please input advance payment[>=%d]:", tp[suffix].price * staydays + 100); scanf("%d", &ad_pay);
			tp[suffix].empty_flag = 0;
			tp[suffix].client_totaldays = staydays;
			tp[suffix].client_ap = ad_pay;
			/******************��������********************/
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
//�˷�
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
			while (p2)/*��ѯ�û�Ա�Ƿ��Ѿ����ڣ���������������ִ�л�Ա�˷�����*/
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
			/*�����˷�*/
			gotoxy(3, y + 2);
			printf("The days of your stay:%d,price:%d", tp[suffix].client_totaldays, tp[suffix].price);
			gotoxy(3, y + 3);
			return_pay = tp[suffix].client_ap - tp[suffix].client_totaldays * tp[suffix].price * 0.9;/*��Ա�����Ż�*/
			printf("Advance payment:%d,Return payment:%.2f", tp[suffix].client_ap, return_pay);
			getchar(); getchar();
			strcpy(clientname, tp[suffix].client_name);
			break;
		}
		else if (ch == 'n' || ch == 'N')/*****************�ǻ�Ա***********************/
		{
			/*�����˷�*/
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
	/*****************���ͷ���¼�ÿ�******************/
	tp[suffix].empty_flag = 1;
	strcpy(tp[suffix].client_name, " ");
	strcpy(tp[suffix].client_ic, " ");
	tp[suffix].client_totaldays = 0;
	tp[suffix].client_ap = 0;
	/*****************��������***********************/
	tp[suffix].client_date.year = 0;
	tp[suffix].client_date.mon = 0;
	tp[suffix].client_date.day = 0;
	saveflag = 1;
	gotoxy(3, y + 4); printf("Room %s is returned bu %s successfully!", tp[suffix].num, clientname);
	getchar(); getchar();
	return;
}
