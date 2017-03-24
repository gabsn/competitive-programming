#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator
#define mp make_pair

int n, l;
v(int) lengths;

void display(v(int) &a) {
    for (auto i: a)
        cout << i << " ";
    cout << endl;
}

void fill() {
    //cout << "entrée fill()" << endl;
    //display(lengths);
    int mid, li, lToFind, a(-1), b(lengths.size()-2);
    li = lengths.back();
    lengths.pop_back();
    lToFind = l-li;
    //cout << "lToFind = " << lToFind << endl;
    if (lToFind == 0 || lengths.empty())
        return;
    while (a+1 < b) {
        mid = (b+a+1)/2; 
        //cout << "mid = " << mid  << " a = " << a << " b = " << b << endl; 
        if (lengths[mid]<=lToFind)
            a = mid;
        else 
            b = mid;
    }
    if (a != -1)
        lengths.erase(lengths.begin()+a);
}

int main() {
	ios_base::sync_with_stdio(0);
    cout << setprecision(50);

    int nCase;
    cin >> nCase;

    for (int cas=0; cas<nCase; ++cas) {
        cin >> n >> l;

        lengths.clear();

        int li;
        for (int item=0; item<n; ++item) {
            cin >> li;
            lengths.push_back(li);
        }
        sort(lengths.begin(),lengths.end());
        int nBins = 0;
        while (!lengths.empty()) {
            fill();
            nBins++;
        }

        cout << nBins << endl;
        if (cas != nCase-1)
            cout << endl;
    }

    return 0;
}
