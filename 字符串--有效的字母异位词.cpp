 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
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
