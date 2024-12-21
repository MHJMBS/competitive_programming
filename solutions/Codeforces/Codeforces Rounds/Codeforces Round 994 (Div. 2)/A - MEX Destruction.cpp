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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& ai : a) cin >> ai;

        int intervals = 0;
        int count = 0;

        for(int ai : a) {
            if(ai == 0) {
                if(count > 0) intervals++;
                count = 0;
            }else {
                count++;
            }
        }

        if(count > 0) intervals++;

        if(intervals == 0) cout << 0 << '\n';
        else if(intervals == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }    
}