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

vector<pair<char, int>> pair_cnts(string s)
{
    int                     cnt  = 0;
    char                    prev = s.front();
    vector<pair<char, int>> ans;
    for (auto c : s)
    {
        if (c == prev)
            cnt++;
        else
        {
            ans.emplace_back(prev, cnt);
            cnt = 1;
        }
        prev = c;
    }
    ans.emplace_back(prev, cnt);
    return ans;
}

string solve(string s1, string s2)
{
    auto p1 = pair_cnts(s1);
    auto p2 = pair_cnts(s2);
    int  n  = p1.size();
    if (n != (int)p2.size())
        return "NO";
    for (int i = 0; i < n; ++i)
        if (p1[i].first != p2[i].first or p1[i].second > p2[i].second)
            return "NO";
    return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solve(s1, s2) << endl;
    }
    return 0;
}
