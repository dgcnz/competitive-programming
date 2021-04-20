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

string match(string s1, string s2, char c)
{
    int    n = s1.size();
    string ans;
    int    i = 0, j = 0;
    while (i < n and j < n)
    {
        while (i < n and s1[i] != c)
        {
            ans.push_back(s1[i]);
            i++;
        }
        while (j < n and s2[j] != c)
        {
            ans.push_back(s2[j]);
            j++;
        }
        while (i < n and j < n and s1[i] == c and s2[j] == c)
        {
            ans.push_back(s1[i]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        ans.push_back(s1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(s2[j]);
        j++;
    }
    return ans;
}

string solve(vector<string> s)
{
    int        n = s[0].size() / 2;
    vector<vi> cnt(3, vi(2, 0));
    for (int i = 0; i < 3; ++i)
        for (auto c : s[i])
            cnt[i][c - '0']++;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (min(cnt[i][0], cnt[j][0]) >= n)
                return match(s[i], s[j], '0');
            if (min(cnt[i][1], cnt[j][1]) >= n)
                return match(s[i], s[j], '1');
        }
    }
    return "";
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
        vector<string> s(3);
        read(all(s));
        cout << solve(s) << endl;
    }
    return 0;
}
