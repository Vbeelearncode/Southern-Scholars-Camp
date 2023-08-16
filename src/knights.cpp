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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

const int oo = 1e9 + 7;
const ll loo = (ll)1e18 + 7; 
const int N = 5;
const int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

int getdiff(vector<vector<int>> &a, vector<vector<int>> &b){
	int cnt = 0;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) cnt += (a[i][j] != b[i][j]);
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	int t; cin >> t;
	vector<vector<int>> target(5, vector<int>(5));
	for (int i = 0; i < 5; i++){
		for (int j = i; j < 5; j++) target[i][j] = 1;
	}
	target[2][2] = -1;
	target[4][4] = 0;
	target[3][3] = 0;
	string temp; getline(cin, temp);
	while (t--){
		vector<vector<int>> base(5, vector<int> (5));
		pair<int, int> save;
		for (int i = 0; i < 5; i++){
			string s;
			getline(cin, s);
			for (int j = 0; j < 5; j++){
				if (s[j] != '0' && s[j] != '1') base[i][j] = -1, save = make_pair(i, j);
				else base[i][j] = s[j] - '0';
			}
		}
		map<vector<vector<int>>, int> M;
		queue<pair<vector<vector<int>>, pair<int, int>>> kew;
		kew.push({base, save});
		M[base] = 1;
		bool havefound = false;
		while (!kew.empty()){
			auto k = kew.front();
			if (k.fi == target){
				havefound = true;
				cout << M[k.fi] - 1 << "\n";
				break;
			}
			kew.pop();
			int value = M[k.fi];
			if (getdiff(k.fi, target) >= 15 - value) continue;
			if (M[k.fi] == 11) continue;
			pair<int, int> pos = k.se;
			for (int i = 0; i < 8; i++){
				int newx = pos.fi + dx[i];
				int newy = pos.se + dy[i];
				if (newx >= 0 && newx < 5 && newy >= 0 && newy < 5){
					swap(k.fi[newx][newy], k.fi[pos.fi][pos.se]);
					if (!M.count(k.fi)){
						M[k.fi] = value + 1;
						kew.push({k.fi, make_pair(newx, newy)});
					} 
					swap(k.fi[newx][newy], k.fi[pos.fi][pos.se]);
				}
			}
		}
		if (havefound == false) cout << "123456789\n";
	}
	return 0;
}