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
    int n, k;
    cin >> n >> k;
    vi p(n);
    read(all(p));

    vector<int> mark(256, -1);

    for (int i = 0; i < n; ++i)
    {
        int pi = p[i];
        if (mark[pi] != -1)
            continue;

        int l = max(0, pi - k + 1);
        while (mark[l] != -1 and mark[l] < l)
            ++l;
        while (pi >= l)
            mark[pi] = l, pi--;
    }
    for (int i = 0; i < n; ++i)
        cout << mark[p[i]] << " ";
    cout << endl;
    return 0;
}
