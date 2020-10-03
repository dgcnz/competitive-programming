#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(x) x
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

int const NMAX = 1e5 + 11;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi f0(NMAX, 0), f1(NMAX, 0), f2(NMAX, 0);

    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        if (i % 2 == 0)
            ++f0[ai];
        else
            ++f1[ai];
        ++f2[ai];
    }

    sort(all(f0), greater<int>());
    sort(all(f1), greater<int>());
    sort(all(f2), greater<int>());
    dbg(f0);

    if (f2[0] == f0[0] + f1[0])
        cout << n - max(f0[0] + f1[1], f0[1] + f1[0]) << endl;
    else
        cout << n - f0[0] - f1[0] << endl;

    return 0;
}
