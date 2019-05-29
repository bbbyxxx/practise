#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(int* nums, int numsSize){
	sort(nums,nums+numsSize);
    for(int i=0;i<numsSize;i++){
        if(nums[i]==nums[i+1]){
            return true;
        }
    }
	return false;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(containsDuplicate(a,n)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}
