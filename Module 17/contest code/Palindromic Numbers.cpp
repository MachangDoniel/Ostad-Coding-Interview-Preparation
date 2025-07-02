#include<bits/stdc++.h>
using namespace std;
const int N = 20;
#define ll long long
int ar[20];
ll dp[20][20][2][2];
ll fun(int pos, int st, bool tight, bool cmpWithMirror) {
	if (pos == 20) {
		return (tight | (cmpWithMirror == 2 || cmpWithMirror == 0));
	}
	if (st && (st + (19 - st) / 2) + 1 == pos) {
		return (tight | (cmpWithMirror == 2 || cmpWithMirror == 0));
	}
	if (dp[pos][st][tight][cmpWithMirror] != -1)return dp[pos][st][tight][cmpWithMirror];
	int start = 0, limit = ar[pos];
	if (tight) limit = 9;
	ll ret = 0;
	for (int digit = start; digit <= limit; digit++) {
		if (digit) {
			if (!st)st = pos;
		}
		if (st) {
			int sym = 19 - pos + st;
			int tempCmpWithMirror = cmpWithMirror;
			if (digit > ar[sym]) tempCmpWithMirror = 1;
			else if (digit < ar[sym]) tempCmpWithMirror = 0;
			ret += fun(pos + 1, st, tight | (digit < ar[pos]), tempCmpWithMirror);
		}
		else {
			ret += fun(pos + 1, st, tight | (digit < ar[pos]), cmpWithMirror);
		}
	}
	return dp[pos][st][tight][cmpWithMirror] = ret;

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