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

int solve(vector<string> hand)
{
    sort(all(hand));
    map<string, int> cnt;
    for (auto s : hand)
        cnt[s]++;

    int ans = 2;
    for (auto s : hand)
    {
        if (cnt[s] >= 2)
            ans = min(ans, 3 - cnt[s]);

        string s1      = {char(s[0] + 1), s[1]};
        string s2      = {char(s[0] + 2), s[1]};
        int    shuntsu = 2;
        if (cnt[s1] > 0)
            shuntsu--;
        if (cnt[s2] > 0)
            shuntsu--;
        ans = min(ans, shuntsu);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    vector<string> hand(3);
    for (auto &s : hand)
        cin >> s;
    cout << solve(hand) << endl;

    return 0;
}
