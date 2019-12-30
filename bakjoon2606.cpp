#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int pair_;
int visited[101];
vector<int> a[101];

int bfs(int start) {
	int cou = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			printf(" i :%d  ", i);
			int y = a[x][i];
			printf("[x][i]  : [%d][%d]\n",x, y);
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				cou++;
				printf("cout++ : %d \n",cou);
			}
		}
	}
	return cou;
}

int main() {
	scanf_s("%d", &n);
	scanf_s("%d", &pair_);
	for (int i = 0; i < pair_; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int ans = bfs(1);
	printf("%d", ans);
}
