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

bool test(string br)
{
    int open = 0;
    for (auto ch : br)
    {
        if (ch == '(')
            open++;
        else
            open--;
        if (open < 0)
            return false;
    }
    return open == 0;
}

bool solve(string s)
{
    int  n    = s.size();
    char open = s.front(), close = s.back();
    if (open == close)
        return false;

    string b1(n, ' '), b2(n, ' ');
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == open)
            b1[i] = b2[i] = '(';
        else if (s[i] == close)
            b1[i] = b2[i] = ')';
        else
            b1[i] = '(', b2[i] = ')';
    }

    return test(b1) or test(b2);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
