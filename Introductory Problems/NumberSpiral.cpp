#include<bits/stdc++.h>
#define int long long

using namespace std;
// using namespace std::chrono; 

void print(vector<int>& v) {
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
}

void solve() {
    int x, y;
    cin >> x >> y;

    int prev = max(x, y) - 1;
    int num = prev * prev;

    if(prev % 2 == 0) {
        num += (y);
        if(y == prev + 1) num += (y - x);
    } else {
        num += (x);
        if(x == prev + 1) num += (x - y);
    }

    cout << num << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // auto start = high_resolution_clock::now(); 

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    // auto stop = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
}