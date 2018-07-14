#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main() {
	int t;
	cin>>t;
	int n;
	int arr[1005];
	
	while(t--){
	    cin>>n;
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    sort(arr,arr+n);

	    for(int i=0;i<n-1;i+=2)
	    	swap(&arr[i],&arr[i+1])
	    
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	   cout<<endl;
	}
	return 0;
}