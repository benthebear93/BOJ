#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int line[100001];
int visited[100001] = {0,};
int n, k;
int time;

int bfs() {
	time = 0;
	queue<int> q; 
	q.push(n);
	while (!q.empty()) {
		
		int size = q.size();
 		for (int i = 0; i < size; i++) {
			n = q.front();
			q.pop();
			if (n == k){
				return time;
			}
			if (n > 0 && visited[n - 1] == 0) {
				q.push(n - 1);
				visited[n - 1] = 1;
			}
			if (n < 100000 && visited[n + 1] == 0) {
				q.push(n + 1);
				visited[n + 1] = 1;
			}
			if (n * 2 < 100000 && visited[n * 2] == 0) {
				q.push(n * 2);
				visited[n * 2] = 1;
			}
		}
		time++;
	}
}

int main() {
	cin >> n >> k;
	time = bfs();
	cout << time << endl;
}
