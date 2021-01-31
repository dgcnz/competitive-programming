---
layout: post
mathjax: true
title: 1408A - Circle Coloring
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
using ii = pair<int, int>;
using vi = vector<int>;
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
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
        vi abc[3], ans(n);
        for (int j = 0; j < 3; ++j)
        {
            abc[j].resize(n);
            read_n(begin(abc[j]), n);
        }
        ans[0] = abc[0][0];
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (abc[j][i] != ans[i - 1])
                {
                    ans[i] = abc[j][i];
                    break;
                }
            }
        }
        for (int j = 0; j < 3; ++j)
        {
            if (abc[j][n - 1] != ans[n - 2] and abc[j][n - 1] != ans[0])
            {
                ans[n - 1] = abc[j][n - 1];
                break;
            }
        }
        write(ans.begin(), ans.end(), " "), cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

