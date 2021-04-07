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

ll solve(string s)
{
    int n = s.size(), start = 0, rem = 0;
    ll  ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '-')
        {
            if (rem)
                rem--;
            else
                start++, ans += i + 1;
        }
        else // +
            rem++;
    }
    return ans + n;
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
        cout << solve(s) << endl;
    }
    return 0;
}
