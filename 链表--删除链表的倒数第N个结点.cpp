删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
#include<bits/stdc++.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode *CreateLink(int a[],int n)
{//逆向建立链表 
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
	for(p=head;p;cnt++,p=p->next);//计算链表长度
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
	printf("请输入数组长度：");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入数组元素:");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("请输入要删除倒数第几个结点：");
	scanf("%d",&key);
	struct ListNode *head=CreateLink(a,n);//创建链表 
	head=DeleteTheLastKeyNode(head,key);//删除倒数第key个结点 
	Print(head);//输出链表 
	return 0;
}
