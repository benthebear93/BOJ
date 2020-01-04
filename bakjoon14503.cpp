#include <iostream>
#include <vector>
#include <queue>

using namespace std;




int n, m, d ; // 3=~=50, 0~3 n, e, s, w
int dir_x[] = {-1, 0, 1, 0};
int dir_y[] = {0, 1, 0, -1};
int cleaned[50][50];
int map[50][50];
int r, c;
int ans;
int blocked;
int change_dir(int i){
	if(i==0) return 3;
	else if(i==1) return 0;
	else if(i==2) return 1;
	else return 2;
}
int back(int i){
	if(i==0) return 2;
	else if(i==1) return 3;
	else if(i==2) return 0;
	else return 1;	
}

void bfs(int a, int b){
	cleaned[a][b] = 1; //clean current position
	ans++;
	queue <pair <int, int> > q;
	q.push(make_pair(a, b));
	while(!q.empty()){
		blocked =0;
		int rx = q.front().first;
		int ry = q.front().second;
		q.pop();
		int nd = d;
		for(int i = 0; i < 4; i ++){
			nd = change_dir(nd);
			int nrx = rx + dir_x[nd];
			int nry = ry + dir_y[nd];
			
			if(nrx >= 0 && nry >= 0 && nrx < 50 && nry < 50){
				if(cleaned[nrx][nry] == 0 && map[nrx][nry] != 1){
					//cout << " d : "<< nd << endl;
					q.push(make_pair(nrx, nry));
					cleaned[nrx][nry] = 1;
					d = nd;
					ans ++;
					break;
				}
				if(cleaned[nrx][nry]==1 || map[nrx][nry]==1){
					//cout << blocked << "bl "<< endl;
					blocked++;
				}
			}
			if(blocked==4){
				int back_d = back(d);
				nrx = rx + dir_x[back_d];
				nry = ry + dir_y[back_d];
				if(nrx >= 0 && nry >= 0 && nrx < 50 && nry < 50){
					if(map[nrx][nry]!=1){
						//cout << " back back back " << endl;
						q.push(make_pair(nrx, nry));
					}
					else{
						//cout <<"can't move stop" << endl;
						return;
					}	
				}
			}
		}
	}
}

void input(){
	cin >> n >> m;
	cin >> r >> c >> d;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
/*	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/		
}
/*void check(){
	int a = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << cleaned[i][j] << " ";
			if(map[i][j] ==0){
				a++;
			}
		}
		cout << endl;
	}	
	//cout << "o is : " << a <<endl;
}*/

int main(){
	input();
	bfs(r,c);
	cout << ans << endl;
	//check();

}
