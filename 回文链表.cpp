/*
��������
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false
ʾ�� 2:

����: 1->2->2->1
���: true
���ף�
���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
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
	int top=-1;//ջ��ָ��
	int *stack=(int *)malloc(100000*sizeof(int));
	for(struct ListNode *p=head;p;p=p->next){//��ջ 
		stack[++top]=p->val;
	}
	for(struct ListNode *q=head;q&&stack[top]==q->val;q=q->next) {//ջ��Ԫ�س�ջ �Ƚ�  ��һ������Ⱦͷ���false 
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
	printf("���������鳤��n��");
	scanf("%d",&n);
	printf("����������Ԫ�أ�");
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	struct ListNode *head=CreateLink(a,n);//������������
	if(isPalindrome(head)){
		printf("��һ����������");
	}
	else{
		printf("����һ����������");
	}
	return 0;
}
