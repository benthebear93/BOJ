#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 50
int n, m; //maze size
int map[MAX][MAX];
int copymap[MAX][MAX];
int visited[MAX][MAX];

int dir_x[]= { 0, 0, 1, -1 };
int dir_y[] = { 1, -1, 0, 0 };


void bfs(int a, int b) {
   queue <pair<pair<int, int>,pair<int,int>>> q;
   q.push(make_pair(make_pair(a,b), make_pair(0,0)));
   visited[a][b][0] = true;
   
   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      int cnt = q.front().second.first;
      int key = q.front().second.second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nx = x + dir_x[i];
         int ny = y + dir_y[i];
         if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (visited[nx][ny][key] == 0 ) { 
                if(map[nx][ny] == '.' || map[nx][ny] == '1'){
                    visited[nx][ny][key] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, key)));
                }
                else if('a'<= map[nx][ny] && map[nx][ny] <='f'){
                    int temp_key = key | (1 << (int(map[nx][ny]='a')));
                    visited[nx][ny][temp_key] = true; //got key 
                    q.push(make_pair(make_pair(nx,ny),make_pair(cnt+1, temp_key)));
                }
                else if()
               }
            }
        }
    }
}

int main() {
   int year = 0;  
   cin >> n >> m;
   int temp = 0;
   start_x , start_y = 0
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> map[i][j];
         if (map[i][j] =='0'){
             start_x = i;
             start_y = j;
         }
      }
   }
   ////////////input ////////////////
}
