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

int main(void)
{
    int n;
    cin >> n;

    vi a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    sort(all(b), greater<int>());

    int l = 0, r = n - 1;

    for (int i = 0; i < n; ++i)
    {
        if (b[i] == a[i])
        {
            if (a[l] != b[i])
            {
                swap(b[l], b[i]);
                ++l;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == a[i])
        {
            if (a[r] != b[i])
            {
                swap(b[r], b[i]);
                --r;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == a[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
