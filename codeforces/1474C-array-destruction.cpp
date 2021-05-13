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

pair<int, vector<ii>> solve(vi a)
{
    int n = a.size();

    for (int i = 0; i < n; ++i)
    {
        multiset<int, greater<int>> s(all(a));
        int                         xx = *s.begin() + a[i], x = xx;
        vector<ii>                  ans;
        while (s.size())
        {
            auto mxit = s.begin();
            int  mx   = *mxit;
            s.erase(mxit);
            auto mnit = s.find(x - mx);
            if (mnit == s.end())
                break;
            int mn = *mnit;
            s.erase(mnit);
            x = mx;
            ans.emplace_back(mx, mn);
        }
        if (s.empty())
            return {xx, ans};
    }
    return {0, {}};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(2 * n);
        read(all(a));
        if (auto [x, ans] = solve(a); x)
        {
            cout << "YES" << endl << x << endl;
            for (auto [x, y] : ans)
                cout << x << " " << y << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
