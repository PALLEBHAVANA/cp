#include<iostream>
#include <queue>
#include<vector>
#include <cstring>
#include<algorithm>
using namespace std;

void check(){
	int n, r, m;
	cin >> n >> r >> m;
	vector<vector<int>> adj(n);
	for(int k=0; k<r; k++){
		int i, j;
		cin >> i >> j;
		adj[i-1].emplace_back(j-1);
		adj[j-1].emplace_back(i-1);
		
	}
	vector<bool> used(n, false);
	vector<int> distance(n);
	vector<bool> used2(n);
	for(int i=0; i<m; i++){
		vector<int> distance(n, -1);
		vector<bool> used2(n, false);
		int c,s;
		cin >> c >> s;
		queue<int> q;
		q.push(c-1);
		distance[c-1] = 0;
		used2[c-1] = true;
		while( !q.empty()){
			int u = q.front();
			q.pop();
			if( used[u] == true){
				cout << "No" << endl;
				return;
			}
			if(distance[u] < s ){
				for( int v: adj[u]){
					if( used2[v] == false){
						q.push(v);
						used2[v] = true;
						distance[v] = distance[u] + 1;	
					}
				}
			}
			used[u] = true;
		}
	}
    	if (all_of(used.begin(), used.end(), [](bool val) { return val; })) {
        	cout << "Yes" << endl;
    	} else {
        	cout << "No" << endl;
    	}
	return;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		check();
	}
}
