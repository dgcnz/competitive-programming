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

bool isvowel(char c)
{
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

array<vector<int>, 2> solve(vector<string> &a)
{
    int         n = a.size();
    vector<int> lv(n, 0), cntv(n, 0);
    for (int i = 0; i < n; ++i)
        for (auto c : a[i])
            if (isvowel(c))
                cntv[i]++, lv[i] = c - 'a';

    map<int, vi> pairable;
    for (int i = 0; i < n; ++i)
        pairable[cntv[i]].push_back(i);

    array<vi, 2> ans;
    for (auto &[k, v] : pairable)
    {
        vector<vi> bucket(26);
        for (auto ix : v)
            bucket[lv[ix]].push_back(ix);
        vi temp;
        for (auto const &b : bucket)
        {
            int n = b.size(), i = 0;
            for (; i < n; i += 2)
            {
                if (i + 1 >= n)
                    break;
                ans[1].push_back(b[i]);
                ans[1].push_back(b[i + 1]);
            }
            for (; i < n; i++)
                temp.push_back(b[i]);
        }
        temp.resize(2 * (temp.size() / 2));
        ans[0].insert(ans[0].end(), all(temp));
    }
    while (ans[1].size() > ans[0].size())
    {
        ans[0].push_back(ans[1].back());
        ans[1].pop_back();
        ans[0].push_back(ans[1].back());
        ans[1].pop_back();
    }
    if (ans[1].size() < ans[0].size())
        ans[0].resize(ans[1].size());
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n);
    read(all(a));

    auto ans = solve(a);
    int  m   = ans[0].size();
    cout << m / 2 << endl;
    for (int i = 0; i < m; ++i)
        cout << a[ans[0][i]] << " " << a[ans[1][i]] << endl;
    return 0;
}
