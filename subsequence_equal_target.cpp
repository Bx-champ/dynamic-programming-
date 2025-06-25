#include<bits/stdc++.h>
using namespace std;
bool second(int ind,int target,vector<int>arr,vector<vector<int>> dp){
    if(target==0){
        return true;
    }
    if(ind==0){
        return (target==arr[0]);
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool not_taken=second(ind-1,target,arr,dp);
    bool taken=false;
    if(arr[ind]<=target){
        taken = second(ind-1,target-arr[ind],arr,dp);
    }
    return not_taken || taken;
}
bool first(vector<int>arr,int target){
    int n=arr.size();
    vector<vector<int>> dp(n,vector(target+1,-1));
    bool res1=second(n-1,target,arr,dp);
    return res1;
    
}
int main(){
    int n;
    int target;
    cout<<"enter the size";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    cout<<"enter the target :";
    cin>>target;
    bool res = first(arr,target);
    cout<<res;
}
