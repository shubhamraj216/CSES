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

void permute(string s, int l, int r, set<string>& st) {
    if(l == r) {
        st.insert(s);
        return;
    }
    for(int i = l; i <= r; i++) {
        swap(s[i], s[l]);
        permute(s, l + 1, r, st);
        swap(s[i], s[l]);
    }
}

void solve() {
    string s;
    cin >> s;

    set<string> st;
    permute(s, 0, s.size() - 1, st);
    cout << st.size() << endl;
    for(auto it = st.begin(); it != st.end(); it++) cout << *it << endl;
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
