��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��
#include<bits/stdc++.h>
using namespace std;
char * longestCommonPrefix(char ** strs, int strsSize){
	int i = 0, j = 0;
	static char rets[10000];
    if (strsSize == 0){
    	return "";
    }
    for(int k = 0; k < 10000; k++){
        rets[k] = '\0';//��ʼ�� 
    }
	while (strs[0][i] != '\0')
	{
        
		for (j = 1; j < strsSize; j++)
		{
			if (strs[0][i] != strs[j][i]){//�ַ�����ȣ��������� 
				return rets;
			}
		}
		rets[i] = strs[0][i];//���������ִ������ַ������� 
		i++;
	}
	rets[i] = '\0';//ֱ��һ���ַ���������  ���Ͻ�β�� 
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
