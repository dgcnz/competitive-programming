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

    int n;
    cin >> n;
    vector<pair<int, string>> name_height(n);
    for (auto &[height, name] : name_height)
        cin >> name >> height;

    sort(all(name_height));

    int l = 1, r = 1, cur_height = name_height.front().first;

    for (auto [height, name] : name_height)
    {
        if (height != cur_height)
        {
            cout << l << " " << r - 1 << endl;
            l          = r;
            cur_height = height;
        }
        cout << name << " ";
        ++r;
    }
    cout << l << " " << r - 1 << endl;

    return 0;
}
