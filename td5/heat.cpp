#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator
#define mp make_pair

string words[200];
char grid[40][40];
bool visited[40][40];
vector<pair<int,int> > indexes;
int n,m,k;

void display_grid() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void display_visited() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void test(string wordToFind, string s) {
    size_t found = s.find(wordToFind); 
    while (found != string::npos) {
        //cout << wordToFind << " found in : " << s << endl;
        for (vector<pair<int,int> >::iterator it = indexes.begin()+found; it != indexes.begin()+found+wordToFind.size(); ++it) {
            visited[(*it).first][(*it).second] = true;
        }
        found = s.find(wordToFind, found+1); 
    }
}

int main() {
	ios_base::sync_with_stdio(0);
    cout << setprecision(50);

    while (cin >> n >> m >> k) {

        string word, s;
        for (int i=0; i<k; ++i) {
            cin >> words[i];
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }
        //display_grid();
        //display_visited();

        for (int word=0; word<k; ++word) {
            //cout << "horizontal" << endl;
            for (int i=0; i<n; ++i) {
                s = "";
                indexes.clear();
                for (int j=0; j<m; ++j) {
                    s += grid[i][j];
                    indexes.push_back(mp(i,j));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }

            //cout << "vertical" << endl;    
            for (int j=0; j<m; ++j) {
                s = "";
                indexes.clear();
                for (int i=0; i<n; ++i) {
                    s += grid[i][j];
                    indexes.push_back(mp(i,j));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }

            //cout << "diagonal1" << endl;    
            for (int r=0; r<n; ++r) {
                s = "";
                indexes.clear();
                for (int c=0; c<=r; ++c) {
                    s += grid[r-c][c];
                    indexes.push_back(mp(r-c,c));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);

            }
            for (int c=1; c<=m-n; ++c) {
                s = "";
                indexes.clear();
                for (int r=n-1; r>=0; --r) {
                    s += grid[r][n-1+c-r];
                    indexes.push_back(mp(r,n-1+c-r));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }
            for (int l=n-1; l>0; --l) {
                s = "";
                indexes.clear();
                for (int r=n-1; r>n-1-l; --r) {
                    s += grid[r][m-l+n-r-1];
                    indexes.push_back(mp(r,m-l+n-r-1));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }

            //cout << "diagonal2" << endl;
            for (int r=n-1; r>=0; --r) {
                s = "";
                indexes.clear();
                for (int l=0; l<n-r; ++l) {
                    s += grid[r+l][l];
                    indexes.push_back(mp(r+l,l));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }
            for (int c=1; c<m-n; ++c) {
                s = "";
                indexes.clear();
                for (int r=0; r<n; ++r) {
                    s += grid[r][c+r];
                    indexes.push_back(mp(r,c+r));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }
            for (int l=n-1; l>0; --l) {
                s = "";
                indexes.clear();
                for (int r=0; r<l; ++r) {
                    s += grid[r][m-l+r];
                    indexes.push_back(mp(r,m-l+r));
                }
                test(words[word],s);
                reverse(s.begin(),s.end());
                reverse(indexes.begin(),indexes.end());
                test(words[word],s);
            }

            //cout << "Pour k : " << word << " , on a visited :" << endl;
            //display_visited();
            //cout << endl;
        }

        s = "";
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!visited[i][j]) {
                    s += grid[i][j];
                }
            }
        }

        cout << s << endl;
    }

    return 0;
}
