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

string solve(vector<int> a)
{
    int          n = a.size();
    map<int, vi> cnt;
    for (int i = 0; i < n; ++i)
        cnt[a[i]].push_back(i);

    vector<ii> sorted;

    for (auto &[x, pos] : cnt)
        sorted.emplace_back(pos.size(), x);

    sort(all(sorted));
    string s(n, ' ');

    bool unbalanced = false;
    for (auto [k, x] : sorted)
    {
        if (k == 1)
        {
            s[cnt[x].front()] = unbalanced ? 'B' : 'A';
            unbalanced        = !unbalanced;
        }
        else if (k >= 2)
            for (auto i : cnt[x])
                s[i] = 'A';
        if (k > 2 and unbalanced)
            s[cnt[x].back()] = 'B', unbalanced = false;
    }
    return unbalanced ? "" : s;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    read(all(a));
    if (auto ans = solve(a); !ans.empty())
    {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
