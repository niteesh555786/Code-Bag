#include <bits/stdc++.h>
using namespace std;

/*int minJumps(int arr[],int l,int h){
	if(l==h)
		return 0;
	if(arr[l]==0)
		return INT_MAX;

	int min=INT_MAX;
	for(int i=l+1;i<=h && i<=l+arr[l];i++){
		int jumps=minJumps(arr,i,h);
		if(jumps !=INT_MAX && jumps+1<min)
			min=jumps+1;
	}

	return min;
}*/

int minJumps(int arr[],int n){
	int *jumps= new int[n];
	int i,j;

	if(n==0 || arr[0]==0)
		return INT_MAX;

	jumps[0]=0;
	for(int i=1;i<n;i++){
		jumps[i]=INT_MAX;
		for(int j=0;j<i;j++){
			if(i<=j+arr[j] && jumps[j]!=INT_MAX){
				jumps[i]=min(jumps[i],jumps[j]+1);
				break;
			}
		}
	}

	return jumps[n-1];
}

int main(){
	int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	int n=sizeof(arr)/sizeof(arr[0]);
	int count=0;

	cout<<minJumps(arr,n);

	return 0;
}