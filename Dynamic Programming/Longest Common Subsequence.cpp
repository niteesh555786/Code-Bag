#include <bits/stdc++.h>
using namespace std;

int lcs(char p[],char q[],int n,int m){
	int l[m+1][n+1];

	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i==0 || j==0)
				l[i][j]=0;
			else if(p[i]==q[j])
				l[i][j]=l[i-1][j-1] +1;
			else
				l[i][j]=max(l[i-1][j],l[i][j-1]);
		}
	}

	return l[m][n];

}

int main(){
	char p[]="ABCDGH";
	char q[]="AEDFHR";
	
	int m = strlen(p);
    int n = strlen(q);

	cout<<lcs(p,q,n,m);

	return 0;
}
