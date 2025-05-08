#ifndef ANGGOTA_H
#define ANGGOTA_H

// Struktur untuk Anggota
typedef struct Anggota {
    char nama[50];
    int prioritas;  // Prioritas (1: Dosen, 2: Mahasiswa, 3: Umum)
} Anggota;

// Fungsi untuk membuat Anggota
Anggota* buatAnggota(char* nama, int prioritas);

#endif

