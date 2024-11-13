#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    string x;
    cin >> x;
    int l = 0; 
    int r = n - 1; 
    int index = -1, solanlap = 0;
    
    while (l <= r) { 
         // Increment the loop count in each iteration
        
        int m = (r + l) / 2; 
       
        if (x == arr[m]) {
            index = m;
            break;  // Store the index of the element if found
        }
        
        if (x > arr[m]) {
            l = m + 1;  // Search the right half
        } else {
            r = m - 1;  // Search the left half
        }
         solanlap++;
        
    } 
    
    if (index == -1) {
        cout << index;
    } else {
        cout << index << endl;
        cout << solanlap+1;
    }

    return 0;
}
