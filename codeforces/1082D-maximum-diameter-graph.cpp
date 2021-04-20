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
    int         n = a.size();
    vector<int> ones;
    ll          sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        if (a[i] == 1)
            ones.push_back(i), a[i] = 0;
    }
    if (sum < 2 * n - 2)
        return {0, {}};

    int diameter = (n - isz(ones)) - 1 + min(2, isz(ones));
    int prev     = -1;
    if (not ones.empty())
    {
        prev = ones.back();
        ones.pop_back();
    }
    vector<ii> edges;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 1)
        {
            if (prev != -1)
            {
                --a[prev];
                --a[i];
                edges.emplace_back(prev, i);
            }
            prev = i;
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        while (!ones.empty() and a[i] > 0)
        {
            --a[i];
            edges.emplace_back(i, ones.back());
            ones.pop_back();
        }
    }
    return {diameter, edges};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));
    if (auto [diam, edges] = solve(a); diam != 0)
    {
        cout << "YES " << diam << endl;
        cout << edges.size() << endl;
        for (auto [a, b] : edges)
            cout << a + 1 << " " << b + 1 << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
