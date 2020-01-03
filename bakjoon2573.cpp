#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int map[300][300];
int copymap[300][300];
int visited[300][300];

int dir_x[]= { 0, 0, 1, -1 };
int dir_y[] = { 1, -1, 0, 0 };


void bfs(int a, int b) {
   queue <pair <int, int> > q;
   q.push(make_pair(a,b));
   visited[a][b] = true;
   
   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int nx = x + dir_x[i];
         int ny = y + dir_y[i];
         if (nx >= 0 && ny >= 0 && nx < 300 && ny < 300) {
            if (map[nx][ny] > 0 && visited[nx][ny] == 0 ) { // ice? 
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
               }
            }
        }
    }
}

int melt(int x, int y){
	int cnt = 0;
	for(int i =0; i < 4; i++){
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if(map[nx][ny] == 0) cnt ++;
	}
	return cnt;
}

int main() {
   int year = 0;  
   cin >> n >> m;
   int temp = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> map[i][j];
      }
   }
   ////////////input ////////////////
   while(true){
   	  int l_cnt = 0;
   	  memset(visited, 0, sizeof(visited));
   	  memset(copymap, 0, sizeof(copymap));
   	  
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (map[i][j] > 0 && visited[i][j] == 0) {
               l_cnt++;
               bfs(i, j);
            }
         }
      } // section ?
      ekaks,
      if (l_cnt>=2) {
         cout  <<  year << endl;
         break;
      }
      if (l_cnt==0) {
         cout  <<  0 << endl;
         break;
      }
      // output
      
      for(int i =0; i<n; i++){
      	for(int j=0; j<m; j++){
      		if(map[i][j] > 0){
      			copymap[i][j] = map[i][j] -melt(i, j);
      			if(copymap[i][j] < 0){
      				copymap[i][j] = 0;
				  }
			  }
		  }
	  }
	  ///melt
	  
	   for (int i = 0; i < n; i++) {
	      for (int j = 0; j < m; j++) {
	         map[i][j] = copymap[i][j];
	      }
	   }
	  year++;
      
   }
}
