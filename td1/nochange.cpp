#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define v(x) vector<int>
#define vv(x) vector<vector<int> >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

using namespace std;
 
int x, k;

void is_possible_to_pay(int n, int v, vv(int) & values) {
    //string s = "is_possible_to_pay("+to_string(n)+","+to_string(v)+")";
    //cout << s << endl;
    // n = d*q + r
    int d = values[v][0]; 
    int & q = values[v][1]; 
    int & r = values[v][2];
    
    if (q == 0) {
        q = (int)n/d;
        r = n%d;
    } else {
        q--;
        r = n - d*q;
    }

    if (v>0 && q > values[v-1][1]) {
        q = values[v-1][1];
        r = n - d*q;
    } 

    if (r == 0) {
        cout << "YES" << endl;
        //cout << values[0][0] << "*" << values[0][1];
        //for (int i=1; i<k; ++i)
        //    cout << " + " << values[i][0] << "*" << values[i][1];
        //cout << endl;
    } else if (v == k-1 && r != 0) {
        cout << "NO" << endl;
    } else if (v > 0 && q == 0) {
        v--;
        q = 0;
        int tot = values[v][0]*values[v][1] + values[v][2];
        is_possible_to_pay(tot,v,values);
    } else {
        v++;
        is_possible_to_pay(r,v,values);
    }
}
   
int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        vv(int) values;
        cin >> x >> k;

        for (int j=0; j<k; ++j) {
            v(int) * tab = new v(int)(3);
            cin >> tab->at(0);
            tab->at(1) = 0;
            tab->at(2) = 0;
            values.push_back(*tab);
        }

        is_possible_to_pay(x,0,values);
        if (i != n-1)
            cout << endl;
    }

    return 0;
}

