#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int mxN = 1e5+9;
int n, m;
vector<vector<pair<ll,ll>>> adlist;
// greater< pair<ll, ll>>
class cmp {
    public:
    bool operator()(pair<ll,ll> a, pair<ll,ll> b) {
        return a.first > b.first;
    }
};

void bfs(int src, vector<ll> &dis)
{
    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, cmp > pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty())
    {
        auto [crntNodeCost,  crntNode] = pq.top();
        pq.pop();
        if (dis[crntNode] < crntNodeCost) continue;
        for(auto [childNode, childCost] : adlist[crntNode])
        {
            if (crntNodeCost + childCost < dis[childNode]) {
                dis[childNode] = crntNodeCost + childCost;
                pq.push({dis[childNode] , childNode});
            }
        }
    }
    
}

void solve()
{
    cin >> n >> m;
    adlist.resize(n+2);
    vector<ll> dis(n+2, LLONG_MAX);
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adlist[a].push_back({b, c});
    }

    bfs(1, dis);
    for(int i=1; i<=n; i++) {
        cout<<dis[i]<<" ";
    }
    cout<<nl;
    
}

int main()
{
    fastIO();
    solve();

    return 0;
}