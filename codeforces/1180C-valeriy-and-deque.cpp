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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi a(n);
    read(all(a));

    vi rmax(n);

    auto op = [](int a, int b) { return max(a, b); };
    partial_sum(all(a), rmax.begin(), op);

    int mix = distance(a.begin(), max_element(all(a)));

    vector<int> tail;
    for (int i = mix + 1; i < n; ++i)
        tail.push_back(a[i]);

    int cur_max = a.front();
    for (int i = 1; i <= mix; ++i)
    {
        tail.push_back(min(a[i], cur_max));
        cur_max = max(a[i], cur_max);
    }

    while (q--)
    {
        ll m;
        cin >> m;
        if (m <= mix)
            cout << rmax[m - 1] << " " << a[m] << endl;
        else
            cout << rmax.back() << " " << tail[(m - mix - 1) % (n - 1)] << endl;
    }
    return 0;
}
