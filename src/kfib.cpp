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

ll t, mod, a, b;

struct Matrix{ 	
	int f[2][2];
	int row() const {return 2;}
	int col() const {return 2;}
	Matrix() = default;
	static Matrix identity(int n){
		Matrix a = Matrix();
		while (n--) a.f[n][n] = 1;
		return a;
	}
	Matrix operator*(const Matrix &b){
		Matrix a = *this;
		assert(a.col() == b.row());
		Matrix c = Matrix();
		for (int i = 0; i < a.row(); i++)
			for (int j = 0; j < b.col(); j++)
				for (int k = 0; k < a.col(); k++)
					c.f[i][j] = (c.f[i][j] + 1LL * a.f[i][k] * b.f[k][j] % mod) % mod;
		return c;
	}
	Matrix pow(int exp){
		assert(row() == col());
		Matrix base = *this, ans = identity(row());
		for (; exp > 0; exp >>= 1, base = base * base){
			if (exp & 1) ans = ans * base;
		}
		return ans;
	}
};

ll bsize;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> mod >> a >> b;
		bsize = sqrt(1LL * 6 * mod);
		map<pair<int, int>, ll> M;
		Matrix base = Matrix();
		base.f[0][0] = base.f[0][1] = base.f[1][0] = 1;
		base = base.pow(bsize);
		Matrix cur = base;
		M[{0, 1}] = 0;
		for (ll i = bsize; i <= 1LL * 6 * mod; i += bsize){
			if (M.count({cur.f[1][0], cur.f[0][0]}) == 0){
				M[{cur.f[1][0], cur.f[0][0]}] = i;
			}
			cur = cur * base;
		}
		ll res = loo;
		for (ll i = 0; i <= bsize; i++){
			if (M.count({a, b}) != 0){
				res = min(res, M[{a, b}] + i);
			}
			ll tmp = (b - a + mod) % mod;
			b = a;
			a = tmp;
		}
		if (res == loo) cout << -1 << "\n";
		else cout << res << "\n";
	}
	return 0;
}