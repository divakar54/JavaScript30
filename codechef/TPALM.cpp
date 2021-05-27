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
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int mid = (x2 + y2) - 1;
	int res = 1;
	int finres = 0;
	for (int i = 1; i <= mid; i++) {
		// finres += res;
		cout << res << " ";
		if (i < mid / 2) {
			res += i + 1;
		}
		else if (i > mid / 2) {
			res += i + 2;
		}
		else {
			res += i - 1;
		}
	}
}
int main() {
	fast_io();
	int t; cin >> t;
	while (t--) {
		solve();
	}
}