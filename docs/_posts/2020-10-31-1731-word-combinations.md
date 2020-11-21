---
layout: post
mathjax: true
title: 1731 Word Combinations
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int CMAX = 26;
ll add(ll a, ll b) { return ((a % MOD) + (b % MOD)) % MOD; }
struct node
{
    bool end;
    vector<node *> children;
    node()
    {
        children.assign(CMAX, nullptr);
        end = false;
    }
};
struct trie
{
    node *root;
    trie() { root = new node(); }
    void insert(string s)
    {
        node *cur = root;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i)
        {
            int j = s[i] - 'a';
            if (cur->children[j] == nullptr)
                cur->children[j] = new node();
            cur = cur->children[j];
        }
        cur->end = true;
    }
    ll query(int l, string s, const vector<ll> &dp)
    {
        ll ans = 0;
        node *cur = root;
        for (int i = l - 1; i >= 0; --i)
        {
            int j = s[i] - 'a';
            if (cur->children[j] == nullptr)
                break;
            cur = cur->children[j];
            if (cur->end)
                ans = add(ans, dp[i]);
        }
        return ans;
    }
};
ll solve(const string &s, const vector<string> &pattern)
{
    int n = s.size();
    vector<ll> dp(n + 1, 0);
    trie t;
    dp[0] = 1;
    for (auto p : pattern)
        t.insert(p);
    for (int l = 1; l <= n; ++l)
        dp[l] = t.query(l, s, dp);
    return dp[n];
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    string s;
    vector<string> patterns;
    cin >> s;
    cin >> k;
    patterns.resize(k);
    for (auto &pattern : patterns)
        cin >> pattern;
    cout << solve(s, patterns) << endl;
    return 0;
}

{% endraw %}
```
