#include <bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){
	int l[n];
	for(int i=0;i<n;i++)
		l[i]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[i] && l[i]<l[j]+1)
				l[i]=l[j]+1;
		}
	}

	int max_val=INT_MIN;
	for(int i=0;i<n;i++){
		max_val=max(l[i],max_val);
	}

	return max_val;
}

int lds(int arr[],int end,int size){
	int n=size-end;
	int l[n];
	for(int i=0;i<n;i++)
		l[i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[end+i]<arr[end+j] && l[i]<l[j]+1)
				l[i]=l[j]+1;
		}
	}

	int max_val=INT_MIN;
	for(int i=0;i<n;i++){
		max_val=max(l[i],max_val);
	}

	return max_val;
}

int lbs(int arr[],int n){
	int max_val=INT_MIN;
	for(int i=0;i<n;i++){
		max_val=max(max_val,lis(arr,i)+lds(arr,i,n));
	}
	return max_val;
}

int main(){
 	int arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
 	int n=sizeof(arr)/sizeof(arr[0]);

 	cout<< lbs(arr,n);

	return 0;
}