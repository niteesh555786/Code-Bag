#include <bits/stdc++.h>
using namespace std;

/*bool ss(int set[],int n,int sum){
	if(sum==0)
		return true;

	if(n==0 && sum !=0)
		return false;
	
	if(set[n-1]>sum)
		return ss(set,n-1,sum);

	return (ss(set,n-1,sum-set[n-1]) || ss(set,n-1,sum));
}
*/

bool ss(int set[],int n,int sum){
	bool ss[n+1][sum+1];
	for(int i=0;i<n;i++)
		ss[i][0]=true;
	for(int i=1;i<n;i++)
		ss[0][i]=false;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<set[i-1])
				ss[i][j]=ss[i-1][j];
			if(j>=set[i-1])
				ss[i][j]=(ss[i-1][j] || ss[i-1][j-set[i-1]]);
		}
	}

	return ss[n][sum];
}


int main(){
	int set[]={3, 34, 4, 12, 5, 2};
	int sum=9;
	int n=sizeof(set)/sizeof(set[0]);

	if(ss(set,n,sum))
		cout<<"true";
	else
		cout<<"false";


	return 0;
}