Լɪ����������Ϸ
[��������]
Լɪ��Joeph�������һ�������ǣ����Ϊ1,2,��,n��n���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ�����루����������һ��ʼ��ѡһ����������Ϊ��������ֵm���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ��������m���˳��У�������������Ϊ�µ�mֵ��������˳ʱ�뷽���ϵ���һ���˿�ʼ���´�1�����������ȥ��ֱ��������ȫ������Ϊֹ�������һ�������������˳��
[����Ҫ��]
���õ���ѭ������洢�ṹģ��˹��̣����ճ��е�˳��ӡ�����˵ı�š�
[��������]
m�ĳ�ֵΪ20�����룺3��1��7��2��4��8��4����ȷ�Ľ��ӦΪ6��1��4��7��2��3��5����
[ʵ����ʾ]
�������к�����Ҫ���û�ָ����ʼ��������ֵ��Ȼ���ȡ���˵����롣��n��30��
[ѡ������]
�����������������˳��ṹ��ʵ�ֵĲ��֡�

//����ʵ��
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
			//��ͷ
			if(p==h){
				h=h->next;
				printf("%4d",p->data);//��֤���Ԫ�� 
				free(p);//p�ͷţ�������ָ���� 
				p=h;	
			} 
			else{
			//ɾ�м�β
				printf("%4d",p->data);
				free(p);
				p=q->next;
			}			
		}
			else{//����
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
	printf("�����뱨������ֵs��");
	while(1){
	scanf("%d",&s);
	if(s<=30){
		break;
	}
	else{
		printf("���������룺");
	}
	}
	printf("���������룺");
	for(i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	ElemSN *head=NULL,*t;
	//��������ѭ������ 
	head=Createlink(a,b);
	//ʵ��Լɪ�� 
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
		for(cnt=1;cnt%s!=0;cnt++,q=p,p=p->next);//����s��Ԫ������ѭ����pָ���s��Ԫ��
		q->next=p->next;//����
		s=p->mima;
		printf("%4d",p->data); 
		free(p);//ɾ��
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
	printf("�����뱨������ֵs��");
	while(1){
	scanf("%d",&s);
	if(s<=30){
		break;
	}
	else{
		printf("���������룺");
	}
	}
	printf("���������룺");
	for(i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	ElemSN *head=NULL,*t;
	//��������ѭ������ 
	head=Createlink(a,b);
	//ʵ��Լɪ�� 
	Tosephus(head,s);
	return 0;
}*/


//����ʵ��
#include<stdio.h>  
#define N 1000000
int flag[N] = {0}; //����ȫ������ 
int b[N]={0};
int main() 
{
	int n = 0, m = 0;
	printf("�����볤�Ⱥͱ������ޣ�");
	scanf("%d %d", &n, &m);
    int i = 0;
	int count = 0; //��¼��Ȧ������ 
	int num = 0; //������
	for(i = 1; i <= n; i++) {
		flag[i] = 1;
	}
	printf("���������룺");
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	while(count < n) {
		for(i = 1; i <= n; i++ ) {
					if (1 == flag[i]) {
						num++;
					} 
					if(num == m) {//��ȣ�˵�����Գ��� 
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



 

