#include <iostream>
#include <algorithm>
#define INF 9999999

using namespace std;

int main(){
	int n, m, c1, c2;//城市数，路数，所在地，目的地
	cin >> n >> m >> c1 >> c2;

	int dis[500] = { INF };//最短距离
	int num[500] = { INF };//路径条数
	int weight[500] = { INF };//救援队数量=权重
	int w[500] = { INF };//c1-c2总权重
	
	bool visit[500] = { false };
	for (int i = 0; i < n; i++){
		cin >> weight[n];
		w[n] = weight[n];
	}
	int r[500][500];//路径矩阵
	fill(r[0], r[0] + 500 * 500, INF);
	int a, b, len;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> len;
		r[a][b] = r[b][a] = len;
	}

	dis[c1] = 0;
	num[c1] = 1;

	for (int i = 0; i < n; i++){
		int u = -1, min = INF;
		for (int j = 0; j < n; j++){
			if (visit[j] == false && dis[j] < min){
				u = j;
				min = dis[j];
			}
		}
		if (u == -1)break;
		visit[u] = true;
		for (int v = 0; v < n; v++){
			if (visit[v] == false && r[u][v] != INF){
				if (dis[u] + r[u][v] < dis[v]){	//c1-u的距离+u-v的距离<c1-v的距离
					dis[v] = dis[u] + r[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];//?
				}
				else if (dis[u] + r[u][v] == dis[v]){
					num[v] += num[u];
					if (w[u] + weight[v]>w[v])
						w[v] = w[u] + weight[v];
				}
			}
		}
	}
	cout << num[c2] << " " << w[c2];
}