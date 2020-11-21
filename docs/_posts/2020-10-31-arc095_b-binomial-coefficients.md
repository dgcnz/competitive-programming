---
layout: post
mathjax: true
title: Arc095_B Binomial Coefficients
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

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
    vi a(n);
    read_n(a.begin(), n);
    sort(a.begin(), a.end());
    int ai = a.back();
    int aj = *max_element(a.begin(), prev(a.end()), [ai](int x, int y) {
        return min(x, ai - x) < min(y, ai - y);
    });
    cout << ai << " " << aj << endl;
    return 0;
}

{% endraw %}
```
