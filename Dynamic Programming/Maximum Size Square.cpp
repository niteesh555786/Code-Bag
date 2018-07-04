#include <bits/stdc++.h>
using namespace std;
#define R 6
#define C 5

int min(int x,int y,int z){
 	if(x<y)
 		return (x<z)?x:z;
 	else
 		return (y<z)?y:z;
}

int maxSquare(int arr[][C]){
	int dp[R][C];
	int maxVal=INT_MIN;

	for(int i=0;i<R;i++)
		dp[i][0]=arr[i][0];
	for(int i=0;i<C;i++)
		dp[0][i]=arr[0][i];

	for(int i=1;i<R;i++){
		for(int j=1;j<C;j++){
			if(arr[i][j]==1){
				dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
				maxVal=max(maxVal,dp[i][j]);
			}
			else
				dp[i][j]=0;
		}
	}

	return maxVal;
}

int main(){
	int M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

    cout<<maxSquare(M);


	return 0;
}