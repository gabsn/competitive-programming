#include <bits/stdc++.h>

using namespace std;

void remove_interval(vector< pair<float, float> > & v, float b, float e) {
	//cout << "----------- Entrée dans remove_interval -------------" << "\n";
	for (vector< pair<float, float> >::iterator it = v.begin(); it != v.end(); it++) {
		float b_origin = (*it).first;
		float e_origin = (*it).second;
		//cout << "origin = (" << b_origin << "," << e_origin << ")" << "\n";
		if (b > b_origin && e < e_origin) {
			v.erase(it);
			v.push_back(make_pair(b_origin, b));
			v.push_back(make_pair(e, e_origin));
			return;
		} else if (b >= b_origin && e < e_origin) {
			v.erase(it);
			v.push_back(make_pair(e, e_origin));
			return;
		} else if (b > b_origin && e <= e_origin) {
			v.erase(it);
			v.push_back(make_pair(b_origin, b));
			return;
		} else if (b == b_origin && e == e_origin) {
			v.erase(it);
			return;
		}
	}
}

void display(vector< pair<float, float> > & v) {
	if (v.empty())
		cout << "vector empty" << endl;
	for (vector< pair<float, float> >::iterator it = v.begin(); it != v.end(); it++) {
		cout << "(" << (*it).first << "," << (*it).second << ")" << endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	while (1) {
		bool job_done = 1;
		int nx, ny;
		double w;
		cin >> nx >> ny >> w;

		if (nx == 0 && ny == 0 && w == 0.0)
			return 0;

		vector< pair<float, float> > vx;
		vx.push_back(make_pair(0,75));
		for (int i=0; i<nx; ++i) {
			float start_position, b, e;
			cin >> start_position;

			b = start_position - w/2;
			if (b < 0)
				b = 0;
			e = start_position + w/2;
			if (e > 75)
				e = 75;

			//cout << "intervalle à tondre : (" << b << "," << e << ")" << "\n";
			remove_interval(vx,b,e);
		}

		if (!vx.empty()) {
			job_done = 0;
		} 
		vector< pair<float, float> > vy;
		vy.push_back(make_pair(0,100));
		for (int i=0; i<ny; ++i) {
			float start_position, b, e;
			cin >> start_position;

			if (job_done) {
				b = start_position - w/2;
				if (b < 0)
					b = 0;
				e = start_position + w/2;
				if (e > 100)
					e = 100;

				//cout << "intervalle à tondre : (" << b << "," << e << ")" << "\n";
				remove_interval(vy,b,e);
			}
		}

		if (!job_done) 
			cout << "NO" << endl;
		else if (job_done && vy.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	} 

	return 0;
}
