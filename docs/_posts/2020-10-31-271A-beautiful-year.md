---
layout: post
mathjax: true
title: 271A Beautiful Year
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int digit_at(int number, int pos) {
  return number / (1000 / (int)pow(10, pos)) % 10;
}
bool is_valid(int y1, int y2) {
  set<int> digits;
  for (int i = 0; i < 4; ++i) {
    int n = digit_at(y2, i);
    if (digits.find(n) != digits.end())
      return false;
    digits.insert(n);
  }
  return true;
}
int get_next(int year) {
  int y = year;
  while (not is_valid(year, ++y))
    ;
  return y;
}
int main(void) {
  int year;
  cin >> year;
  cout << get_next(year) << endl;
  return 0;
}

{% endraw %}
```
