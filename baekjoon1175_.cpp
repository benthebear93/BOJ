#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m; // <=50
int dir_x[] = { 0, 0, 1,  -1};
int dir_y[] = { 1, -1, 0, 0 };
char map[50][50];
int ans = 0;
int start_x, start_y, c_x, c_y, d_x, d_y; //goal c1 = c , goal c2 = d
int goal_count = 0;
bool visited[50][50][5][2][2];  //mapx, map2, dir, c, d

struct DATA{
	int x;
	int y;
	int dir;
	bool c;
	bool d;
	int cnt;
};

void map_input() {
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
					c_x = i;
					c_y = j;
					goal_count =1;
				}
				else{
					map[i][j]='D';
					d_x = i;
					d_y = j;
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
	q.push({start_x,start_y,-1, 0, 0, 0}); // init position X,init position Y, dir, c, d, cnt
	visited[start_x][start_y][4][0][0] = true;
	cout << "start x , y :" << start_x <<"   "<< start_y<<endl;
	while(q.empty()==0){
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int c = q.front().c;
		int d = q.front().d;
		int cnt = q.front().cnt;
		q.pop();
		if(c == true && d == true){
			//visited all
			ans = cnt;
			return;
		}
		for(int i=0; i<4; i++){
			cout << " i :" << i << endl;
			//check all four direction
			if(i ==dir) continue; //but  only check different dir ~ before dir
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			int temp_c = c;
			int temp_d = d;
			
			if(nx >=0 && ny>=0&& nx<n && ny <m){
				if(visited[nx][ny][i][c][d] == false && map[nx][ny]!='#'){
					if(map[nx][ny]=='C') c = true;
					if(map[nx][ny]=='D') d = true;
					
					visited[nx][ny][i][temp_c][temp_d] = true;
					cnt= cnt+1;
					q.push({nx,ny,i,temp_c,temp_d,cnt});	
				}
			}
		}
	}
}
int main() {
	map_input();
	bfs();
	cout << ans << endl;
}
