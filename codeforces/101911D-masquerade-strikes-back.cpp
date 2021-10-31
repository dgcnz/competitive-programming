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

int const NMAX = 1e7 + 11;

vector<ii> solve(vector<int> c)
{
    int n = c.size();

    map<int, vi> cnt;
    for (int i = 0; i < n; ++i)
        cnt[c[i]].push_back(i);

    vector<ii> ans(n, {-1, -1});
    for (auto [x, rep] : cnt)
    {
        for (ll d1 = 1; d1 * d1 <= x; ++d1)
        {
            if (x % d1 == 0)
            {
                int d2 = x / d1;
                int i  = rep.back();
                rep.pop_back();

                ans[i] = {d1, d2};

                if (rep.empty())
                    break;
                if (d1 == d2)
                    break;

                i = rep.back();
                rep.pop_back();

                ans[i] = {d2, d1};
                if (rep.empty())
                    break;
            }
        }
        if (rep.size())
            return {};
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> c(n);
    read(all(c));

    auto ans = solve(c);
    if (ans.empty())
        cout << "NO\n" << endl;
    else
    {
        cout << "YES\n";
        for (auto [a, b] : ans)
            cout << a << " " << b << "\n";
    }
    return 0;
}
