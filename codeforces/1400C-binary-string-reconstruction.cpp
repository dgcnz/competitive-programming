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

string solve(string s, int x)
{
    int    n = s.size();
    string w(n, '1');
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            if (i - x >= 0)
                w[i - x] = '0';
            if (i + x < n)
                w[i + x] = '0';
        }
    }
    for (int i = 0; i < n; ++i)
        if (s[i] == '1' and ((i - x < 0 or w[i - x] == '0') and
                             (i + x >= n or w[i + x] == '0')))
            return "-1";
    return w;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int    x;
        cin >> s >> x;
        cout << solve(s, x) << endl;
    }
    return 0;
}
