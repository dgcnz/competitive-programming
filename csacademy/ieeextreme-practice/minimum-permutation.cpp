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

    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    read_n(a.begin(), n);
    read_n(b.begin(), m);

    sort(all(b));

    auto it = b.begin();
    for (auto ai : a)
    {
        while (it != b.end() and *it < ai)
        {
            cout << *it << " ";
            ++it;
        }
        cout << ai << " ";
    }

    while (it != b.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    return 0;
}
