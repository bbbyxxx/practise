约瑟夫生死者游戏
[问题描述]
约瑟夫（Joeph）问题的一种描述是：编号为1,2,…,n的n个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。一开始任选一个正整数作为报数上限值m，从第一个人开始按顺时针方向自1开始顺序报数，报到m时停止报数。报m的人出列，将他的密码作为新的m值，从他在顺时针方向上的下一个人开始重新从1报数，如此下去，直至所有人全部出列为止。试设计一个程序求出出列顺序。
[基本要求]
利用单向循环链表存储结构模拟此过程，按照出列的顺序印出各人的编号。
[测试数据]
m的初值为20；密码：3，1，7，2，4，8，4（正确的结果应为6，1，4，7，2，3，5）。
[实现提示]
程序运行后首先要求用户指定初始报数上限值，然后读取各人的密码。设n≤30。
[选作内容]
向上述程序中添加在顺序结构上实现的部分。

//链表实现
/*#include<stdio.h>
#include<stdlib.h>
#define N 7
typedef struct node{
	int data;
	int mima;
	struct node *next;
}ElemSN;
ElemSN *Createlink(int a[],int b[])
{
	int key;
	ElemSN *h,*t,*p;
	h=NULL;
	for(int i=0;i<N;i++){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->data=a[i];
		p->mima=b[i];
		if(!h){
			p->next=p;
			h=t=p;
		}
		else{
			p->next=h;
			t=t->next=p;
		}
	}
	return h;
}
void Tosephus(ElemSN *h,int s)
{
	ElemSN *p,*q;
	p=h;
	int cnt=0;
	while(p->next!=p){
		cnt++;
		if(cnt%s==0){
			q->next=p->next;
			s=p->mima;
			cnt=0;
			//移头
			if(p==h){
				h=h->next;
				printf("%4d",p->data);//验证输出元素 
				free(p);//p释放，需重新指上来 
				p=h;	
			} 
			else{
			//删中间尾
				printf("%4d",p->data);
				free(p);
				p=q->next;
			}			
		}
			else{//联动
			q=p;
	 		p=p->next;
			}
	}
	printf("%4d",p->data);
}
int main()
{
	int a[N],i,s;
	int b[N];
	for(i=0;i<N;i++){
	a[i]=i+1;
	}
	printf("\n");
	printf("请输入报数上限值s：");
	while(1){
	scanf("%d",&s);
	if(s<=30){
		break;
	}
	else{
		printf("请重新输入：");
	}
	}
	printf("请输入密码：");
	for(i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	ElemSN *head=NULL,*t;
	//创建单向循环链表 
	head=Createlink(a,b);
	//实现约瑟夫环 
	Tosephus(head,s);
	return 0;
}*/


/*#include<stdio.h>
#include<stdlib.h>
#define N 7
typedef struct node{
	int data;
	int mima;
	struct node *next;
}ElemSN;
ElemSN *Createlink(int a[],int b[])
{
	ElemSN *h,*t,*p;
	h=NULL;
	for(int i=0;i<N;i++){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->data=a[i];
		p->mima=b[i];
		if(!h){
			p->next=p;
			h=t=p;
		}
		else{
			p->next=h;
			t=t->next=p;
		}
	}
	return h;
}
void Tosephus(ElemSN *h,int s)
{
	ElemSN *p,*q;
	int cnt;
	p=h;
	do{
		for(cnt=1;cnt%s!=0;cnt++,q=p,p=p->next);//到第s个元素跳出循环，p指向第s个元素
		q->next=p->next;//挂链
		s=p->mima;
		printf("%4d",p->data); 
		free(p);//删除
		p=q->next;//
	}while(p->next!=p);
	printf("%4d",p->data); 
}
int main()
{
	int a[N],i,s;
	int b[N];
	for(i=0;i<N;i++){
	a[i]=i+1;
	}
	printf("\n");
	printf("请输入报数上限值s：");
	while(1){
	scanf("%d",&s);
	if(s<=30){
		break;
	}
	else{
		printf("请重新输入：");
	}
	}
	printf("请输入密码：");
	for(i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	ElemSN *head=NULL,*t;
	//创建单向循环链表 
	head=Createlink(a,b);
	//实现约瑟夫环 
	Tosephus(head,s);
	return 0;
}*/


//数组实现
#include<stdio.h>  
#define N 1000000
int flag[N] = {0}; //定义全局数组 
int b[N]={0};
int main() 
{
	int n = 0, m = 0;
	printf("请输入长度和报数上限：");
	scanf("%d %d", &n, &m);
    int i = 0;
	int count = 0; //记录出圈的人数 
	int num = 0; //报数器
	for(i = 1; i <= n; i++) {
		flag[i] = 1;
	}
	printf("请输入密码：");
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	while(count < n) {
		for(i = 1; i <= n; i++ ) {
					if (1 == flag[i]) {
						num++;
					} 
					if(num == m) {//相等，说明可以出列 
						printf("%4d", i);
						count++;
						flag[i] = 0;
						num = 0;
						m=b[i];
					}
		} 	
	} 
	return 0;
}



 

