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

double solve(int n, int k)
{
    double ans = 0.0;
    auto   P   = [&](int i)
    {
        double p = 1.0;
        while (i < k)
            p *= 0.5, i *= 2;
        return p;
    };
    for (int i = 1; i <= n; ++i)
        ans += P(i);
    return ans / n;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << fixed << setprecision(12) << solve(n, k) << endl;
    return 0;
}
