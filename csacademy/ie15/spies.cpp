#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cassert>
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
    int t;
    cin >> t;
    while (t--)
    {
        int nr, nb, q;
        cin >> nr >> nb >> q;

        vector<int> parent(nr + nb, -1);

        auto id  = [&](char c, int i) { return i + (c == 'R' ? 0 : nr); };
        auto rid = [&](int u) -> pair<char, int>
        {
            if (u >= nr)
                return {'B', u - nr};
            return {'R', u};
        };
        auto parse = [&](string s) -> pair<char, int> {
            return {s[0], stoi(string(s.begin() + 1, s.end())) - 1};
        };

        for (int i = 0; i < nr - 1; ++i)
        {
            string s;
            cin >> s;
            auto [c, j]          = parse(s);
            parent[id(c, i + 1)] = id(c, j);
        }
        for (int i = 0; i < nb - 1; ++i)
        {
            string s;
            cin >> s;
            auto [c, j]          = parse(s);
            parent[id(c, i + 1)] = id(c, j);
        }
        assert(make_pair('R', 0) == rid(id('R', 0)));
        assert(make_pair('B', 0) == rid(id('B', 0)));
        int const INF = 1e9;

        while (q--)
        {
            char type;
            cin >> type;
            string x, y;
            cin >> x >> y;
            auto [cx, ix] = parse(x);
            auto [cy, iy] = parse(y);
            if (type == 'w')
            {
                auto get_head = [&](char c, int i) -> tuple<char, int, int>
                {
                    vector<bool> vis(nr + nb, false);
                    int          u = id(c, i), k = 0;

                    while (u != id('R', 0) and u != id('B', 0) and not vis[u])
                    {
                        vis[u] = true;
                        u      = parent[u];
                        k++;
                    }
                    auto [cj, j] = rid(u);
                    if (j != 0)
                        k = INF;
                    return {cj, j, k};
                };

                auto [cxx, ixx, kxx] = get_head(cx, ix);
                auto [cyy, iyy, kyy] = get_head(cy, iy);
                if (ixx != 0 and iyy != 0) // check
                    cout << "NONE" << endl;
                else if (ixx != 0 or kyy < kxx)
                    cout << (cyy == 'R' ? "RED " : "BLUE ") << kyy << endl;
                else if (iyy != 0 or kxx < kyy)
                    cout << (cxx == 'R' ? "RED " : "BLUE ") << kxx << endl;
                else // kxx == kyy and ixx == 0 and iyy == 0
                {
                    if (cxx == cyy)
                        cout << (cxx == 'R' ? "RED " : "BLUE ") << kxx << endl;
                    else
                        cout << "TIE " << kxx << endl;
                }
            }
            else
            {
                parent[id(cx, ix)] = id(cy, iy);
            }
        }
    }
    return 0;
}
