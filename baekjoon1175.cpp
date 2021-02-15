#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m; //<=50
int dir_x[] = { -1, 0, 1, 0 };
int dir_y[] = { -1, 0, 1, 0 };
char map[50][50];
int ans = 0;

void input() {
	cout << "put things" <<endl;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
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
int main() {
	input();
	show();
	cout << ans << endl;
}
