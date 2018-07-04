#include <bits/stdc++.h>
using namespace std;

int lscs(int arr[],int n){
	int max_current,max_global;

	max_current=max_global=arr[0];

	for(int i=1;i<n;i++){
		max_current=max(arr[i],arr[i]+max_current);
		max_global=max(max_current,max_global);
	}
	return max_global;
}

int main(){
	int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<lscs(arr,n);

	return 0;
}