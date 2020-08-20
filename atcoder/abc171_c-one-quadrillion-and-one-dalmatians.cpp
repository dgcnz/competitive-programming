#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    ll     n;
    char   c;
    string s;
    cin >> n;

    while (n > 0)
    {
        n -= 1;
        c = 'a' + (n % 26LL);
        s = c + s;
        n /= 26LL;
    };

    cout << s << endl;

    return 0;
}
