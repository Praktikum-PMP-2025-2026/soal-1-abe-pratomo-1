/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 – Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin 20 April 2026
 *   Nama (NIM)          : Jonathan Chandra (13224103)
 *   Nama File           : Soal1.c
 *   Deskripsi           : Pemulihan Sensor Fragmen
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int nilai_max(int a, int b){
    if(a>b){
        return a;
    }
    else if(a<=b){
        return b;
    }
}

int main() {
    int N;
    
    if (scanf("%d",&N)!=1) {
        return 0;
    }

    int *arr = (int*)malloc(N*sizeof(int));
    if (arr == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    for (int i=0; i<N;++i) {
        scanf("%d", &arr[i]);
    }

    for (int i=0;i<N;++i) {
        if (arr[i] == -1) {
            int kiri = 0; 
            int var_kiri = 0;

            if (i > 0) {
                kiri = 1;
                var_kiri = arr[i - 1];
            }

            int kanan = 0;
            int var_kanan = 0;

            for (int j=i+1;j<N;++j) {
                if (arr[j] != -1) {
                    kanan = 1;
                    var_kanan = arr[j];
                    break;
                }
            }

            if(kiri && kanan){
            arr[i] = floor((var_kiri + var_kanan) / 2.0);
            } else if (kiri) {
                arr[i] = var_kiri;
            } else if (kanan) {
                arr[i] = var_kanan;
            } else {
                arr[i] = 0;
            }
        }
    }

    printf("RECOVERED");
    for(int i=0;i<N;++i){
        printf(" %d",arr[i]);
    }
    printf("\n");
    
    int max_sum = arr[0];
    int sum = arr[0];
    
    for (int i=1;i<N;++i){
        sum= nilai_max((int)arr[i],sum + arr[i]);
        max_sum = nilai_max(max_sum,sum);        
    }

    printf("MAX_SUM %d",max_sum);

}
