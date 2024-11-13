#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void insert_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int pos=i-1;
        while(pos>=0 && a[pos]>key){
            a[pos+1] = a[pos];
            pos--;
            REP(i,n) cout<<a[i]<<" ";
            cout<<endl;
        }
        a[pos+1] =key;
        REP(i,n) cout<<a[i]<<" ";
        cout<<endl;
    }
    
}
int main(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    insert_sort(a,n);
    return 0;
}