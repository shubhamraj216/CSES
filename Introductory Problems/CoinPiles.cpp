#include<bits/stdc++.h>
#define int long long
// #define cout cout<<'>'
#define mod 1000000007

using namespace std;
// using namespace std::chrono; 

void print(vector<int>& v) {
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int x = 2 * a - b, y = 2 * b - a;
    if(x % 3 == 0 && x / 3 >= 0 && y % 3 == 0 && y / 3 >= 0) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // auto start = high_resolution_clock::now(); 

    int t;
    cin >> t;

    while(t--)
        solve();

    // auto stop = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
}