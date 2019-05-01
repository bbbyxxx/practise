#include<bits/stdc++.h>
#define N 10001
using namespace std;
void Add(char s1[],char s2[])
{
	int top1=strlen(s1)-1;
	int top2=strlen(s2)-1;
	int t1,t2,t3,n=0,top=-1;
	int s[N];
	//³öÕ»
	while(top1!=-1&&top2!=-1){
		t1=s1[top1--]-'0';
		t2=s2[top2--]-'0';
		t3=t1+t2+n;
		if(t3/2){
		s[++top]=0+t3%2;
		n=1;
		}
		else{
			s[++top]=t3;
			n=0;
		}
	} 
		while(top1!=-1){
		if((s1[top1]-'0'+n)/2){
		s[++top]=0+(s1[top1]-'0'+n)%2;
			n=1;
		}
		else{
			s[++top]=s1[top1]-'0'+n;
			n=0;
		}
		top1--;
		}
		while(top2!=-1){
		if((s1[top2]-'0'+n)/2){
		s[++top]=0+(s1[top2]-'0'+n)%2;
			n=1;
		}
		else{
			s[++top]=s1[top2]-'0'+n;
			n=0;
		}
		top2--;
		}
	if(n){
		s[++top]=n;
	}
	while(top!=-1){
		cout<<s[top--];
	}
}
int main()
{
	char s1[N];
	char s2[N];
	gets(s1);
	gets(s2);
	Add(s1,s2);
	return 0;
}
