#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>
struct Queue {
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    void push(T val) {
        Node* newNode = new Node(val);
        if (empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void pop() {
        if (empty()) {
            cerr << "Kolejka jest pusta!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    T peek() const {
        if (empty()) {
            throw runtime_error("Kolejka jest pusta!");
        }
        return front->data;
    }

    bool empty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }
};

struct node {
    char chr;
    vector<node*> nextVector;
    bool isEndOfWord;

    bool isChrInNext(char checking_chr) {
        for (auto next : nextVector)
            if (checking_chr == next->chr)
                return true;
        return false;
    }

    node* getNodeInVectorByChar(char c) {
        for (auto next : nextVector)
            if (c == next->chr)
                return next;
        return nullptr;
    }

    node* addCharToVector(char new_char, bool is_end) {
        node* newNode = new node;
        newNode->chr = new_char;
        newNode->isEndOfWord = is_end;

        nextVector.push_back(newNode);

        return newNode;
    }
};

void wypisz_w_glab(node* n, string prevStr) {
    if (n == nullptr) return;

    if (n->chr != ' ')
        prevStr += n->chr;

    if (n->isEndOfWord) {
        cout << prevStr << endl;
    }

    for (node* child : n->nextVector)
        wypisz_w_glab(child, prevStr);
}

void wypisz_wszerz(node* n, string prevStr) {
    if (n == nullptr) return;

    Queue<pair<node*, string>> q;
    q.push({n, ""});

    while (!q.empty()) {
        pair<node*, string> element = q.peek();
        q.pop();

        node* current = element.first;
        string prevStr = element.second;

        string currentStr = prevStr;
        if (current->chr != ' ')
            currentStr += current->chr;

        if (current->isEndOfWord)
            cout << currentStr << endl;

        for (node* child : current->nextVector)
            q.push({child, currentStr});
    }
}

void sprawdz(node root, string word) {
    node* currentNode = &root;
    for (int i=0; i<word.length(); i++) {
        node* nextNode = currentNode->getNodeInVectorByChar(word[i]);
        if (nextNode == nullptr) {
            cout << "Brak słowa “" << word << "” w słowniku";
            return;
        } else {
            currentNode = nextNode;
        }
    }
    if (currentNode->isEndOfWord)
        cout << "Słowo “" << word << "” występuje w słowniku";
    else
        cout << "Brak słowa “" << word << "” w słowniku";
}

int main(int argc, char* argv[]) {
    string line;
    ifstream file("slownik_11.txt");
    if(!file.is_open()) return -1;

    node root;
    root.chr = ' ';

    while(getline(file, line)) {
        node* currentNode = &root;
        string lin;
        for (int i=0; i<line.length(); i++) {
            node* nextNode = currentNode->getNodeInVectorByChar(line[i]);
            lin += line[i];
            if (nextNode == nullptr) {
                node* newNode = currentNode->addCharToVector(line[i], (i==line.length()-1));
                currentNode = newNode;
            } else {
                currentNode = nextNode;
            }
        }
    }

    return 0;
}