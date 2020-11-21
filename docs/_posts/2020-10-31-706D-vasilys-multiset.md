---
layout: post
mathjax: true
title: 706D Vasilys Multiset
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
const int CMAX = 2;
const int TMAX = 30;
struct node
{
    int cnt;
    node *children[CMAX];
    ~node()
    {
        cnt = 0;
        for (node *child : children)
            delete child;
    }
};
struct trie
{
    node *root;
    trie() { root = new node(); }
    void insert(int x)
    {
        node *cur = root;
        for (int i = TMAX; i >= 0; --i)
        {
            int j = (x >> i) & 1;
            if (cur->children[j] == nullptr)
                cur->children[j] = new node();
            cur = cur->children[j];
            cur->cnt += 1;
        }
    }
    void remove(int x)
    {
        node *cur = root;
        node *past;
        for (int i = TMAX; i >= 0; --i)
        {
            int j = (x >> i) & 1;
            past = cur;
            cur = cur->children[j];
            cur->cnt -= 1;
            if (cur->cnt == 0)
            {
                past->children[j] = nullptr;
                delete cur;
                return;
            }
        }
    }
    int query(int x)
    {
        int xi, yi, ans = 0;
        node *cur = root;
        for (int i = TMAX; i >= 0; --i)
        {
            xi = (x >> i) & 1;
            yi = 1 - xi;
            if (cur->children[yi] == nullptr)
                yi = xi;
            cur = cur->children[yi];
            ans ^= (xi ^ yi) << i;
        }
        return ans;
    }
};
int main(void)
{
    int q, x;
    char type;
    cin >> q;
    trie t;
    t.insert(0);
    while (q--)
    {
        cin >> type >> x;
        if (type == '+')
            t.insert(x);
        else if (type == '-')
            t.remove(x);
        else
            cout << t.query(x) << endl;
    }
    return 0;
}

{% endraw %}
```
