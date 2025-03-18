#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int mxN = 1e5+9;
int n, m, startpoint, endpoint;
vector<int> adlist[mxN];
bool vis[mxN], flag;
int parent[mxN];

void resetGlobal(int n) {
    for(int i=0; i<=n+2; i++) {
        adlist[i].clear();
        vis[i] = false;
        parent[i] = -1;
    }
}

void dfs(int src)
{
    if (flag) return;
    vis[src] = true;
    for(auto child : adlist[src]) {
        if (flag) return;
        if (!vis[child]) {
            parent[child] = src;
            dfs(child);
        } else {
            if (child != parent[src]) {
                if (flag == false) {
                    startpoint = src;
                    endpoint = child;
                    flag = true;
                }
                
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    resetGlobal(n);
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    flag = false;
    for(int i=1; i<=n; i++) {
        if (!vis[i] && flag == false) {
            dfs(i);
        }
    }

    if (flag == false) {
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }

    vector<int> path;
    path.push_back(endpoint);
    while(true)
    {
        path.push_back(startpoint);
        startpoint = parent[startpoint];
        if (startpoint == endpoint) {
            path.push_back(startpoint);
            break;
        }
    }

    cout<<path.size()<<nl;
    for(auto x : path) {
        cout<<x<<" ";
    }
}
int main()
{
    fastIO();
    solve();

    return 0;
}