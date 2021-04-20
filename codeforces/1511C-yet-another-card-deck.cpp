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

    vector<int> first(50, 1e8);
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai, ai--;
        first[ai] = min(i, first[ai]);
    }

    while (q--)
    {
        int c;
        cin >> c, c--;

        int i = first[c];
        cout << i + 1 << " ";
        for (auto &j : first)
            if (j < i)
                j++;
        first[c] = 0;
    }
    cout << endl;
    return 0;
}
