#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

char map[50][50];
int visited[50][50];
int dir_x[] = { 0,0,-1,1 };
int dir_y[] = { -1,1,0,0 };
int n, m;
int max_dist;
int dist[50][50];

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));
	visited[x][y] = 1;
	dist[x][y] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx_x = x + dir_x[i];
			int nx_y = y + dir_y[i];

			if (nx_x >= 0 && nx_x < n && nx_y >= 0 && nx_y < m) {

				if(map[nx_x][nx_y]=='L'&& !visited[nx_x][nx_y]){
					q.push(make_pair(nx_x, nx_y));
					visited[nx_x][nx_y] = true;
					dist[nx_x][nx_y] = dist[x][y] + 1;
					max_dist = max(max_dist, dist[nx_x][nx_y]);
				}
			}
		}
	}
	return max_dist;
}

int main() {
	int ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				memset(dist, 0, sizeof(dist));
				memset(visited, false, sizeof(visited));
				ans = bfs(i, j);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
