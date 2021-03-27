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

int solve(string s)
{
    int n = s.size(), ans = 0;
    if (n % 2) // odd
        for (int k = 1; k <= n / 2; ++k)
            ans += s[n / 2 - k] != s[n / 2 + k];
    else
        for (int k = 0; k < n / 2; ++k)
            ans += s[n / 2 - 1 - k] != s[n / 2 + k];
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;

    cout << solve(s) << endl;
    return 0;
}
