#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int> >v;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int start[n],last[n];
        for(int i=0;i<n;i++){
            start[i]=v[i].first;
            last[i]=v[i].second;
        }
        while(m--){
            int p;
            cin>>p;
            int it=lower_bound(start,start+n,p)-start;
            if(it==0){
                cout<<start[it]-p<<endl;
            }
            else{
                if(it>=n){
                    if(start[n-1]<=p && last[n-1]>p){
                        cout<<"0"<<endl;
                    }
                    else{
                    cout<<"-1"<<endl;
                    }
                }
                else{
                    if(p>=start[it-1] && p<last[it-1])
                        cout<<"0"<<endl;
                    else{
                        cout<<start[it]-p<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
