#include "pengembalian.h"
#include <stdio.h>

// Fungsi untuk mengembalikan buku
void prosesPengembalian(Buku* buku) {
    buku->stok++; // Tambah stok buku setelah dikembalikan
    printf("Buku %s telah dikembalikan.\n", buku->judul);

    // Cek antrian peminjam berikutnya berdasarkan prioritas
    if (buku->antrianPeminjam != NULL) {
        printf("Peminjam berikutnya yang akan menerima buku: %s\n", buku->antrianPeminjam->anggota->nama);
        // Proses peminjaman buku untuk peminjam berikutnya
        prosesPeminjaman(buku);
    } else {
        printf("Tidak ada peminjam yang menunggu untuk buku %s.\n", buku->judul);
    }
}

