#include<stdio.h>
#include<math.h>
#include<time.h>

#define pi 3.141592
#define M 8
#define N 8 

int main() {
    int x, y;
    double tmp;
    int f[8][8] =
    { {139, 144, 149, 153, 155, 155, 155, 155},
    {144,	151,	153,	156,	159,	156,	156,	156},
    {150,	155,	160,	163,	158,	156,	156,	156},
    {159,	161,	162,	160,	160,	159,	159,	159 },
    {   159,	160,	161,	162,	162,	155,	155,	155},
    {   161,	161,	161,	161,	160,	157,	157,	157},
    {   161,	162,	161,	163,	162,	157,	157,	157},
    {   162,	162,	161,	161,	163,	158,	158,	158} };

    int quant[8][8] = { {16,    11,   10,   16,   24,   40,     51,     61},
                        {12,    12,   14,   19,   26,   58,     60,     55},
                        {14,    13,   16,   24,   40,   57,     69,     56},
                        {14,    17,   22,   29,   51,   87,     80,     62},
                        {18,    22,   37,   56,   68,   109,    103,    77},
                        {24,    35,   55,   64,   81,   104,    133,    92},
                        {49,    64,   78,   87,   103,  121,    120,    101},
                        {72,    92,   95,   98,   112,  100,    103,    99} };
    double Cu[N] = { 0 };
    double Cv[M] = { 0 };
    double F[8][8];
    double start, end;
    double start1, end1;
    int i, j, u, v;
    printf("input data\n");
    printf("\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", f[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    start = clock();
    for (u = 0;u < N;u++) {
        if (u == 0)    Cu[u] = 1 / sqrt(N);
        else        Cu[u] = sqrt(2 / N);
        for (v = 0;v < M;v++) {
            if (v == 0)    Cv[v] = 1 / sqrt(M);
            else        Cv[v] = sqrt(2 / M);
            F[u][v] = 0;
            for (i = 0;i < N;i++) {
                for (j = 0;j < M;j++) {
                    F[u][v] += 0.25 * cos((2 * i + 1) * u * pi / (2 * N)) * cos((2 * j + 1) * v * pi / (2 * M)) * f[i][j];
                }
            }
        }
    }
    end = clock();
    printf("2D DCT 수행시간: %lf \n", end - start);
    printf("DCT\n");
    printf("\n");
    for (u = 0; u < 8; u++) {
        for (v = 0; v < 8; v++) {
            printf("%3.0f ", round(F[u][v]));
        }
        printf("\n");
    }
    printf("DCT quantized\n");
    printf("\n");
    for (u = 0; u < 8; u++) {
        for (v = 0; v < 8; v++) {
            printf("%3.0f ", round(F[u][v] / quant[u][v]));
        }
        printf("\n");
    }

}

