#ifndef ANTRIAN_H
#define ANTRIAN_H

#include "anggota.h"

// Struktur untuk Antrian Peminjam
typedef struct Antrian {
    Anggota* anggota;  // Pointer ke anggota yang ingin meminjam
    struct Antrian* next;  // Pointer ke antrian berikutnya
} Antrian;

// Fungsi untuk membuat Antrian
Antrian* buatAntrian();

// Fungsi untuk menambah peminjam ke antrian berdasarkan prioritas
void insertPeminjam(Antrian** queue, Anggota* anggota);

// Fungsi untuk menampilkan antrian
void tampilkanAntrian(Antrian* queue);

#endif

