#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[],int n){
    int i,j=n-1;
    
    

    while(j){
        i=n-1;
        while(arr[i]<0 && i>=0)
            i--;//1st +ve from left
        j=i-1;
        while(arr[j]>=0 && j>0){
            if(j!=0)
                j--;//1st -ve from left after i
        }
        
        if(j==0 && arr[0]>=0)
            break;

        int temp=arr[j];
        for(int k=j;k<i;k++){
            arr[k]=arr[k+1];
        }

        arr[i]=temp;
    }
}

int main(){
    int arr[1005];
    int t;
    int n;
    cin>>t;
    
    while(t--){
    
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];

    rearrange(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    }

    return 0;
}