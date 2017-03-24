#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

using namespace std;

void floyd_warshall(int nbVertices, vv(int) & distances) {
    for(int k = 0; k < nbVertices; k++)
        for(int i = 0; i < nbVertices; i++)
            for(int j = 0; j < nbVertices; j++)
                if(distances[i][j]>distances[i][k]+distances[k][j])
                    distances[i][j]=distances[i][k]+distances[k][j];
}

void display(vv(int) & a, int row, int column) {
     for(int i = 0; i<row; i++) {
         for(int j = 0; j<column; j++) {
             cout << a[i][j] << " ";
         }
         cout << "\n";
     }
     cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	int nbCases;
	cin >> nbCases;

	for (int c=0; c<nbCases; ++c) {
		int n, e, t, m, counter(0);
		cin >> n >> e >> t >> m;

        vv(int) distances(n, v(int)(n,9999999));
        for (int i=0; i<n; ++i)
            distances[i][i] = 0;
		for (int i=0; i<m; ++i) {
			int a, b, distance;
			cin >> a >> b >> distance;
            distances[a-1][b-1] = distance;
		}

        floyd_warshall(n,distances);
        //display(distances,n,n);

        for (int i=0; i<n; ++i)
            if (distances[i][e-1] <= t)
                counter++;
		if (c != nbCases-1)
			cout << counter << endl << endl;
		else
			cout << counter << endl; 
	}

	return 0;
}
