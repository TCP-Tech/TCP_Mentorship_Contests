#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>

void solve() {
    ll a,b;
    cin>>a>>b;
    while(a!=b){
        if(a>b) a/=2;
        else b/=2;
    }
    cout<<a<<endl;
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

