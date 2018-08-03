#include <bits/stdc++.h>
using namespace std;

int fap(char str[],int n){
    int dp[n][n];

    for(int i=0;i<n;i++){
        dp[i][i]=0;
        if(i!=n-1 && str[i]==str[i+1])
            dp[i][i+1]=0;
        if(i!=n-1 && str[i]!=str[i+1])
            dp[i][i+1]=1;
    }

    for(int cl=3;cl<=n;cl++){
        for(int i=0;i<n-cl+1;i++){
            int j=i+cl-1;
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1];
            else
                dp[i][j]=min(dp[i][j-1],dp[i+1][j])+1;
        }
    }

    return dp[0][n-1];

}

int main(){
    int t;
    cin>>t;

    char str[44];
    int n;
    

    while(t--){
        cin>>str;
        n=strlen(str);

        cout<<fap(str,n)<<endl;
    }

    return 0;
}
