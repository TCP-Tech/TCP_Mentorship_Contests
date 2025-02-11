#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    
    for (ll &x : a) cin >> x;  

    sort(a.begin(), a.end());  

    ll min_diff = LLONG_MAX;
    
    for (int i = 1; i < n; i++) {
        min_diff = min(min_diff, a[i] - a[i - 1]);
    }

    cout << min_diff << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


