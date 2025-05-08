#ifndef BUKU_H
#define BUKU_H

#include "antrian.h"

#define MAX_BUKU 10

// Struktur untuk Buku
typedef struct Buku {
    char judul[50];   // Nama buku
    int stok;         // Stok buku
    Antrian* antrianPeminjam;  // Pointer ke antrian peminjam
} Buku;

// Array untuk menyimpan daftar buku
extern Buku daftarBuku[MAX_BUKU];

// Fungsi untuk membuat Buku
Buku* buatBuku(char* judul, int stok);

// Fungsi untuk menampilkan Buku
void tampilkanBuku(Buku* buku);

// Fungsi untuk menginisialisasi array buku
void inisialisasiBuku();

#endif

