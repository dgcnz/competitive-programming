---
layout: post
mathjax: true
title: 1417C K Amazing Numbers
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n), ans(n, -1), last(n + 1, -1), sep(n + 1, 0);
        read_n(a.begin(), n);
        for (int i = 0; i < n; ++i)
        {
            sep[a[i]] = max(sep[a[i]], i - last[a[i]]);
            last[a[i]] = i;
        }
        for (int x = 1; x <= n; ++x)
            sep[x] = max(sep[x], n - last[x]);
        for (int x = 1; x <= n; ++x)
        {
            int first_k = sep[x];
            if (first_k == n + 1 or ans[first_k - 1] != -1)
                continue;
            ans[first_k - 1] = x;
        }
        int prv = -1;
        for (int i = 0; i < n; ++i)
        {
            if (prv != -1)
            {
                if (ans[i] == -1 or ans[i] > prv)
                    ans[i] = prv;
            }
            prv = ans[i];
        }
        write(ans.begin(), ans.end(), " "), cout << endl;
    }
    return 0;
}

{% endraw %}
```