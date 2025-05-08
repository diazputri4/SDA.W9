#include "peminjaman.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk melakukan peminjaman buku
void prosesPeminjaman(Buku* buku) {
    if (buku->stok > 0) {
        // Cek antrian peminjam berdasarkan prioritas
        Antrian* peminjam = buku->antrianPeminjam;
        if (peminjam != NULL) {
            printf("Peminjaman Buku: %s kepada %s\n", buku->judul, peminjam->anggota->nama);
            buku->stok--; // Kurangi stok buku
            // Hapus peminjam dari antrian (karena sudah meminjam buku)
            buku->antrianPeminjam = peminjam->next;
            free(peminjam);
        }
    } else {
        printf("Stok buku %s tidak tersedia!\n", buku->judul);
    }
}

