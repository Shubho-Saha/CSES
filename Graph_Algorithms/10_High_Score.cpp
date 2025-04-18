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
        this->u = u, this->v = v, this->c =c;
    }
};

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<Edge> edlist;
    for(int i=1; i<=m; i++) {
        int u, v, c;
        cin>>u>>v>>c;
        c *= -1;
        edlist.push_back(Edge(u,v,c));
    }

    ll pinf = 1e17;
    ll ninf = -1*pinf;
    vector<ll> dis(n+1, pinf);
    dis[1] = 0;

    for(int i=1; i<n; i++)
    {
        for(auto [u, v, c] : edlist)
        {
            if (dis[u] == pinf) continue;
            dis[v] = min(dis[v], (dis[u]+c));
            dis[v] = max(ninf, dis[v]);
        }
    }

    // as self edge can exist. we have to run this loop n times.
    for(int i=1; i<=n; i++)
    {
        for(auto [u, v, c] : edlist)
        {
            if (dis[u] == pinf) continue;
            if (dis[u] + c < dis[v]) 
            {
                dis[v] = ninf;
            }
        }
    }

    if (dis[n] == ninf) {
        cout<<-1<<nl;
    } else {
        cout<<dis[n]*-1<<nl;
    }

}

int main()
{
    fastIO();
    solve();
    
    return 0;
}