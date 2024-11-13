#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int max_hash = 50000;  


int hash_string(const string& s) {
    int hash_value = 0;
    for (char c : s) {
        hash_value = (hash_value * 31 + c) % max_hash;
    }
    return hash_value;
}
bool check_and_insert(string &code, vector<string>& hash_table) {
    int index = hash_string(code);
    
    while (!hash_table[index].empty()) {
        if (hash_table[index] == code) {
            return false; 
        }
        index = (index + 1) % max_hash;  
    }
    hash_table[index] = code;  
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> hash_table(max_hash, "");  
    int distinct_count = 0;  
    

    for (int i = 0; i < N; i++) {
        string code;
        cin >> code;
        
        if (check_and_insert(code, hash_table)) {
            distinct_count++;  
        }
    }
    
    cout << distinct_count << endl;  
    return 0;
}
