通讯录 
[问题描述]
编写一个通讯录管理系统，以把所学数据结构知识应用到实际软件开发中去。每条信息至包含 ：姓名（NAME ）街道（STREET）城市（CITY）邮编（EIP）国家（STATE）几项
[基本要求]
（1）创建通讯录信息 
（2）显示通信录信息 
（3）查找以姓名作为关键字 
（4）删除某个人信息 
[数据结构]
采用单循环链表或顺序表
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

typedef struct node{
	char *name;//指向姓名的指针 
	char *street;//指向街道的指针 
	char *city;//指向城市的指针 
	int  eip;//指向邮编的指针 
	char *state;//指向国家的指针 
	struct node *next;
}ElemSN;

typedef struct pode{
	char name[10];//姓名 
	char street[10];//街道 
	char city[10];//城市 
	int  eip;//邮编 
	char state[10];//国家 
}Get;

ElemSN *CreateLink(Get a[],int n)//创建含每个人信息的单向循环链表
{
	ElemSN *head=NULL,*p,*tail;	
	for(int i=0;i<n;i++){//给每个结点赋值
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->name=a[i].name;
		p->street=a[i].street;
		p->city=a[i].city;
		p->eip=a[i].eip;
		p->state=a[i].state;
		if(head==NULL){//是头结点，p链接自己，头指针和尾指针指上来
			p->next=p;
			head=tail=p;
		}
		else{//不是，插入
			p->next=head;
			tail=tail->next=p;
		}
	}
		return head;
}

void Searchsomeone(ElemSN *head,int n,char someonename[])
//寻找某一个人，显示包括重复姓名的
{
	ElemSN *p;
	p=head;
	int cnt=0;//判断是否有此人信息
	for(int i=0;i<n;i++,p=p->next){
		if(strcmp(p->name,someonename)==0){//找到并输出相应信息
			printf("找到了！下列是他的信息：\n");
			printf("姓名:%s\t街道：%s\t城市：%s\t邮编：%d\t国家：%s\n",p->name,p->street,p->city,p->eip,p->state);
			cnt++;
		}
	}
	if(cnt==0){
		printf("对不起，你的通讯录中没有此人信息！");
	}
}

void Deletesomeone(ElemSN *head,int *n,char someonename[])
//删除某个人的所有信息
{
		int cnt=0;//判断是否有此人 
		ElemSN *p,*q;
		p=head;
	 	if(*n==1&&strcmp(p->name,someonename)){
//通讯录只有与一个人，刚好这个人也是要删除的对象 
			free(p);
			head=NULL;
		}
		else{
			for(int i=0;i<*n;i++){
				q=p;
				p=p->next;
				if(strcmp(p->name,someonename)==0){
//找到此人，删除他的所有信息 
					q->next=p->next;
					free(p);
					*n=*n-1;
					cnt=1;
				}
			} 
		}
		if(cnt==0){
			printf("没有要删除人的任何信息！"); 
		}
}

void PrintLink(ElemSN *head,int n)//输出每个人的信息
{
	ElemSN *p;
	p=head;
	printf("姓名\t街道\t城市\t邮编\t国家\n");
	for(int i=0;i<n;i++,p=p->next){
		printf("%s\t%s\t%s\t%d\t%s\n",p->name,p->street,p->city,p->eip,p->state);
	}
}

int main()
{
	int n;
	printf("请输入人数n：");
	scanf("%d",&n);
	Get a[N];
	printf("请输入每个人的姓名、街道、城市、邮编和国家信息：\n");
	for(int i=0;i<n;i++){//输入每个人的信息
		scanf("%s",&a[i].name);
		scanf("%s",&a[i].street);
		scanf("%s",&a[i].city);
		scanf("%d",&a[i].eip);
		scanf("%s",&a[i].state);
	}
	ElemSN *head=NULL;
	head=CreateLink(a,n);//创建单循环链表
	printf("请输入1（显示通讯录信息）或2（查找某人信息）或3（删除某人信息）：");
	int key;
	char someonename[20];//要查找或者删除的某一个人的姓名
	while(1){
	scanf("%d",&key);//输入要实现的功能编号
	if(key>=1&&key<=3){
		break;
	}
	else{
		printf("请重新输入：");
	}
	}
	switch(key){
		case 1:
			PrintLink(head,n);
			break;
		case 2:
			printf("请输入要查找的人的姓名：");
			scanf("%s",someonename);
			Searchsomeone(head,n,someonename);
			break;
		case 3:
			printf("请输入要删除的人的姓名：");
			scanf("%s",someonename);
			Deletesomeone(head,&n,someonename);
			if(head){
			printf("删除后的通讯录信息为：\n");
			PrintLink(head,n);
			}
			else{
				printf("你的通讯录已为空！"); 
			}
			break;
		default:
			printf("------------------------------------------");

	}
	return 0;
}
