#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/strings/z_function>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n, m, q;
    string s, t;
    cin >> n >> m >> q;
    cin >> s >> t;

    auto        pi = z_function(t + "#" + s);
    vector<int> ans(n, 0);
    for (int i = m + 1; i < n + m + 1; ++i)
        if (pi[i] == m)
            ans[i - m - 1] = 1;
    partial_sum(all(ans), begin(ans));
    auto query = [&](int l, int r) {
        if (r < l)
            return 0;
        return ans[r] - (l ? ans[l - 1] : 0);
    };

    while (q--)
    {
        int l, r;
        cin >> l >> r, l--, r--;
        cout << query(l, r - m + 1) << endl;
    }
    return 0;
}
