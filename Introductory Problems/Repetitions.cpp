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
    string s;
    cin >> s;
    int i = 0, ans = 0;

    while(i < s.size()) {
        char c = s[i];
        int temp = 0;
        while (i < s.size() && c == s[i]) {
            temp++;
            i++;
        }
        ans = max(ans, temp);
    }

    cout << ans;
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