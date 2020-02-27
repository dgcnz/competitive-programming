#include <algorithm>
#include <iostream>

#define NMAX 110

using namespace std;

int n;
int a[NMAX];

int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }

int solve(void)
{
    sort(a, a + n);
    int ngcd = a[0];

    for (int i = 1; i < n; ++i)
    {
        ngcd = gcd(a[i], ngcd);
        if (ngcd == 1)
            break;
    }
    return ((a[n - 1] / ngcd) - n) % 2;
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << (solve() ? "Alice" : "Bob") << endl;

    return 0;
}
