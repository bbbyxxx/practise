ͨѶ¼ 
[��������]
��дһ��ͨѶ¼����ϵͳ���԰���ѧ���ݽṹ֪ʶӦ�õ�ʵ�����������ȥ��ÿ����Ϣ������ ��������NAME ���ֵ���STREET�����У�CITY���ʱࣨEIP�����ң�STATE������
[����Ҫ��]
��1������ͨѶ¼��Ϣ 
��2����ʾͨ��¼��Ϣ 
��3��������������Ϊ�ؼ��� 
��4��ɾ��ĳ������Ϣ 
[���ݽṹ]
���õ�ѭ�������˳���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

typedef struct node{
	char *name;//ָ��������ָ�� 
	char *street;//ָ��ֵ���ָ�� 
	char *city;//ָ����е�ָ�� 
	int  eip;//ָ���ʱ��ָ�� 
	char *state;//ָ����ҵ�ָ�� 
	struct node *next;
}ElemSN;

typedef struct pode{
	char name[10];//���� 
	char street[10];//�ֵ� 
	char city[10];//���� 
	int  eip;//�ʱ� 
	char state[10];//���� 
}Get;

ElemSN *CreateLink(Get a[],int n)//������ÿ������Ϣ�ĵ���ѭ������
{
	ElemSN *head=NULL,*p,*tail;	
	for(int i=0;i<n;i++){//��ÿ����㸳ֵ
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->name=a[i].name;
		p->street=a[i].street;
		p->city=a[i].city;
		p->eip=a[i].eip;
		p->state=a[i].state;
		if(head==NULL){//��ͷ��㣬p�����Լ���ͷָ���βָ��ָ����
			p->next=p;
			head=tail=p;
		}
		else{//���ǣ�����
			p->next=head;
			tail=tail->next=p;
		}
	}
		return head;
}

void Searchsomeone(ElemSN *head,int n,char someonename[])
//Ѱ��ĳһ���ˣ���ʾ�����ظ�������
{
	ElemSN *p;
	p=head;
	int cnt=0;//�ж��Ƿ��д�����Ϣ
	for(int i=0;i<n;i++,p=p->next){
		if(strcmp(p->name,someonename)==0){//�ҵ��������Ӧ��Ϣ
			printf("�ҵ��ˣ�������������Ϣ��\n");
			printf("����:%s\t�ֵ���%s\t���У�%s\t�ʱࣺ%d\t���ң�%s\n",p->name,p->street,p->city,p->eip,p->state);
			cnt++;
		}
	}
	if(cnt==0){
		printf("�Բ������ͨѶ¼��û�д�����Ϣ��");
	}
}

void Deletesomeone(ElemSN *head,int *n,char someonename[])
//ɾ��ĳ���˵�������Ϣ
{
		int cnt=0;//�ж��Ƿ��д��� 
		ElemSN *p,*q;
		p=head;
	 	if(*n==1&&strcmp(p->name,someonename)){
//ͨѶ¼ֻ����һ���ˣ��պ������Ҳ��Ҫɾ���Ķ��� 
			free(p);
			head=NULL;
		}
		else{
			for(int i=0;i<*n;i++){
				q=p;
				p=p->next;
				if(strcmp(p->name,someonename)==0){
//�ҵ����ˣ�ɾ������������Ϣ 
					q->next=p->next;
					free(p);
					*n=*n-1;
					cnt=1;
				}
			} 
		}
		if(cnt==0){
			printf("û��Ҫɾ���˵��κ���Ϣ��"); 
		}
}

void PrintLink(ElemSN *head,int n)//���ÿ���˵���Ϣ
{
	ElemSN *p;
	p=head;
	printf("����\t�ֵ�\t����\t�ʱ�\t����\n");
	for(int i=0;i<n;i++,p=p->next){
		printf("%s\t%s\t%s\t%d\t%s\n",p->name,p->street,p->city,p->eip,p->state);
	}
}

int main()
{
	int n;
	printf("����������n��");
	scanf("%d",&n);
	Get a[N];
	printf("������ÿ���˵��������ֵ������С��ʱ�͹�����Ϣ��\n");
	for(int i=0;i<n;i++){//����ÿ���˵���Ϣ
		scanf("%s",&a[i].name);
		scanf("%s",&a[i].street);
		scanf("%s",&a[i].city);
		scanf("%d",&a[i].eip);
		scanf("%s",&a[i].state);
	}
	ElemSN *head=NULL;
	head=CreateLink(a,n);//������ѭ������
	printf("������1����ʾͨѶ¼��Ϣ����2������ĳ����Ϣ����3��ɾ��ĳ����Ϣ����");
	int key;
	char someonename[20];//Ҫ���һ���ɾ����ĳһ���˵�����
	while(1){
	scanf("%d",&key);//����Ҫʵ�ֵĹ��ܱ��
	if(key>=1&&key<=3){
		break;
	}
	else{
		printf("���������룺");
	}
	}
	switch(key){
		case 1:
			PrintLink(head,n);
			break;
		case 2:
			printf("������Ҫ���ҵ��˵�������");
			scanf("%s",someonename);
			Searchsomeone(head,n,someonename);
			break;
		case 3:
			printf("������Ҫɾ�����˵�������");
			scanf("%s",someonename);
			Deletesomeone(head,&n,someonename);
			if(head){
			printf("ɾ�����ͨѶ¼��ϢΪ��\n");
			PrintLink(head,n);
			}
			else{
				printf("���ͨѶ¼��Ϊ�գ�"); 
			}
			break;
		default:
			printf("------------------------------------------");

	}
	return 0;
}
