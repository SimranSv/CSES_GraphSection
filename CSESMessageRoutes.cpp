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
const ll N = 1e6 + 10;
const ll inf = 1e9 + 10;
vector<ll> adj[N];
vector<ll> vis(N);
vector<ll> dis(N, inf);
map<ll, ll> parchiuwu;
void bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    while (!q.empty())
    {
        ll k = q.front();

        q.pop();
        for (auto &i : adj[k])
        {

            if (dis[k] + 1 < dis[i])
            {
                dis[i] = dis[k] + 1;
                parchiuwu.insert({i, k});
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
    dis[1] = 0;
    bfs(1);

    vector<ll> dispro;
    ll k=n;
    if(dis[n]==inf){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    while(k!=1){
        dispro.pb(k);
        k=parchiuwu[k];
    }
    dispro.pb(1);
    reverse(dispro.begin(),dispro.end());
    cout<<dispro.size()<<'\n';
    for(auto &i:dispro){
        cout<<i<<" ";
    }
}
int main()
{
    FAST;

    solve();
}