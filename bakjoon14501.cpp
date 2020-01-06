#include <iostream>
#include <queue>

using namespace std;
int t[16], p[16], n, result;
int a;
void solver(int day, int money) {
   if (day == n + 1) {  // end of the working day (condition 1)
      result = max(result, money);
      return;
   }
   else if (day > n + 1) { // end of the working day 2 (condition 2)
      return;
   }
   solver(day + t[day], money + p[day]);
   solver(day + 1, money);
}

int main() {
   cin >> n;
   for (int i = 1; i <=n; i++) {
      cin >> t[i] >> p[i];
   }
   solver(1, 0);
   cout << result;
   return 0;
}
