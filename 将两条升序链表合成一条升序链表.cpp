/*
�ϲ�������������
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/
#include<bits/stdc++.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode *CreateLink(int a[],int n)
{
	struct ListNode *head=NULL,*np,*p;
	for(int i=n-1;i>=0;i--){
		np=(struct ListNode *)malloc(sizeof(struct ListNode));
		np->val=a[i];
		np->next=head;
		head=np;
	}
	return head;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *p,*tail,*head;
	if(!l1||!l2){
		return l1==NULL?l2:l1;
	}
	if(l1->val<l2->val){
		head=tail=l1;
		l1=l1->next; 
	}
	else{
		head=tail=l2;
		l2=l2->next;
	}
	while(l1&&l2){//������������ 
		if(l1->val<l2->val){
			p=l1;//pʱ��ָ����С�� 
			l1=l1->next;
		}
		else{
			p=l2;
			l2=l2->next;
		}
		p->next=NULL;
		tail=tail->next=p;
	}
	//l1�������l2����
	//l1����,l2ʣ�µ���ֱ�ӹ��� 
	if(!l1){
		tail->next=l2; 
	} 
	else{
		tail->next=l1;
	}
	return head; 
}
void Print(struct ListNode *head)
{
	for(struct ListNode *p=head;p;p=p->next){
		printf("%4d",p->val);
	}
}
int main()
{
	int n1,n2;
	printf("����������a1��a2�ĳ���n1��n2��");
	scanf("%d %d",&n1,&n2);
	int a1[n1],a2[n2];
	printf("����������a1��Ԫ��ֵ��");
	for(int i=0;i<n1;i++){
		scanf("%d",&a1[i]);
	}
	printf("����������a2��Ԫ��ֵ��");
	for(int j=0;j<n2;j++){
		scanf("%d",&a2[j]);
	}
	struct ListNode *head1=CreateLink(a1,n1);
	struct ListNode *head2=CreateLink(a2,n2);
	struct ListNode *head=mergeTwoLists(head1,head2);
	Print(head);
	return 0;
}
