# Fibonacci Rekursif Naif (Bahasa C)

Program C interaktif untuk menghitung nilai barisan Fibonacci suku ke-*n* menggunakan pendekatan **rekursi naif**. Program ini awalnya dibuat untuk memenuhi tugas sekolah kelas XI, namun telah disempurnakan dengan antarmuka CLI (*Command Line Interface*) sederhana, manajemen *buffer* input, dan fungsi *delay* lintas-OS.

## Fitur Utama

* **Validasi Input Ketat:** Mencegah program *crash* akibat input huruf atau simbol. Menggunakan kombinasi `fgets()` dan pengecekan manual karakter berdasarkan tabel ASCII ('0' - '9').
* **Cross-Platform Sleep (`molor`):** Menggunakan *preprocessor directives* (`#ifdef _WIN32`) agar efek *delay* program dapat berjalan universal baik di Windows maupun Linux/macOS.
* **Pembersihan Buffer Dinamis:** Menggunakan `strcspn()` untuk membuang karakter *newline* (`\n`) bawaan `fgets()` dengan aman.
* **Pencegahan Integer Overflow & Hang:** Mengunci perhitungan maksimal pada suku ke-40 untuk menghindari *infinite waiting* akibat inefisiensi rekursi murni.

## Known Issues & Technical Debt

Sebagai bentuk transparansi *software engineering*, program ini sengaja menyisakan beberapa batasan teknis:

1. **Kompleksitas Waktu $O(2^n)$:** 
   Program ini menggunakan rekursi naif tanpa memoisasi (*memoization*). Fungsi akan melakukan komputasi ulang untuk nilai yang sama berkali-kali. Menghitung suku di atas 40 tidak disarankan karena akan memakan waktu komputasi yang ekstrem. Solusi untuk produksi nyata adalah menggunakan *Dynamic Programming* (Tabulasi/Bottom-Up).
2. **Input Stream Pollution (Pencemaran Buffer):** 
   Variabel penampung input maksimal menampung 49 karakter. Jika pengguna dengan sengaja menginput lebih dari 49 karakter, fungsi `fgets()` akan berhenti mengambil data, meninggalkan sisa karakter di *stdin buffer*. Hal ini berpotensi memicu rantai pembacaan otomatis pada iterasi input selanjutnya.

## Cara Menjalankan Program

Pastikan Anda memiliki *compiler* C (seperti GCC) yang terinstal di komputer.

1. *Clone* repositori ini:
   ```bash
   git clone https://github.com/rneywjy/rekursi_naif_fibonacci.git
   ```
2. Pindah ke direktori program dan *compile*:
   ```bash
   gcc main.c -o fibonacci
   ```
3. Jalankan program:
   * **Windows:** `fibonacci.exe`
   * **Linux / macOS:** `./fibonacci`

## 👤 Author

**Roney Wijaya**
* GitHub: [@rneywjy](https://github.com/rneywjy)
