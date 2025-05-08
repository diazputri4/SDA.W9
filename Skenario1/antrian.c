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

    if (*queue == NULL) {
        *queue = newPeminjam;
    } else {
        Antrian* temp = *queue;
        if (temp->anggota->prioritas > anggota->prioritas) {
            newPeminjam->next = temp;
            *queue = newPeminjam;
        } else {
            while (temp->next != NULL && temp->next->anggota->prioritas <= anggota->prioritas) {
                temp = temp->next;
            }
            newPeminjam->next = temp->next;
            temp->next = newPeminjam;
        }
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

