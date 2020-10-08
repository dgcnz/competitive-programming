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
        int n;
        cin >> n;
        vi abc[3], ans(n);
        for (int j = 0; j < 3; ++j)
        {
            abc[j].resize(n);
            read_n(begin(abc[j]), n);
        }

        ans[0] = abc[0][0];
        // greedy choice
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (abc[j][i] != ans[i - 1])
                {
                    ans[i] = abc[j][i];
                    break;
                }
            }
        }
        // fix last
        for (int j = 0; j < 3; ++j)
        {
            if (abc[j][n - 1] != ans[n - 2] and abc[j][n - 1] != ans[0])
            {
                ans[n - 1] = abc[j][n - 1];
                break;
            }
        }
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
