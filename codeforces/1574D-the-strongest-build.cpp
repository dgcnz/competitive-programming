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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<vi> a(n);
    for (auto &ai : a)
    {
        int c;
        cin >> c;
        ai.resize(c);
        read(all(ai));
    }

    int m;
    cin >> m;
    vector<vi> c(m, vi(n));
    for (auto &ci : c)
    {
        read(all(ci));
        decrement(all(ci));
    }

    c.emplace_back();
    for (int i = 0; i < n; i++)
        c.back().push_back(a[i].size());

    sort(all(c));

    vi maxi(n, -1);
    vi cur(n);
    ll ans = 0;

    function<void(int, vi const &, vi &, ll)> go =
        [&](int i, vi const &ban, vi &cur, ll sum)
    {
        if (i == n)
        {
            if (sum > ans && !binary_search(all(c), cur))
            {
                ans  = sum;
                maxi = cur;
            }
            return;
        }

        if (ban[i] < (int)a[i].size())
        {
            cur[i] = ban[i];
            go(i + 1, ban, cur, sum + a[i][ban[i]]);
        }

        if (ban[i] > 0)
        {
            cur[i] = ban[i] - 1;
            go(i + 1, ban, cur, sum + a[i][ban[i] - 1]);
        }
    };

    for (auto &ci : c)
        go(0, ci, cur, 0);

    increment(all(maxi));
    write(all(maxi), " "), cout << endl;

    return 0;
}
