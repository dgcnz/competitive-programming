#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    ll t, x1, y1, x2, y2;
    cin >> t;

    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2 - x1) * (y2 - y1) + 1 << endl;
    }
    return 0;
}
