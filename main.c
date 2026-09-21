/*
    Program untuk memenuhi tugas sekolah. Program ini mengimplementasikan konsep rekursi untuk mencari barisan fibonacci suku ke-n dengan batas n tidak lebih dari 92 karena akan menyebabkan integer overflow. Meskipun bisa menghitung hingga suku ke-92, namun itu tidak disarankan karena program ini hanya menerapkan rekursi naif, yaitu fungsi rekursif yang memanggil dirinya sendiri secara langsung tanpa optimalisasi, sehingga sering kali melakukan perhitungan ulang untuk data yang sama secara berulang-ulang, menyebabkan sorotnya efisiensi. Demikian membutuhkan waktu yang lama untuk menghitung suku di atas 44. Sehingga penulis membatasi sampai suku ke 40 saja alih-alih 92 meskipun bisa dihitung jika memakan waktu berhari-hari mungkin. Selain itu, program ini juga dilengkapi dengan sistem pengecekan input yang tidak memperbolehkan user untuk memasukkan karakter apa pun selain angka.
    
    Alternatif metode yang bisa digunakan adalah menggunakan konsep dynamic programming yang tidak diterapkan di program ini. Penulis mengatakan ini hanya sekedar untuk memberitahu bahwa ada metode lain yang jauh jauh lebih efisien daripada penerapan rekursi naif.

    Program ini memiliki kelemahan. Salah satunya adalah tidak melakukan input validation jika input user melebihi 49 karakter, di mana itu adalah jumlah karakter maksimum yang bisa ditampung oleh variabel array of character input. Akibatnya, jika user iseng memasukkan karakter yang lebih dari 49 karakter, maka fgets() akan berhenti mengambil dari input buffer dan sisanya akan tetap tertinggal di input buffer. Hal ini akan menyebabkan yang namanya Input Stream Pollution (Pencemaran Aliran Input), yaitu ketika sisa karakter yang tertinggal akan menyebabkan efek domino dan akan dibaca oleh fungsi input selanjutnya tanpa menunggu user memasukkan input.
    
    Author: Roney Wijaya
    Github: rneywjy
*/

#include <stdio.h>
#include <string.h> // Untuk strlen()
#include <stdlib.h> // Untuk atoi()

// Jika OS Windows maka include header window, selain itu include header unistd
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Membuat fungsi sleep yang universal di OS Windows maupun MacOS/Linux
void molor(int milidetik){
    #ifdef _WIN32
        Sleep(milidetik);
    #else
        sleep(milidetik/1000);
    #endif
}

// Function prototype
long long int fib(int n);
int cekAngka(char karakter);
int validasiInput(char input[]);

int main(){
    // Insiialisasi variabel yang dibutuhkan
    int n = 0;
    char input[50] = {0};
    long long int hasil = 0;

    // User interface sederhana dan identitas author
    printf("***** FIBONACCI *****\n");
    printf("Nama  : Roney Wijaya\n");
    printf("Kelas : XI-A\n");
    printf("Absen : 38\n");
    printf("*********************\n\n");
    molor(1000);

    // Looping untuk mendapatkan input yang valid
    do {
        printf("Mau hitung suku ke berapa?: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // Jika input tidak valid maka continue (kembali ke atas)
        if (validasiInput(input) == 0) {
            printf("\nTolong masukkan input yang valid!\n\n");
            molor(1000);
            continue;
        }

        // Jika berhasil melewati validasiInput, maka ubah ke integer kemudian setor ke intInput
        n = atoi(input);

        // Pengecekan jika yang dimasukkan adalah 0 maka peringatkan user
        if (n == 0){
            printf("\nTolong masukkan angka positif saja!\n\n");
            molor(1000);
            continue;
        // Long long int hanya dapat menampung barisan fibonacci hingga suku ke 92. Selebihnya akan mengalami integer overflow. Sehingga harus dihindari. Makanya peringati user dan continue (balik ke atas)
        } else if (n > 40) {
            printf("\nMaaf, program akan menghitung dengan sangat lambat jika suku yang dihitung di atas 40 karena menggunakan rekursi naif!\n\n");
            molor(1000);
            continue;
        }

        // Jika user input berhasil melewati semua pengecekan, maka keluar dari loop
        break;
    } while (1);

    // Menghitung barisan fibonacci suku ke-n dan disimpan ke hasil
    hasil = fib(n);

    // Mencetak hasil
    printf("\nBarisan Fibonacci suku ke-%d adalah %lld\n", n, hasil);

    return 0;
}

// Fungsi fibonacci dengan konsep rekursi
long long int fib(int n){
    if (n == 1 || n == 2) { return 1; }
    return fib(n-2) + fib(n-1);
}

// Fungsi untuk mengecek suatu char berada dalam rentang kode ASCII '0' sampai '9' atau tidak
int cekAngka(char karakter){
    if (karakter >= '0' && karakter <= '9'){
        return 1;
    } else { return 0; }
}

// Fungsi untuk looping array of char untuk mengecek setiap charnya terdapat karakter selain angka atau tidak dengan memanfaatkan fungsi cekAngka
int validasiInput(char input[]){
    int panjang = strlen(input);
    if (panjang == 0) { return 0; }
    for (int i = 0; i < panjang; i++){
        if (cekAngka(input[i]) == 1){
            continue;
        } else { return 0; }
    }
    return 1;
}
