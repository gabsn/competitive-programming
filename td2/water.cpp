#include <bits/stdc++.h>

#define EPS 1E-9
#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

using namespace std;

void display(vv(double) a, int row, int column) {
     for(int i = 0; i<row; i++) {
         for(int j = 0; j<column; j++) {
             cout << a[i][j] << " ";
         }
         cout << "\n";
     }
     cout << "\n";
}

double compute_total_volume(double level, vv(double) & citerns) {
    double total_volume = 0;
    for (auto citern : citerns) {
        //double initial_volume = total_volume;
        if (level <= citern[0]) 
            total_volume = total_volume;
        else if (level >= citern[0] + citern[1])
            total_volume += citern[1]*citern[2]*citern[3];
        else
            total_volume += (level-citern[0])*citern[2]*citern[3];
        //cout << "volume de la citerne : " << total_volume-initial_volume << endl; 
    }
    return total_volume;
}

double binary_search_p(double C, double a, double b, vv(double) citerns) {
   double low = a, high = b;
   //cout << "abs : " << abs(low-high) << endl;
   while(abs(low-high) > EPS) {
      double mid = low + (high - low)/2;
      double v = compute_total_volume(mid, citerns); 
      //cout << "volume : " << v << " pour mid : " << mid << endl;
      if (v < C)
          low = mid;
      else
          high = mid;
   }
   return (low + high)/2;
}

int main() {
	ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(2);
	int nbCases;
	cin >> nbCases;

	for (int c=0; c<nbCases; ++c) {
        int nbCiterns;
        double volume, maxHeight(0), maxVolume(0);
        cin >> nbCiterns;

        vv(double) citerns(nbCiterns, v(double)(4));
        for (int c=0; c<nbCiterns; ++c) {
            v(double) citern(4);
            cin >> citern[0] >> citern[1] >> citern[2] >> citern[3];
            citerns[c] = citern;
            maxHeight = (citern[0]+citern[1] > maxHeight) ? citern[0]+citern[1] : maxHeight;
            maxVolume += citern[1]*citern[2]*citern[3];
        }

        cin >> volume;
        
        if (volume > maxVolume)
            cout << "OVERFLOW" << endl << endl;
        else
            cout << binary_search_p(volume,0,maxHeight,citerns) << endl << endl;
    }

	return 0;
}
