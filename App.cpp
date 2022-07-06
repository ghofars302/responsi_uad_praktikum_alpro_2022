#include "App.h"
#include <algorithm>

App::App() {
    items = {
        { "AF110", "Bumi Manusia", "P Ananta Toer", 24, 55 },
        { "AB101", "Luka Citra", "Valerie Patkar", 15, 3 },
        { "AC222", "Perahu Kertas", "Dewi Lestari", 11, 44 },
        { "AF111", "Rumah Kaca", "P Ananta Toer", 20, 3 },
        { "AC201", "Filosofi Kopi", "Dewi Lestari", 30, 21 },
    };
}

void App::Sort(std::vector<Item>& out) {
    std::copy(items.begin(), items.end(), std::back_inserter(out));

    std::sort(out.begin(), out.end(), [](Item a, Item b) {
        return a.Stok > b.Stok;
    });
}

void App::Search(std::string nameToSearch, std::vector<Item>& out) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].Penulis.find(nameToSearch) != std::string::npos) {
            out.push_back(items[i]);
        }
    }
}
