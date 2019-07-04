#include<stdio.h>
#include<stdlib.h>
#define V 10

typedef struct{
	int gno;//��Ʒ���
	int gv;//��Ʒ��� 
}ElemG;//��Ʒ��Ϣ

typedef struct node{
	int gno;//��Ʒ��� 
	struct node *link;
}GoodsLink;//��Ʒ�����Ϣ

typedef struct box{
	int remainder;//���ӵ���� 
	GoodsLink *hg;//ָ����Ʒ��� 
	struct box *next;//ָ����һ�����ӽ�� 
}BoxLink;

void SortD(ElemG *g,int n)
{
	ElemG t;
	int i,j;
	for(i=0;i<n-1;i++){//ð������ 
		for(j=i+1;j<n;j++){
			if(g[i].gv<g[j].gv){
				t=g[i];
				g[i]=g[j];
				g[j]=t;
			}
		}
	}
} 

BoxLink *Packing(ElemG *g,int n)
{
	BoxLink *hbox,*tail,*p;
	GoodsLink *q,*newg;
	hbox=NULL;
	for(int i=0;i<n;i++){
		for(p=hbox;p&&p->remainder<g[i].gv;p=p->next);//ѭ���������������ҳ�Ҫ�ŵ����ӻ����жϿ�����������
		if(!p){//û���Ѵ򿪵����ӿɷ� ���������� 
			p=(BoxLink *)malloc(sizeof(BoxLink));
			p->remainder=V;//������������� 
			p->hg=NULL; 
			p->next=NULL;//���ӽ��ָ�������Ʒ���ָ���򸳿� 
			if(!hbox){//��һ��Ҫ�������� 
				hbox=tail=p;
			}
			else{//�������ӣ����� 
				tail=tail->next=p;
			}
		}
		p->remainder-=g[i].gv;//������Ʒ������������� 
		newg=(GoodsLink *)malloc(sizeof(GoodsLink));//������Ʒ��� 
		newg->gno=g[i].gno;//��Ʒ����� ����Ʒ��� 
		newg->link=NULL;//��Ʒ���ָ���򸳿� 
		for(q=p->hg;q&&q->link;q=q->link);//������Ʒ��������ҵ�Ҫ�ҵĵط� 
		if(!q){//��Ʒ����û����Ʒ 
			p->hg=newg;
		}
		else{//��Ʒ���н�㣬������β��㣬���� 
			q->link=newg;
		}
	}
	return hbox; 
}

void PrintBox(BoxLink *h)
{
	int i=0;
	BoxLink *p;
	GoodsLink *q;
	for(p=h;p;p=p->next){//���������� 
		printf("��%d�����ӣ�",++i);
		for(q=p->hg;q;q=q->link){//�����ǰ���ӽ���е���Ʒ������Ʒ��� 
			printf("�е�%d����Ʒ��",q->gno);
		}
		printf("\n");
	}
}

int main()
{
	ElemG *g;
	BoxLink *hbox;
	int n;//��Ʒ����
	//��ʼ����Ʒ��Ϣ
	printf("��������Ʒ����");
	scanf("%d",&n);
	g=(ElemG *)malloc(n*sizeof(ElemG));
	printf("���������Ʒ���:");
	for(int i=0;i<n;i++){
		g[i].gno=i+1;
		scanf("%d",&g[i].gv);
	} 
	//����
	SortD(g,n);
	//װ��
	hbox=Packing(g,n);
	//���
	PrintBox(hbox);
	return 0; 
}
