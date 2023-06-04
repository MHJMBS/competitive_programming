#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int i1, i2;

        vector<int> p(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            if(p[i] == 1) i1 = i;
            else if(p[i] == 2) i2 = i;
        }

        if(i1 > i2) swap(i1,i2);

        if(p[1] > p[n]) {
            cout << 1 << ' ' << i1 << '\n';
        }else {
            cout << i2 << ' ' << n << '\n';
        }
    }
}