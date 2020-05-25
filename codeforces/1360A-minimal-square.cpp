#include <cmath>
#include <iostream>

using namespace std;

int main(void)
{
    int t, a, b, ans;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);

        // a < b
        // test 2a > b
        if (2 * a > b)
            ans = 2 * a * 2 * a;
        else
            ans = b * b;
        cout << ans << endl;
    }

    return 0;
}
