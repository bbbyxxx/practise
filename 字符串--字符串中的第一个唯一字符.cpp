字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。
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

