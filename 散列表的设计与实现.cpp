ɢ�б�������ʵ�� 
[��������] 
���ɢ�б�ʵ�ֵ绰�������ϵͳ��ʹ��ƽ�����ҳ��Ȳ�����2�� 
[����Ҫ��] 
��1����ÿ����¼������������绰���롢�û�������ַ�� 
��2���Ӽ����������¼���Ե绰����Ϊ�ؼ��ֽ���ɢ�б� 
��3������һ���ķ��������ͻ�� 
��4�����Ҳ���ʾ�����绰����ļ�¼�� 
[���ݽṹ]
˳�����ʽ�洢����ϣ�����ó������������죬������̽����ɢ�з�������ַ�������ͻ
#include<bits/stdc++.h>
#define N 10//��ϣ���鳤�ȣ��ɱ� 
using namespace std;
typedef struct node{
	long long int data;//�绰���� 
	char *name;// �û���
	char *address;//��ַ 
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
	for(i=0;i<N;i++){//��ʼ����ϣ���� 
		head[i]=NULL;
	}
	long long int x;
	for(i=0;i<n;i++){//������ϣ�� 
		x=0;
		for(int j=0;g[i].s[j];j++){
			x=x*10+g[i].s[j]-'0';
		}
		np=(ElemSN *)malloc(sizeof(ElemSN));
		np->data=x;
		np->name=g[i].name;
		np->address=g[i].address;
		np->next=NULL;
		t=np->data%N;//�����ַ 
		for(tail=head[t];tail&&tail->next;tail=tail->next);//�жϹ�ϣ�����Ƿ�Ϊ�� 
		if(!tail){//Ϊ�գ����µĽ������ 
			head[t]=np;
		}
		else{//��Ϊ�գ����½��β�嶼��������
			tail->next=np;
		} 
	}
	return head;
}
void PrintHash(ElemSN **head)
{
	ElemSN *p;
	int i;
	cout<<"��ַ"<<"\t"<<"Ԫ��"<<"\t"<<"\n";
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
	cout<<"���������鳤��n��";
	cin>>n;
	ElemSN **head;
	ElemSN *p; 
	PNode g[n];
	cout<<"������绰���룬�û�������ַ��";
	for(int i=0;i<n;i++){
		cin>>g[i].s;
		cin>>g[i].name;
		cin>>g[i].address;
	}
	cout<<"������key��";
	cin>>key;
	head=CreateHash(n,g);//������ϣ�� 
	PrintHash(head);//�����ϣ�� 
	p=FindKey(head,key);//����Ԫ�� 
	if(!p){//û�ҵ� 
		cout<<"Not Found!";
	} 
	else{//�ҵ�����������Ϣ 
		cout<<"��ϲ�㣡�д�����Ϣ���ҵ��ˣ�"<<endl;
		cout<<"\n"<<p->data<<"\t"<<p->name<<"\t"<<p->address;
	}
	return 0;
}
