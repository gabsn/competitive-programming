#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

#define NMAX 6 

struct Point {
    int x, y, z, id; 
    double box_distance, r;
};

Point points[6];
v(Point) balloons;
double distances[6][6];

void display(int n) {
    for (int i=0; i<n; ++i) {
            cout << points[i].x << " " << points[i].y << " " << points[i].z << " box_distance : " << points[i].box_distance << endl;
    }
}

void distance(int n) {
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            distances[i][j] = sqrt(pow(points[i].x-points[j].x,2) + pow(points[i].y-points[j].y,2) + pow(points[i].z-points[j].z,2));
            if (i != j)
                distances[j][i] = distances[i][j];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
    cout << setprecision(50);
    int n, box_volume;
    double empty_volume, result;
    v(int) first_corner(3), opposite_corner(3);
    int i_test_case = 0;
    do {
        i_test_case++;
        cin >> n;

        if (n == 0)
            return 0;

        for (int i=0; i<3; ++i)
            cin >> first_corner[i];
        for (int i=0; i<3; ++i)
            cin >> opposite_corner[i];
        for (int i=0; i<n; ++i) { 
            int x,y,z;
            cin >> x >> y >> z;
            if (x < opposite_corner[0] && x > first_corner[0] &&
                y < opposite_corner[1] && y > first_corner[1] && 
                z < opposite_corner[2] && z > first_corner[2]) {
                points[i].x = x;
                points[i].y = y;
                points[i].z = z;
                points[i].box_distance = min({abs(points[i].x-first_corner[0]),abs(points[i].x-opposite_corner[0]),
                                              abs(points[i].y-first_corner[1]),abs(points[i].y-opposite_corner[1]),
                                              abs(points[i].z-first_corner[2]),abs(points[i].z-opposite_corner[2])});
            } else {
                n--;
                i--;
            }
        }

        int permutation[n];
        for (int i=0; i<n; ++i)
            permutation[i] = i;
        box_volume = abs((opposite_corner[0]-first_corner[0])*
                         (opposite_corner[1]-first_corner[1])*
                         (opposite_corner[2]-first_corner[2]));
        result = box_volume;
        distance(n);
        //for (int i=0; i<n; ++i) {
        //    for (int j=0; j<n; ++j)
        //        cout << distances[i][j] << " ";
        //    cout << endl;
        //}

        do { 
            empty_volume = box_volume;
            balloons.clear();
            for (auto i : permutation) {
                //cout << i << " ";
                Point p = points[i];
                double r = p.box_distance;
                for (auto b : balloons) {
                    r = min(r,max(distances[i][b.id]-b.r,(double)0)); 
                }
                double volume = 4.0/3*M_PI*pow(r,3);
                //cout << "volume : " << volume << " & r : " << r << endl;
                empty_volume -= volume;
                if (r != 0) {
                    p.r = r;
                    p.id = i;
                    balloons.push_back(p);
                }
            }
            //cout << endl << "empty_volume : " << empty_volume << endl;
            result = min(result, empty_volume);
        } while (next_permutation(permutation, permutation+n));

        cout << "Box " << i_test_case << ": " << round(result) << endl << endl;   

    } while (1);
        
    return 0;
}
