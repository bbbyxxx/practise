ɾ������ĵ�����N���ڵ�
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����

������ n ��֤����Ч�ġ�

���ף�

���ܳ���ʹ��һ��ɨ��ʵ����
#include<bits/stdc++.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode *CreateLink(int a[],int n)
{//���������� 
	struct ListNode *head=NULL,*p;
	for(int i=n-1;i>=0;i--){
		p=(struct ListNode *)malloc(sizeof(struct ListNode));
		p->val=a[i];
		p->next=head;
		head=p;
	}
	return head;	
}
struct ListNode *DeleteTheLastKeyNode(struct ListNode *head,int n)
{
	int cnt=0;
	struct ListNode *q=NULL,*p;
	for(p=head;p;cnt++,p=p->next);//����������
	p=head;
	if(cnt-n==0){
		head=head->next;
		free(p);
	}
	else{
	for(int i=0;i<cnt-n;i++){
		q=p;
		p=p->next;
	} 
	q->next=p->next;
	free(p);
	}
	return head;
}
void Print(struct ListNode *head)
{
	if(head){
		printf("%4d",head->val);
		Print(head->next);
	}
}
int main()
{
	int n,key;
	int *a;
	printf("���������鳤�ȣ�");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("����������Ԫ��:");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("������Ҫɾ�������ڼ�����㣺");
	scanf("%d",&key);
	struct ListNode *head=CreateLink(a,n);//�������� 
	head=DeleteTheLastKeyNode(head,key);//ɾ��������key����� 
	Print(head);//������� 
	return 0;
}
