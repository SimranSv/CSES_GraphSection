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
vector<ll> parchild(N);
bool bfs(ll node, ll boss)
{
    queue<ll> q;
    q.push(node);
    while (!q.empty())
    {
      

        ll nodeh = q.front();
       
        vis[nodeh] = 1;
        q.pop();
        for (auto &i : adj[nodeh])
        {
            if (vis[i] == 1 )
            {
                if(parchild[i]==parchild[nodeh])return 0;
                
            }
            if (!vis[i])
            {
                if (parchild[nodeh] == 1)
                {
                    parchild[i] = 2;
                }
                else
                {
                    parchild[i] = 1;
                }

                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return true;
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
    {
        if (!vis[i])
        {
            parchild[i] = 1;
            if (!bfs((ll)i, (ll)-1))
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << parchild[i] << " ";
    }
    cout << '\n';
}
int main()
{
    FAST;
    solve();
}