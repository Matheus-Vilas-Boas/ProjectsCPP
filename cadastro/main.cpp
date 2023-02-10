#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Item {
    string name;
    float value;
    time_t date;
};

vector<Item> items;

void addItem() {
    Item item;
    cout << "Digite o nome do item: ";
    cin >> item.name;
    cout << "Digite o valor do item: ";
    cin >> item.value;
    item.date = time(0);

    items.push_back(item);
    cout << "Item adicionado com sucesso!" << endl;
}

void viewItems() {
    if (items.size() == 0) {
        cout << "Não há itens para exibir." << endl;
    } else {
        cout << "Itens cadastrados:" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].name << " - R$" << items[i].value << " - " << ctime(&items[i].date);
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Adicionar item" << endl;
        cout << "2. Ver itens" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}
