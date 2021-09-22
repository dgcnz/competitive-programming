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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ii>   chords;
        vector<bool> used(2 * n);
        for (int i = 0; i < k; ++i)
        {
            int x, y;
            cin >> x >> y, x--, y--;
            if (x > y)
                swap(x, y);

            chords.emplace_back(x, y);
            used[x] = used[y] = true;
        }

        vector<int> unused;
        for (int i = 0; i < 2 * n; ++i)
            if (not used[i])
                unused.push_back(i);

        for (int i = 0; i < n - k; ++i)
            chords.emplace_back(unused[i], unused[i + n - k]);

        auto intersect = [&](ii a, ii b)
        {
            if (a.first > b.first)
                swap(a, b);
            return a.second > b.first and a.second < b.second;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ans += intersect(chords[i], chords[j]);

        cout << ans << endl;
    }
    return 0;
}
