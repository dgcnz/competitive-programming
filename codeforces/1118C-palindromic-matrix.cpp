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

vector<vi> solve(int n, vi a)
{
    map<int, int> cnt;
    for (auto ai : a)
        cnt[ai]++;

    vector<int> a1, a2, a4;
    for (auto [k, v] : cnt)
    {
        while (v >= 4)
            a4.push_back(k), v -= 4;
        while (v >= 2)
            a2.push_back(k), v -= 2;
        while (v >= 1)
            a1.push_back(k), v -= 1;
    }
    vector<vi> ans(n, vi(n));

    if (n % 2)
    {
        if (a1.size() != 1)
            return {};
        ans[n / 2][n / 2] = a1.back();
        a1.pop_back();
    }
    else if (n % 2 == 0 and (a1.size() or a2.size()))
        return {};

    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            if (a4.empty())
                return {};
            ans[i][j] = ans[n - i - 1][j] = ans[i][n - j - 1] =
                ans[n - i - 1][n - j - 1] = a4.back();
            a4.pop_back();
        }
    }

    if (n % 2 == 0)
        return ans;

    for (auto x : a4)
        a2.push_back(x), a2.push_back(x);

    for (int i = 0; i < n / 2; ++i)
    {
        ans[i][n / 2] = ans[n - i - 1][n / 2] = a2.back();
        a2.pop_back();
    }

    for (int j = 0; j < n / 2; ++j)
    {
        ans[n / 2][j] = ans[n / 2][n - j - 1] = a2.back();
        a2.pop_back();
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n * n);
    read(all(a));
    auto ans = solve(n, a);
    if (ans.empty())
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (auto &row : ans)
            write(all(row), " "), cout << endl;
    }
    return 0;
}
