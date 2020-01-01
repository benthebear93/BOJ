#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int n; // map size
int map[100][100];
int visited[100][100];
int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};
int section;
int max_v;
queue <pair <int, int> > q;
priority_queue <int> p_q;

void bfs(int a, int b, int k){
	q.push(make_pair(a,b));
	visited[a][b] = 1;
	int chk = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4 ; i++){
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if(nx >= 0 && ny >= 0 && nx < n && ny < n){
				if(visited[nx][ny] ==0 && map[nx][ny] > k){
					q.push(make_pair(nx, ny));
					visited[nx][ny] = 1;	
				}
			}
		}
	}
}




int main(){
	cin >> n ;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			max_v = max(map[i][j], max_v);
		}
	} // map update
	
	for(int k = 0; k < max_v; k++){ // max rain
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(map[i][j] > k && visited[i][j] == 0){
					bfs(i, j, k);
					section++;
				}
			}
		} // map update
		p_q.push(section);
		memset(visited, 0, sizeof(visited));
		section = 0;
	}	
	cout << p_q.top();
	
}




//int n; //map
//int map[100][100];
//int visited[100][100];
//int dir_x[] = {0, 0, -1, 1};
//int dir_y[] = {-1, 1, 0, 0};
//int section;
//int max_v;
//queue <pair<int, int> > q;
//priority_queue  < int > pq;
//
//void bfs(int a, int b, int min_v){
//	q.push(make_pair(a,b)); //push area
//	visited[a][b]==1;
//	while(!q.empty()){
//		int x = q.front().first;
//		int y = q.front().second;
//		q.pop();
//		for(int i = 0; i<4; i++){
//			int nx = x + dir_x[i];
//			int ny = y + dir_y[i];
//			if(nx > 0 && ny > 0 && nx < n && ny < n){
//				if(map[nx][ny]> min_v && visited[nx][ny]==0){
//					visited[nx][ny] = 1;
//					q.push(make_pair(nx,ny));
//				}
//			}
//		}
//	}
//}
//
//int main(){
//	cin >> n;
//	for(int i = 0; i < n; i++){
//		for(int j =0; j < n; j++){
//			cin >> map[i][j];
//			max_v = max(max_v, map[i][j]);
//		}
//	}
//	for(int k = 0; k < max_v; k++){
//		for(int i = 0; i < n; i++){
//			for(int j =0; j<n; j++){
//				if(map[i][j] > k && visited[i][j] == 0){ // okay?
//					bfs(i, j, k);
//					section++;
//					cout << " sectio : " << section << endl;
//				}
//			}
//		}
//		pq.push(section);
//		memset(visited,0,sizeof(visited)); 	
//		section = 0;
//	}
//	pq.push(1);		
//	cout << pq.top() << endl;
//}

