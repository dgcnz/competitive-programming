#include <algorithm>
#include <iostream>

using namespace std;

bool solve(int a, int b)
{
    if (a < b)
        swap(a, b);

    int diff = a - b;

    if (b < diff)
        return false;

    a -= 2 * diff;
    b -= diff;

    return (a % 3 == 0);
}

int main(void)
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << (solve(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
