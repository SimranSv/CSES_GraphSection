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

vector<ll> vis(N), store(N, -1), ans;

bool h = false;
void dfs(ll node, ll boss)
{

    store[node] = boss;
    vis[node] = 1;
    for (auto &i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, node);
        }
        else
        {

            if (i != boss)
            {

                ll curr = node;
                ans.pb(node);
                while (store[curr] != i)
                {

                    curr = store[curr];
                    ans.pb(curr);
                }
                ans.pb(i);
                ans.pb(node);

                cout << ans.size() << '\n';
                for (auto &i : ans)
                    cout << i << " ";
                // return;
                exit(0);
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
    for (int i = 1; i <= n; i++)
    if(!vis[i])
        dfs(i, -1);
    cout << "IMPOSSIBLE\n";

    return;
}
int main()
{
    FAST;
    solve();
}