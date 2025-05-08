#include "anggota.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membuat Anggota
Anggota* buatAnggota(char* nama, int prioritas) {
    Anggota* anggota = (Anggota*)malloc(sizeof(Anggota));
    strcpy(anggota->nama, nama);
    anggota->prioritas = prioritas;
    return anggota;
}

