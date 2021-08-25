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

string solve(string s, int n)
{
    string t = "abacaba";
    for (int i = 0; i + (int)t.size() <= n; ++i)
    {
        string st = s;

        bool ok = [&](int i)
        {
            for (int j = 0; j < (int)t.size(); ++j)
            {
                if (st[i + j] == '?')
                    st[i + j] = t[j];
                else if (st[i + j] != t[j])
                    return false;
            }
            return true;
        }(i);

        for (int j = 0; j < n; ++j)
            if (st[j] == '?')
                st[j] = 'z';

        ok &= [&](int i)
        {
            for (int j = 0; j < n; ++j)
                if (i != j and t == st.substr(j, t.size()))
                    return false;
            return true;
        }(i);
        if (ok)
            return "Yes\n" + st;
    }
    return "No";
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
        cout << solve(s, n) << endl;
    }
    return 0;
}
