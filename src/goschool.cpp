#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define fi first
#define se second
#define TASK ""
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) ((x >> (i)) & 1)
 
using namespace std;

const int oo = 1e9 + 7;
const ll loo = (ll)1e18 + 7; 
const int N = 1e5 + 7;

struct Edge{
	ll to, a, b;
};

ll n, m, k, dist[4][N];
vector<Edge> g[N], revg[N];

void dijkstra(int s, int graph, int key, bool walk){
	for (int i = 1; i <= n; i++){
		dist[key][i] = loo;
	}
	dist[key][s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> kew;
	kew.push({0, s});
	while (!kew.empty()){
		auto k = kew.top();
		kew.pop();
		if (k.fi > dist[key][k.se]) continue;
		if (graph == 1){
			for (auto v : g[k.se]){
				ll cost = (walk ? v.a : v.b);
				if (dist[key][v.to] > k.fi + cost){
					dist[key][v.to] = k.fi + cost;
					kew.push({dist[key][v.to], v.to});
				}
			}
		}
		else {
			for (auto v : revg[k.se]){
				ll cost = (walk ? v.a : v.b);
				if (dist[key][v.to] > k.fi + cost){
					dist[key][v.to] = k.fi + cost;
					kew.push({dist[key][v.to], v.to});
				}
			}
		}
	}
}	

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int u, v, a, b; cin >> u >> v >> a >> b;
		g[u].pb({v, a, b});
		revg[v].pb({u, a, b});	
	}
	dijkstra(k, 2, 2, 1);
	dijkstra(1, 1, 1, 0);
	dijkstra(n, 2, 3, 0);
	ll res = loo;	
	for (int i = 1; i <= n; i++){
		if (dist[1][i] + dist[2][i] <= 59){
			res = min(res, dist[1][i] + dist[3][i]);
		}
	}
	cout << res;
	return 0;
}