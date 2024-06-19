#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,paircount=0;
    cin>>n;
    vector<vector<int>> arr(11);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int digsum=0;
        for(auto ch:s){
            // cout<<int(ch)-48<<' ';
            digsum+=(int(ch)-48);
        }
        // cout<<digsum<<endl;
        arr[s.size()].push_back(digsum);
    }

    for(int i=2;i<=6;i++){
        vector<int> vec(50,0),vec2(50,0);
        for(auto ele:arr[i]){
            // cout<<ele<<' ';
            vec[ele]+=1;
        }
        if(i!=6){
            for(auto ele:arr[12-i]){
                // cout<<ele<<' ';
                vec2[ele]+=1;
            }        
        }
        for(int j=1;j<50;j++){
            paircount+=vec[j]*vec2[50-j];
        }

    }
    cout<<paircount*2<<endl;
}