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

vi prefix_function(string s)
{
    int n = (int)s.size();
    vi  pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string str, pat;
        cin >> str >> pat;

        int  pat_sz = isz(pat);
        auto pi     = prefix_function(pat + "#" + str);
        vi   ans;

        for (int i = pat_sz + 1, len = isz(pi); i < len; ++i)
            if (pi[i] == pat_sz)
                ans.push_back(i + 1 - 2 * pat_sz);

        if (isz(ans) == 0)
            cout << "Not Found" << endl;
        else
            cout << isz(ans) << endl, write(all(ans), " "), cout << endl;
    }

    return 0;
}
