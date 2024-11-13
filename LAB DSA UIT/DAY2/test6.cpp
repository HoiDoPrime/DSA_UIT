#include <bits/stdc++.h>
using namespace std;

// Hàm hoán đổi hai điểm
void swap(pair<int, int>& a, pair<int, int>& b) {
    pair<int, int> temp = a;
    a = b;
    b = temp;
}
int partition(vector<pair<int, int>>& points, int low, int high) {
    pair<int, int> pivot = points[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
       
        if (points[j].first < pivot.first || (points[j].first == pivot.first && points[j].second > pivot.second)) {
            i++;
            swap(points[i], points[j]);
        }
    }
    swap(points[i + 1], points[high]);
    return i + 1;
}
void quickSort(vector<pair<int, int>>& points, int low, int high) {
    if (low < high) {
        int pi = partition(points, low, high);
        quickSort(points, low, pi - 1);
        quickSort(points, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

   
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    quickSort(points, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << points[i].first << " " << points[i].second <<"\n";
    }

    return 0;
}
