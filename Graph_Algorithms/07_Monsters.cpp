#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int mxN = 1e3+9;
int n, m, si, sj, endi, endj;
vector<vector<int>> grid;
vector<pair<int,int>> monsters;
map<pair<int,int>, pair<int,int>> parent;
vector<pair<int,int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j, int time) {
    if (i < 1 || i > n || j < 1 || j > m) {
        return false;
    }

    if (grid[i][j] <= time) return false;
    return true;
}

bool canEscape(int i, int j, int time) {
    if (isValid(i, j, time) == false) return false;
    if (i==1 || i==n || j == 1 || j==m) return true;
    return false;
}

void resetGlobal(int n, int m) {
    grid.resize(n+2);
    for(int i=0; i<=n; i++) {
        grid[i].resize(m+2);
    }
    monsters.clear();
    si = sj = endi = endj = -1;
}

void monstersBFS()
{
    queue<tuple<int,int,int>> q;
    for(auto [mi, mj] : monsters) {
        q.emplace(mi, mj, 0);
    }

    while(!q.empty())
    {
        auto [mi, mj, time] = q.front();
        q.pop();
        time++;
        for(auto [di, dj] : direction) {
            int ci = mi + di;
            int cj = mj + dj;
            if (isValid(ci, cj, time)) {
                grid[ci][cj] = time;
                q.emplace(ci, cj, time);
            }
        }
    }
}

bool playerBFS()
{
    queue<tuple<int,int,int>> q;
    q.emplace(si, sj, 0);
    parent[{si, sj}] = {-1, -1};

    while(!q.empty())
    {
        auto [ai, aj, time] = q.front();
        q.pop();
        time++;
        for(auto [di, dj] : direction) {
            int ci = di + ai;
            int cj = dj + aj;
            if (canEscape(ci, cj, time)) {
                parent[{ci, cj}] = {ai, aj};
                endi = ci, endj = cj;
                return true;
            }

            if (isValid(ci, cj, time)) {
                parent[{ci, cj}] = {ai, aj};
                grid[ci][cj] = time;
                q.emplace(ci, cj, time);
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    resetGlobal(n, m);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            char c; cin>>c;
            if (c == 'M') {
                monsters.push_back({i, j});
                grid[i][j] = 0;
            } else if (c == 'A') {
                si = i, sj = j;
            } else if (c == '#') {
                grid[i][j] = 0;
            } else {
                grid[i][j] = INT_MAX;
            }
        }
    }

    if (si == 1 || si == n || sj == 1 || sj == m) {
        cout<<"YES"<<nl;
        cout<<0<<nl;
        return;
    }

    monstersBFS();
    if (!playerBFS()) {
        cout<<"NO"<<nl;
    } else {
        string path = "";
        while(true)
        {
            int pi = parent[{endi, endj}].first;
            int pj = parent[{endi, endj}].second;
            if (pi == -1 && pj == -1) break;
            if (pi == endi) {
                if (pj < endj) {
                    path.push_back('R');
                } else {
                    path.push_back('L');
                }
            } else {
                if (pi < endi) {
                    path.push_back('D');
                } else {
                    path.push_back('U');
                }
            }
            endi = pi, endj = pj;
        }

        reverse(all(path));
        cout<<"YES"<<nl;
        cout<<path.size()<<nl;
        cout<<path<<nl;
    }
    
}
int main()
{
    fastIO();
    solve();

    return 0;
}