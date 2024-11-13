#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;cin>>x;
    int l=0,r=n-1;
    int index=-1,solanduyet=0;
    while(l<=r){
        int m =(l+r)/2;
        if(a[m] == x){
            index = m;
            break;
        }
        else if(a[m]>x){
            r=m-1;
        }
        else{
            l=m+1;
        }
        solanduyet++;
    }
    if(index==-1){
        cout<<-1;
    }
    else{
        cout<<index<<endl;
        cout<<solanduyet+1;

    }
    return 0;
}