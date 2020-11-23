---
layout: post
mathjax: true
title: Abc149_D Prediction And Reststriction
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
using vi = vector<int>;
int const M = 3;
map<char, int> const id = {{'r', 0}, {'s', 1}, {'p', 2}};
int arg_max(vector<int> v)
{
    return distance(v.begin(), max_element(v.begin(), v.end()));
}
vector<vi> transpose(const vector<vi> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vi> ans(m, vi(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans[j][i] = mat[i][j];
    return ans;
}
int solve(int n, int k, vector<vi> reward, vi t)
{
    int ans = 0, last;
    vector<vi> reward_T = transpose(reward);
    for (int res = 0; res < k; ++res)
    {
        last = -1;
        for (int i = res; i < n; i += k)
        {
            if (t[i] == last)
            {
                if (i + k < n)
                {
                    for (int j = 0; j < M; ++j)
                        if (j != t[i] and j != t[i + k])
                            last = j;
                }
            }
            else
            {
                last = t[i];
                ans += reward[arg_max(reward_T[t[i]])][t[i]];
            }
        }
    }
    return ans;
}
int main(void)
{
    int n, k;
    string t;
    vi tp;
    vector<vi> reward(M, vi(M, 0));
    cin >> n >> k;
    cin >> reward[0][1] >> reward[1][2] >> reward[2][0];
    cin >> t;
    tp.resize(n);
    for (int i = 0; i < n; ++i)
        tp[i] = id.at(t[i]);
    cout << solve(n, k, reward, tp) << endl;
    return 0;
}

{% endraw %}
```
</details>

