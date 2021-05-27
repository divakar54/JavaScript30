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
	int D, d, a, b, c;
	cin >> D >> d >> a >> b >> c;
	int res = D * d;

	if (res < 10) {
		cout << 0 << "\n";
		return;
	}
	else if (10 <= res && res < 21) {
		cout << a << "\n";
		return;
	}
	else if (21 <= res && res < 42) {
		cout << b << "\n";
		return;
	}
	else {
		cout << c << "\n";
		return;
	}
}
int main() {
	fast_io();
	int t; cin >> t;
	while (t--) {
		solve();
	}
}