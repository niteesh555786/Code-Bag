#include<bits/stdc++.h>
using namespace std;

int maxMat(int arr[],int l,int r){
    int maxVal=INT_MIN;
    for(int i=l;i<r;i++){
        maxVal=max(maxVal,arr[i]);
    }
    return maxVal;
}


int main(){
    int t;
    cin>>t;
    int arr[105];
    int dp[105];
    int n;
    
    while(t--){
        cin>>n;
        dp[0]=0;
        dp[n-1]=0;
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
    
        for(int i=1;i<n-1;i++){
            int max_l=maxMat(arr,0,i);
            int max_r=maxMat(arr,i+1,n);
    
            if(arr[i]>=max_l || arr[i]>=max_r)
                dp[i]=0;
            else
                dp[i]=min(max_l,max_r)-arr[i];
        }
    
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=dp[i];
    
        cout<<sum<<endl;

    }

    return 0;
}
