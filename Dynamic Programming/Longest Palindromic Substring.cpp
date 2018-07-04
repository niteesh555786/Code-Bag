#include <bits/stdc++.h>
using namespace std;

void printStr(char *str,int n,int m){
	for(int i=n;i<m;i++)
		cout<<str[i];
	cout<<endl;
}

int lps(char *str){
	
	int n=strlen(str);
	int maxlength=1;
	int start=0;
	bool dp[n][n];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++){
		dp[i][i]=true;

		if(str[i]==str[i+1] && i!=n-1){
			dp[i][i+1]=true;
			start=i;
			maxlength=2;
		}
	}

	for(int k=3;k<=n;k++){//k is for length
		for(int i=0;i<n-k+1;i++){// i is for the starting index
			int j=i+k-1;// j is for ending index
			if(str[i]==str[j] && dp[i+1][j-1]){
				dp[i][j]=true;
				start=i;
				maxlength=max(k,maxlength);
			}
		}
	}
	printStr(str,start,start+maxlength);

	return maxlength;
}

int main(){
	char str[] = "forgeeksskeegfor";
	cout<<lps(str);

	return 0;
}