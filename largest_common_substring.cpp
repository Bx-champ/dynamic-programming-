#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    int ans=0;
    vector<vector<int>> dp(n+1,vector(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val=1+dp[i-1][j-1];
                dp[i][j]=val;
                ans=max(ans,val);
            }else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}
int main(){
    string s1,s2;
    cout<<"enter 1st string :";
    getline(cin,s1);
    cout<<"enter 2nd string:";
    getline(cin,s2);
    int res=lcs(s1,s2);
    cout<<res;
}
