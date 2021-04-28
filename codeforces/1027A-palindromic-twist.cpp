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
    int n = s.size();
    for (int i = 0; i < n / 2; ++i)
    {
        int c1 = s[i] - 'a', c2 = s[n - i - 1] - 'a';
        if (c1 != c2 + 2 and c1 != c2 - 2 and c1 != c2)
            return false;
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
