#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void merge(int a[], int l, int m, int r) {
    // Trộn hai mảng con đã được sắp xếp
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);

    int i = 0, j = 0;
    int start_l = l;  // Lưu vị trí bắt đầu của mảng con

    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            a[l] = x[i];
            l++; i++;
        } else {
            a[l] = y[j];
            l++; j++;
        }
    }
    while (i < x.size()) {
        a[l] = x[i];
        i++; l++;
    }
    while (j < y.size()) {
        a[l] = y[j];
        j++; l++;
    }

    // In mảng sau mỗi lần trộn với phần đã trộn được bao bởi []
    for (int k = 0; k < start_l; k++) {
        cout << a[k] << " ";  // Phần mảng trước khi trộn
    }

    cout << "[ ";
    for (int k = start_l; k <= r; k++) {
        cout << a[k] << " ";  // Phần mảng đã trộn
    }
    cout << "] ";

    for (int k = r + 1; k < l; k++) {
        cout << a[k] << " ";  // Phần mảng chưa trộn
    }
    cout << endl;
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    REP(i, n) cin >> a[i];

    merge_sort(a, 0, n - 1);

    return 0;
}
