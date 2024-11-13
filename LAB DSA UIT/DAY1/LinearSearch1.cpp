#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;cin>>x;
    int vitricuax=-1,vitricuoidendau=-1;
    for(int i=0;i<n;i++){
        if(a[i] ==x ){
            vitricuax =i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==x){
            vitricuoidendau = n-i-1;
            break;
        }
    }
    if(vitricuax == -1){
        cout<<vitricuax;
        return 0;
    }
    else{
        cout<<vitricuax<<endl;
        cout<<vitricuax+1<<endl;
        cout<<vitricuoidendau<<endl;
        cout<<vitricuoidendau+1;
    }
    return 0;
}