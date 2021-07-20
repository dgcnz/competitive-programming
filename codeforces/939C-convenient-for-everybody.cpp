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

int solve(vector<ll> a, int s, int f)
{
    int n = a.size(), k = f - s;
    a.insert(a.end(), all(a));
    vector<ll> pa(a.size());
    partial_sum(all(a), begin(pa));

    pair<ll, int> ans = {-1, -3 * n};
    auto sum = [&](int l, int r) { return pa[r] - (l > 0 ? pa[l - 1] : 0LL); };
    auto start = [&](int i) { return (s - i + n) % n; };
    for (int i = 0; i < n; ++i)
        ans = max(ans, {sum(i, i + k - 1), -start(i)});

    return -ans.second;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, s, f;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    cin >> s >> f, s--, f--;

    cout << solve(a, s, f) + 1 << endl;

    return 0;
}
