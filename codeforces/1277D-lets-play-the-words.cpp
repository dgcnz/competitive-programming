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

template <typename T, int ALPH>
struct Trie
{
    int                      n, nmax;
    vector<array<int, ALPH>> t;
    vector<int>              cnt;

    Trie() : n(0), t(1), cnt(1) {}
    int new_node()
    {
        t.push_back(array<int, ALPH>());
        fill(all(t.back()), 0);
        cnt.push_back(0);
        return ++n;
    }
    void add(vector<int> const &a)
    {
        int cur = 0;
        for (auto ai : a)
        {
            if (!t[cur][ai])
                t[cur][ai] = new_node();
            cur = t[cur][ai];
        }
        cnt[cur]++;
    }

    int count(vector<int> const &a) const
    {
        int cur = 0;
        for (auto ai : a)
        {
            if (!t[cur][ai])
                return 0;
            cur = t[cur][ai];
        }
        return cnt[cur];
    }
};

vector<int> to_vec(string s)
{
    vi ans(s.size());
    transform(all(s), begin(ans), [](char c) { return c - '0'; });
    return ans;
}

pair<bool, vi> solve(vector<string> words)
{
    int const       ALPH = 2;
    Trie<int, ALPH> trie;

    for (auto &word : words)
        if (word.front() != word.back())
            trie.add(to_vec(word));

    int         n = words.size();
    vector<int> cnt(4, 0), revix[4];
    auto        id = [](char f, char b) { return (f - '0') * 2 + (b - '0'); };
    for (int i = 0; i < n; ++i)
    {
        char f = words[i].front(), b = words[i].back();
        cnt[id(f, b)]++;
        if (f == b)
            continue;
        auto rev = string(words[i].rbegin(), words[i].rend());
        if (trie.count(to_vec(rev)) == 0)
            revix[id(f, b)].push_back(i + 1);
    }
    if (cnt[1] < cnt[2])
    {
        swap(cnt[1], cnt[2]);
        swap(revix[1], revix[2]);
    }
    if (cnt[1] == 0 and cnt[2] == 0 and (cnt[0] and cnt[3]))
        return {false, {}};
    cnt[1] -= cnt[2];
    revix[1].resize(min((int)revix[1].size(), cnt[1] / 2));

    vi ans(all(revix[1]));

    if ((int)ans.size() < cnt[1] / 2)
        return {false, {}};

    return {true, ans};
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
        vector<string> words(n);
        read(all(words));
        if (auto [ok, ans] = solve(words); ok)
        {
            cout << ans.size() << endl;
            write(all(ans), " "), cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
