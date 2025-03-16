#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isValid(int x, int y) {
    return (x>=0 && x<n && y>=0 && y<m);
}

void dfs(int si, int sj, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
    vis[si][sj] = true;

    for(int i=0; i<4; i++) {
        int ci = si + dx[i];
        int cj = sj + dy[i];
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
            dfs(ci, cj, grid, vis);
        }
    }
}
void solve()
{
    
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (vis[i][j] == false && grid[i][j] == '.') {
                dfs(i,j, grid, vis);
                cnt++;
            }
        }
    }

    cout<<cnt<<nl;

}
int main()
{
    fastIO();
    solve();

    return 0;
}