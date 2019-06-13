/*验证回文字符串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/

#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
bool isPalindrome(char * s){
	//static char b[10000];
	char *b=(char *)malloc(sizeof(char)*(strlen(s)+1));
	int i=0,k=0;
	int j=strlen(s)-1;
	for(i=0;i<strlen(s);i++){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z')){
			b[k++]=s[i];
		}
	}
	i=0;
	j=k-1;
	while(i<=j){
		if(b[i]>='a'&&b[i]<='z'){
			b[i]=b[i]-32;
		}
		if(b[j]>='a'&&b[j]<='z'){
			b[j]=b[j]-32;
		}
		if(b[i]!=b[j]){
			return false;
		}
		else{
			i++;
			j--;
		}
	}
	return true;
}
int main()
{
	static char s[10000];
	gets(s);
	if(isPalindrome(s)){
		printf("true");
	}
	else{
		printf("false");
	}
	return 0;
}
