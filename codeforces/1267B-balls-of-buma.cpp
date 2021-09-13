#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/string/utils>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;

    vector<pair<char, int>> groups;

    int i = 0, n = s.size();
    while (i < n)
    {
        int j = i;
        while (j < n and s[i] == s[j])
            ++j;
        groups.emplace_back(s[i], j - i);
        i = j;
    }

    int ans = 0, m = groups.size();
    if (m % 2 and groups[m / 2].second >= 2)
    {
        bool flag = true;
        for (int i = 1; i <= m / 2; ++i)
        {
            auto l = groups[m / 2 - i], r = groups[m / 2 + i];
            if (l.first != r.first or l.second + r.second < 3)
                flag = false;
        }

        if (flag)
            ans = groups[m / 2].second + 1;
    }

    cout << ans << endl;

    return 0;
}
