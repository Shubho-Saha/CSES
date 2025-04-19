#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#ifndef ONLINE_JUDGE
// #include "../DebugTemplate/debug.h"
#else
#define debug(x...)
#define dbgsize(x)
#endif

class Edge
{
    public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u, this->v = v, this->c = c;
    }
};

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<Edge> edlist;

    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edlist.push_back(Edge(a,b,c));
    }
    
    vector<ll> parent(n+1, -1), dis(n+1, 0);
 
    int x=-1;
    for(int i=1; i<=n; i++)
    {
        x = -1;
        for(auto [u, v, c] : edlist)
        {
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout<<"NO"<<nl;
        return;
    }

    int y = x;
    for(int i=1; i<=n; i++)
    {
        y = parent[y];
    }  

    vector<int> path;
    for(int cur = y; ; cur = parent[cur])
    {
        path.push_back(cur);
        if (cur == y && path.size()>1) break;
    }

    reverse(all(path));
    
    cout<<"YES"<<nl;
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