#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n, m;
const int mxN = 1005;
char grid[mxN][mxN];
bool vis[mxN][mxN];
pair<int,int> parent[mxN][mxN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void resetGlobal(int n, int m) {
    for(int i=0; i<=n+2; i++) {
        fill(vis[i], vis[i]+m+1, false);
        for(int j=0; j<=m+1; j++) {
            parent[i][j] = {-1, -1};
        }
    }
}
bool isValid(int x, int y) {
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty())
    {
        auto par = q.front();
        int pi = par.first;
        int pj = par.second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ci = pi + dx[i];
            int cj = pj + dy[i];
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                parent[ci][cj] = {pi, pj};
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    resetGlobal(n, m);
    int si, sj,  ti , tj;
    si = sj = ti = tj = -1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>grid[i][j];
            if (grid[i][j] == 'A') {
                si = i, sj = j;
            } else if (grid[i][j] == 'B') {
                ti = i, tj= j;
            }
        }
    }

    bfs(si, sj);

    if (vis[ti][tj] == false) {
        cout<<"NO"<<nl;
        return;
    }

    string s = "";

    while(true)
    {
        int pi = parent[ti][tj].first;
        int pj = parent[ti][tj].second;

        if (pi == ti) {
            if (pj < tj) {
                s.push_back('R');
            } else {
                s.push_back('L');
            }
        } else {
            if (pi < ti) {
                s.push_back('D');
            } else {
                s.push_back('U');
            }
        }
        ti = pi, tj = pj;
        if (ti == si && tj == sj) break;
    }

    reverse(all(s));
    cout<<"YES"<<nl;
    cout<<s.size()<<nl;
    cout<<s<<nl;
    
}

int main()
{
    fastIO();
    solve();

    return 0;
}