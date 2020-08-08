#include <bits/stdc++.h>

using namespace std;

inline bool in_range(int x) { return 1 <= x and x <= 9; }

int main(void)
{
    int a, b;
    cin >> a >> b;

    if (in_range(a) and in_range(b))
    {
        cout << a * b << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
