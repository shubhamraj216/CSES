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
    int q;
    cin >> q;

    vector<int> search(20, 0);
    int m = 9;
    for(int i = 1; i < 18; i++) {
        search[i] = search[i - 1] + i * m;
        m = m * 10;
    }
    // print(search);

    while(q--) {
        int x;
        cin >> x;

        // 9*1, 90*2, 900*3, 9000*4, 90000*5, 900000*6 ....

        // int l = lower_bound(search.begin(), search.end(), x) - search.begin();
        // if(l == 20) l = 17;

        int l = 17;
        for(int i = 17; i >= 0; i--) {
            if(search[i] >= x) l = i;
            else break;
        }
        int curr = x - search[l - 1];
        int num = curr / l;
        int ss = 1;
        for(int i = 1; i < l; i++) ss = ss * 10;
        int last_num =  ss - 1;
        if(curr % l == 0) {
            cout << (num + last_num) % 10 << endl;
        } else {
            string next = to_string(num + last_num + 1);
            cout << next[curr % l - 1] << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
    // #endif

    // auto start = high_resolution_clock::now(); 

    solve();

    // auto stop = high_resolution_clock::now();

    // auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
}
