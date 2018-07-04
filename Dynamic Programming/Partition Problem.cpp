#include <bits/stdc++.h>
using namespace std;

int subset(int arr[],int n,int sum){
	if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;
	if(arr[n-1]>sum)
		return subset(arr,n-1,sum);
	return subset(arr,n-1,sum)||subset(arr,n-1,sum-arr[n-1]);
}

bool findPartion(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];

	if(sum%2==0)
		subset(arr,n,sum/2);
	else
		return false;
}

int main(){
	int arr[] = {3, 1, 5, 9, 12};
  	int n = sizeof(arr)/sizeof(arr[0]);

  	if(findPartion(arr,n))
  		cout<<"true";
  	else
  		cout<<"false";


	return 0;
}