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

void shift(int n, int from, int to, int via) {
    if(n == 1) {
        cout << from << " " << to << endl;
        return;
    }
    shift(n - 1, from, via, to);
    cout << from << " " << to << endl;
    shift(n - 1, via, to, from);
}

void solve() {
    int n;
    cin >> n;

    cout << pow(2, n) - 1 << endl;

    shift(n, 1, 3, 2);
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