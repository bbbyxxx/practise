�ַ����еĵ�һ��Ψһ�ַ�
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��

����:

s = "leetcode"
���� 0.

s = "loveleetcode",
���� 2.
 

ע����������Լٶ����ַ���ֻ����Сд��ĸ��
int firstUniqChar(char * s){
    int hashtable[256];
    int i,l=strlen(s),ret=-1;
    memset(hashtable,0,sizeof(int)*256);
    if(l){
            
        for(i=0;i<l;i++)
        {
            hashtable[s[i]]++;
        }
        for(i=0;i<l;i++)
        {
            if(hashtable[s[i]]==1){          
                ret = i;
                break;
            }
        }
    }
 
    return ret;
}

