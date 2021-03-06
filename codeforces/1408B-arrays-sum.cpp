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
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vi a(n);
        read_n(a.begin(), n);

        int nu = distance(a.begin(), unique(all(a)));

        if (k == 1 and nu > 1)
            cout << -1 << endl;
        else
        {
            int ans = 0;
            do
            {
                nu -= min(k, nu);
                nu++; // 0 again
                ans++;
            } while (nu != 1);
            cout << ans << endl;
        }
    }
    return 0;
}
