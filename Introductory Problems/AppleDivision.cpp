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
int diff = INT_MAX;
int sum = 0;

void divide(vector<int>& arr, int idx, int curr, int n) {
    if(idx == n) return;
    int temp = curr + arr[idx];
    diff = min(diff, abs(sum - 2 * temp));
    divide(arr, idx + 1, temp, n);

    divide(arr, idx + 1, curr, n);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    divide(arr, 0, 0, n);

    cout << diff;

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