/*ʵ��strStr()
ʵ�� strStr() ������

����һ�� haystack �ַ�����һ�� needle �ַ�����
�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ�� 1:

����: haystack = "hello", needle = "ll"
���: 2
ʾ�� 2:

����: haystack = "aaaaa", needle = "bba"
���: -1
˵��:

�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�
����һ���������кܺõ����⡣

���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ��
����C���Ե� strstr() �Լ� Java�� indexOf() ���������*/
#include<bits/stdc++.h>
#define N 1001
using namespace std;
int Index(char s[],char t[])
{
	int s1=strlen(s);
	int t1=strlen(t);
	int i=0,j=0;
	while(i<s1&&j<t1){
		if(s[i]==t[j]){//����ƥ����һ���ַ� 
			i++;
			j++;
		}
		else{//�������Ӵ�ָ��������¿�ʼ��һ��ƥ�� 
			i=i-j+1;//��������һ��λ�ÿ�ʼƥ�� 
			j=0;//�Ӵ���ͷ��ʼƥ�� 
		}
	}
	if(j>=t1){
		return (i-t1);//����ƥ��ĵ�һ���ַ����±� 
	}
	else{
		return -1;//ƥ�䲻�ɹ� 
	}
}
int main()
{
	char a[N];
	cout<<"������������";
	gets(a);
	char b[N];
	cout<<"������ģʽ����";
	gets(b);
	int t=Index(a,b);
		cout<<t<<endl; 
	return 0; 
}
