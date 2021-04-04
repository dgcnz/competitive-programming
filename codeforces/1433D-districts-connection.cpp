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

vector<ii> solve(vector<int> a)
{
    int        n = a.size();
    vector<ii> edges;

    vector<int> gang1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[0])
            edges.emplace_back(1, i + 1);
        else
            gang1.push_back(i + 1);
    }

    if ((int)gang1.size() + 1 == n)
        return {};

    for (auto g : gang1)
        edges.emplace_back(edges.front().second, g);
    return edges;
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
        vector<int> a(n);
        read(all(a));
        if (auto edges = solve(a); not edges.empty())
        {
            cout << "YES" << endl;
            for (auto [x, y] : edges)
                cout << x << " " << y << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
