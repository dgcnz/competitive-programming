#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int t, a, b, mod;
    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        mod = a % b;
        cout << (b - mod) % b << endl;
    }
}
