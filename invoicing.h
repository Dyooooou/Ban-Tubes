// HEADER INVOICING //

#ifndef INVOICING_H
#define INVOICING_H

extern int harga;

void invoice_film(int pil_film, int pil_lokasi, int pil_jadwal, int pil_kursi, char* atasnama);
int confirmpembayaran();
int proses_bayar (int pil_film, int pil_lokasi);
void tiket_film(int pil_film, int pil_lokasi, int pil_jadwal, int pil_kursi, char* atasnama);

#endif
