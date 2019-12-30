#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int t_case[100][100][100];
int visited[100][100][100];
int m, n, h;
int dist[100][100][100];
int day = 0;
int dir_x[] = { 0, 0, 1, -1 , 0 , 0}; // up, down, right, left, case up, case donw
int dir_y[] = { 1, -1, 0, 0, 0, 0 };
int dir_z[] = { 0, 0, 0, 0, 1, -1 };
queue <pair<pair<int, int>, int> > q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			int nz = z + dir_z[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx <m && ny <n && nz <h) {
				if (visited[nx][ny][nz] == 0&&t_case[nx][ny][nz]!=-1) {
					visited[nx][ny][nz] = 1;
					q.push(make_pair(make_pair(nx, ny), nz));
					dist[nx][ny][nz] = dist[x][y][z] + 1;
					day = max(day, dist[nx][ny][nz]);
				}
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				cin >> t_case[i][j][k];
				if (t_case[i][j][k] == 1) {
					q.push(make_pair(make_pair(i, j), k));
					visited[i][j][k] = true;
				}
			}
		}
	}
	bfs();

	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				if (visited[i][j][k]==0 && t_case[i][j][k]== 0) {
					day = -1;
				}
			}
		}
	}
	cout << day;
	return 0;
}
