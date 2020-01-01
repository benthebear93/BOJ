#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int n; //map
int map[100][100];
int visited[100][100];
int dir_x[] = {0, 0, -1, 1};
int dir_y[] = {-1, 1, 0, 0};
int section;
int max_v;
queue <pair<int, int> > q;
int area[10000];
priority_queue  < int > pq;
void bfs(int min_v){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++){
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if(nx > 0 && ny > 0 && nx < n && ny < n){
				if(map[nx][ny]> min_v && visited[nx][ny]==0){
					visited[nx][ny] = 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j =0; j < n; j++){
			cin >> map[i][j];
			max_v = max(max_v, map[i][j]);
		}
	}

	for(int k = 0; k < max_v; k++){
		for(int i = 0; i < n; i++){
			for(int j =0; j<n; j++){
				if(map[i][j] > k && visited[i][j] == 0){ // okay?
					visited[i][j] = 1;	
					q.push(make_pair(i,j)); //push area
					bfs(k);
					section++;
				}
			}
		}
		pq.push(section);
		memset(visited,0,sizeof(visited)); 	
		section = 0;
	}
	pq.push(1);		
	cout << pq.top() << endl;
}

