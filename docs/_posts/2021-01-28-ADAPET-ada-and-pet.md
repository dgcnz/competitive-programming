---
layout: post
mathjax: true
title: ADAPET - Ada And Pet
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
int const NMAX = 5e5 + 11;
int n, pi[NMAX];
char s[NMAX];
int prefix_function(string s)
{
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n - 1];
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int k;
        scanf("%s %d", s, &k);
        n = strlen(s);
        int x = prefix_function(s);
        printf("%lld\n", ll(k - 1) * ll(n - x) + n);
    }
    return 0;
}

{% endraw %}
```
</details>

