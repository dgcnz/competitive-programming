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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<ii>> right(n);
        for (int i = 0; i < n; ++i)
        {
            int l, r;
            cin >> l >> r, l--, r--;
            right[l].emplace_back(r, i);
        }

        set<ii>     open;
        vector<int> ans(n);
        bool        flag = true;
        for (int l = 0; l < n; ++l)
        {
            for (auto [r, ix] : right[l])
                open.emplace(r, ix);

            if (open.size())
            {
                auto [r, ix] = *open.begin();
                open.erase(open.begin());
                // dbg(l, r, ix);
                if (r < l)
                {
                    flag = false;
                    break;
                }
                ans[l] = ix;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag and open.empty())
        {
            increment(all(ans));
            write(all(ans), " "), cout << endl;
        }
        else
            cout << "impossible" << endl;
    }
    return 0;
}
