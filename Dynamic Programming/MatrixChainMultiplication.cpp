#include <bits/stdc++.h>
using namespace std;

/*int mcm(int arr[],int i,int j){
	if(i==j)
		return 0;
	int minVal=INT_MAX;

	for(int k=i;k<j;k++)
		minVal=min(minVal,mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);

	return minVal;
}*/
int mcm(int arr[],int n){
	int dp[n][n];

	for(int i=0;i<n;i++)
		dp[i][i]=0;

	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main(){
	int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<mcm(arr,n);
	return 0;
}