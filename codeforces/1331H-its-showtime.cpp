#include <iostream>

using namespace std;

int main(void)
{
    int input, n, mod, lower, ans = 1;

    cin >> input;

    mod   = input % 1000;
    n     = (input - mod) / 1000;
    lower = (input % 2 == 0 ? 2 : 1);

    cout << n << endl << mod << endl;

    for (int i = n; i >= lower; i -= 2)
        ans = (ans * i) % mod;

    cout << lower << endl;
    cout << ans << endl;
    cout << ans % mod << endl;

    return 0;
}
