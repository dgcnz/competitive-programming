---
layout: post
mathjax: true
title: 1462A - Favorite Sequence
problem_url: https://codeforces.com/contest/1462/problem/A
tags: easy, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Reverse the operation.


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
        vi a(n), ans(n);
        read_n(begin(a), n);
        int i = 0, l = 0, r = n - 1;
        while (l < r)
        {
            ans[i++] = a[l++];
            ans[i++] = a[r--];
        }
        if (l == r)
            ans[i] = a[l];
        write(begin(ans), end(ans), " "), cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

