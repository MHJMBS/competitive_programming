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

template <typename T>
struct SegmentTree {
    inline static const T neutral = numeric_limits<T>::max();
    vector<T> seg;
    int leafsBegin;
    int leafsCount;

    SegmentTree(const vector<T>& v) {
        leafsCount = 1;
        while(leafsCount < v.size()) leafsCount *= 2;
        seg.resize(2*leafsCount-1, neutral);
        
        leafsBegin = seg.size() - leafsCount;

        for(int i = 0; i < v.size(); i++) {
            seg[leafsBegin+i] = v[i];
        }

        for(int i = leafsBegin-1; i >= 0; i--) {
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }

    void upd(int i, T val) {
        i = leafsBegin + i;
        seg[i] = val;
        while(i > 0) {
            i = (i-1)/2;
            seg[i] = op(seg[2*i+1], seg[2*i+2]);
        }
    }

    T query(int l, int r) {
        return query(l, r, 0, leafsCount-1, 0);
    }

    T query(int l, int r, int lx, int rx, int i) {
        if(rx < l || r < lx) return neutral;
        if(l <= lx && rx <= r) return seg[i];
        int mid = (lx+rx)/2;
        return op( query(l, r, lx, mid, 2*i+1), query(l, r, mid+1, rx, 2*i+2) );
    }

    T op(T a, T b) {
        return min(a,b);
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    SegmentTree seg(x);

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            seg.upd(k,u);
        }else {
            int a, b;
            cin >> a >> b;
            a--,b--;
            cout << seg.query(a,b) << '\n';
        }
    }
}