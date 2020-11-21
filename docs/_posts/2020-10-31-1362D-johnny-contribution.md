---
layout: post
title: 1362D Johnny Contribution
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 5e5 + 11;
int n, m, topic[NMAX];
vi g[NMAX], blogs;
vi solve(void)
{
    auto cmp = [](int x, int y) { return topic[x] < topic[y]; };
    sort(blogs.begin(), blogs.end(), cmp);
    for (auto b : blogs)
    {
        sort(g[b].begin(), g[b].end(), cmp);
        int nxt = 1;
        for (auto v : g[b])
            if (nxt == topic[v])
                ++nxt;
        if (topic[b] != nxt)
            return {-1};
    }
    return blogs;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> topic[i];
        blogs.push_back(i);
    }
    for (auto u : solve())
        cout << u << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
