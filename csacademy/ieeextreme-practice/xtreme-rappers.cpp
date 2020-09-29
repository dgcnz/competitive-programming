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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll k, j;
    cin >> k >> j;

    // Let's say that k is the bigger of the two.
    // If k == 2 * j, then I can match 1 ji to every 2 ki
    // If k < 2 * j, then I might match at most (k + j) / 3
    // If k > 2 * j, then I might match at most j
    cout << min(min(k, j), (k + j) / 3) << endl;
    return 0;
}
