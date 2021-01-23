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
    int n;
    cin >> n;

    while(n != 1) {
        cout << n << " ";
        if(n % 2) n = 3 * n + 1;
        else n /= 2;
    }

    cout << 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // auto start = high_resolution_clock::now(); 

    solve();

    // auto stop = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
}