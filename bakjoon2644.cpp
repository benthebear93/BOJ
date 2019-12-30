#include <iostream>
#include <vector>
using namespace std;

int visited[101];
int n, m, p1, p2;
int p_c; //parent_child
vector <int> node[101];
int x, y;
int result ;
int conshu = -1;

void dfs(int start) {
	visited[start] = true;
	if (start == p2) { conshu = result;}
	for (int i = 0; i < node[start].size(); i++) {
		int y = node[start][i];
		//cout << y << endl;
			//cout << "here" << endl}
		if (!visited[y]){
			result++;
			dfs(y);
		}
	}
	return ;
}

int main() {
	int x = 0;
	int y = 0;
	cin >> n; //9
	cin >> p1 >> p2; // 7,3 
	cin >> p_c;
	for (int i = 0; i < p_c; i++) {

		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	dfs(p1);

	cout << conshu;
}
