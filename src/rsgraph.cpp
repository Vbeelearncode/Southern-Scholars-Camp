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

int n, m, d[N], cnt[N], cntedge[N], cntsame[N];
vector<int> g[N];

ll sqr(ll x){
	return x * x % oo;
}

ll conquer(ll x, ll n){
	if (n == 0) return 1;
	if (n % 2 == 0) return sqr(conquer(x, n / 2) % oo) % oo;
	return 1LL * x * sqr(conquer(x, n / 2) % oo) % oo;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	cin >> n >> m;
	vector<int> save;
	ll res = 1;
	for (int i = 2; i <= n; i++) {
		cin >> d[i], save.pb(d[i]), cnt[d[i]]++;
		if (d[i] == 0) return cout << 0, 0;
	}
	sort(all(save)); save.resize(unique(all(save)) - save.begin());
	if ((int)save.size() != save.back()) return cout << 0, 0;
	for (int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		if (abs(d[u] - d[v]) > 1) return cout << 0, 0;
		if (d[u] == d[v]) cntsame[d[u]]++;
		if (d[u] > d[v]) swap(u, v);
		if (d[u] != d[v]) cntedge[v]++;
	}	
	cnt[0] = 1;
	for (int i = 2; i <= n; i++){
		if (cntedge[i] == 0){
			res = 1LL * res * (conquer(2, cnt[d[i] - 1]) % oo - 1 + oo) % oo;
		}
		else {
			res = 1LL * res * (conquer(2, cnt[d[i] - 1] - cntedge[i]) % oo) % oo;
		}
	}
	// cout << res;
	for (int i = 1; i <= n; i++){
		if (cnt[i] == 0) break;
		res = 1LL * res * (conquer(2, 1LL * cnt[i] * (cnt[i] - 1) / 2 - cntsame[i]) % oo) % oo;
	}
	cout << res;
	return 0;
}