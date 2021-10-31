#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int f(int x)
{
    int unlucky = 0;
    for (int i = 0; i < 3; ++i)
    {
        unlucky -= x % 10;
        x /= 10;
    }
    for (int i = 0; i < 3; ++i)
    {
        unlucky += x % 10;
        x /= 10;
    }
    unlucky = abs(unlucky);
    assert(unlucky <= 27);
    return unlucky;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ii> a(n, {0, 0});
    for (int i = 0; i < n; ++i)
    {
        string b;
        cin >> b;

        a[i].second = i;
        for (int j = 0; j < 6; ++j)
            a[i].first = 10 * a[i].first + (b[j] - '0');
    }

    vector<int> acc(28, 0);
    vector<int> ans(n);
    int         ix = 0;

    sort(all(a));
    for (auto [ai, i] : a)
    {
        while (ix < ai)
            acc[f(ix++)]++;
        ans[i] = accumulate(acc.begin(), acc.begin() + f(ai), 0);
    }
    write(all(ans));

    return 0;
}
