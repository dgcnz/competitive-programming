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

int solve(vector<string> s)
{
    int         n = s.size();
    vector<int> cnt(2, 0);
    bool        odd = false;
    for (auto si : s)
    {
        odd |= si.size() % 2;
        for (auto c : si)
            cnt[c - '0']++;
    }

    return n - (cnt[0] % 2 and cnt[1] % 2 and !odd);
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
        vector<string> s(n);
        for (auto &si : s)
            cin >> si;
        cout << solve(s) << endl;
    }
    return 0;
}
