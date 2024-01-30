#include <iostream>
#include <math.h>
#include <thread>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;


vector<long double> sumas;


void pi_decimals(int i_inicial, int i_final, double delta)
{
    long double suma = 0;
    for(int i = i_inicial; i <= i_final; i = i + 1)
    {
        double xi = (i + 0.5) * delta;
        suma += 4 / (1 + pow(xi, 2));
    }
    sumas.emplace_back(suma);
}


long double pi_decimals_multithread(int N, int p)
{
    double delta = 1.0 / N;
    int paso = N/p;
    int mod = N%p;

    sumas.reserve(p);
    vector<thread> threads;
    threads.reserve(p);

    int i0 = 0;
    int i1 = paso - 1;
    for(int i = 0; i < p; i = i + 1) {
        threads.emplace_back(pi_decimals, i0, i1, delta);
        if(mod == 0)
        {
            i0 = i1 + 1;
            i1 = i1 + paso;
        } else {
            i0 = i1 + 1;
            i1 = i1 + paso + 1;
            mod = mod - 1;
        }
    }

    for(int i = 0; i < p; i = i + 1) {
        threads[i].join();
    }
    
    long double total = 0;
    for(int i = 0; i < p; i = i + 1) {
        total += sumas[i];
    }
    total = total * delta;
    return total;
}


int main(int argc, char *argv[])
{
    double t0,t1;
    t0=clock();

    int N = strtol(argv[1], NULL, 10);
    int p = strtol(argv[2], NULL, 10);

    long double total = pi_decimals_multithread(N, p);

    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    
    cout << "Execution Time: " << setprecision(4) << time << endl;
    cout << "Pi decimals: " << setprecision(100) << total << endl;

    return 0;
}