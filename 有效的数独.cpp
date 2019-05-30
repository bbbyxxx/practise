 判断一个 9x9 的数独是否有效。
 只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
示例 2:

输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
 #include<bits/stdc++.h>
 using namespace std;
 bool isValidSudoku(char** board, int RSize, int CSize){
		int map[10],i,j,k,l,num;  
    if(boardRowSize!=9 || boardColSize!=9)return false;  
    for(i=0;i<9;i++){  
        memset(map,0,sizeof(map));  
        for(j=0;j<9;j++){  
            if(board[i][j]=='.')continue;  
            if(board[i][j]<'0' || board[i][j]>'9')return false;  
            num=board[i][j]-'0';  
            if(map[num]!=0)return false;  
            map[num]=1;  
        }  
    }  
    for(j=0;j<9;j++){  
        memset(map,0,sizeof(map));  
        for(i=0;i<9;i++){  
            if(board[i][j]=='.')continue;  
            num=board[i][j]-'0';  
            if(map[num]!=0)return false;  
            map[num]=1;  
        }  
    }  
    for(i=0;i<9;i+=3){  
        for(j=0;j<9;j+=3){  
            memset(map,0,sizeof(map));  
            for(k=i;k<i+3;k++){  
                for(l=j;l<j+3;l++){  
                    if(board[k][l]=='.')continue;  
                    num=board[k][l]-'0';  
                    if(map[num]!=0)return false;  
                    map[num]=1;  
                }  
            }  
        }  
    }  
    return true;  
    
		/*int i,j,t,k;
		bool a[9][9];//标记行 
		bool b[9][9];//标记列
		bool c[9][9];//标记3*3小方阵
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				a[i][j]=0;
				b[i][j]=0;
				c[i][j]=0;
			}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(board[i][j]!='.'){
					t=board[i][j]-'1';//第t列 
					k=i/3*3+j/3;//计算是第几行即表示的第几块 
					if(a[i][t]||b[j][t]||c[k][t]){//任何一个不是0表示当前位置已经有过此元素了 
						 return false;
						} 
					else{
						a[i][t]=1;
						b[j][t]=1;
						c[k][t]=1;	
					}
			}
				else{
					continue;
					}
			}
		}
		return true;*/
}
 int main()
 {
 	char *p[9];
 	char a[9][9];
 	for(int i=0;i<9;i++){
 		for(int j=0;j<9;j++){
 			cin>>a[i][j];
 		}
 	}
 	for(int k=0;k<9;k++){
 		p[k]=a[k];
 	}
 	if(isValidSudoku(p,9,9)){
 		cout<<"true";
 	}
 	else{
 		cout<<"false";
 	}
 	
 	return 0;
 }
