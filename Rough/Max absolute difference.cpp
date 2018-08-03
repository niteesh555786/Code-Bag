#include<bits/stdc++.h>
using namespace std;
int temp[105];

int maxArray(int arr[],int l,int r){
    temp[l]=arr[l];
    int maxVal=arr[l];
    for(int i=l+1;i<r;i++){
        temp[i]=max(arr[i],arr[i]+temp[i-1]);
        maxVal=max(temp[i],maxVal);
    }
    return maxVal;
}

int minArray(int arr[],int l,int r){
    temp[l]=arr[l];
    int minVal=arr[l];
    for(int i=l+1;i<r;i++){
        temp[i]=min(arr[i],arr[i]+temp[i-1]);
        minVal=min(minVal,temp[i]);
    }
    return minVal;
}


int main(){
    int t;
    cin>>t;
    int arr[105];
    int dp[105];
    int n;

    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int maxVal=arr[0];
        for(int i=0;i<n;i++){
            int leftMax=maxArray(arr,0,i);
            int leftMin=minArray(arr,0,i);
            int rightMax=maxArray(arr,i,n);
            int rightMin=minArray(arr,i,n);

            dp[i]=max(abs(rightMax-leftMin),abs(leftMax-rightMin));
            maxVal=max(maxVal,dp[i]);
        }

        cout<<maxVal<<endl;
    }


    return 0;
}