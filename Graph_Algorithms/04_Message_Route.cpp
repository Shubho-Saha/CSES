#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int mxN = 1e5+9;
int n, m;
vector<int> adlist[mxN];
bool vis[mxN];
int parent[mxN];

void resetGlobal(int n)
{
    for(int i=0; i<=n+2; i++) {
        adlist[i].clear();
        vis[i] = false;
        parent[i] = -1;
    }
}

void bfs(int src)
{
    vis[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto child : adlist[node]) {
            if (!vis[child]) {
                vis[child] = true;
                parent[child] = node;
                q.push(child);
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    resetGlobal(n);
    for(int i=1; i<=m; i++) {
        int a, b;
        cin>>a>>b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    bfs(1);

    if (vis[n] == false) {
        cout<<"IMPOSSIBLE"<<nl;
    } else {
        deque<int> path;
        int crnt = n;
        while(true)
        {
            path.push_front(crnt);
            crnt = parent[crnt];
            if (crnt == -1) break;
        }
        cout<<path.size()<<nl;
        for(auto x : path) {
            cout<<x<<" ";
        }
        cout<<nl;
    }

}
int main()
{
    fastIO();
    solve();

    return 0;
}