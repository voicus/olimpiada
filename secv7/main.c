#include <stdio.h>
#include <stdlib.h>
int v[30001];
int minim(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}
int main()
{
    FILE*in = fopen("secv7.in", "r");
    FILE*out = fopen("secv7.out", "w");
    int n, i, max, s, sum, j, maxx, p, summ, j2;
    sum = 20001;
    max = -10001;
    fscanf(in, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(in, "%d", &v[i]);
        if (max < v[i]) {
            max = v[i];
            p = i;
        }
    }
    s = v[0] + v[n-1] + max;
    maxx = v[0];
    for (i = 1; i < p; i++) {
        if (v[i] + maxx < sum) {
            sum = v[i] + maxx;
            j = i;
        }
        if (maxx < v[i]) {
            maxx = v[i];
        }
    }
    maxx = v[n-1];
    summ = 20001;
    for (i = n-2; i >= p+1; i--) {
        if (v[i] + maxx < summ) {
            summ = v[i] + maxx;
            j2 = i;
        }
        if (maxx < v[i]) {
            maxx = v[i];
        }
    }
    sum += max;
    summ += max;
    if (sum == minim(sum, summ)) {
        sum = minim(sum, summ);
        fprintf(out, "%d\n", minim(s, sum));
        if (minim(s, sum) == sum) {
            fprintf(out, "%d %d", j, j+1);
        } else {
            fprintf(out, "1 %d", n-1);
        }
    } else {
        sum = minim(sum, summ);
        fprintf(out, "%d\n", minim(s, sum));
        if (minim(s, sum) == sum) {
            fprintf(out, "%d %d", j2, j2+1);
        } else {
            fprintf(out, "1 %d", n-1);
        }
    }
 
 
 
    return 0;
}
