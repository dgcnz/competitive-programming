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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vi a(n), ans(n, -1), last(n + 1, -1), sep(n + 1, 0);
        read_n(a.begin(), n);

        for (int i = 0; i < n; ++i)
        {
            sep[a[i]]  = max(sep[a[i]], i - last[a[i]]);
            last[a[i]] = i;
        }

        for (int x = 1; x <= n; ++x)
            sep[x] = max(sep[x], n - last[x]);

        for (int x = 1; x <= n; ++x)
        {
            int first_k = sep[x];
            if (first_k == n + 1 or ans[first_k - 1] != -1)
                continue;
            ans[first_k - 1] = x;
        }

        int prv = -1;
        for (int i = 0; i < n; ++i)
        {
            if (prv != -1)
            {
                if (ans[i] == -1 or ans[i] > prv)
                    ans[i] = prv;
            }

            prv = ans[i];
        }

        write(all(ans), " "), cout << endl;
    }
    return 0;
}
