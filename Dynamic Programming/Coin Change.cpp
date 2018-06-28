#include <bits/stdc++.h>
using namespace std;

//recursive
/*int coinChange(int arr[],int m,int n){
	if(n==0 )
		return 1;
	if(n<0)
		return 0;
	if(m<=0 & n>=1)
		return 0;
	return (coinChange(arr,m-1,n)+coinChange(arr,m,n-arr[m-1]));

}*/

int coinChange(int arr[],int m,int n){
	int dp[n+1][m];

	for(int i=0;i<m;i++)
		dp[0][i]=1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<m;++j){
			int x=(i-arr[j])>=0?dp[i-arr[j]][j]:0;
			int y=(j-1)>=0?dp[i][j-1]:0;

			dp[i][j]=x+y;
		}
	}

	return dp[n][m-1];
}

int main(){
	int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;

	cout<<coinChange(arr,m,n);
	return 0;
}
