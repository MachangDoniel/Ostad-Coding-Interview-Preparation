#include<bits/stdc++.h>
using namespace std;
const int N = 20;
#define ll long long
int ar[20];
ll dp[20][20][2][2];
ll fun(int pos, int st, bool f1, bool f2) {
	if (pos == 20) {
		return (f1 | (f2 == 2 || f2 == 0));
	}
	if (st && (st + (19 - st) / 2) + 1 == pos) {
		return (f1 | (f2 == 2 || f2 == 0));
	}
	if (dp[pos][st][f1][f2] != -1)return dp[pos][st][f1][f2];
	int l = 0, r = ar[pos];
	if (f1)r = 9;
	ll ret = 0;
	for (int i = l; i <= r; i++) {
		if (i) {
			if (!st)st = pos;
		}
		if (st) {
			int sym = 19 - pos + st;
			int ff2 = f2;
			if (i > ar[sym])ff2 = 1;
			else if (i < ar[sym])ff2 = 0;
			ret += fun(pos + 1, st, f1 | (i < ar[pos]), ff2);
		}
		else {
			ret += fun(pos + 1, st, f1 | (i < ar[pos]), f2);
		}
	}
	return dp[pos][st][f1][f2] = ret;

}
void set_ar(ll x) {
	memset(ar, 0, sizeof ar);
	int id = 19;
	while (x) {
		ar[id] = x % 10;
		x /= 10;
		id--;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	if (a > b)swap(a, b);
	set_ar(b);
	memset(dp, -1, sizeof dp);
	ll ans = fun(1, 0, 0, 0);
	if (a) {
		a--;
		set_ar(a);
		memset(dp, -1, sizeof dp);
		ans -= fun(1, 0, 0, 0);
	}
	cout << ans << endl;
}