---
layout: post
mathjax: true
title: SUBXOR - Subxor
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
const int ALPH = 2;
const int TRIEMAX = 20;
struct node
{
    ll cnt;
    node *children[ALPH];
    node(void)
    {
        children[0] = children[1] = nullptr;
        cnt = 0;
    }
    ~node()
    {
        for (int i = 0; i < ALPH; ++i)
        {
            delete children[i];
            children[i] = nullptr;
            cnt = 0;
        }
    }
};
struct trie
{
    node *root;
    trie() { root = new node(); }
    ~trie()
    {
        delete root;
        root = nullptr;
    }
    inline ll get_cnt(node *cur) { return cur == nullptr ? 0 : cur->cnt; }
    void insert(int x)
    {
        node *cur = root;
        for (int i = TRIEMAX; i >= 0; --i)
        {
            int j = (x >> i) & 1;
            if (cur->children[j] == nullptr)
                cur->children[j] = new node();
            cur = cur->children[j];
            cur->cnt += 1;
        }
    }
    ll query(int x, int k)
    {
        int xi, ki, j;
        ll ans = 0;
        node *cur = root;
        for (int i = TRIEMAX; i >= 0; --i)
        {
            if (cur == nullptr)
                break;
            xi = (x >> i) & 1;
            ki = (k >> i) & 1;
            if (xi == 0 and ki == 1)
            {
                ans += get_cnt(cur->children[0]);
                j = 1;
            }
            else if (xi == 1 and ki == 0)
            {
                j = 1;
            }
            else if (xi == 0 and ki == 0)
            {
                j = 0;
            }
            else
            {
                ans += get_cnt(cur->children[1]);
                j = 0;
            }
            cur = cur->children[j];
        }
        return ans;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, n, k, x, acc;
    ll ans;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        trie t;
        acc = ans = 0;
        t.insert(acc);
        while (n--)
        {
            cin >> x;
            acc ^= x;
            ans += t.query(acc, k);
            t.insert(acc);
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

