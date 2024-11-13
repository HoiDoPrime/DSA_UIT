#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
int d[100005];
void merge(int a[],int l,int m,int r,int n){
    // tron hai mang da sap xep 
   vector<int> x(a+l,a+m+1);
   vector<int> y(a+m+1,a+r+1);
   
   int i=0,j=0;
   int start_l = l,end_r=r;
   while(i<x.size() && j<y.size()){
       if(x[i] <= y[j]){
          a[l]=x[i];
          l++;i++;
       }
       else{
          a[l] =y[j];
          l++;j++;
       }
   }
   while(i<x.size()){
       a[l]=x[i];
       i++;l++;
   }
   while(j<y.size()){
       a[l]=y[j];
       j++;l++;
   }
   
   for(int i=0;i<start_l;i++){
       cout<<a[i]<<" ";
    }
   cout << "[ ";
    for (int k = start_l; k <= r; k++) {
        cout << a[k] << " ";
     
    }
    cout << "] ";
    // In phần còn lại của mảng chưa được trộn
    for(int i=r+1;i<n;i++){
       
        cout<<a[i]<<" ";
        
    }
    cout << endl;
}
void merge_sort(int a[],int l,int r,int n){
    if(l>=r) return;
    int m=(l+r)/2;
    merge_sort(a,l,m,n);
    merge_sort(a,m+1,r,n);
    merge(a,l,m,r,n);
    
}
int main(){
    int n;cin>>n;
    int a[n];
    REP(i,n){
        cin>>a[i];
        d[a[i]]++;
    }
    merge_sort(a,0,n-1,n);
    return 0;
}