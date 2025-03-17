#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int mxN = 1e5+9;
bool vis[mxN];
vector<int> adlist[mxN];
vector<int> res(mxN);
bool flag;

void resetGlobal(int n)
{
    for(int i=0; i<=n+2; i++) {
        adlist[i].clear();
        vis[i] = false;
        res[i] = 0;
    }
}

void dfs(int src, int f)
{
    vis[src] = true;
    if (f) {
        res[src] = 1;
    } else {
        res[src] = 2;
    }

    for(auto child : adlist[src]) {
        if (vis[child] == false) {
            dfs(child, !f);
        } else {
            if (res[child] == res[src]) {
                flag = true;
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    resetGlobal(n);
    
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    flag = false;
    for(int i=1; i<=n; i++) {
        if (vis[i] == false) {
            dfs(i, 1);
        }
    }

    if (flag) {
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }

    for(int i=1; i<=n; i++) {
        cout<<res[i]<<" ";
    }
    cout<<nl;
}
int main()
{
    fastIO();
    solve();

    return 0;
}