#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#ifndef ONLINE_JUDGE
#include "../DebugTemplate/debug.h"
#else
#define debug(x...)
#define dbgsize(x)
#endif

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adlist(n+1);

    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adlist[a].push_back({b,c});
    }

    ll inf = 18e17;
    vector<ll> full(n+1, inf), disc(n+1, inf);
    full[1] = 0, disc[1] = 0;    

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

    pq.emplace(0,1,0);

    while(!pq.empty())
    {
        auto [c, u, f] = pq.top();
        pq.pop();

        if (f && c > disc[u] ) continue;
        if (!f && c > full[u]) continue;

        for(auto [v, vc] : adlist[u])
        {
            if (f)
            {
                if (c + vc < disc[v]) {
                    pq.emplace(c+vc, v, 1);
                    disc[v] = c + vc;
                }
            } else {
                if (c+vc < full[v]) {
                    pq.emplace(c+vc, v, 0);
                    full[v] = c+vc;
                }

                if (c + (vc/2) < disc[v])
                {
                    pq.emplace(c+(vc/2), v, 1);
                    disc[v] = c + (vc/2);
                }
            }
        }
    }

    cout<<disc[n]<<nl;
}

int main()
{
    fastIO();
    solve();
    
    return 0;
}