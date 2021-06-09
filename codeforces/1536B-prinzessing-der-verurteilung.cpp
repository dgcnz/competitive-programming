#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/strings/utils>
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
    int                                           n = s.size();
    set<string, bounded_lexicographical::compare> ord;
    for (int i = 0; i < n; ++i)
    {
        string t = string(1, s[i]);
        ord.insert(t);
        if (i < n - 1)
        {
            t += s[i + 1];
            ord.insert(t);
            if (i < n - 2)
            {
                t += s[i + 2];
                ord.insert(t);
            }
        }
    }
    string x = "a";
    for (auto y : ord)
    {
        if (x != y)
            break;
        x = bounded_lexicographical::next(x);
    }
    return x;
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
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}
