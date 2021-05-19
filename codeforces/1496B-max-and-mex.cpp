#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
T mex(InputIt first, InputIt last, T start = 0)
{
    for (auto it = first; it != last; ++it, ++start)
        if (*it != start)
            break;
    return start;
}

int solve(vi a, int k)
{
    sort(all(a));
    int x = mex(all(a)), n = a.size();
    if (x == n)
        return n + k;

    int y = (a.back() + x + 1) / 2;
    if (k and find(all(a), y) == a.end())
        return n + 1;
    else
        return n;
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
        read(all(a));
        cout << solve(a, k) << endl;
    }
    return 0;
}
