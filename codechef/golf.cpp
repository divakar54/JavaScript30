#include<bits/stdc++.h>
using namespace std;

void fast_io() {
	// ios_base::sync_with_studio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.text", "w", stdout);
#endif
}

void solve(int N, int x, int k) {

	if (x % k == 0) {
		printf("YES\n");
	}
	else if ( (N + 1 - x) % k == 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main() {
	fast_io();
	int t;
	cin >> t;
	while (t--) {
		long long int N, x, k;
		scanf("%d%d%d", &N, &x, &k);
		solve(N, x, k);
	}
}