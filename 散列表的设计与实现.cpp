散列表的设计与实现 
[问题描述] 
设计散列表实现电话号码查找系统，使得平均查找长度不超过2。 
[基本要求] 
（1）设每个记录有下列数据项：电话号码、用户名、地址； 
（2）从键盘输入各记录，以电话号码为关键字建立散列表； 
（3）采用一定的方法解决冲突； 
（4）查找并显示给定电话号码的记录； 
[数据结构]
顺序表形式存储，哈希函数用除留余数法构造，用线性探测再散列法或链地址法处理冲突
#include<bits/stdc++.h>
#define N 10//哈希数组长度，可变 
using namespace std;
typedef struct node{
	long long int data;//电话号码 
	char *name;// 用户名
	char *address;//地址 
	struct node *next;
}ElemSN;
typedef struct pode{
	char s[12];
	char name[20];
	char address[20];
}PNode;
ElemSN **CreateHash(int n,PNode g[])
{
	ElemSN **head;
	ElemSN *tail,*np;
	head=(ElemSN **)malloc(N*sizeof(ElemSN *));
	int i,t;
	for(i=0;i<N;i++){//初始化哈希数组 
		head[i]=NULL;
	}
	long long int x;
	for(i=0;i<n;i++){//创建哈希表 
		x=0;
		for(int j=0;g[i].s[j];j++){
			x=x*10+g[i].s[j]-'0';
		}
		np=(ElemSN *)malloc(sizeof(ElemSN));
		np->data=x;
		np->name=g[i].name;
		np->address=g[i].address;
		np->next=NULL;
		t=np->data%N;//计算地址 
		for(tail=head[t];tail&&tail->next;tail=tail->next);//判断哈希数组是否为空 
		if(!tail){//为空，将新的结点链入 
			head[t]=np;
		}
		else{//不为空，将新结点尾插都已有链上
			tail->next=np;
		} 
	}
	return head;
}
void PrintHash(ElemSN **head)
{
	ElemSN *p;
	int i;
	cout<<"地址"<<"\t"<<"元素"<<"\t"<<"\n";
	cout<<"...................."<<"\n";
	for(i=0;i<N;i++){
		cout<<i<<"\t";
		for(p=head[i];p;p=p->next){
			cout<<p->data<<"\t"; 
		} 
		cout<<"\n";
	} 
} 
ElemSN *FindKey(ElemSN **head,long long int key)
{
	ElemSN *p;
	int i;
	i=key%N;
	for(p=head[i];p&&p->data!=key;p=p->next);
	return p;
}
int main()
{
	long long int key;
	int n;
	cout<<"请输入数组长度n：";
	cin>>n;
	ElemSN **head;
	ElemSN *p; 
	PNode g[n];
	cout<<"请输入电话号码，用户名，地址：";
	for(int i=0;i<n;i++){
		cin>>g[i].s;
		cin>>g[i].name;
		cin>>g[i].address;
	}
	cout<<"请输入key：";
	cin>>key;
	head=CreateHash(n,g);//创建哈希表 
	PrintHash(head);//输出哈希表 
	p=FindKey(head,key);//查找元素 
	if(!p){//没找到 
		cout<<"Not Found!";
	} 
	else{//找到并输出相关信息 
		cout<<"恭喜你！有此人信息！找到了！"<<endl;
		cout<<"\n"<<p->data<<"\t"<<p->name<<"\t"<<p->address;
	}
	return 0;
}
