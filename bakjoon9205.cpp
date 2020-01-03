#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int num_market;
int test_case;
int h_x, h_y;
vector <pair <int, int> > market;
int end_x, end_y;
int arrive;
int num_test[50];  //test case 50
int market_visited[100]; //market num 100
void bfs() {
   queue <pair<int, int> > q;
   q.push(make_pair(h_x, h_y)); //home_x, home_y
   while (!q.empty()) {
      int nx = q.front().first;
      int ny = q.front().second;
      q.pop();
      for (int n_mar = 0; n_mar < num_market; n_mar++) {
         int mark_x = market[n_mar].first;
         int mark_y = market[n_mar].second;

         if (abs(nx - market[n_mar].first) + abs(ny - market[n_mar].second) <= 1000 && market_visited[n_mar]== 0) {
            q.push(make_pair(mark_x, mark_y));
            market_visited[n_mar] = 1;
            //cout << "which market : " << n_mar << " market_visited : "<<  market_visited[n_mar]  << endl;
         }
         else if (abs(nx - end_x) + abs(ny - end_y) <= 1000) {
            arrive = 2;
         }
      }
      if (num_market == 0 && abs(nx - end_x) + abs(ny - end_y) <= 1000) {
         arrive = 2;
      }
      if (num_market == 0 && abs(nx - end_x) + abs(ny - end_y) > 1000) {
         arrive = 1;
      }
   }

}

int main() {
   cin >> test_case;
   for (int i = 0; i < test_case; i++) {

      cin >> num_market;
      cin >> h_x >> h_y;
      for (int j = 0; j < num_market; j++) {
         int x, y;
         cin >> x >> y;
         market.push_back(make_pair(x, y));
         //cout << j << " : " << market[j].first << " , " << market[j].second << endl;
      }
      cin >> end_x >> end_y;
      bfs(); 
      //cout << "arrived : " << arrive << endl;
      num_test[i] = arrive;
      //cout << i << " : " << num_test[i]<< endl;
      arrive = 0;
      market.clear();
      memset(market_visited, 0, sizeof(market_visited));
   }
   for (int i = 0; i < test_case; i++) {
      //cout << " test case" << test_case << endl;
      if (num_test[i] == 2) {
         cout << "happy " << endl;
      }
      if (num_test[i] == 0|| num_test[i]==1) {
         cout << "sad" << endl;
      }
   }

}
