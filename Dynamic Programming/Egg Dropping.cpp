#include <bits/stdc++.h>
using namespace std;

/*int eggDrop(int n,int k){
	if(k==0 || k==1)
		return k;

	if(n==1)
		return k;

	int min=INT_MIN;
	int res;
	for(int x=1;x<=k;x++){
		res=max(eggDrop(n-1,x-1),eggDrop(n,k-x));
		if(res<min)
			min=res;
	}

	return min +1;
}*/

int eggDrop(int n,int k){
	int dp[n+1][k+1];

	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}

	for(int i=1;i<=k;i++)
		dp[1][i]=i;

	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				int res=1+max(dp[i-1][x-1],dp[i][j-x]);
				if(res<dp[i][j])
					dp[i][j]=res;
			}
		}
	}

	return dp[n][k];


}


int main(){
	int n=2,k=36;
	cout<<eggDrop(n,k);

	return 0;
}