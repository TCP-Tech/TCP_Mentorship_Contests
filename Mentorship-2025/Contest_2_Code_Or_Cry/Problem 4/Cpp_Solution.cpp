#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    
    for (ll &x : a) cin >> x;

    // Prefix minimum array
    vl prefMin = a;
    for (int i = 1; i < n; i++) {
        prefMin[i] = min(prefMin[i - 1], a[i]);
    }

    // Lambda function to check if mid is a valid starting value
    auto check = [&](ll mid) -> bool {
        ll curr = mid;
        bool used = false;

        for (int i = 0; i < n; i++) {
            curr += a[i];
            if (curr < 0) {
                if (!used) {
                    curr -= prefMin[i];
                    used = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    };

    ll low = 0, high = 3e14, ans = 3e14;

    // Binary search to find the minimum starting value
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
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
