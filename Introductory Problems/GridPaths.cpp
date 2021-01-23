#include<bits/stdc++.h>
#define int long long
// #define cout cout<<'>'
#define mod 1000000007

using namespace std;
// using namespace std::chrono; 

void print(vector<int>& v) {
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << v[i];
    } cout << endl;
}
vector<vector<int>> grid(7, vector<int>(7, 0));

//                R   D   L   U
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ans = 0;
string s;

bool out_of_bound(int x, int y) {
    if(x < 0 || y < 0 || x >= 7 || y >= 7) return true;
    return false;
}

bool possible(int x, int y, int d) {
    int dx = dir[d][0], dy = dir[d][1];
    int next_x = x + dx, next_y = y + dy;

    // out of bounds
    if(out_of_bound(next_x, next_y)) return false;
    
    // already visited
    if(grid[next_x][next_y]) return false;

    //  will hit a wall ---- #->body, @->head
    // #*********   #*********
    // #**#####@*   #######@*#
    // ####******   **********
    // **********   **********
    int one = (d + 1) % 4, sec = (d + 3) % 4;
    if(out_of_bound(next_x + dx, next_y + dy) || grid[next_x + dx][next_y + dy]) {
        if(out_of_bound(next_x + dir[one][0], next_y + dir[one][1]) || out_of_bound(next_x + dir[sec][0], next_y + dir[sec][1]) ||
           grid[next_x + dir[one][0]][next_y + dir[one][1]] || grid[next_x + dir[sec][0]][next_y + dir[sec][1]]) 
        return true; 
        else return false;
    }

    // hit a corner ---- #->body, @->head
    // #*******#*   #*********
    // #@******#*   ###*******
    // **#######*   ***@#####*
    // **********   **********
    if(!out_of_bound(x - 1, y - 1) && grid[x - 1][y - 1] && !grid[x - 1][y]  && !grid[x][y - 1]) return false;
    if(!out_of_bound(x - 1, y + 1) && grid[x - 1][y + 1] && !grid[x - 1][y]  && !grid[x][y + 1]) return false;
    if(!out_of_bound(x + 1, y + 1) && grid[x + 1][y + 1] && !grid[x + 1][y]  && !grid[x][y + 1]) return false;
    if(!out_of_bound(x + 1, y - 1) && grid[x + 1][y - 1] && !grid[x + 1][y]  && !grid[x][y - 1]) return false;

      
    return true;
}

void moveNext(int x, int y, int k, int prev) {
    // for(int i = 0; i < 7; i++) print(grid[i]);
    // cout << endl;
    if(x == 6 && y == 0) {
        ans += (k == 48);
        return;
    }

    int pos;
    if(s[k] == 'R' || s[k] == '?') {
        pos = 0;
        if(possible(x, y, pos) && pos != (prev + 2) % 4) {
            grid[x + dir[pos][0]][y + dir[pos][1]] = 1;
            moveNext(x + dir[pos][0], y + dir[pos][1], k + 1, pos);
            grid[x + dir[pos][0]][y + dir[pos][1]] = 0;
        }
    }
    if(s[k] == 'D' || s[k] == '?') {
        pos = 1;
        if(possible(x, y, pos) && pos != (prev + 2) % 4) {
            grid[x + dir[pos][0]][y + dir[pos][1]] = 1;
            moveNext(x + dir[pos][0], y + dir[pos][1], k + 1, pos);
            grid[x + dir[pos][0]][y + dir[pos][1]] = 0;
        }
    }
    if(s[k] == 'L' || s[k] == '?') {
        pos = 2;
        if(possible(x, y, pos) && pos != (prev + 2) % 4) {
            grid[x + dir[pos][0]][y + dir[pos][1]] = 1;
            moveNext(x + dir[pos][0], y + dir[pos][1], k + 1, pos);
            grid[x + dir[pos][0]][y + dir[pos][1]] = 0;
        }
    }
    if(s[k] == 'U' || s[k] == '?') {
        pos = 3;
        if(possible(x, y, pos) && pos != (prev + 2) % 4) {
            grid[x + dir[pos][0]][y + dir[pos][1]] = 1;
            moveNext(x + dir[pos][0], y + dir[pos][1], k + 1, pos);
            grid[x + dir[pos][0]][y + dir[pos][1]] = 0;
        }
    }

    return;
    
}

void solve() {
    cin >> s;

    grid[0][0] = 1;
    moveNext(0, 0, 0, -5);

    cout << ans;
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