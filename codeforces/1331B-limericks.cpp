#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s;
    int    n;
    cin >> s;

    n = s.size();

    cout << (s[n - 1] % 2 == 1) << endl;
    return 0;
}
