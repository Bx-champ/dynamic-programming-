#include<bits/stdc++.h>
using namespace std;
int lcs(string s){
    string s1=s;
    reverse(s.begin(),s.end());
    int n=s1.size();
    int m=s.size();
    vector<vector<int>> dp(n+1,vector(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int ind=1;ind<=n;ind++){
        for(int jnd=1;jnd<=m;jnd++){
            if(s1[ind-1]==s[jnd-1]){
                dp[ind][jnd]=1+dp[ind-1][jnd-1];
            }else{
                dp[ind][jnd]=max(dp[ind-1][jnd],dp[ind][jnd-1]);
            }
        }
    }
    return dp[n][m];
    
}
int main(){
    string s;
    cout<<"enter the string :";
    getline(cin,s);
    int size=s.size();
    int l=lcs(s);
    cout<<"string length to make the pallindrom are :"<<(size-l);
    
}
