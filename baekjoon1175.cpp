#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; //<=50
int dir_x[] = { 0, 0, 1,  -1};
int dir_y[] = { 1, -1, 0, 0 };
char map[50][50];
int ans = 0;
int start_x, start_y;
int gc_x, gc_y,gd_x, gd_y;
int goal_count = 0;
bool visited[50][50][4][2][2];

struct DATA{
	int x;
	int y;
	int dir;
	bool c;
	bool d;
	int cnt;
};
void input() {
	cout << "put things" <<endl;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j] =='S'){
				start_x = i;
				start_y = j;
				map[i][j] ='.';
			}
			else if(map[i][j]=='C'){
				if(goal_count == 0){
					gc_x = i;
					gc_y = j;
				}
				else{
					map[i][j]='D';
					gd_x = i;
					gd_y = j;
				}
			}
		}
	}
}
void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void bfs(){
	queue <DATA> q;
	q.push({start_x, start_y, -1, 0, 0, 0});
	visited[start_x][start_x][4][0][0] = true;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int c_check = q.front().c;
		int d_check = q.front().d;
		int cnt = q.front().cnt;
		q.pop();
		if(c_check == true && d_check == true){ //if they already visted 
			ans = cnt;
			return;
		}
		for(int i=0; i<4; i++){ //check near direction
			if(i == dir) continue;
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			bool tmp_c_check = c_check;
			bool tmp_d_check = d_check;
			if(nx >= 0 && ny>=0&&nx<n && ny<m){
				if(visited[nx][ny][i][c_check][d_check]==false &&map[nx][ny]!='#'){
					if(map[nx][ny]=='C') c_check =true;
					if(map[nx][ny]=='D') d_check =true;
					visited[nx][ny][i][tmp_c_check][tmp_d_check]=true;
					cnt=+1;
					q.push({nx, ny, i, tmp_c_check, tmp_d_check, cnt});
				}
			}
		}
	}
	
}
int main() {
	input();
	bfs();
	cout << ans << endl;
}
