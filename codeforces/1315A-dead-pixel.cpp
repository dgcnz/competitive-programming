#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int t;

    cin >> t;

    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int ans = max({x * b, a * y, (a - x - 1) * b, a * (b - y - 1)});

        cout << ans << endl;
    }

    return 0;
}
