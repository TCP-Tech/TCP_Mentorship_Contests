#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

ll bme(ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = (ans * b) % M;
        b = (b * b) % M;
        e /= 2;
    }
    return ans;
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0, diff = 0;

    for (int i = 0; i < k; i++) {
        if ((a & (1LL << i)) != (b & (1LL << i))) {
            diff++;
        }
    }

    for (int i = 0; i < k; i++) {
        ll power = (1LL << i) % M;
        ll multiplier;

        if ((a & (1LL << i)) == (b & (1LL << i))) {
            if (!(a & (1LL << i))) {
                multiplier = bme(2, diff);
                ans = (ans + (power * multiplier) % M) % M;
            }
        } else {
            if (diff) {
                multiplier = bme(2, diff - 1);
                ans = (ans + (power * multiplier) % M) % M;
            }
        }
    }

    cout << ans << '\n';
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


