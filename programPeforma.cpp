#include <iostream>
using namespace std;

struct DataPemain{
    int NoPunggung;
    string NamaPemain;
    string PosisiPemain;
    int Gol;
    int Assist;
};

const int MAX = 15;
DataPemain Dpemain[MAX];

// Awal fungsi
int HitungPeforma(int x, int y){
    int TotalPoint = x * 4 + y * 2;
    return TotalPoint;
}
// Akhir fungsi

// Awal prosedur
void HasilSearching(int jumlah, int key){
    for(int i = 1; i < jumlah; i++){
        DataPemain key = Dpemain[i];
        int j = i - 1;

        while(j >= 0 && Dpemain[j].NoPunggung < key.NoPunggung){
            Dpemain[j + 1] = Dpemain[j];
            j--;
        }
        Dpemain[j + 1] = key;
    }
    
    int left = 0, right = jumlah - 1;
    int posisi = -1;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(Dpemain[mid].NoPunggung == key){
            posisi = mid;
            break;
        } else if (key < Dpemain[mid].NoPunggung){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(posisi != -1){
        cout << "Data ditemukan pada indeks ke-" << posisi << endl;
    } else {
        cout << "Data tidak ditemukan";
    }
}

void HasilSortingGol(int jumlah){
    for(int i = 1; i < jumlah; i++){
        DataPemain key = Dpemain[i];
        int j = i - 1;
                
        while(j >= 0 && Dpemain[j].Gol < key.Gol){
            Dpemain[j+1] = Dpemain[j];
            j--;
        }
        Dpemain[j + 1] = key;
    }
}

void HasilSortingPeforma(int jumlah){
    for(int i = 1; i < jumlah; i++){
        DataPemain key = Dpemain[i];
        int j = i - 1;
        int keyPeforma = HitungPeforma(key.Gol, key.Assist);
                
        while(j >= 0 && HitungPeforma(Dpemain[j].Gol, Dpemain[j].Assist) < keyPeforma){
            Dpemain[j+1] = Dpemain[j];
            j--;
        }
        Dpemain[j + 1] = key;
    }
}

void TampilKategoriPeforma(int total){
    if (total > 20){
        cout << "--- Pemain memiliki peforma yang bagus ---" << endl;
    } else if (total >= 10){
        cout << "--- Pemain memiliki peforma yang cukup ---" << endl;
    } else {
        cout << "--- Pemain memiliki peforma yang buruk ---" << endl;
    }
}

void TampilData(int jumlah){
    for (int i = 0; i < jumlah; i++){
        int peforma = HitungPeforma(Dpemain[i].Gol, Dpemain[i].Assist);
        cout << "No punggung pemain ke-" << i + 1 << "    : " << Dpemain[i].NoPunggung << endl;
        cout << "Nama Pemain                                : " << Dpemain[i].NamaPemain << endl;
        cout << "Posisi Pemain                              : " << Dpemain[i].PosisiPemain << endl;
        cout << "Total cetak gol                            : " << Dpemain[i].Gol << endl;
        cout << "Total cetak assist                         : " << Dpemain[i].Assist << endl;
        cout << "Nilai peforma pemain ialah                 : " << peforma << endl;
        TampilKategoriPeforma(peforma);
        cout << endl;
    }
}
// Akhir prosedur

int main(){
    int SizeKlub;
    int pilihan;

    cout << "Selamat Datang di Program Menghitung Peforma Pemain !!!" << endl;
    cout << "-------------------------------------------------------" << endl;
    do {
        cout << "Masukkan jumlah pemain: ";
        cin >> SizeKlub;

        if (SizeKlub > MAX) {
            cout << "Jumlah pemain maksimal 15!" << endl;
        }
    } while (SizeKlub > MAX);

    for (int i = 0; i < SizeKlub; i++){
        bool duplikat = true;

        while (duplikat) {
            duplikat = false;
            cout << "Masukan No punggung pemain ke-" << i + 1 << " : ";
            cin >> Dpemain[i].NoPunggung;

            for (int j = 0; j < i; j++){
                if (Dpemain[i].NoPunggung == Dpemain[j].NoPunggung){
                    cout << "No punggung sudah dipakai, silahkan input ulang!" << endl;
                    duplikat = true;
                    break;
                }
            }
        }

        cout << "Masukan nama pemain             : ";
        cin.ignore();
        getline(cin, Dpemain[i].NamaPemain);
        cout << "Masukan posisi pemain           : ";
        cin >> Dpemain[i].PosisiPemain;
        cout << "Masukan jumlah gol              : ";
        cin >> Dpemain[i].Gol;
        cout << "Masukan jumlah assist           : ";
        cin >> Dpemain[i].Assist;
        cout << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    do {
        cout << "Ketik 1 untuk menampilkan data pemain" << endl;
        cout << "Ketik 2 untuk pengurutan berdasarkan nilai peforma" << endl;
        cout << "Ketik 3 untuk pengurutan berdasarkan cetak gol" << endl;
        cout << "Ketik 4 untuk pencarian data pemain" << endl;
        cout << "Ketik 5 untuk keluar program" << endl;
        cout << "Silahkan untuk memilih salah satu opsi yang tersedia di atas : ";
        cin >> pilihan;
        cout << endl;

        if(pilihan == 1){
            cout << "---------- Tampilkan data pemain ----------" << endl;
            for (int i = 0; i < SizeKlub; i++){
                int peforma = HitungPeforma(Dpemain[i].Gol, Dpemain[i].Assist);
                cout << "No punggung pemain ke-" << i + 1 << "     : " << Dpemain[i].NoPunggung << endl;
                cout << "Nama pemain : " << Dpemain[i].NamaPemain << endl;
                cout << "Posisi pemain : " << Dpemain[i].PosisiPemain << endl;
                cout << "Total cetak goal : " << Dpemain[i].Gol << endl;
                cout << "Total cetak assist : " << Dpemain[i].Assist << endl;
                cout << "Nilai peforma pemain ialah : " << peforma << endl;
                TampilKategoriPeforma(peforma);
                cout << endl;
            }
        } else if (pilihan == 2) {
            cout << "---------- Pengurutan nilai peforma pemain klub anda dari tertinggi hingga terendah ----------" << endl;
            HasilSortingPeforma(SizeKlub);
            for(int j = 0; j < SizeKlub; j++){
                cout << "Posisi ke-" << j + 1 << " "<< Dpemain[j].NamaPemain << " Dengan peforma : " << HitungPeforma(Dpemain[j].Gol, Dpemain[j].Assist) << endl;
            }
            cout << endl;
        } else if (pilihan == 3){
            cout << "---------- Pengurutan pemain dengan gol terbanyak ----------" << endl;
            HasilSortingGol(SizeKlub);
            for (int j = 0; j < SizeKlub; j++){
                cout << "Posisi ke-" << j + 1 << " "<< Dpemain[j].NamaPemain << " Dengan gol : " << Dpemain[j].Gol << endl;
            }
            cout << endl;
        } else if (pilihan == 4){
            cout << "---------- Pencarian berdasarkan No punggung pemain ----------" << endl;
            int key;
            cout << "Masukan No punggung pemain yang anda ingin cari : ";
            cin >> key;

            HasilSearching(SizeKlub, key);
            cout << endl;
        } else if(pilihan == 5){
            break; 
        } else {
            cout << "Silahkan pilih kembali dari 5 opsi tersebut" << endl;
        }
    } while (true);

    cout << "---------- Program selesai terimakasih ----------";    
    return 0;
}