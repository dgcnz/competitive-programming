#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(vi a)
{
    int n = a.size();
    for (int i = 0; i < n; ++i)
    {
        int del = 0;
        ll  x   = i + 2;
        while (x != 0 and a[i] % x == 0)
        {
            del += 1;
            x = lcm(x, i + 2 - del);
        }
        if (x == 0)
            return "NO";
    }
    return "YES";
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
        vi a(n);
        read(all(a));

        cout << solve(a) << endl;
    }
    return 0;
}
