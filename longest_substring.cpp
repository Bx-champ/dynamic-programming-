#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    string s3="";
    int ans=0;
    int ind1,ind2;
    vector<vector<int>> dp(n+1,vector(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val=1+dp[i-1][j-1];
                dp[i][j]=val;
                if(val>=ans){
                    ind1=i;
                    ind2=j;
                }
                ans=max(ans,val);
                
            }else{
                dp[i][j]=0;
            }
        }
    }
    cout<<"ind1:"<<ind1<<endl<<"ind2:"<<ind2<<endl;
    while(dp[ind1][ind2]>0 && (ind1!=0 || ind2!=0)){
       s3=s1[ind1-1]+s3;
       ind1=ind1-1;
       ind2=ind2-1;
    }
    cout<<"substring is :"<<s3<<endl;
    return ans;
}
int main(){
    string s1,s2;
    cout<<"enter 1st string :";
    getline(cin,s1);
    cout<<"enter 2nd string:";
    getline(cin,s2);
    int res=lcs(s1,s2);
    cout<<"longest substring length is:"<<res;
}
