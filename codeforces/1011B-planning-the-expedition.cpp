#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi a, int people)
{
    vector<int> cnt(100);
    for (auto ai : a)
        cnt[ai]++;

    for (int d = 100; d > 0; --d)
    {
        int cur = 0;
        for (auto c : cnt)
            cur += c / d;
        if (cur >= people)
            return d;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi a(m);
    read(all(a));
    decrement(all(a));

    cout << solve(a, n) << endl;
    return 0;
}
