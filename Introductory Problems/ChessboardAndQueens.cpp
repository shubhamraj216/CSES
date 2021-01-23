#include<bits/stdc++.h>
#define int long long
// #define cout cout<<'>'
#define mod 1000000007

using namespace std;
// using namespace std::chrono; 

void print(vector<char>& v) {
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
}

vector<vector<char>> board(8, vector<char> (8));
int ans = 0;

bool check(int i, int j) {
    // out of bounds
    if(i < 0 || j < 0 || i >= 8 || j >= 8) return false;

    // if on *
    if(board[i][j] == '*') return false;

    // check row ########
    for(int k = 0; k <= 7; k++) {
        if(board[i][k] == 'Q') return false;
    }

    // check column
    for(int k = 0; k <= 7; k++) {
        if(board[k][j] == 'Q') return false;
    }

    // check diagonal with m = 1
    for(int k = i, l = j; k >= 0 && l < 8; k--, l++) {
        if(board[k][l] == 'Q') return false;
    }
    for(int k = i, l = j; k < 8 && l >= 0; k++, l--) {
        if(board[k][l] == 'Q') return false;
    }

    // check diagonal with m = -1
    for(int k = i, l = j; k >= 0 && l >= 0; k--, l--) {
        if(board[k][l] == 'Q') return false;
    }
    for(int k = i, l = j; k < 8 && l < 8; k++, l++) {
        if(board[k][l] == 'Q') return false;
    }

    return true;
}

void placeQueens(int i) {
    if(i == 8) {
        ans++;
        return;
    }

    for(int j = 0; j < 8; j++)  {
        if(check(i, j)) {
            char temp = board[i][j];
            board[i][j] = 'Q';
            placeQueens(i + 1);
            board[i][j] = temp;
        }
    }
}


void solve() {
    for(int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++) board[i][j] = s[j];
    }

    placeQueens(0);

    cout << ans << endl;
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