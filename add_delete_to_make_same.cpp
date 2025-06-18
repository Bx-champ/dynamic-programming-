#include<bits/stdc++.h>
using namespace std;
int lcs(string word1,string word2){
   int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1]==word2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];

                }else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        int res=(n-dp[n][m])+(m-dp[n][m]);
        return res;
        
    
}
int main(){
    string s1,s2;
    cout<<"enter 1st string :";
    getline(cin,s1);
    cout<<"enter 2nd string:";
    getline(cin,s2);
    
    int l=lcs(s1,s2);
    cout<<"string length to add and delete are :"<<l;
    
}
