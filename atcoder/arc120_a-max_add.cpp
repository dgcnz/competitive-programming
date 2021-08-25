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

vector<ll> solve(vector<ll> a)
{
    int        n = a.size();
    vector<ll> sa(n), mxa(n);
    partial_sum(all(a), begin(sa));
    partial_sum(all(a), begin(mxa), [](auto x, auto y) { return max(x, y); });
    vector<ll> ans(n, 0);
    for (int i = 0; i < n; ++i)
        ans[n - 1] += (n - i) * (ll)a[i];
    ans[n - 1] += n * mxa[n - 1];

    for (int i = n - 2; i >= 0; --i)
    {
        ans[i] = ans[i + 1];
        ans[i] -= (i + 2) * mxa[i + 1];
        ans[i] += (i + 1) * mxa[i];
        ans[i] -= sa[i + 1];
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    auto ans = solve(a);
    write(all(ans), "\n");
    return 0;
}
