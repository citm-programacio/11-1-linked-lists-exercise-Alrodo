// ConsoleApplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <iostream>

class List {
public:
    List();
    ~List();

    void push_back(const int& value);
    void insert(unsigned int position, const int& value);
    void print() const;

private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int num_elems = 0;
};

List::List() : first(nullptr), last(nullptr), num_elems(0) {}

List::~List() {
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}

void List::push_back(const int& value) {
    Node* newNode = new Node(value);
    if (last == nullptr) {
        first = last = newNode;
    }
    else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    num_elems++;
}

void List::insert(unsigned int position, const int& value) {
    if (position == 0) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        num_elems++;
    }
    else if (position >= num_elems) {
        push_back(value);
    }
    else {
        Node* current = first;
        unsigned int index = 0;
        while (index < position) {
            current = current->next;
            index++;
        }
        Node* newNode = new Node(value);
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        num_elems++;
    }
}


void List::print() const {
    Node* current = first;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    List myList;
    myList.push_back(1);
    myList.print();
    myList.insert(3, 0);
    myList.print();
    myList.insert(2, 2);
    myList.print();
    myList.insert(1, 3);
    myList.print();
    myList.insert(0, 4);
    myList.print(); 

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
