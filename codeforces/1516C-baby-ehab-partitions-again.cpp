#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/dp/subset_sum>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vi solve(vi a)
{
    ll sum = accumulate(all(a), 0LL);
    if (sum % 2 or not SubsetSum(a, sum / 2).solve())
        return {};

    ii ans = {100, 0};
    for (int i = 0, n = a.size(); i < n; ++i)
        ans = min(ans, {__builtin_ctz(a[i]), i});
    return {ans.second + 1};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));
    auto ans = solve(a);
    if (ans.size())
    {
        cout << ans.size() << endl;
        write(all(ans), " "), cout << endl;
    }
    else
        cout << 0 << endl;

    return 0;
}
