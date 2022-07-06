#include "App.h"
#include <iomanip>

int main() {
    bool IsLoop = true;

    std::cout << "Aplikasi search dan sort stok buku" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "1. Tampilkan \t Tampilkan list buku yang belum di sort" << std::endl;
    std::cout << "2. Sort \t Sortir list buku stok dan terjual nya" << std::endl;
    std::cout << "3. Search \t Cari buku berdasarkan nama penulisnya" << std::endl;
    std::cout << "4. Exit \t Self explainitory" << std::endl;
    std::cout << "==========================================================" << std::endl;

    App* app = new App();
    
    do {
        std::cout << "Pilih menu: ";
        int pilihan; std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                std::cout << "==========================================================" << std::endl;
                std::cout << "ID\tJudul\t\tPenulis\tStok\tTerjual" << std::endl;
                std::cout << "==========================================================" << std::endl;
                for (int i = 0; i < app->items.size(); i++) {
                    std::cout << std::setw(5) << app->items[i].ID << std::setw(20) << app->items[i].Judul << std::setw(20) << app->items[i].Penulis << std::setw(5) << app->items[i].Stok << std::setw(5) << app->items[i].Terjual << std::endl;
                }
                std::cout << "==========================================================" << std::endl;
                break;
            }

            case 2: {
                std::vector<Item> items;
                app->Sort(items);

                std::cout << "==========================================================" << std::endl;
                std::cout << "ID\tJudul\t\tPenulis\tStok\tTerjual" << std::endl;
                std::cout << "==========================================================" << std::endl;
                for (int i = 0; i < items.size(); i++) {
                    std::cout << items[i].ID << "\t" << items[i].Judul << "\t" << items[i].Penulis << "\t" << items[i].Stok << "\t" << items[i].Terjual << std::endl;
                }
                std::cout << "==========================================================" << std::endl;
                break;
            }

            case 3: {
                std::string nameToSearch;
                std::cout << "Masukkan nama buku yang dicari: "; std::cin >> nameToSearch;
                std::vector<Item> items;
                app->Search(nameToSearch, items);

                if (!items.empty()) {
                    std::cout << "Search keyword: " << nameToSearch << std::endl;
                    std::cout << "Search results: " << std::endl;
                    for (int i = 0; i < items.size(); i++) {
                        std::cout << "- \t ID \t\t: " << items[i].ID << std::endl;
                        std::cout << "\t Judul \t\t: " << items[i].Judul << std::endl;
                        std::cout << "\t Penulis \t: " << items[i].Penulis << std::endl;
                        std::cout << "\t Stok \t\t: " << items[i].Stok << std::endl;
                        std::cout << "\t Terjual \t: " << items[i].Terjual << std::endl;
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "Tidak ditemukan buku dengan nama penulis: " << nameToSearch << std::endl;
                }
                break;
            }

            case 4: {
                std::cout << "Terima kasih telah menggunakan program ini" << std::endl;
                IsLoop = false;
                break;
            }

            default: {
                std::cout << "Menu tidak ada" << std::endl;
                break;
            }
        }

        std::cout << std::endl;
    } while (IsLoop);

    return 0;
}
