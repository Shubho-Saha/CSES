#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#ifndef ONLINE_JUDGE
#include "../../DebugTemplate/debug.h"
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

int main()
{
    fastIO();
    int n, e;
    cin>>n>>e;

    vector<Edge> edlist;
    vector<ll> dis(n+1, LLONG_MAX);
    dis[1] = 0;
    while(e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edlist.push_back(Edge(u, v, c));
    }

    for(int i=1; i<n; i++)
    {
        for(auto [u, v, c] : edlist)
        {
            if (dis[u] != LLONG_MAX && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (auto [u, v, c] : edlist)
    {
        if (dis[u] != LLONG_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout<<"cycle found"<<nl;
    } else {
        for(int i=1; i<=n; i++) {
            cout<<i<<" : "<<dis[i]<<nl;
        }
    }
    
    
    return 0;
}