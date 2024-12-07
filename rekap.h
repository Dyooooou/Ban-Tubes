#ifndef REKAP_H
#define REKAP_H


void CatatTransaksi(int PilihanFilm, int Lokasi, int Jadwal, int Harga);
void Rekapitulasi();
int ValidasiTgl(const char* Tanggal);
void InputPeriode(char* PeriodeAwal, char* PeriodeAkhir);

#endif

