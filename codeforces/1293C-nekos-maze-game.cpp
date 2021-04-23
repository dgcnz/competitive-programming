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

struct Board
{
    int        n;
    vector<vi> b;
    set<ii>    blocking;
    Board(int n) : n(n), b(2, vi(n, 0)) {}
    void toggle(int r, int c)
    {
        if (b[r][c] == 0) // set
        {
            if (c > 0 and b[1 - r][c - 1])
            {
                if (r == 0)
                    blocking.emplace(c, c - 1);
                else
                    blocking.emplace(c - 1, c);
            }
            if (b[1 - r][c])
            {
                blocking.emplace(c, c);
            }
            if (c < n - 1 and b[1 - r][c + 1])
            {
                if (r == 0)
                    blocking.emplace(c, c + 1);
                else
                    blocking.emplace(c + 1, c);
            }
        }
        else
        {
            blocking.erase(ii{c, c});
            if (r == 0)
            {
                blocking.erase(ii{c, c - 1});
                blocking.erase(ii{c, c + 1});
            }
            else
            {
                blocking.erase(ii{c - 1, c});
                blocking.erase(ii{c + 1, c});
            }
        }
        b[r][c] = 1 - b[r][c];
    }
    bool query() const { return blocking.empty(); }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    Board b(n);
    while (q--)
    {
        int r, c;
        cin >> r >> c, r--, c--;
        b.toggle(r, c);
        cout << (b.query() ? "Yes" : "No") << endl;
    }
    return 0;
}
