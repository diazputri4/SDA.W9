#include "buku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membuat Buku
Buku* buatBuku(char* judul, int stok) {
    Buku* buku = (Buku*)malloc(sizeof(Buku));
    strcpy(buku->judul, judul);
    buku->stok = stok;
    buku->antrianPeminjam = NULL; // Antrian peminjam dimulai dengan NULL
    return buku;
}

// Fungsi untuk menampilkan Buku
void tampilkanBuku(Buku* buku) {
    printf("Judul Buku: %s\n", buku->judul);
    printf("Stok Buku: %d\n", buku->stok);
}

