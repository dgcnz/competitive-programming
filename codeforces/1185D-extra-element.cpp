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

int solve(vector<ll> b)
{
    int n = b.size();
    if (n <= 3)
        return 0;
    vector<pair<ll, int>> bindex(n);
    for (int i = 0; i < n; ++i)
        bindex[i] = {b[i], i};
    sort(all(b));
    sort(all(bindex));
    auto in_range = [n](int i) { return 0 <= i and i < n; };
    auto check    = [&](int i0, int i1, int i2, int i3) {
        ll ldelta = -1, rdelta = -1;
        if (in_range(i0) and in_range(i1))
            ldelta = b[i1] - b[i0];
        if (in_range(i2) and in_range(i3))
            rdelta = b[i3] - b[i2];
        return ldelta == rdelta or ldelta == -1 or rdelta == -1;
    };

    vector<bool> lvalid(n, 0), rvalid(n, 0);
    for (int i = 0; i < n; ++i)
        if ((i <= 0 or lvalid[i - 1]) and check(i - 2, i - 1, i - 1, i))
            lvalid[i] = true;

    for (int i = n - 1; i >= 0; --i)
        if ((i >= n - 1 or rvalid[i + 1]) and check(i, i + 1, i + 1, i + 2))
            rvalid[i] = true;

    for (int i = 0; i < n; ++i)
    {
        if ((i <= 0 or lvalid[i - 1]) and (i >= n - 1 or rvalid[i + 1]) and
            check(i - 2, i - 1, i + 1, i + 2) and
            check(i - 2, i - 1, i - 1, i + 1) and
            check(i - 1, i + 1, i + 1, i + 2))
        {
            return bindex[i].second;
        }
    }
    return -2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> b(n);
    read(all(b));
    cout << solve(b) + 1 << endl;
    return 0;
}
