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

int main()
{
    fastIO();
    int n, e;
    cin>>n>>e;

    vector<vector<ll>> grid(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i=1; i<=n; i++) {
        grid[i][i] = 0;
    }

    while(e--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        grid[a][b] = c;
    }

    ll inf = LLONG_MAX;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if (grid[i][j] == inf) {
                cout<<"Inf"<<" ";
            } else {
                cout<<grid[i][j]<<" ";
            }
        }
        cout<<nl;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if (grid[i][k] != inf && grid[k][j] != inf) {
                    if (grid[i][k] + grid[k][j] < grid[i][j]) {
                        grid[i][j] = grid[i][k] + grid[k][j];
                    }
                }
            }
        }
    }

    cout<<"------------"<<nl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if (grid[i][j] == inf) {
                cout<<"Inf"<<" ";
            } else {
                cout<<grid[i][j]<<" ";
            }
        }
        cout<<nl;
    }
    
    return 0;
}