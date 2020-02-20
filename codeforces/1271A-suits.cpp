// STATUS: ACCEPTED
#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
  int a, b, c, d, e, f, ne, nf;

  cin >> a >> b >> c >> d >> e >> f;

  auto ex = [&]() {
    ne = min(a, d);
    d -= ne;
  };

  auto fx = [&]() {
    nf = min({b, c, d});
    d -= nf;
  };

  if (e >= f) {
    ex();
    fx();
  } else {
    fx();
    ex();
  }

  cout << e * ne + f * nf << endl;

  return 0;
}
