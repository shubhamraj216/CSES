#include<bits/stdc++.h>
#define int long long
// #define cout cout<<'>'

using namespace std;
// using namespace std::chrono; 

void print(vector<int>& v) {
    for(unsigned int i = 1; i < v.size(); i++) {
        cout << v[i] << endl;
    } cout << endl;
}

int calculate(int n) {
    int c = 1;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int diff = 0;
        if((i == 1 || i == n) && n >= 3) diff += 2;
        else if(i == 2 || i == n - 1) {
            if(n >= 3) diff += 2;
            if(n >= 4) diff++;
        }
        else if(i >= 3) {
            diff += 4;
        }

        res += n * n - diff - i;
    }
    // cout << res << endl;
    for(int i = 2; i <= n; i++) {
        int diff = 0;
        if(i == n && n >= 3) diff += 2;
        else if(i == 2 || i == n - 1) {
            if(n >= 3) diff += 2;
            if(n >= 4) diff++;
        }
        else if(i >= 3) diff += 4;

        if((i == 2 || i == 3) && n >= 3) diff--;       

        res += n * n - diff - i - n + 1;
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);

    arr[0] = 0;
    arr[1] = 0; 

    for(int i = 2; i <= n; i++) {
        int ans = arr[i - 1];

        ans += calculate(i);
        arr[i] = ans;
    }
    print(arr);
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