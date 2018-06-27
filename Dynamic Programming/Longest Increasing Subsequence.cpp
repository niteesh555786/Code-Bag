#include <iostream>
using namespace std;

int lis(int arr[],int n){
	int l[n];

	for(int i=0;i<n;++i)
		l[i]=1;

	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){
			if(arr[i]>arr[j] && l[i]< l[j]+1)
				l[i]=l[j]+1;
		}
	}

	int max=INT_MIN;
	for(int i=0;i<n;++i){
		if(max<l[i])
			max=l[i];
	}

	return max;
}

int main(){
	int arr[]={2,4,5,1,3,10,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<lis(arr,n);

	return 0;
}