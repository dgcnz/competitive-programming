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

vector<pair<int, string>> solve(int n, int m, int k)
{
    if (4 * n * m - 2 * n - 2 * m < k)
        return {};
    vector<pair<int, string>> ans;
    if (n == 1)
    {
        int x = min(m - 1, k);
        k -= x;
        ans.emplace_back(x, "R");
        if (k == 0)
            return ans;
        x = min(m - 1, k);
        k -= x;
        ans.emplace_back(x, "L");
        return ans;
    }
    if (m == 1)
    {
        int x = min(n - 1, k);
        k -= x;
        ans.emplace_back(x, "D");
        if (k == 0)
            return ans;
        x = min(n - 1, k);
        k -= x;
        ans.emplace_back(x, "U");
        return ans;
    }

    int t = m - 1;
    while (t--)
    {
        auto x = *binary_search10(
            itint(0), itint(n), [&](int r) { return k >= 3 * r; });
        k -= 3 * x;
        if (x != 0)
            ans.emplace_back(x, "DRL");
        if (x != n - 1 and k)
        {
            ans.emplace_back(1, string("DRL").substr(0, k));
            return ans;
        }
        if (k == 0)
            return ans;
        x = min(n - 1, k);
        k -= x;
        ans.emplace_back(x, "U");
        if (k == 0)
            return ans;
        ans.emplace_back(1, "R");
        k -= 1;
        if (k == 0)
            return ans;
    }

    int x = min(n - 1, k);
    k -= x;
    ans.emplace_back(x, "D");
    if (k == 0)
        return ans;

    x = min(n - 1, k);
    k -= x;
    ans.emplace_back(x, "U");
    if (k == 0)
        return ans;

    x = min(m - 1, k);
    k -= x;
    ans.emplace_back(x, "L");
    if (k)
        return {};
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    if (auto ans = solve(n, m, k); ans.size())
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto [a, f] : ans)
            cout << a << " " << f << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
