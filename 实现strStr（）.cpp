/*实现strStr()
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？
这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。*/
#include<bits/stdc++.h>
#define N 1001
using namespace std;
int Index(char s[],char t[])
{
	int s1=strlen(s);
	int t1=strlen(t);
	int i=0,j=0;
	while(i<s1&&j<t1){
		if(s[i]==t[j]){//继续匹配下一个字符 
			i++;
			j++;
		}
		else{//主串，子串指针回溯重新开始下一次匹配 
			i=i-j+1;//主串从下一个位置开始匹配 
			j=0;//子串从头开始匹配 
		}
	}
	if(j>=t1){
		return (i-t1);//返回匹配的第一个字符的下标 
	}
	else{
		return -1;//匹配不成功 
	}
}
int main()
{
	char a[N];
	cout<<"请输入主串：";
	gets(a);
	char b[N];
	cout<<"请输入模式串：";
	gets(b);
	int t=Index(a,b);
		cout<<t<<endl; 
	return 0; 
}
