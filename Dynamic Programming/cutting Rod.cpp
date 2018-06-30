#include <bits/stdc++.h>
using namespace std;

/*int cutRod(int arr[],int n){
	if(n<=0)
		return 0;
	int max_val=INT_MIN;

	for(int i=0;i<n;i++)
		max_val=max(max_val,arr[i]+cutRod(arr,n-1-i));

	return max_val;
}*/

int cutRod(int arr[],int n){
	if(n==0)
		return 0;

	int dp[n+1];
	dp[0]=0;
	

	for(int i=1;i<=n;i++){
		int max_val=INT_MIN;
		for(int j=0;j<i;j++){
			max_val=max(max_val,arr[j]+dp[i-1-j]);
		}
		dp[i]=max_val;
	}

	return dp[n];
}

int main(){
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<cutRod(arr,n);

	return 0;
}