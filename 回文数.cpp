#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x){
	long long int i,j,t=0,k;
	k=x;
	if(k<0){
		return 0;
	} 
	while(k){
		t=t*10+k%10;
		k=k/10;
	}
	return t==x?1:0;
}
int main()
{
	int n;
	cin>>n;
	if(isPalindrome(n)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}
