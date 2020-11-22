---
layout: post
mathjax: true
title: 1398D Colored Rectangles
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
using ms = multiset<int, greater<int>>;
using vi = vector<int>;
int const NMAX = 200 + 11;
int dp[NMAX][NMAX][NMAX], nrgb[3];
vi rgb[3];
int solve(void)
{
    auto [r, g, b] = rgb;
    auto [nr, ng, nb] = nrgb;
    for (int ir = 0; ir <= nr; ++ir)
    {
        for (int ig = 0; ig <= ng; ++ig)
        {
            for (int ib = 0; ib <= nb; ++ib)
            {
                int &ans = dp[ir][ig][ib];
                if (ig > 0 and ib > 0)
                    ans = dp[ir][ig - 1][ib - 1] + g[ig] * b[ib];
                if (ir > 0 and ig > 0)
                    ans = max(ans, dp[ir - 1][ig - 1][ib] + r[ir] * g[ig]);
                if (ir > 0 and ib > 0)
                    ans = max(ans, dp[ir - 1][ig][ib - 1] + r[ir] * b[ib]);
            }
        }
    }
    return dp[nr][ng][nb];
}
int main(void)
{
    cin >> nrgb[0] >> nrgb[1] >> nrgb[2];
    for (int i = 0; i < 3; ++i)
    {
        rgb[i].resize(nrgb[i] + 1);
        for (int j = 1; j <= nrgb[i]; ++j)
            cin >> rgb[i][j];
        sort(next(rgb[i].begin()), rgb[i].end());
    }
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```