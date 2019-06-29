#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct{
	char data[5];//���� 
	float weight;//Ȩ��
	int parent;//˫�׽��
	int lchild;//���ӽ�� 
	int rchild;//�Һ��ӽ�� 
}HTNode;



typedef struct{
	char cd[N];//��ŵ�ǰ���Ĺ��������� 
	int start;//startָ��cd�������ʼ�������±� 
}HCode;

void CreateHuffmanTree(HTNode ht[],int n)
{
	int i,j,k,lnode,rnode;
	float min1,min2;
	for(i=0;i<2*n-1;i++){//���н���˫�ף����Һ�����ֵ-1 
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	} 
	for(i=n;i<2*n-1;i++){//��Ϊ0~n-1�����Ҷ�ӽ���Ȩֵ�����Դ�n��ʼ��2n-2��n��Ҷ�ӽ���Huffman�����ܹ���2n-1����� 
		min1=min2=32767;//�����ܴ������Ƚϵõ�Сֵ��ḳ��min
		lnode=rnode=-1;//��СȨ�ص���������±� 
		for(k=0;k<i;k++){//��ԭ���鷶Χ��Ѱ�ң����ν���ֵ����Ȼ����ֵ����Ϊԭֵ��������Ȩֵ��С��������� 
			if(ht[k].parent==-1){//ֻ����δ�����������Ľ���в��� 
				if(ht[k].weight<=min1){//С����С 
					min2=min1;//��С������С 
					rnode=lnode;//ָ���СȨֵ����ָ����� 
					min1=ht[k].weight;//��Сֵ���� 
					lnode=k;//��Сֵ��ָ����� 
				}
				else if(ht[k].weight<min2){//��������С��С�ڴ�С 
					min2=ht[k].weight;//���´�Сֵ 
					rnode=k;//����ָ���Сֵ��ָ�� 
				}
			}
		}//for��k��   �õ���С����С 
			ht[lnode].parent=i;
			ht[rnode].parent=i;
			ht[i].weight=ht[lnode].weight+ht[rnode].weight;//�õ��µ�Ȩֵ 
			ht[i].lchild=lnode;//ָ����СȨֵ��� 
			ht[i].rchild=rnode;//ָ���СȨֵ��� 
	}
}

void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
	int i,f,c;
	HCode hc;
	for(i=0;i<n;i++){//����Huffman������������� 
		hc.start=n;
		c=i;//ÿ��ָ��ǰҶ�ӽ����±� 
		f=ht[i].parent;//fÿ��ָ��ǰҶ�ӽ���˫�� 
		while(f!=-1){//ѭ��ֱ����˫�׽��Ľ�㣬������� 
			if(ht[f].lchild==c){//������ 
				hc.cd[hc.start--]='0';
			}
			else{//���Һ��� 
				hc.cd[hc.start--]='1';
			}
			c=f;//c����Ϊ˫�׽�� 
			f=ht[f].parent;//f����Ϊ˫�׽���˫�� 
		}
		hc.start++;//��ù����������start��ָ����ǰһ��Ԫ�أ�Ӧ�ü�һָ���ʼԪ�� 
		hcd[i]=hc;//hcd������յ�ǰҶ�ӽ������������startֵ 
	}
}

void Print(HTNode ht[],int n)
{
	for(int i=n;i<2*n-1;i++){
		//printf("%c+%c=%5.2f\n",ht[ht[i].lchild].data,ht[ht[i].rchild].data,ht[i].weight);
		printf("%5.2f\n",ht[i].weight);
	}
}

void PrintHuffmanCode(HTNode ht[],HCode hcd[],int n)
{
	int i,k,j;
	double sum=0,m=0;
	printf("����Ĺ���������Ϊ��\n");
	for(i=0;i<n;i++){
		j=0;//�����Ȩ·������ 
		printf("%s::",ht[i].data);
		for(k=hcd[i].start;k<=n;k++){
			printf("%c",hcd[i].cd[k]);
			j++;
		}
		m+=ht[i].weight;//����Ҷ�ӽ��Ȩ��֮�� 
		sum+=ht[i].weight*j;//�����Ȩ·������ֵ
		printf("\n");
	} 
	printf("m=%5.2lf��n=%5.2lf",m,sum);//�����Ȩ·������ֵ 
}

int main()
{
	int n;
	printf("������Ҷ�ӽ�����:");
	scanf("%d",&n);
	HTNode ht[n*2-1];
	printf("������Ҷ�ӽ���Ȩֵ��");
	int i=0;
	while(i<n){
		scanf("%s %f",ht[i].data,&ht[i].weight);
		i++;
	}
	CreateHuffmanTree(ht,n);//������������ 
	Print(ht,n);//����ϳɵĸ�����Ȩ�� 
	HCode hcd[n];//��ȡn��Ҷ�ӽ��Ĺ��������� 
	CreateHCode(ht,hcd,n);//��ȡ��Ӧ�Ĺ��������� 
	PrintHuffmanCode(ht,hcd,n);//�����Ҷ�ӽ��Ĺ��������� 
	return 0;
}
