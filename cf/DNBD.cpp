#include<bits/stdc++.h>
using namespace std;
void fast_io() {
	// ios_base::sync_with_studio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.text", "w", stdout);
#endif
}

void solve() {
	long long int n = 0;
	cin >> n;
	int res = 1;
	int i = 1;
	bool flag = true;
	while (flag) {
		int curr = 1 << i;
		if (curr > n) {
			break;
		}
		res = curr;
		i++;
	}
	cout << (res - 1) << endl;
	return;
}

int main() {
	fast_io();
	int t; cin >> t;
	while (t--) {
		solve();
	}
}