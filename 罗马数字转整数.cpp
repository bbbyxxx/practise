�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��

ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90�� 
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת��������������ȷ���� 1 �� 3999 �ķ�Χ�ڡ�

ʾ�� 1:

����: "III"
���: 3
ʾ�� 2:

����: "IV"
���: 4
ʾ�� 3:

����: "IX"
���: 9
ʾ�� 4:

����: "LVIII"
���: 58
����: L = 50, V= 5, III = 3.
ʾ�� 5:

����: "MCMXCIV"
���: 1994
����: M = 1000, CM = 900, XC = 90, IV = 4.
#include<bits/stdc++.h>
using namespace std;
/*int Switch(char c){
	switch(c){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
}
int romanToInt(char *s){
	int i,cnt=Switch(s[strlen(s)-1]);
	for(i=strlen(s)-2;i>=0;i--){
		if(Switch(s[i])<Switch(s[i+1])){
			cnt-=Switch(s[i]);
		}
		else{
			cnt+=Switch(s[i]);
		}
	}
	return cnt;
}*/
int romanToInt(char * s)
{
	int n[15];
	int i = 0, j = 0, k ;
	j = strlen(s);
	for (i = 0; s[i] != '\0'; i++)         
	{
		if (s[i] == 'I')
			n[i] = 1;
		if (s[i] == 'V')
			n[i] = 5;
		if (s[i] == 'X')
			n[i] = 10;
		if (s[i] == 'L')
			n[i] = 50;
		if (s[i] == 'C')
			n[i] = 100;
		if (s[i] == 'D')
			n[i] = 500;
		if (s[i] == 'M')
			n[i] = 1000;
	}
	k = n[j-1];                        
	for (j=strlen(s)-2; j>=0; j--)           
	{
		if (n[j] < n[j+1]){
			k -= n[j];
		}
		else{
			k += n[j];
		}
	}
	return k;  
}
int main()
{
	char s[100];
	gets(s);
	int t=romanToInt(s);
	cout<<t;
	return 0;
}

