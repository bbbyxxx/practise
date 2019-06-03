编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
#include<bits/stdc++.h>
using namespace std;
char * longestCommonPrefix(char ** strs, int strsSize){
	int i = 0, j = 0;
	static char rets[10000];
    if (strsSize == 0){
    	return "";
    }
    for(int k = 0; k < 10000; k++){
        rets[k] = '\0';//初始化 
    }
	while (strs[0][i] != '\0')
	{
        
		for (j = 1; j < strsSize; j++)
		{
			if (strs[0][i] != strs[j][i]){//字符不相等，结束函数 
				return rets;
			}
		}
		rets[i] = strs[0][i];//将公共部分存入新字符数组中 
		i++;
	}
	rets[i] = '\0';//直到一个字符串遍历完  附上结尾符 
	return rets;
}
int main()
{
	int n;
	cin>>n;
	char *p[n];   
	char arr[n][100];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
		p[i]=arr[i]; 
	}
	char *b=longestCommonPrefix(p,n);
	printf("%s",b);
	return 0;
}
