---
layout: post
mathjax: true
title: 842D - Vitya And Strange Lesson
problem_url: https://codeforces.com/problemset/problem/842/D
tags: trie, string
memory_complexity: O(n)
time_complexity: O(n)
---

[Editorial](https://codeforces.com/blog/entry/54179).



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
template <typename T>
struct Trie
{
    int n, nmax;
    vector<vector<int>> t;
    vector<T> val;
    Trie(int N, int alphasz) : n(0), t(N, vector<int>(alphasz, 0)), val(N, T())
    {
    }
    void update(const vector<int> &a, function<void(T &)> f)
    {
        int cur = 0;
        for (int i = 0; i < (int)a.size(); ++i)
        {
            if (!t[cur][a[i]])
                t[cur][a[i]] = ++n;
            cur = t[cur][a[i]];
            f(val[cur]);
        }
    }
    void traverse(const vector<int> &a, function<void(T &, int)> f)
    {
        int cur = 0;
        for (int i = 0; i < (int)a.size(); ++i)
        {
            if (!t[cur][a[i]])
                return;
            f(val[t[cur][a[i]]], i);
            cur = t[cur][a[i]];
        }
    }
};
template <size_t N>
vector<int> bitvec(int x)
{
    vi a(N);
    for (int i = (int)N - 1; i >= 0; --i)
        a[i] = (x >> i) & 1;
    return a;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int const MAXLEN = 20, ALPHA_SZ = 2;
    Trie<int> trie(1 << MAXLEN, ALPHA_SZ);
    auto f1 = [](int &a) { a++; };
    vector<bool> vis(3e5 + 11, false);
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        if (!vis[ai])
        {
            auto a = bitvec<MAXLEN>(ai);
            reverse(begin(a), end(a));
            trie.update(a, f1);
            vis[ai] = true;
        }
    }
    int x = 0;
    while (m--)
    {
        int xi, ans = 0;
        cin >> xi;
        x ^= xi;
        auto a = bitvec<MAXLEN>(x);
        reverse(begin(a), end(a));
        auto f2 = [MAXLEN, &a, &ans](int &val, int i) {
            int j = MAXLEN - i - 1;
            if (val == (1 << j))
            {
                ans |= 1 << j;
                a[i] = 1 - a[i];
            }
        };
        trie.traverse(a, f2);
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

