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
        int n, T;
        cin >> n >> T;

        vi a(n), ans(n);
        read_n(a.begin(), n);

        int cnt = count_if(all(a), [T](int ai) { return 2 * ai == T; });
        cnt /= 2;

        for (int i = 0; i < n; ++i)
        {
            if (2 * a[i] < T)
                ans[i] = 0;
            else if (2 * a[i] == T and cnt)
            {
                ans[i] = 0;
                cnt--;
            }
            else
                ans[i] = 1;
        }

        write(all(ans), " "), cout << endl;
    }
    return 0;
}
