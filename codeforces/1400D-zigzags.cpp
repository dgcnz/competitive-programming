#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(vi a)
{
    int n   = a.size();
    ll  ans = 0;

    auto        id = [&](int x, int y) { return n * x + y; };
    vector<int> cnt(n * n, 0);

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i + 2; j < n; ++j)
            cnt[id(a[i + 1], a[j])]++;

        for (int j = 0; j < i; ++j)
            ans += cnt[id(a[j], a[i])];
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        read(all(a));
        decrement(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
