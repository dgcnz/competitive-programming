#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int lcp(string s, string t)
{
    int i = 0;
    while (i < (int)s.size() and i < (int)t.size() and s[i] == t[i])
        ++i;
    return i;
}

string solve(string s, string t)
{
    if (count(all(s), '*') == 0)
        return s == t ? "YES" : "NO";

    int l = lcp(s, t);
    int r = lcp(string(rall(s)), string(rall(t)));
    int n = s.size(), m = t.size();
    if (l + r > m or s[l] != '*' or s[n - r - 1] != '*')
        return "NO";
    else
        return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;

    cout << solve(s, t) << endl;
    return 0;
}
