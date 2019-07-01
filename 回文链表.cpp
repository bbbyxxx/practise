/*
回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/
#include<bits/stdc++.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode *CreateLink(int a[],int n)
{
	struct ListNode *head=NULL,*p;
	for(int i=n-1;i>=0;i--){
		p=(struct ListNode *)malloc(sizeof(struct ListNode));
		p->val=a[i];
		p->next=head;
		head=p; 
	} 
	return head;
}
bool isPalindrome(struct ListNode* head){
	int top=-1;//栈顶指针
	int *stack=(int *)malloc(100000*sizeof(int));
	for(struct ListNode *p=head;p;p=p->next){//入栈 
		stack[++top]=p->val;
	}
	for(struct ListNode *q=head;q&&stack[top]==q->val;q=q->next) {//栈顶元素出栈 比较  有一个不相等就返回false 
		if(top!=-1){
			top--;
		}
		if(top==-1){
			break;
		}
	}
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
int main()
{
	int n;
	printf("请输入数组长度n：");
	scanf("%d",&n);
	printf("请输入数组元素：");
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	struct ListNode *head=CreateLink(a,n);//创建单向链表
	if(isPalindrome(head)){
		printf("是一个回文链表！");
	}
	else{
		printf("不是一个回文链表！");
	}
	return 0;
}
