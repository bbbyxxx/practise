 ��Ч����ĸ��λ��
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ��һ����ĸ��λ�ʡ�

ʾ�� 1:

����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:

����: s = "rat", t = "car"
���: false
˵��:
����Լ����ַ���ֻ����Сд��ĸ��

����:
��������ַ������� unicode �ַ���ô�죿���ܷ������Ľⷨ��Ӧ�����������
#include<bits/stdc++.h>
using namespace std;
bool reverseString(char *s,char *t)
{
	int i,j,cnt1=0,cnt2=0;
	int b[26]={0};
	if(strlen(s)!=strlen(t)){
		return 0;
	}
	else{
		for(i=0;i<strlen(s);i++){
			cnt1+=abs(s[i]-t[i]-'0');
			b[s[i]-'a']++;
		}
		for(j=0;j<strlen(t);j++){
			cnt2+=abs(t[j]-s[j]-'0');
			b[t[j]-'a']--;
		}
	}
	for(i=0;i<26&&b[i]==0;i++);
	if(cnt1==cnt2&&i==26){
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	char s[10000];
	gets(s);
	char t[10000];
	gets(t);
	int p;
	p=reverseString(s,t);
	if(p){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
			}
	return 0;
}
