#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int c=n-m;
    if(c>1||n==1 && c<-1)cout<<-1<<endl;
    
    else if(c<=1&&c>=-1)cout<<2*(n-1)-c<<endl;
    else if(-c%2==0)cout<<2*(n-1)-4*(c/2)<<endl;
    else cout<<2*(n-1)-4*(c/2)+1<<endl;

    

}