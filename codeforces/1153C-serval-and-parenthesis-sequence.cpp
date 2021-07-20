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

string solve(string s)
{
    string const NO = ":(";
    int          n  = s.size();
    if (n % 2 == 1)
        return NO;
    int rpar = n / 2 - count(all(s), ')');
    if (rpar < 0)
        return NO;

    for (int i = n - 1; rpar and i >= 0; --i)
        if (s[i] == '?')
            s[i] = ')', rpar--;

    for (int i = 0; i < n; ++i)
        if (s[i] == '?')
            s[i] = '(';

    int lpar = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
            lpar++;
        else if (s[i] == ')' and (lpar > 1 or (i == n - 1 and lpar > 0)))
            lpar--;
        else
            return NO;
    }
    return lpar ? NO : s;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> n >> s;

    cout << solve(s) << endl;
    return 0;
}
