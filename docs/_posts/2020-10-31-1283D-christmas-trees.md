---
layout: post
title: 1283D Christmas Trees
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using vi = vector<int>;
pair<ll, vi> msbfs(vi const &sources, int limit)
{
    vector<pair<int, int>> order;
    set<int> visited;
    queue<pair<int, int>> frontier;
    for (auto source : sources)
    {
        frontier.push({source, 0});
        visited.insert(source);
    }
    while ((int)order.size() < limit and not frontier.empty())
    {
        auto [i, dist] = frontier.front();
        frontier.pop();
        for (auto j : {i - 1, i + 1})
        {
            if (visited.find(j) == visited.end())
            {
                order.emplace_back(dist + 1, j);
                frontier.push({j, dist + 1});
                visited.insert(j);
                if ((int)order.size() == limit)
                    break;
            }
        }
    }
    ll ans = 0;
    vi x;
    for (auto [dist, i] : order)
    {
        ans += dist;
        x.push_back(i);
    }
    return {ans, x};
}
int main(void)
{
    int n, m;
    vi sources;
    cin >> n >> m;
    sources.resize(n);
    for (auto &source : sources)
        cin >> source;
    auto [ans, x] = msbfs(sources, m);
    cout << ans << endl;
    for_each(x.begin(), x.end(), [](int const &xi) { cout << xi << " "; }),
        cout << endl;
    return 0;
}

{% endraw %}
```
