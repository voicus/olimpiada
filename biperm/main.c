#include <stdio.h>
#include <iostream>
 
using namespace std;
int viz[2][10003],a[2][10003],b[2][10003];
int main()
{   int n,i,j,p,nrmin,invers,l,poz,ant,aux,urmviz;
    FILE*in = fopen("biperm.in", "r");
    FILE*out = fopen("biperm.out", "w");
    fscanf(in, "%d", &n);
    for (i=0;i<2;++i)
        for (j=1;j<=n;++j)
        {
            fscanf(in, "%d", &a[i][j]);
            if (viz[0][a[i][j]]==0) {
                viz[0][a[i][j]]=j;
            } else {
                viz[1][a[i][j]]=j;
            }
        }
    p=1;
    nrmin=0;
    for (i=1;i<=n;++i)
        if (b[0][i]==0) {
            l=1; invers=0;poz=i;
            b[0][poz]=a[0][poz];
            b[1][poz]=a[1][poz];
            ant=poz;
            urmviz=b[1][poz];
            if (viz[0][urmviz]==poz) {
                poz=viz[1][urmviz];
            } else {
                poz=viz[0][urmviz];
            }
            while (!b[0][poz])
            {
                if (a[0][poz]==b[1][ant])
                {
                    b[0][poz]=a[0][poz];
                    b[1][poz]=a[1][poz];
                    l++;
                    ant=poz;
                    urmviz=b[1][poz];
                    if (viz[0][urmviz]==poz) {
                        poz=viz[1][urmviz];
                    } else {
                        poz=viz[0][urmviz];
                    }
                }
                else
                {
                    b[0][poz]=a[1][poz];
                    b[1][poz]=a[0][poz];
                    l++;invers++;
                    ant=poz;
                    urmviz=b[1][poz];
                    if (viz[0][urmviz]==poz) {
                        poz=viz[1][urmviz];
                    } else {
                        poz=viz[0][urmviz];
                    }
                }
 
            }
            if (l>1)
                p*=2;
            if (invers>l-invers)
                nrmin+=l-invers;
            else
                nrmin+=invers;
        }
    fprintf(out, "%d %d\n", p, nrmin);
    for(i=0;i<2;++i)
    {   for(j=1;j<n;++j) {
            fprintf(out, "%d ", b[i][j]);
        }
        fprintf(out, "%d\n", b[i][n]);
    }
    fclose(in);
    fclose(out);
    return 0;
}
