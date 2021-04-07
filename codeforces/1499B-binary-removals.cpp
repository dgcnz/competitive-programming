#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(string s)
{
    int n = s.size();

    vector<bool> ok_left(n, 0), ok_right(n, 0);

    ok_left[0] = true;
    for (int i = 1; i < n; ++i)
    {
        if (s[i - 1] == '1' and s[i] == '1')
            break;
        ok_left[i] = true;
    }
    ok_right[n - 1] = true;
    for (int i = n - 2; i >= 0; --i)
    {
        if (s[i] == '0' and s[i + 1] == '0')
            break;
        ok_right[i] = true;
    }
    if (ok_left[n - 1] or ok_right[0])
        return true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (ok_left[i] and ok_right[i + 1])
            return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
