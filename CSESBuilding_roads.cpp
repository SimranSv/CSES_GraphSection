#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define readInputFile                 \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
const ll N = 1e5 + 10;
vector<ll> adj[N];
vector<ll> vis(N);
void bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (auto &i : adj[node])
        {
            if(!vis[i]){
            vis[i] = 1;
            q.push(i);
            }
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll count = 0;
    vector<pair<ll, ll>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);

            count++;

            ans.pb({i - 1, i});
        }
    }
    cout<<ans.size()-1<<'\n';
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
}
int main()
{
    FAST;

    solve();
}