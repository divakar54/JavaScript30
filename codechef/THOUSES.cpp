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
vector<int> c;
priority_queue<pair<ll, ll>> pq;
vector<ll> adj[300010];
// template<size_t N>
void dfs(int s, int e) {
	c[s] = 1;
	for (auto u : adj[s]) {
		if (u == e) continue;
		dfs(u, s);
		c[s] += c[u];
	}
}
void solve(ll n, ll x) {
	vector<ll> bx(n + 1, 0);
	n--;
	while (n--) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		// adj[v].push_back(u);
	}
	dfs(1, 0);
	bx[1] = x;
	for (int i = 1; i < n + 1; i++) {
		for (auto&s : adj[i])
			pq.push({c[s], s});
		int k = 1;
		x = bx[i];
		while (!pq.empty()) {
			int node = pq.top().second;
			bx[node] = k * x;
			pq.pop();
			k++;
		}
	}
	ll sum = 0;
	for (auto&i : bx) {
		sum += i % MOD;
	}
	cout << sum << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		solve(n, x);
	}
}
