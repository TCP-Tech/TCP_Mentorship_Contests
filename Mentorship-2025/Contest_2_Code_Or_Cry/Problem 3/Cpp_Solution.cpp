#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>

void solve() {
    ll n, x;
    cin >> n >> x;
    vl a(n);
    
    for (ll &e : a) cin >> e;  

    map<ll, vl> remainder_groups;

    // Group numbers by their remainder when divided by x
    for (ll e : a) {
        remainder_groups[e % x].push_back(e);
    }

    ll max_diff = 0;

    // Find the maximum difference in each remainder group
    for (auto &[rem, values] : remainder_groups) {
        ll max_val = *max_element(values.begin(), values.end());
        ll min_val = *min_element(values.begin(), values.end());
        max_diff = max(max_diff, max_val - min_val);
    }

    cout << max_diff << endl;
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


