#include <bits/stdc++.h>

using namespace std;
template < typename key_type, typename value_type >
    struct my_map {
        int m;
        int _size;
        vector < vector < pair < key_type, value_type >>> chains;
        my_map(int m): m(m), _size(0) {
            chains.resize(m);
        }
        value_type & operator[](const key_type & key) {
            int chain_position = _hash(key);
            int at = 0;
            while (at < chains[chain_position].size() and chains[chain_position]
                [at].first != key) {
                ++at;
            }
            if (at == chains[chain_position].size()) {
                chains[chain_position].emplace_back(key, value_type());
                ++_size;
            }
            return chains[chain_position][at].second;
        }

        void erase(const key_type & key) {
            int chain_position = _hash(key);
            int at = 0;
            while (at < chains[chain_position].size() and chains[chain_position]
                [at].first != key) {
                ++at;
            }
            if (at != chains[chain_position].size()) {
                if (at != chains[chain_position].size() - 1) {
                    swap(chains[chain_position].back(), chains[chain_position][at]);
                }
                chains[chain_position].pop_back();
                --_size;
            }
        }



        bool has_key(const key_type & key) const {
            int chain_position = _hash(key);
            int at = 0;
            while (at < chains[chain_position].size() and chains[chain_position]
                [at].first != key) {
                ++at;
            }
            if (at == chains[chain_position].size()) {
                return false;
            }
            return true;
        }
        
        int _hash(key_type key) const {
        const int B = 311;
        const int MOD = 1e9 + 7;
        long long k = key;
        if (k < 0) k = -k; // o usa un manejo distinto si el signo debe importar
        int hash_value = 0;
        if (k == 0) return 0; // caso especial
        while (k > 0) {
            int d = k % 10;
            hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
            k /= 10;
    }
        return hash_value % m;
}

        int size() const {
            return _size;
        }

        value_type get(const key_type & key, const value_type & def = value_type()) const {
        int chain_position = _hash(key);
        for (auto & e : chains[chain_position])
            if (e.first == key) return e.second;
        return def;
}

        bool empty() const { return _size == 0;}

        void clear() {
            for (auto & c : chains) c.clear();
            _size = 0;
        }

        void print() {
            for (int i = 0; i < m; ++i) {
                cout << "Bucket " << i << ": " << endl;
                for (auto & e: chains[i]) {
                    cout << e.first << " --> " << e.second << endl;
                }
                cout << "End bucket" << endl;
            }
        }
    };
    
 
