#include <bits/stdc++.h>
using namespace std;

int min(int x,int y,int z){
		return (min(x,y),z);
}

int editDistance(string str1, string str2, int n, int m	){
	int l[n+1][m+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)
				l[i][j]=j;
			else if(j==0)
				l[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				l[i][j]=l[i-1][j-1];
			else
				l[i][j]=1+min(l[i-1][j],l[i][j-1],l[i-1][j-1]);
		}
	}

	return l[n][m];
}

int main(){
	string str1 = "sunday";
    string str2 = "saturday";

    cout<<editDistance(str1,str2,str1.length(),str2.length());

	return 0;
}
