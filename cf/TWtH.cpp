#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000
void fast_io() {
	// ios_base::sync_with_studio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.text", "w", stdout);
#endif
}

void solve(int n, int d) {
	vector<int> dp(n);
	// vector<int> a(n, 0);
	string b;
	cin >> b;
	for (int i = 0; i < n; i++) {
		dp[i] = inf;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == '1') {
			for (int j = 0; j <= d; j++) {
				if (i + j < n && b[i + j] == '1') {

					dp[i + j] = min(dp[i] + 1, dp[i + j]);
				}
			}
		}
	}

	if (dp[n - 1] == inf) {
		cout << -1 << "\n";
	}
	else {
		cout << dp[n - 1] << "\n";
	}
}

int main() {

	fast_io();
	int n, d; cin >> n >> d;
	solve(n, d);
}