#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define v(x) vector<x >
#define vv(x) vector<vector<x > >
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

#define NCITIES 1000
#define MAXCOST 999999999

struct Edge {
    int u,v,w;
    bool operator<(Edge other) const {
        return w < other.w;
    }
};

int nCity, q;
double minCost;

int subNetworks[NCITIES];
int subCost[8];
int xCity[NCITIES];
int yCity[NCITIES];
int neighbor[NCITIES];
double cost[NCITIES][NCITIES];
bool mask[8];
bool visited[NCITIES];
int parent[NCITIES];
queue<Edge> edges;
v(int) sub[8];

void display_sub(int n) {
    for (int i=0; i<n; ++i) {
        cout << subNetworks[i] << " ";
    }
    cout << endl;
}

void display_coord(int n) {
    for (int i=0; i<n; ++i) {
        cout << xCity[i] << " " << yCity[i] << endl;
    }
}

void display_cost(int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

void display_mask(int q) {
    for (int i=0; i<q; ++i)
        cout << mask[i] << " ";
    cout << endl;
}

double get_cost(int u, int v) {
    return (xCity[u]-xCity[v])*(xCity[u]-xCity[v]) + (yCity[u]-yCity[v])*(yCity[u]-yCity[v]);
}

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void kruskal() {
    double totalCost = 0;
    int nEdge(1);

    for (int i=0; i<nCity; ++i) {
        parent[i] = i;
    }
    
    for (int i=0; i<q; ++i) {
        if (mask[i]) {
            totalCost += subCost[i];
            for (auto city : sub[i]) {
                parent[city] = parent[sub[i][0]];
            }
        }
    }
    cout << "totalCost after initializing subNetworks : " << totalCost << endl;

    while (nEdge < nCity) {
        Edge edge = edges.pop();
        edges.pop_front();
        int u = findset(edge.u);
        int v = findset(edge.v);
        if(u != v) {
            totalCost += edge.w; // add edge cost
            parent[u] = parent[v]; // link
            nEdge++;
        }
    }
    minCost = min(minCost,totalCost);
    display_mask(q);
    cout << "totalCost : " << totalCost << endl;
}

void kruskal2() {
    double totalCost = 0;
    int nEdges(1), index(0), nCityVisited(0);

    for (int i=0; i<q; ++i) {
        if (mask[i]) {
            totalCost += subCost[i];
        }
    }

    for (int i=0; i<nCity; ++i) {
        if (mask[subNetworks[i]]) {
            visited[i] = true;
            cout << "city " << i << " visited" << endl;
            nCityVisited++;
        }
    }

    cout << "nCityVisited before while : " << nCityVisited << endl;
    
    while (nCityVisited < nCity) {
        //cout << "nCityVisited in while : " << nCityVisited << endl;
        Edge edge = edges[index++];
        if (!(visited[edge.u] && visited[edge.v])) {
            cout << "On ajoute l'arête : (" << edge.u << "," << edge.v << ") de poid : " << edge.w << endl;
            if (!visited[edge.u]) {
                visited[edge.u] = true;
                nCityVisited++;
            }
            if (!visited[edge.v]) {
                visited[edge.v] = true;
                nCityVisited++;
            }
            totalCost += edge.w;

        }
    }
    minCost = min(minCost,totalCost);
    display_mask(q);
    cout << "totalCost : " << totalCost << endl;
}

void parcours(int n) {
    if (n == q) {
        kruskal();
    } else {
        parcours(n+1);
        mask[n] = false;
        for (int i=n+1; i<q; ++i)
            mask[i] = true;
        parcours(n+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << setprecision(50);

    int nTestCase;
    cin >> nTestCase >> nCity >> q;

    for (int testC=0; testC<nTestCase; ++testC) {
        for (int subN=0; subN<q; ++subN) {
            int n, cost;
            cin >> n >> cost;
            subCost[subN] = cost;

            int city;
            for (int i=0; i<n; ++i) {
                cin >> city;
                subNetworks[city-1] = subN;
                sub[subN].push_back(city);
            }
        }
        //display_sub(nCity);

        for (int city=0; city<nCity; ++city) {
            cin >> xCity[city] >> yCity[city];
        }
        //display_coord(nCity);

        edges.clear();
        Edge edge;
        for (int i=0; i<nCity; ++i) {
            for (int j=i; j<nCity; ++j) {
                //cost[i][j] = get_cost(i,j);
                //if (cost[i][j] == 0)
                //    cost[i][j] = MAXCOST;
                //cost[j][i] = cost[i][j];
                double cost = get_cost(i,j);
                if (cost == 0)
                    cost = MAXCOST;
                edge.u = i;
                edge.v = j;
                edge.w = cost;
                edges.push_back(edge);
            }
        }
        //display_cost(nCity);
        sort(edges.begin(), edges.end());

        memset(visited,false,nCity);
        memset(mask,true,q);
        minCost = MAXCOST;
        parcours(0);

    }

    return 0;
}
