#include "buku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array untuk menyimpan daftar buku
Buku daftarBuku[MAX_BUKU];

// Fungsi untuk membuat Buku
Buku* buatBuku(char* judul, int stok) {
    for (int i = 0; i < MAX_BUKU; i++) {
        if (strlen(daftarBuku[i].judul) == 0) {  // Cari tempat kosong
            strcpy(daftarBuku[i].judul, judul);
            daftarBuku[i].stok = stok;
            daftarBuku[i].antrianPeminjam = NULL;
            return &daftarBuku[i];
        }
    }
    return NULL;  // Jika array penuh
}

// Fungsi untuk menampilkan Buku
void tampilkanBuku(Buku* buku) {
    printf("Judul Buku: %s\n", buku->judul);
    printf("Stok Buku: %d\n", buku->stok);
}

// Fungsi untuk menginisialisasi array buku
void inisialisasiBuku() {
    for (int i = 0; i < MAX_BUKU; i++) {
        daftarBuku[i].judul[0] = '\0';  // Inisialisasi judul kosong
        daftarBuku[i].stok = 0;
        daftarBuku[i].antrianPeminjam = NULL;
    }
}

