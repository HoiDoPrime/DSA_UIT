#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void slectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_pos=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_pos]){
                min_pos=j;
            }
        }
    
        swap(a[i],a[min_pos]);
        if(i!=min_pos){
        REP(i,n) cout<<a[i]<<" ";
        cout<<endl;
        }
        
    }
}
int main(){
    int n;cin>>n;
    int a[n];
    REP(i,n) cin>>a[i];
    slectionsort(a,n);
    return 0;
}