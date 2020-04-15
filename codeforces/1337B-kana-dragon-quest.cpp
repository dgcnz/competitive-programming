#include <iostream>

using namespace std;

inline void void_absorption(int &x) { x = x / 2 + 10; }

inline void lightning_strike(int &x) { x = x - 10; }

bool solve(int x, int n, int m)
{
    while (n-- > 0 and x > 20)
        void_absorption(x);

    while (m-- > 0 and x > 0)
        lightning_strike(x);

    return x <= 0;
}

int main(void)
{
    int t, x, n, m;

    cin >> t;

    while (t--)
    {
        cin >> x >> n >> m;
        cout << (solve(x, n, m) ? "YES" : "NO") << endl;
    }

    return 0;
}
