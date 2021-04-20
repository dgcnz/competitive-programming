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

tuple<int, int, int> solve(vi p)
{
    int n = p.size();

    map<int, int, greater<int>> cnt;
    for (auto pi : p)
        cnt[pi]++;

    int g = 0, s = 0, b = 0;
    for (auto [k, v] : cnt)
    {
        if (g == 0)
            g = v;
        else
        {
            if (s <= g)
                s += v;
            else if (b <= g)
                b += v;
            else if (g + s + b + v <= n / 2)
                b += v;
            else
                break;
        }
    }
    if (g and s and b and g + s + b <= n / 2 and g < s and g < b)
        return {g, s, b};
    else
        return {0, 0, 0};
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
        vi p(n);
        read(all(p));

        auto [g, s, b] = solve(p);
        cout << g << " " << s << " " << b << endl;
    }
    return 0;
}
