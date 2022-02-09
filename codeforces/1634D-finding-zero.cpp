#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int query(int i, int j, int k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

ii solve(int n)
{
    map<set<int>, int> cache;
    map<set<int>, int> vis;
    auto               find_extreme = [&](int a, int b)
    {
        vector<ii> q;
        for (int i = 1; i <= n; ++i)
        {
            if (i != a and i != b)
            {
                if (!vis[{a, b, i}])
                    vis[{a, b, i}] = true, cache[{a, b, i}] = query(a, b, i);
                q.emplace_back(cache[{a, b, i}], i);
            }
        }
        auto qmax = *max_element(all(q));
        return qmax.second;
    };

    vector<int> first_4 = {cache[{2, 3, 4}] = query(2, 3, 4),
                           cache[{1, 3, 4}] = query(1, 3, 4),
                           cache[{1, 2, 4}] = query(1, 2, 4),
                           cache[{1, 2, 3}] = query(1, 2, 3)};
    vis[{2, 3, 4}] = vis[{1, 3, 4}] = vis[{1, 2, 4}] = vis[{1, 2, 3}] = true;

    auto sigma = argsort(all(first_4));
    int  a = sigma[2] + 1, b = sigma[3] + 1;
    if (n == 4)
        return {sigma[0] + 1, sigma[1] + 1};

    auto x = find_extreme(a, b); // a, b are non-zero
    auto y = find_extreme(a, x);
    return {x, y};
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

        auto [x, y] = solve(n);
        cout << "! " << x << " " << y << endl;
        cout.flush();
    }
    return 0;
}
