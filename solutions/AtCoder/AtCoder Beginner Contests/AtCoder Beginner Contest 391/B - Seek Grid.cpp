#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<string> s(n), t(m);

    for(string& row : s) cin >> row;
    for(string& row : t) cin >> row;

    for(int i = 0; i <= n-m; i++) {
        for(int j = 0; j <= n-m; j++) {
            bool ok = true;
            for(int a = 0; a < m; a++) {
                for(int b = 0; b < m; b++) {
                    ok = ok && (s[i+a][j+b] == t[a][b]);
                }
            }
            if(ok) {
                cout << i+1 << ' ' << j+1 << '\n';
                return 0;
            }
        }
    }
}