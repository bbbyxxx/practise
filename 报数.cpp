 报数
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"
#include<bits/stdc++.h>
char * countAndSay(int n){
	int i=0,j=0,k=1;
	char *s1=(char *)malloc(sizeof(char)*10000);
	char *s2=(char *)malloc(sizeof(char)*10000);
	if(n==1){//n==1说明只要一个结果，即报数1 
		s1[0]='1';
		s1[1]='\0';
		return s1;
	} 
	s1=countAndSay(n-1);//递归调用，从1开始到n回溯 
	while(s1[i]){
		if(s1[i]!=s1[i+1]){
			s2[j]=k+'0';//将值的个数赋值到值的前一个位置 
			s2[j+1]=s1[i];//将值填入到值个数后面位置 
			k=1;//重置计数器 
			j+=2;//向后推移 
		}
		else{
			k++;//记录相同数的个数 
		}
		i++;
	}
	s2[j]='\0';
	free(s1);
	return s2;
}
int main()
{
	int n;
	scanf("%d",&n);
	char *s=countAndSay(n);
	printf("%s",s);
	return 0;
}
