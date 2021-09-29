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

string solve(vector<vi> a, vector<vi> b)
{
    int                   n = a.size(), m = a.back().size();
    vector<multiset<int>> da(n + m - 1), db(n + m - 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            da[i + j].insert(a[i][j]);
            db[i + j].insert(b[i][j]);
        }
    }
    for (int i = 0; i < n + m - 1; ++i)
        if (da[i] != db[i])
            return "NO";
    return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));
    for (auto &ai : a)
        read(all(ai));
    vector<vi> b(n, vi(m));
    for (auto &bi : b)
        read(all(bi));

    cout << solve(a, b) << endl;

    return 0;
}
