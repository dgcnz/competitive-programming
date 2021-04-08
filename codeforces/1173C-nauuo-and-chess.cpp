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

int solve(vi a, vi b)
{
    int n = a.size();
    vi  draw_time(n + 1, 0);
    for (int i = 0; i < n; ++i)
        draw_time[b[i]] = i + 1;

    if (draw_time[1] != 0)
    {
        bool flag = true;
        for (int t = draw_time[1]; t < n; ++t)
            if (b[t] != b[t - 1] + 1)
                flag = false;
        for (int x = b.back() + 1, t = 0; x <= n; ++x, ++t)
            if (draw_time[x] > t)
                flag = false;
        if (flag)
            return draw_time[1] - 1;
    }

    auto ok = [&](int k) {
        for (int t = 0; t < n; ++t)
            if (draw_time[t + 1] > k + t)
                return false;
        return true;
    };

    itint l(0), r(2 * n);
    return *binary_search01(l, r, ok) + n;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);
    read(all(a)), read(all(b));
    cout << solve(a, b) << endl;
    return 0;
}
