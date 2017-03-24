#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

#define NMAX 50

bool available[NMAX][NMAX];
int work[NMAX][NMAX];
       
void display_available(int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j)
            cout << available[i][j] << " ";
        cout << endl;
    }
}

void display_work(int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j)
            cout << work[i][j] << " ";
        cout << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);

    int n;
    while (cin >> n) {
        char c;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> c;
                if (c == '.')
                    available[i][j] = true;
                else
                    available[i][j] = false;
            }
        }
        display_available(n);

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> work[i][j];
            }
        }
        display_work(n);
    }

    return 0;
}
