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
int const NMAX = 2e5 + 11;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n), freq(NMAX, 0);
    read_n(a.begin(), n);

    for (auto ai : a)
        freq[ai]++;
    set<int> uniq(all(a));

    ll ans = 0;
    for (auto x : uniq)
        ans += (ll(freq[x]) * (ll(freq[x]) - 1)) / 2;

    for (auto kai : a)
        cout << ans - freq[kai] + 1 << endl;

    return 0;
}
