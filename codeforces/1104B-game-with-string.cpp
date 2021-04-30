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
    int      n = s.size(), ans = 0;
    set<int> indices;
    for (int i = 0; i < n; ++i)
        indices.insert(i);

    for (int i = 0; i < n - 1; ++i)
    {
        auto itl = indices.find(i);
        if (itl == indices.end())
            continue;

        auto itr = next(itl);
        if (itr == indices.end())
            continue;

        while (itl != indices.begin() and itr != indices.end() and
               s[*itl] == s[*itr])
        {
            itl--;
            itr++;
            indices.erase(next(itl));
            indices.erase(prev(itr));
            ans++;
        }
        if (itl == indices.begin() and itr != indices.end() and
            s[*itl] == s[*itr])
        {
            indices.erase(itl);
            indices.erase(itr);
            ans++;
        }
    }
    dbg(ans);
    return ans % 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << endl;
    return 0;
}
