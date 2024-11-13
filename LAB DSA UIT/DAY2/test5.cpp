#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> codes;  
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        string code;
        cin >> code;
    
        bool found = false;
        for (int j = 0; j < ans; j++) {
            if (codes[j] == code) {
                found = true;
                break;
            }
        }
        if (!found) {
            codes.push_back(code);
            ans++;
        }
    }

    cout << ans << endl;  
    return 0;
}
