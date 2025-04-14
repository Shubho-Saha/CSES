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

void solve()
{
    int n, m, q;
    cin>>n>>m>>q;
    ll inf = LLONG_MAX;
    vector<vector<ll>> grid(n+1, vector<ll> (n+1, inf));
    for(int i=1; i<=n; i++) {
        grid[i][i] = 0;
    }

    for(int i=1; i<=m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        if (c < grid[a][b]) {
            grid[a][b] = c;
            grid[b][a] = c;
        }
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if (grid[i][k] != inf && grid[k][j] != inf) {
                    if (grid[i][k] + grid[k][j] < grid[i][j]) {
                        grid[i][j] = grid[i][k] + grid[k][j];
                    }
                }
            }
        }
    }

    while(q--)
    {
        int a, b;
        cin>>a>>b;
        if (grid[a][b] == inf) {
            cout<<-1<<nl;
        } else {
            cout<<grid[a][b]<<nl;
        }
    }
}
int main()
{
    fastIO();
    solve();
    
    return 0;
}
