#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

using namespace std;

void display(vv(int) a, int row, int column) {
     for(int i = 0; i<row; i++) {
         for(int j = 0; j<column; j++) {
             cout << a[i][j] << " ";
         }
         cout << "\n";
     }
     cout << "\n";
}

bool is_feasible(v(int) & row, int nbTasks) {
    bool result = true;
    for (int i=0; i<nbTasks; ++i) {
        if (row[i] != 0) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	int nbCases;
	cin >> nbCases;

	for (int c=0; c<nbCases; ++c) {
        int nbTasks, nbRules;
        cin >> nbTasks >> nbRules;

        vv(int) dependencies(nbTasks, v(int)(nbTasks, 0));
        for (int i=0; i<nbRules; ++i) {
            int task, k, dependence;
            cin >> task >> k;

            for (int j=0; j<k; ++j) {
                cin >> dependence;
                dependencies[task-1][dependence-1] = 1;
            }
        }

        //display(dependencies,nbTasks,nbTasks);
        int nbTasksToBuild = nbTasks;
        while (nbTasksToBuild > 0) {
            for (int i=0; i<nbTasks; ++i) {
                v(int) & row = dependencies[i];
                if (is_feasible(row, nbTasks)) {
                    for (int line=0; line<nbTasks; ++line) {
                        if (dependencies[line][i] == 1)
                            dependencies[line][i] = 0;
                        dependencies[i][line] = 8;
                    }
                    nbTasksToBuild--;
                    if (nbTasksToBuild > 0)
                        cout << i+1 << " ";
                    else
                        cout << i+1;
                    break;
                }
            }
            //display(dependencies,nbTasks,nbTasks);
        }
        if (c != nbCases-1)
            cout << endl << endl;
        else
            cout << endl;
    }

	return 0;
}
