#include <bits/stdc++.h>
using namespace std;

struct Par {
    long long clave;
    int valor;
};

class TablaHash {
private:
    vector<vector<Par>> cubetas;
    int capacidad;
    int cantidadClaves = 0;

    int funcionHash(long long clave) {
        long long h = clave * 2654435761LL;
        if (h < 0) h = -h;
        return h % capacidad;
    }

    int buscarEnCubeta(vector<Par>& cubeta, long long clave) {
        for (int i = 0; i < (int)cubeta.size(); ++i) {
            if (cubeta[i].clave == clave) return i;
        }
        return -1;
    }

public:
    TablaHash(int cap) : capacidad(cap) {
        cubetas.resize(capacidad);
    }

    int& operator[](long long clave) {
        int indice = funcionHash(clave);
        vector<Par>& cubeta = cubetas[indice];

        int pos = buscarEnCubeta(cubeta, clave);
        if (pos == -1) {
            cubeta.push_back({clave, 0});
            cantidadClaves++;
            pos = (int)cubeta.size() - 1;
        }
        return cubeta[pos].valor;
    }

    int obtener(long long clave) {
        int indice = funcionHash(clave);
        vector<Par>& cubeta = cubetas[indice];
        int pos = buscarEnCubeta(cubeta, clave);
        if (pos == -1) return 0;
        return cubeta[pos].valor;
    }

    bool has_key(long long clave) {
        int indice = funcionHash(clave);
        return buscarEnCubeta(cubetas[indice], clave) != -1;
    }

    void erase(long long clave) {
        int indice = funcionHash(clave);
        vector<Par>& cubeta = cubetas[indice];
        int pos = buscarEnCubeta(cubeta, clave);
        if (pos != -1) {
            cubeta[pos] = cubeta.back();  
            cubeta.pop_back();
            --cantidadClaves;
        }
    }

    template <typename F>
    void for_each(F f) {
        for (auto& cubeta : cubetas)
            for (auto& p : cubeta)
                f(p.clave, p.valor);
    }

    void clear() {
        for (auto& cubeta : cubetas) cubeta.clear();
        cantidadClaves = 0;
    }

    bool empty() const {
        return cantidadClaves == 0;
    }

    int size() const {
        return cantidadClaves;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    TablaHash frecuencias(2 * n);

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        frecuencias[x]++;
    }

    while (q--) {
        long long x;
        cin >> x;
        cout << frecuencias.obtener(x) << '\n';
    }

    return 0;
}
