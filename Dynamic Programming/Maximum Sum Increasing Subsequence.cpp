#include <bits/stdc++.h>
using namespace std;

int msis(int arr[],int n){
	int dp[n];
	dp[0]=arr[0];

	int g_max=dp[0];
	for(int i=1;i<n;i++){
		int max_val=INT_MIN;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				max_val=max(max_val,arr[i]+dp[j]);
			}
		}
		dp[i]=max_val;
		g_max=max(g_max,max_val);
	}

	return g_max;
}

int main(){
	int arr[]= {1, 101, 2, 3, 100, 4, 5};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<msis(arr,n);
}