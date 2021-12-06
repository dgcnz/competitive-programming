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

string solve(int n)
{
    for (int x = 2; x * x * x <= n; ++x)
    {
        if (n % x == 0)
        {
            int m = n / x;
            for (int y = x + 1; y * y < m; ++y)
                if (m % y == 0)
                    return "YES\n" + to_string(x) + " " + to_string(y) + " " +
                           to_string(m / y) + "\n";
        }
    }
    return "NO";
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
        cout << solve(n) << endl;
    }
    return 0;
}
