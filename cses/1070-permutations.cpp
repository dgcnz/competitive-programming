#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    if (n > 1 and n <= 3)
        cout << "NO SOLUTION" << endl;
    else
    {
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
        for (int i = 1; i <= n; i += 2)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
