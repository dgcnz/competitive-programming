#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct FenwickTree2D
{
    vector<vector<int>> bit;
    int                 n, m;

    // init(...) { ... }

    FenwickTree2D(vector<vector<int>> a)
    {
        n = isz(a), m = isz(a.front());
        bit.assign(n, vi(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                add(i, j, a[i][j]);
    }

    int sum(int x, int y)
    {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta)
    {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }

    int query(int y1, int x1, int y2, int x2)
    {
        auto ans = sum(x2, y2);
        if (x1 > 0)
            ans -= sum(x1 - 1, y2);
        if (y1 > 0)
            ans -= sum(x2, y1 - 1);
        if (x1 > 0 and y1 > 0)
            ans += sum(x1 - 1, y1 - 1);
        return ans;
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<vi> a(n, vi(n));

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            char ch;
            cin >> ch;
            a[row][col] = ch == '*';
        }
    }

    FenwickTree2D tree(a);
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1--, x1--, y2--, x2--;

        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);

        cout << tree.query(y1, x1, y2, x2) << endl;
    }

    return 0;
}
