/*��֤�����ַ���
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false
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
