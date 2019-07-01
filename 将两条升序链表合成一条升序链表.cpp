/*
合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
	while(l1&&l2){//两条链都不空 
		if(l1->val<l2->val){
			p=l1;//p时刻指向最小的 
			l1=l1->next;
		}
		else{
			p=l2;
			l2=l2->next;
		}
		p->next=NULL;
		tail=tail->next=p;
	}
	//l1先完或者l2先完
	//l1先完,l2剩下的链直接挂上 
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
	printf("请输入数组a1和a2的长度n1和n2：");
	scanf("%d %d",&n1,&n2);
	int a1[n1],a2[n2];
	printf("请输入数组a1的元素值：");
	for(int i=0;i<n1;i++){
		scanf("%d",&a1[i]);
	}
	printf("请输入数组a2的元素值：");
	for(int j=0;j<n2;j++){
		scanf("%d",&a2[j]);
	}
	struct ListNode *head1=CreateLink(a1,n1);
	struct ListNode *head2=CreateLink(a2,n2);
	struct ListNode *head=mergeTwoLists(head1,head2);
	Print(head);
	return 0;
}
