#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/string>
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using namespace placeholders;

int solve(vector<int> &sa, string &c, string s)
{
    int m = sa.size(), n = s.size(), ans = 0, l = 0;

    while (l < n)
    {
        auto p1 = [&](char cc, int delta, int i) {
            return c[sa[i] + delta] >= cc;
        };
        auto p2 = [&](char cc, int delta, int i) {
            return c[sa[i] + delta] > cc;
        };
        auto first = itint(0), last = itint(m);
        auto ok = [&](char cc, int delta) {
            first = binary_search01(first, last, bind(p1, cc, delta, _1));
            last  = binary_search01(first, last, bind(p2, cc, delta, _1));
            return first != last;
        };

        if (!ok(s[l], 0))
            return -1;
        int r = l + 1;
        while (r < n and ok(s[r], r - l))
            ++r;
        l = r;
        ans++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    string c;
    cin >> c;
    auto sa = suffix_array(c);
    int  t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(sa, c, s) << endl;
    }
    return 0;
}
