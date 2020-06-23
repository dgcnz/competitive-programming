#include <bits/stdc++.h>

using namespace std;

int solve(int k, int r)
{
    int rem;
    for (int i = 1; i < 10; ++i)
    {
        rem = (i * k) % 10;
        if (rem == 0 or rem == r)
            return i;
    }
    return 10;
}

int main(void)
{
    int k, r;
    cin >> k >> r;

    cout << solve(k, r) << endl;
    return 0;
}
