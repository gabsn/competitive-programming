#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define ld long double
#define v(x) vector<x>
#define it(x) std::vector<x>::iterator
#define rit(x) std::vector<x>::reverse_iterator

using namespace std;

void sieve_atkins(ll n, vector<bool> & is_prime) {
    is_prime[2] = true;
    is_prime[3] = true;
    for (ll i = 5; i <= n; i++) {
        is_prime[i] = false;
    }
    ll lim = ceil(sqrt(n));
    for (ll x = 1; x <= lim; x++) {
        for (ll y = 1; y <= lim; y++) {
            ll num = (4*x*x + y*y);
            if (num <= n && (num % 12 == 1 || num % 12 == 5)) {
                is_prime[num] = true;
            }
            num = (3*x*x + y*y);
            if (num <= n && (num % 12 == 7)) {
                is_prime[num] = true;
            }

            if (x > y) {
                num = (3*x*x - y*y);
                if (num <= n && (num % 12 == 11)) {
                    is_prime[num] = true;
                }
            }
        }
    }

    for (ll i = 5; i <= lim; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    //for (ll i = 2; i <= n; i++) {
    //     if (is_prime[i])
    //     {
    //         cout<<i<<"\t";
    //     }
    //}
}

void godbach(ll n, v(bool) & is_prime) {
    for (ll i=n-3; i>=n/2; i-=2) {
        if (is_prime[i] && is_prime[n-i]) {
            cout << n << " = " << n-i << " + " << i;
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);

    ll nmax, n(1);
    v(bool) is_prime(1e6+1);
    v(ll) inputs;

    while (n) {
        cin >> n;
        if (n)
            inputs.push_back(n);
    }

    sort(inputs.begin(), inputs.end());
    nmax = inputs.back(); 
    sieve_atkins(nmax, is_prime);

    for (ll i=0; i<(ll)inputs.size(); ++i) {
        godbach(inputs[i], is_prime);
        cout << endl;
    }

    return 0;
}

