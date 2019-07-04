#include<stdio.h>
#include<stdlib.h>
#define V 10

typedef struct{
	int gno;//物品结点
	int gv;//物品体积 
}ElemG;//物品信息

typedef struct node{
	int gno;//物品编号 
	struct node *link;
}GoodsLink;//物品结点信息

typedef struct box{
	int remainder;//箱子的体积 
	GoodsLink *hg;//指向物品结点 
	struct box *next;//指向下一个箱子结点 
}BoxLink;

void SortD(ElemG *g,int n)
{
	ElemG t;
	int i,j;
	for(i=0;i<n-1;i++){//冒泡排序 
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
		for(p=hbox;p&&p->remainder<g[i].gv;p=p->next);//循环遍历箱子链，找出要放的箱子或者判断开不开新箱子
		if(!p){//没有已打开的箱子可放 创建新箱子 
			p=(BoxLink *)malloc(sizeof(BoxLink));
			p->remainder=V;//赋上新箱子体积 
			p->hg=NULL; 
			p->next=NULL;//箱子结点指针域和物品结点指针域赋空 
			if(!hbox){//第一个要开的箱子 
				hbox=tail=p;
			}
			else{//其他箱子，挂链 
				tail=tail->next=p;
			}
		}
		p->remainder-=g[i].gv;//放入物品，箱子体积减少 
		newg=(GoodsLink *)malloc(sizeof(GoodsLink));//创建物品结点 
		newg->gno=g[i].gno;//物品结点编号 即物品编号 
		newg->link=NULL;//物品结点指针域赋空 
		for(q=p->hg;q&&q->link;q=q->link);//遍历物品结点链，找到要挂的地方 
		if(!q){//物品链还没有物品 
			p->hg=newg;
		}
		else{//物品链有结点，遍历到尾结点，挂链 
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
	for(p=h;p;p=p->next){//遍历箱子链 
		printf("第%d个箱子：",++i);
		for(q=p->hg;q;q=q->link){//输出当前箱子结点中的物品链各物品编号 
			printf("有第%d个物品、",q->gno);
		}
		printf("\n");
	}
}

int main()
{
	ElemG *g;
	BoxLink *hbox;
	int n;//物品个数
	//初始化物品信息
	printf("请输入物品数：");
	scanf("%d",&n);
	g=(ElemG *)malloc(n*sizeof(ElemG));
	printf("请输入各物品体积:");
	for(int i=0;i<n;i++){
		g[i].gno=i+1;
		scanf("%d",&g[i].gv);
	} 
	//排序
	SortD(g,n);
	//装箱
	hbox=Packing(g,n);
	//输出
	PrintBox(hbox);
	return 0; 
}
