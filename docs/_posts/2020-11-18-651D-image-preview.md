---
layout: post
mathjax: true
title: 651D Image Preview
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
using ii = pair<int, int>;
using vi = vector<ll>;
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
using predicate = function<bool(ll)>;
ll n, a, b, t;
string s;
vi rot;
ll bs(ll l, ll r, predicate p)
{
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    if (not p(l))
        return -1;
    return l;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> a >> b >> t;
    cin >> s;
    rot.resize(n);
    transform(begin(s), end(s), begin(rot), [](char c) { return b * (c == 'w'); });
    partial_sum(begin(rot), end(rot), begin(rot));
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll solo = rot[i] + a * i + (i + 1);
        if (solo > t)
            break;
        ans = max(ans, i + 1);
        if (i < n - 1)
        {
            ll right = solo + a * i;
            if (right > t)
                continue;
            auto left_cost = [](ll ix) -> ll {
                return a * (n - ix) + (n - ix) + rot[n - 1] - rot[ix - 1];
            };
            auto ok = [right, left_cost](ll ix) {
                return right + left_cost(ix) <= t;
            };
            ll j = bs(i + 1, n - 1, ok);
            if (j == -1)
                continue;
            ans = max(ans, i + 1 + (n - j));
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
