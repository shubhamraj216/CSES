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
    string s;
    cin >> s;
    vector<int> arr(26, 0);
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 'A']++;
    }
    int idx = -1;
    for(int i = 0; i < 26; i++) {
        if(arr[i] % 2 == 0) {
            arr[i] /= 2;
        } else {
            if(idx == -1) {
                idx = i;
            } else {
                cout << "NO SOLUTION\n";
                return;
            }
        }
    }

    string res = "";
    for(int i = 0; i < 26; i++) {
        if(arr[i] != 0 && i != idx) {
            char c = 'A' + i;
            for(int j = 0; j < arr[i]; j++) {
                res += c;
            }
        }
    }
    if(idx != -1) {
        char c = 'A' + idx;
        for(int j = 0; j < arr[idx]; j++) {
            res += c;
        }
    }
    for(int i = 25; i >= 0; i--) {
        if(arr[i] != 0 && i != idx) {
            char c = 'A' + i;
            for(int j = 0; j < arr[i]; j++) {
                res += c;
            }
        }
    }

    cout << res << endl;
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