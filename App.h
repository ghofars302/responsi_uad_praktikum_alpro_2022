#pragma once
#include <iostream>
#include <vector>

struct Item {
    std::string ID;
    std::string Judul;
    std::string Penulis;
    int Stok;
    int Terjual;
};

class App {
    public:
        std::vector<Item> items;

        App();
        void Sort(std::vector<Item>& out);
        void Search(std::string, std::vector<Item>& out);
};
