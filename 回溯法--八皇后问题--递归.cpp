//��˷��--�˻ʺ����� 
#include<stdio.h>
int col[8]={0};
int left[15]={0};
int right[15]={0};
int Q[8]={0};
int cnt=0;

void Print()
{
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
		if(Q[i]==j){//�ʺ��λ�� �����±�iΪ������Q[i]��ֵΪ��Ӧ������ 
		printf("X  ");//��ǻʺ� 
		}
		else{
			printf("0  ");
		} 
		}
		printf("\n");
	}
	printf("\n"); 
}

void Queen(int i)
{
	/*if(i>7){
				cnt++;
				Print();
	} 
	else{
	for(int j=0;j<8;j++){
		if(!left[i+j]&&!right[7+i-j]&&!col[j]){
			Q[i]=j;//�Żʺ�
			left[i+j]=1;//��ǵ�ǰ�У���б�ߣ���б�� 
			right[i+7-j]=1;//�������лʺ� 
			col[j]=1;
			Queen(i+1);
						//Ĩ���ʺ� ������j�Ѿ����뵽��һ��ѭ���ˣ������൱��Ĩ���˻ʺ� 
			left[i+j]=0;//��ǵ�ǰ�У���б�ߣ���б�� 
			right[i+7-j]=0;//�����ʺ���Ĩȥ 
			col[j]=0;
		}
	}
 }*/
 
	for(int j=0;j<8;j++){
		if(!left[i+j]&&!right[7+i-j]&&!col[j]){
			Q[i]=j;//�Żʺ�
			left[i+j]=1;//��ǵ�ǰ�У���б�ߣ���б�� 
			right[i+7-j]=1;//�������лʺ� 
			col[j]=1;
			if(i<7){
			Queen(i+1);
		}
			else{
				cnt++;
				Print();
			}
						//Ĩ���ʺ� ������j�Ѿ����뵽��һ��ѭ���ˣ������൱��Ĩ���˻ʺ� 
			left[i+j]=0;//��ǵ�ǰ�У���б�ߣ���б�� 
			right[i+7-j]=0;//�����ʺ���Ĩȥ 
			col[j]=0;
		}
	}
}

int main()
{
	Queen(0);
	printf("�ܹ���%d��⣡",cnt);
	return 0;
	
}
