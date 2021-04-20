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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        s     = '!' + s + '!';

        auto mex = [](char a, char b) {
            vector<int> opts = {'a', 'b', 'c'};
            opts.erase(remove_if(all(opts),
                                 [a, b](char c) { return c == a or c == b; }),
                       opts.end());
            return opts;
        };

        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i] == s[i - 1])
                flag = false;
            if (s[i] == '?')
            {
                auto opts = mex(s[i - 1], s[i + 1]);
                s[i]      = opts.front();
            }
        }
        if (flag)
        {
            for (int i = 1; i <= n; ++i)
                cout << s[i];
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
