#include <stdio.h>
#include "buku.h"
#include "antrian.h"
#include "anggota.h"
#include "peminjaman.h"
#include "pengembalian.h"

void tampilkanMenu() {
    printf("\n======== Menu ========\n");
    printf("1. Insert Buku\n");
    printf("2. Insert Anggota\n");
    printf("3. Peminjaman Buku\n");
    printf("4. Pengembalian Buku\n");
    printf("5. Tampilkan Antrian Buku\n");
    printf("6. Keluar\n");
    printf("======================\n");
    printf("Pilih opsi (1-6): ");
}

int main() {
    // Inisialisasi array buku
    inisialisasiBuku();
    
    int pilihan;
    int stok;
    char judul[50];
    char nama[50];
    int prioritas;

    while (1) {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: // Insert Buku
                printf("Masukkan judul buku: ");
                scanf("%s", judul);
                printf("Masukkan stok buku: ");
                scanf("%d", &stok);
                Buku* buku = buatBuku(judul, stok);
                if (buku) {
                    printf("Buku %s dengan stok %d berhasil ditambahkan.\n", judul, stok);
                } else {
                    printf("Gagal menambah buku. Array penuh.\n");
                }
                break;

            case 2: // Insert Anggota
                printf("Masukkan nama anggota: ");
                scanf("%s", nama);
                printf("Masukkan prioritas (1: Dosen, 2: Mahasiswa, 3: Umum): ");
                scanf("%d", &prioritas);
                Anggota* anggota = buatAnggota(nama, prioritas);

                printf("Pilih buku yang ingin dipinjam (1: %s, 2: %s): ", daftarBuku[0].judul, daftarBuku[1].judul);
                int pilihBuku;
                scanf("%d", &pilihBuku);

                if (pilihBuku == 1) {
                    insertPeminjam(&daftarBuku[0].antrianPeminjam, anggota);
                } else if (pilihBuku == 2) {
                    insertPeminjam(&daftarBuku[1].antrianPeminjam, anggota);
                }
                printf("Anggota %s dengan prioritas %d berhasil dimasukkan ke antrian.\n", nama, prioritas);
                break;

            case 3: // Peminjaman Buku
                printf("Pilih buku untuk peminjaman (1: %s, 2: %s): ", daftarBuku[0].judul, daftarBuku[1].judul);
                int pilihBukuPeminjaman;
                scanf("%d", &pilihBukuPeminjaman);

                if (pilihBukuPeminjaman == 1) {
                    prosesPeminjaman(&daftarBuku[0]);
                } else if (pilihBukuPeminjaman == 2) {
                    prosesPeminjaman(&daftarBuku[1]);
                }
                break;

            case 4: // Pengembalian Buku
                printf("Pilih buku yang dikembalikan (1: %s, 2: %s): ", daftarBuku[0].judul, daftarBuku[1].judul);
                int pilihBukuPengembalian;
                scanf("%d", &pilihBukuPengembalian);

                if (pilihBukuPengembalian == 1) {
                    prosesPengembalian(&daftarBuku[0]);
                } else if (pilihBukuPengembalian == 2) {
                    prosesPengembalian(&daftarBuku[1]);
                }
                break;

            case 5: // Tampilkan Antrian Buku
                printf("Pilih buku yang ingin ditampilkan antriannya (1: %s, 2: %s): ", daftarBuku[0].judul, daftarBuku[1].judul);
                int pilihBukuTampil;
                scanf("%d", &pilihBukuTampil);

                if (pilihBukuTampil == 1) {
                    printf("Antrian Peminjam Buku %s:\n", daftarBuku[0].judul);
                    tampilkanAntrian(daftarBuku[0].antrianPeminjam);
                } else if (pilihBukuTampil == 2) {
                    printf("Antrian Peminjam Buku %s:\n", daftarBuku[1].judul);
                    tampilkanAntrian(daftarBuku[1].antrianPeminjam);
                }
                break;

            case 6: // Keluar
                printf("Terima kasih! Keluar dari program.\n");
                return 0;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    }

    return 0;
}

