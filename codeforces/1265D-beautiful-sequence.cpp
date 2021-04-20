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

vi solve(int a, int b, int c, int d, int xa, int xb, int xc, int xd)
{
    int n = a + b + c + d;
    vi  s(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            if (a)
                s[i] = xa, a--;
            else if (c)
                s[i] = xc, c--;
        }
        else
        {
            if (b)
                s[i] = xb, b--;
            else if (d)
                s[i] = xd, d--;
        }
    }
    if (count(all(s), -1) > 0)
        return {};

    for (int i = 1; i < n; ++i)
        if (abs(s[i] - s[i - 1]) != 1)
            return {};
    return s;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto ans01 = solve(a, b, c, d, 0, 1, 2, 3);
    auto ans10 = solve(b, a, d, c, 1, 0, 3, 2);
    if (!ans01.empty())
    {
        cout << "YES" << endl;
        write(all(ans01), " "), cout << endl;
    }
    else if (!ans10.empty())
    {
        cout << "YES" << endl;
        write(all(ans10), " "), cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
