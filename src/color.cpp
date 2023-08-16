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

int n, k, color[N];
pair<int, int> f[N][2];
void minimize(pair<int, int> &a, pair<int, int> b){
	if (a > b) a = b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> color[i];
	}	
	for (int i = 0; i <= n; i++) for (int c = 0; c < 2; c++) f[i][c] = make_pair(oo, oo);
	if (color[1] != 2)
		f[1][0] = make_pair(1, 1);
	if (color[1] != 1)
		f[1][1] = make_pair(1, 1);
	for (int i = 1; i < n; i++){
		for (int c = 0; c < 2; c++) if (f[i][c] != make_pair(oo, oo)) {
			if (color[i + 1] == 0){
				if (f[i][c].se < k) minimize(f[i + 1][c], make_pair(f[i][c].fi, f[i][c].se + 1));
				minimize(f[i + 1][0], make_pair(f[i][c].fi + 1, 1));
				minimize(f[i + 1][1], make_pair(f[i][c].fi + 1, 1));
			}
			else if (color[i + 1] == 1){
				if (c == 0){
					if (f[i][c].se < k) minimize(f[i + 1][c], make_pair(f[i][c].fi, f[i][c].se + 1));
					else minimize(f[i + 1][c], make_pair(f[i][c].fi + 1, 1));
				}
				else {
					int nxt = min(n, max(i + 1, i + k - f[i][c].se));
					minimize(f[nxt][0], make_pair(f[i][c].fi + 1, nxt - i));
				}
			}
			else {
				if (c == 0){
					int nxt = min(n, max(i + 1, i + k - f[i][c].se));
					minimize(f[nxt][1], make_pair(f[i][c].fi + 1, nxt - i));
				}
				else {
					if (f[i][c].se < k) minimize(f[i + 1][c], make_pair(f[i][c].fi, f[i][c].se + 1));
					else minimize(f[i + 1][c], make_pair(f[i][c].fi + 1, 1));
				}
			}
		}
	}
	pair<int, int> res = make_pair(oo, oo);
	for (int c = 0; c < 2; c++) minimize(res, f[n][c]);
	cout << res.fi;
	return 0;
}