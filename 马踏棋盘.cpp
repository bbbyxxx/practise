#include<bits/stdc++.h>
int cnt = 0;//标记
int H[12][12] = {0};
int count = 0;
int Move[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
void Print(){
        for (int i = 2; i < 10; i++) {
            for (int j = 2; j < 10; j++) {
                printf("%4d",H[i][j]);
            }
            printf("\n");
        }
    }


void Horse(int x,int y){
        for (int i = 0; i < 8; i++) {
            //计算a，b
            int a = x + Move[i][0];
            int b = y + Move[i][1];
            if (H[a][b] == 0){//能踏
                H[a][b] = ++cnt;//标记
                if (cnt == 64){
                	count++;
                    Print();
                    printf("\n");
                }else{
                    Horse(a,b);
                }
                H[a][b] = 0;//抹掉
                cnt--;
            }
        }
    }

int main() {
	for(int i = 0;i<12;i++){
		for(int j = 0;j<12;j++){
			if(i==0||i==1||i==10||i==11){
				H[i][j]=-1;
			}
			if(j==0||j==1||j==10||j==11){
				H[i][j]=-1;
			}
		}
	}
        for (int i = 2; i < 10; i++) {
            for (int j = 2; j < 10; j++) {
                cnt = 0;
                H[i][j] = ++cnt;
                Horse(i,j);
            }
        }
        printf("共%d组解！",count);
    }
