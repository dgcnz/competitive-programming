---
layout: post
mathjax: true
title: abc184_a - Determinant
problem_url: https://atcoder.jp/contests/abc184/tasks/abc184_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

$a \times d - b \times c$.


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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << a * d - b * c << endl;
    return 0;
}

{% endraw %}
```
</details>

