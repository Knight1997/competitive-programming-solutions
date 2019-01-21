#include<bits/stdc++.h>
using namespace std;
long long int ans=0;
pair<long long int,long long int> sortTheleaves(long long int arr[],vector<long long int>adj[],long long int n,long long int s)
{
    if(adj[s].size()==0)
    {
        //cout<<arr[s]<<"%%%%%%%"<<endl;
        return {arr[s],arr[s]};
    }
    else
    {
        //cout<<s<<"!!!!"<<endl;
        pair<long long int,long long int>l=sortTheleaves(arr,adj,n,adj[s][0]);
        pair<long long int,long long int>r=sortTheleaves(arr,adj,n,adj[s][1]);

        if(l.first==-1 || r.first==-1 || l.second==-1 || r.second==-1)
        return {-1,-1};

        //cout<<"$$$$$$"<<endl;
        if(l.first>r.first && l.first<r.second)
        {
            ans=-1;
            return {-1,-1};
        }
        else if(r.first<l.second && r.first>l.first)
        {
            ans=-1;
            return {-1,-1};
        }
        if(l.first<r.first)
        {
            if(l.second<r.first)
            {
                return {l.first,r.second};
            }
            else
            {
                ans=-1;
                return {-1,-1};
            }
        }
        else
        {
            if(l.first>r.second)
            {
                //cout<<"####"<<endl;
                ans++;
                return {r.first,l.second};
            }
            else
            {
                ans=-1;
                return {-1,-1};
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<long long int>adj[n+1];

        long long int arr[n];
        memset(arr,0,sizeof(arr));
        for(long long int i=1;i<=n;i++)
        {
            long long int l,r;
            cin>>l>>r;

            if(l!=-1)
            {
                adj[i].push_back(l);
                adj[i].push_back(r);
            }
            else
            {
                arr[i]=r;
            }
        }
        ans=0;
        pair<int,int> p=sortTheleaves(arr,adj,n,1);
        if(p.first==-1 || p.second==-1)
            ans=-1;

        cout<<ans<<endl;
    }
    return 0;
}
