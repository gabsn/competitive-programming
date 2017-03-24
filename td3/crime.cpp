#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

#define MAXINTERSECTIONS (int)1e3

using namespace std;

v(int) intersections[MAXINTERSECTIONS];
bool visited[MAXINTERSECTIONS];
int color[MAXINTERSECTIONS];

void display(int nbIntersections) {
    for (int i=0; i<nbIntersections; ++i) {
        for (auto intersection : intersections[i])
            cout << intersection << " ";
        cout << endl;
    }
}

void display(vv(int) & array) {
    for (unsigned int i=0; i<array.size(); ++i) {
        for (auto a: array[i])
            cout << a << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs_cc(int s, v(int) & cc) {
    visited[s] = true;
    cc.push_back(s);
    for (auto son: intersections[s]) {
        if (!visited[son])
            dfs_cc(son,cc);
    }
}

int find_summit(int nbIntersections) {
    int s = 0;
    while (visited[s] && s < nbIntersections)
        ++s;
    //cout << "find_summit : " << s << endl;
    return s;
}

bool is_2_coloriable(v(int) & v) {
    for (auto s: v) {
        for (auto n: intersections[s]) {
            if (color[n] == -1) {
                color[n] = 1 - color[s];
            } else if (color[n] != 1 - color[s]) {
                return false;
            }
        }
    }
    return true;
}
    
int nb_ppps(v(int) v) {
    int a(0), b(0);
    for (auto i : v) {
        if (color[i] == 0)
            a++;
        else if (color[i] == 1)
            b++;
        //cout << "i = " << i << " : " << a << ", " << b << endl;
    }
    return (a <= b) ? a : b;
}
        
int main() {
	ios_base::sync_with_stdio(0);

    int nbIntersections, nbStreets;
    while (cin >> nbIntersections) {
        cin >> nbStreets;

        // reset of global variables
        memset(visited,false,nbIntersections); 
        for (int i=0; i<nbIntersections; ++i) {
            intersections[i].clear();
            color[i] = -1;
        }

        for (int street = 0; street<nbStreets; ++street) {
            int a, b;
            cin >> a >> b;
            intersections[a-1].push_back(b-1);
            intersections[b-1].push_back(a-1);
        }

        vv(int) ccSet;
        int s = find_summit(nbIntersections);
        while (s < nbIntersections) {
            color[s] = 0;
            v(int) cc;
            dfs_cc(s,cc);
            ccSet.push_back(cc);
            s = find_summit(nbIntersections);
        }
        
        //display(ccSet);
        //cout << "color : ";
        //for (int i=0; i<nbIntersections; ++i)
        //    cout << color[i] << " ";
        //cout << endl;

        bool feasible = true;
        for (auto v: ccSet) {
            if (!is_2_coloriable(v)) {
                feasible = false;
                break;
            }
        }

        //cout << "color : ";
        //for (int i=0; i<nbIntersections; ++i)
        //    cout << color[i] << " ";
        //cout << endl;

        if (feasible) {
            int counter(0);
            for (auto v : ccSet) {
                counter += nb_ppps(v);
            }
            cout << counter << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

	return 0;
}
