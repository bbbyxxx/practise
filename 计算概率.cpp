/*
假设淘宝网上某商品A在任一时刻t内若有人浏览，
则该商品在下一时刻t+1内无人浏览的概率为0.35
（即下一时刻的浏览情况仅与当前时段相关），
定义此条件概率为 P(O_{t+1}=0|O_t=1)=0.35
(即用“1”代表有人浏览的事件，用“0”代表无人浏览的事件），
类似得定义P(O_{t+1}=1|O_t=1)=0.65，P(O_{t+1}=0|O_t=0)=0.4，P(O_{t+1}=1|O_t=0)=0.6。
若此商品A在t=0时有人浏览，它在t=100000时有人浏览的概率是（ C ）
A.0.5371	B.0.4582	C.0.6316
D.0.1435	E.0.3276	F.0.7132
*/
#include <stdio.h>
double fun (int times,int juduge){
	if(times==25){
		if(juduge==1){
		   return 0.65;
		}
		else{
		   return 0.6;
		}
	}
	else{
		if(juduge==1){
		   return 0.35*fun(times+1,0)+0.65*fun(times+1,1);
		}
		if(juduge==0){
		   return 0.4*fun(times+1,0)+0.6*fun(times+1,1);
		}
	}
}
int main (void)
{
	printf("%lf\n",fun(1,1));
	return 0;
}

