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
    long double r, b, d, div;
    cin >> r >> b >> d;
    div = r > b ? r / b : b / r;
    if (r > b) {
        int temp;
        temp = r;
        r = b;
        b = temp;
    }
    if (b > r * (d + 1)) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}