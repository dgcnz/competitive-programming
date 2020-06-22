#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, m, k, ix, ans;
    cin >> n >> m >> k;

    vi a(n), b(m);
    for (auto &ai : a)
        cin >> ai;

    for (auto &bi : b)
        cin >> bi;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ix = 0, ans = 0;
    for (auto bi : b)
    {
        while (ix < n and a[ix] < bi - k)
            ++ix;
        if (bi - k <= a[ix] and a[ix] <= bi + k)
            ++ix, ++ans;
        if (ix >= n)
            break;
    }

    cout << ans << endl;

    return 0;
}
