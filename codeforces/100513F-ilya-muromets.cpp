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

int solve(vi f, int k)
{
    int n = f.size();
    vi  pf(n);
    partial_sum(all(f), begin(pf));

    if (2 * k > n)
        return pf.back();

    auto sum = [&](int l, int r) { return pf[r] - (l ? pf[l - 1] : 0); };
    vi   mx(n);
    mx[0] = f[0];
    for (int r = 1; r < n; ++r)
        mx[r] = max(mx[r - 1], sum(max(r - k + 1, 0), r));
    int ans = *max_element(all(mx));
    for (int r = k; r < n; ++r)
        ans = max(mx[r - k] + sum(r - k + 1, r), ans);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vi f(n);

    read(all(f));
    cout << solve(f, k) << endl;

    return 0;
}
