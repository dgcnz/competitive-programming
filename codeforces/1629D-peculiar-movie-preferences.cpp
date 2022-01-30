#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/string/utils>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <int ALPH>
struct Trie
{
    int                 n;
    vector<vector<int>> t;
    vector<int>         cnt;

    Trie() : n(0), t(1, vector<int>(ALPH, 0)), cnt(1, 0) {}
    int new_node()
    {
        t.emplace_back(ALPH, 0);
        cnt.push_back(0);
        return ++n;
    }
    void add(string const &s)
    {
        int cur = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i)
        {
            int x = s[i] - 'a';
            if (!t[cur][x])
                t[cur][x] = new_node();
            cur = t[cur][x];
            cnt[cur]++;
        }
    }
    void remove(string const &s)
    {
        int cur = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i)
        {
            int x = s[i] - 'a';
            cur   = t[cur][x];
            cnt[cur]--;
        }
    }

    bool query(string const &s) const
    {
        int cur = 0;
        for (int i = 0, m = s.size(); i < m; ++i)
        {
            int x = s[i] - 'a';
            if (!t[cur][x] or cnt[t[cur][x]] == 0)
                return false;
            cur = t[cur][x];
        }
        return cnt[cur] > 0;
    }
};

bool solve_prefix(vector<string> const &a)
{
    Trie<26> trie;
    for (string const &s : a)
        trie.add(s);

    for (string const &s : a)
    {
        trie.remove(s);
        if (trie.query(s))
            return true;
    }
    return false;
}

bool solve(vector<string> a)
{
    vector<string> ra;
    for (string const &s : a)
    {
        if (s.size() == 1)
            return true;

        ra.emplace_back(rall(s));
        if (s == ra.back())
            return true;
    }
    reverse(all(ra));

    return solve_prefix(a) or solve_prefix(ra);
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
        vector<string> a(n);
        read(all(a));
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}
