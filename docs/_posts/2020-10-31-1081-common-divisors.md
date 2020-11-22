---
layout: post
mathjax: true
title: 1081 Common Divisors
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
    int n;
    cin >> n;
    int const NMAX = 1e6;
    vi freq(NMAX + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    for (int i = NMAX; i > 0; --i)
    {
        ll cnt = 0;
        for (int j = i; j <= NMAX; j += i)
            cnt += freq[j];
        if (cnt >= 2)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

{% endraw %}
```