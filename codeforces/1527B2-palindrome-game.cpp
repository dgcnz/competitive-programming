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
    int n     = s.size();
    int zeros = count(all(s), '0');
    if (zeros > 1 and n % 2 and s[n / 2] == '0')
        return 1;
    else
        return 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    string ans[2] = {"BOB", "ALICE"};
    while (t--)
    {
        int    n;
        string s;
        cin >> n >> s;
        string s2(s);

        int cnt = 0, zeros = count(all(s), '0');
        for (int i = 0; i < n / 2; ++i)
        {
            if (s[i] != s[n - i - 1])
            {
                s2[i] = s2[n - i - 1] = 1;
                cnt++;
            }
        }
        if (cnt == 0)
            cout << ans[solve(s2)] << endl;
        else if (cnt == 1 and zeros == 2)
            cout << "DRAW" << endl;
        else
            cout << "ALICE" << endl;
    }
    return 0;
}
