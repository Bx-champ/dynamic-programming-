#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
            }else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1,s2;
    cout<<"enter string 1:";
    getline(cin,s1);
    cout<<"enter string 2:";
    getline(cin,s2);
    int res=lcs(s1,s2);
    cout<<res;
}
