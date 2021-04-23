#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vector<ll> a, ll s)
{
    int        n = a.size();
    vector<ll> pa(n);
    partial_sum(all(a), pa.begin());

    int maxsongs = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pa[i] > s)
            break;
        maxsongs++;
    }
    pair<ll, int> ans = {maxsongs, 0};

    for (int i = 0; i < n; ++i)
    {
        auto f     = [&](int ix) { return pa[ix] - (ix < i ? 0 : a[i]); };
        auto ok    = [&](int ix) { return f(ix) <= s; };
        int  songs = *binary_search10(itint(0), itint(n), ok);
        songs      = songs == n ? 0 : songs;
        ans        = max(ans, {songs, i + 1});
    }
    return ans.second;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll  s;
        cin >> n >> s;
        vector<ll> a(n);
        read(all(a));
        cout << solve(a, s) << endl;
    }
    return 0;
}
