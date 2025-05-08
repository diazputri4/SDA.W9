#include "antrian.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membuat Antrian
Antrian* buatAntrian() {
    return NULL;
}

// Fungsi untuk menambah peminjam ke antrian berdasarkan prioritas
void insertPeminjam(Antrian** queue, Anggota* anggota) {
    Antrian* newPeminjam = (Antrian*)malloc(sizeof(Antrian));
    newPeminjam->anggota = anggota;
    newPeminjam->next = NULL;
    newPeminjam->prev = NULL;

    if (*queue == NULL) {
        *queue = newPeminjam;
    } else {
        Antrian* temp = *queue;
        // Menambah peminjam ke antrian (urutkan berdasarkan prioritas)
        while (temp->next != NULL && temp->next->anggota->prioritas <= anggota->prioritas) {
            temp = temp->next;
        }
        newPeminjam->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newPeminjam;
        }
        temp->next = newPeminjam;
        newPeminjam->prev = temp;
    }
}

// Fungsi untuk menampilkan antrian
void tampilkanAntrian(Antrian* queue) {
    Antrian* temp = queue;
    while (temp != NULL) {
        printf("Peminjam: %s (Prioritas: %d)\n", temp->anggota->nama, temp->anggota->prioritas);
        temp = temp->next;
    }
}

