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
const int N = 1e3 + 7;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, q, table[N][N];
pair<pair<int, int>, int> trace[N][N][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char x; cin >> x;
			if (x == 'W') table[i][j] = 1;
			else table[i][j] = -1;
		}
	}	
	cin >> q;
	while (q--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		queue<pair<pair<int, int>, pair<int, int>>> kew;
		kew.push({{x1, y1}, {table[x1][y1], 0}});
		int istrue = -1;
		while (!kew.empty()){
			auto k = kew.front();
			if (k.fi == make_pair(x2, y2) && k.se.fi == 0) istrue = k.se.se;	
			kew.pop();
			for (int i = 0; i < 4; i++){
				int newx = k.fi.fi + dx[i];
				int newy = k.fi.se + dy[i];
				if (newx < 1 || newy < 1 || newx > n || newy > m) continue;
				int cur = table[newx][newy] + k.se.fi; 
				if (abs(cur) > 1) continue;
				kew.push({{newx, newy}, {cur, k.se.se + 1}});
				trace[newx][newy][cur + 1] = {k.fi, k.se.fi + 1};
			}
		}	
		if (istrue != -1) {
			cout << istrue << " ";
			int diff = 1;
			pair<int, int> state = {x2, y2};
			vector<pair<int, int>> save;
			while (state != make_pair(0, 0)){
				save.pb(state);
				state = trace[state.fi][state.se][diff];
			}
			reverse(all(save));
			for (auto u : save) cout << u.fi << " " << u.se << "\n";
		}
	}
	return 0;
}