#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>

using namespace std;

 double equacDiferencial1(double alpha, double M, double T, int nx, int nt){
        // transformando valores continuos em valores ou categorias discretas.
        double dx=M/(nx-1);
        double dt=T/(nt-1);
        double r = alpha*dt/(dx*dx);

        //vetor da temperatura
        vector<double> t1(nx,0.0),t2(nx,0.0);

        for (int i = 0; i < nx; ++i){
            t1[i]=sin(M_PI*i*dx);
        }
        for (int t = 0; t < nt; ++t){
            for (int i = 1; i < nx - 1; ++i) {
                t2[i] = t1[i] + r * (t1[i - 1] - 2 * t1[i] + t1[i + 1]);
            }
            //Para atualizar o valor da temperatura no laço
            t1=t2;
            printf("Tempo = %.2f : ", t * dt);
            for (double temp:t1) {
                printf("%.2f",temp);
            }
            printf("\n");
         }
            double sum = 0.0;
            for (double temp : t1) {
                sum += temp;
            }
            return sum / nx;
}


