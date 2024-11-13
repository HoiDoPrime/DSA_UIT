#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;cin>>n;
    int a[n],sizeb=0;
    vector<int> b(0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;cin>>x;
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            count++;
            b.push_back(i);
            sizeb++;
            b.resize(sizeb);
            
        }
    }
    if(count==0){
        cout<<0;
        return 0;
    }
    else{
        cout<<count<<endl;
        for(int x :b){
            
            cout<<x<<" "<<x+1<<endl;
            
        }
    }

    
    return 0;
}