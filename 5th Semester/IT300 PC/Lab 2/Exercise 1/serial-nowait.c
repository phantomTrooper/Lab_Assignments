#include <omp.h>
#include <stdio.h>
#include <time.h>

int main(){
    int i,n = 327000;
    int a[n],c[n];
    double start_time,end_time;
    double b[n],d[n];

    for(i=0;i<n;++i) {
        a[i] = (i+1)%n;
        c[i] = (i-1)%n;
    }
    
    start_time = omp_get_wtime();
    
    for(i=0; i<(n-1);i++){
        b[i] = (a[i]+a[i+1])/2.0;
    }

    for(i=0;i<n;i++) {
        d[i] = (1.0/c[i]);
    }

    end_time = omp_get_wtime();

    printf("Time taken for serial nowait approach = %lf s\n", end_time - start_time);

    return 0;
}