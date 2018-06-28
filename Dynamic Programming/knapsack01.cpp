#include <bits/stdc++.h>
using namespace std;

//recursion
/*int knapsack(int wt[],int val[],int W,int n){
	if(n==0 || W==0)
		return 0;
	
	if(wt[n-1]>W)
		return knapsack(wt,val,W,n-1);

	else 
		return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
}*/

//memoisation
int knapsack(int wt[],int val[],int W,int n){
	int dp[n+1][W+1];

	for(int i=0;i<n+1;++i){
			for(int j=0;j<W+1;++j){
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(wt[i-1]>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
		}
	}

	return dp[n][W];
}

int main(){
	int wt[]={10,20,30};
	int val[]={60,100,120};

	int W=50;
	int n=sizeof(wt)/sizeof(wt[0]);

	cout<<knapsack(wt,val,W,n);

	return 0;
}
