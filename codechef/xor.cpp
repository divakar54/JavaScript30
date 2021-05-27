#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void fast_io() {
	// ios_base::sync_with_studio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.text", "w", stdout);
#endif
}
const ll MOD = 1000000007;
ll powerLL(ll x, ll n)
{
	ll result = 1;
	while (n) {
		if (n & 1)
			result = result * x % MOD;
		n = n / 2;
		x = x * x % MOD;
	}
	return result;
}
void solve(int n) {

	cout << powerLL(2, n - 1) % MOD << endl;
}

int main() {
	fast_io();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		solve(n);
	}
}