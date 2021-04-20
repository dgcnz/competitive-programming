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

bool solve(string s)
{
    for (int i = 0; i < 2; ++i)
    {
        int m = 0, t = 0;
        for (auto c : s)
        {
            if (c == 'M')
                m++;
            else
                t++;
            if (m > t)
                return false;
        }
        if (m * 2 != t)
            return false;
        reverse(all(s));
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string s;
        cin >> n >> s;
        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
