---
layout: post
mathjax: true
title: abc157_e - Simple String Queries
problem_url: https://atcoder.jp/contests/abc157/tasks/abc157_e
tags: segment_tree, data_structures
memory_complexity: O(n)
time_complexity: O(q \log{n})
---

Build a segment tree where nodes store a frequency array of the characters in
their respective range.


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
struct Node
{
    array<int, 26> cnt;
    Node() { fill(begin(cnt), end(cnt), 0); }
    Node(int i) : Node() { cnt[i]++; }
};
Node op(Node a, Node b)
{
    Node ans;
    for (int i = 0; i < 26; ++i)
        ans.cnt[i] = a.cnt[i] + b.cnt[i];
    return ans;
}
Node e() { return Node(); }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n;
    vector<Node> a(n);
    for (auto &x : a)
    {
        char ch;
        cin >> ch;
        x.cnt[ch - 'a']++;
    }
    atcoder::segtree<Node, op, e> st(a);
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            char ch;
            cin >> i >> ch, i--;
            st.set(i, Node(ch - 'a'));
        }
        else
        {
            int l, r;
            cin >> l >> r, l--;
            auto freq = st.prod(l, r).cnt;
            cout << count_if(begin(freq), end(freq), [](int x) { return x != 0; }) << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

