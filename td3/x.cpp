#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

#define SIZE (int)1e5

using namespace std;

v(int) camarades[SIZE];
bool visited[SIZE];
int distance_p[SIZE];

int bfs(int s, int t) {
    queue<int> q;
    distance_p[s] = 0;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int n : camarades[f]) {
            if (!visited[n]) {
                visited[n] = true;
                distance_p[n] = distance_p[f]+1;
                q.push(n);
            }
            if (n == t)
                return distance_p[n]-1;
        }
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	int nbCases;
	cin >> nbCases;

    for (int c=0; c<nbCases; ++c) {
        int n, camarade, nbFriends, f, seeker, helper;
        cin >> n;

        memset(visited, false, SIZE); 
        memset(distance_p, -1, SIZE);
        for (int i=0; i<n; ++i) 
            camarades[i].clear();

        for (int i=0; i<n; ++i) {
            cin >> camarade >> nbFriends;
            for (int j=0; j<nbFriends; ++j) {
                cin >> f;
                camarades[i].push_back(f);
            }
        }

        cin >> seeker >> helper;
        cout << seeker << " " << helper << " " << bfs(seeker,helper) << endl;

        if (c != nbCases-1)
            cout << endl;
    }

    
        
	return 0;
}
