#include<bits/stdc++.h>
#define int long long
// #define cout cout<<'>'

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
    int sum = (n * (n + 1)) / 2;
    if(sum % 2) {
        cout << "NO";
        return;
    } else {
        sum /= 2;
        cout << "YES\n";
        int i = 0, j = n, curr = 0;
        vector<int> v;

        while(j + curr <= sum)  {
            curr += j;
            v.push_back(j);
            j--;
        }
        if(curr != sum){
            v.push_back(sum - curr);
            i = sum - curr;
        }
        cout << v.size() << endl;
        print(v);
        v.clear();
        for(int k = 1; k <= j; k++) {
            if(k != i) v.push_back(k);
        }
        cout << v.size() << endl;
        print(v);
    }
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

// 1 2 3 4 5 6 7 8 9 10 11