#include<bits/stdc++.h>
#define int long long
// #define cout cout<<'>'
#define mod 1000000007

using namespace std;
// using namespace std::chrono; 

void print(vector<string>& v) {
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    } cout << endl;
}

void calc(vector<string>& prev, int x, int n) {
    if(x == n) {
        print(prev);
        return;
    }

    vector<string> temp;
    for(int i = 0; i < prev.size(); i++) {
        temp.push_back("0" + prev[i]);
    }
    for(int i = prev.size() - 1; i >= 0; i--) {
        temp.push_back("1" + prev[i]);
    }
    prev.clear();
    calc(temp, x + 1, n);
}

void solve() {
    int n;
    cin >> n;

    vector<string> prev(2);
    prev[0] = "0"; prev[1] = "1";

    calc(prev, 1, n);
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