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

ll solve(string s)
{
    vector<ll> cnt1(26, 0), cnt2(26 * 26, 0);
    auto id = [](char c1, char c2) { return (c1 - 'a') * 26 + (c2 - 'a'); };
    for (auto c2 : s)
    {
        for (int c1 = 0; c1 < 26; ++c1)
            cnt2[id(char(c1 + 'a'), c2)] += cnt1[c1];
        cnt1[c2 - 'a']++;
    }
    return max(*max_element(all(cnt1)), *max_element(all(cnt2)));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
