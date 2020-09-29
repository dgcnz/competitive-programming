#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

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

ll dist(ll u, ll v)
{
    ll lu = log2(u), lv = log2(v), ans = 0;

    if (lu < lv)
        swap(lu, lv), swap(u, v);

    // u is the deeper one

    while (lu > lv)
    {
        u /= 2;
        lu--, ans++;
    }

    // dbg(u, v);
    while (u != v)
    {
        lu--, lv--, ans += 2;
        u /= 2, v /= 2;
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll u, v;
        cin >> u >> v;
        cout << dist(u, v) << endl;
    }
    return 0;
}
