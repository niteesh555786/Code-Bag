#include <bits/stdc++.h>
using namespace std;

int min(int x,int y,int z){
	return min(min(x,y),z);
}

int minCost(int cost[3][3],int m,int n){
	int dp[3][3];

	dp[0][0]=cost[0][0];
	for(int i=1;i<=m;i++)
		dp[i][0]=dp[i-1][0]+cost[i][0];

	for(int j=1;j<=n;++j)
		dp[0][j]=dp[0][j-1]+cost[0][j];

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]= cost[i][j]+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}

	return dp[m][n];
}

int main(){
	int cost[3][3]={ {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

    cout<<minCost(cost,2,2);	

	return 0;
}