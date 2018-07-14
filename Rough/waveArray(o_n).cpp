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
	    
	    for(int i=0;i<n;i+=2){
	        if(i>0 && arr[i-1]>arr[i])
	            swap(&arr[i-1],&arr[i]);
	        if(i<n-1 && arr[i+1]> arr[i])
	            swap(&arr[i+1],&arr[i]);
	    }
	    
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	   cout<<endl;
	}
	return 0;
}