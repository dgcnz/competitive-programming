#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi a, int k)
{
    int  n  = a.size();
    auto ok = [&](int x) {
        vector<ll> b(n), pb(n), minpb(n);
        for (int i = 0; i < n; ++i)
            b[i] = (a[i] >= x ? 1 : -1);
        partial_sum(all(b), begin(pb));
        partial_sum(all(pb), begin(minpb), cplib::min<int>());
        for (int i = k - 1; i < n; ++i)
            if (pb[i] - (i >= k and minpb[i - k] < 0 ? minpb[i - k] : 0LL) > 0)
                return true;
        return false;
    };

    return *binary_search10(itint(1), itint(n + 1), ok);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi a(n);
    read(all(a));
    cout << solve(a, k) << endl;
    return 0;
}
