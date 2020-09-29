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

optional<ii> solve(vi a, int s)
{
    int     n = isz(a), best = 1e9;
    set<ii> ordered;
    ii      ans;

    for (int i = 0; i < n; ++i)
        ordered.emplace(a[i], i);

    for (int i = 0; i < n; ++i)
    {
        int x = s - a[i];
        if (auto it = ordered.upper_bound({x, i});
            it != ordered.end() and it->first == x)
        {
            if (it->second < best)
                best = it->second, ans = {it->first, a[i]};
        }
    }

    return best != 1e9 ? make_optional(ans) : nullopt;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int s, n;
        cin >> s >> n;
        if (n == 0)
        {
            cout << "!OK" << endl;
            continue;
        }

        vi a(n);
        read_n(a.begin(), n);

        if (auto ans = solve(a, s); ans)
        {
            if (ans->first > ans->second)
                swap(ans->first, ans->second);
            cout << ans->first << " " << ans->second << endl;
        }
        else
            cout << "!OK" << endl;
    }
    return 0;
}
