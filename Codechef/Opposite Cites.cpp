#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==3){
            cout<<"NO"<<endl;
            continue;
        }


        int flag=0;
        for(int i=0;i<n/2;i++){
            if(arr[i]==-1){
                if(arr[i+n/2]==-1){
                    arr[i]=arr[i+n/2]=1;
                }
                else
                    arr[i]=arr[i+n/2];
            }
            else if(arr[i+n/2]==-1){
                arr[i+n/2]=arr[i];
            }
            else
            {
                if(arr[i]==arr[n/2+i])
                    continue;
                flag=1;
                break;
            }

        }
        if(flag==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int  i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }

    }
    return 0;
}
