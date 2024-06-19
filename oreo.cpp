#include<bits/stdc++.h>
using namespace std;
int  main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        map <int,int> costnum;
        vector <int> ans(k+1,0);
        ans[0]=0;
        for(int j=0;j<n;j++){
            int cost,num;
            cin>>cost>>num;
            if(cost<=k) costnum[cost]=num;
        }
        for(auto &ele :costnum){
            int cost=ele.first;
            int num=ele.second;
            vector<int> arr=ans;
            for(int j=cost;j<=k;j++){
                 if (ans[j-cost]!=0||j==cost)
                arr[j]=max(arr[j],arr[j-cost]+num); //updated all possible cases with cost between cost to k.
            }
            ans=arr;
        }
        int maxnum=0;
        for(auto ele:ans){
            if(ele>maxnum) maxnum=ele;
        }
        // for(auto ele:ans) cout<<ele<<' ';
        // cout<<endl;
        cout<<maxnum<<endl;
    }
}