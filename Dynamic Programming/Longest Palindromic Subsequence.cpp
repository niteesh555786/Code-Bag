#include <bits/stdc++.h>
using namespace std;

/*int lps(char a[],int i,int j){
	if(i==j)
		return 1;
	if(j==i+1 && a[j]==a[i])
		return 2;
	if(a[i]==a[j])
		return lps(a,i+1,j-1) +2;
	else
		return max(lps(a,i+1,j),lps(a,i,j-1));

}*/

int lps(char a[], int n){
	int l[n][n];

	for(int i=0;i<n;i++){
		l[i][i]=1;
	}

	for (int cl=2; cl<=n; cl++)
    {
        for (int i=0; i<n-cl+1; i++)
        {
            int j = i+cl-1;
            if (a[i] == a[j] && cl == 2)
               l[i][j] = 2;
            else if (a[i] == a[j])
               l[i][j] = l[i+1][j-1] + 2;
            else
               l[i][j] = max(l[i][j-1], l[i+1][j]);
        }
    }

	return l[0][n-1];
}

int main(){
	char a[]="GEEKSFORGEEKS";
	int n=strlen(a);
	cout<<lps(a,n);

	return 0;
}
