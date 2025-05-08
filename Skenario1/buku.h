#ifndef BUKU_H
#define BUKU_H

#include "antrian.h"

// Struktur untuk Buku
typedef struct Buku {
    char judul[50];   // Nama buku
    int stok;         // Stok buku
    Antrian* antrianPeminjam;  // Pointer ke antrian peminjam
} Buku;

// Fungsi untuk membuat Buku
Buku* buatBuku(char* judul, int stok);

// Fungsi untuk menampilkan Buku
void tampilkanBuku(Buku* buku);

#endif

