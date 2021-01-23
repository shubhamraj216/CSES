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
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > arr[i]) {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
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