#include <iostream>
using namespace std;

struct node {
    char value;
    node* left = nullptr;
    node* right = nullptr;
};

string findNawias(string wholeStr, int startIndex) {
    int howMany = 0;
    string newString = "";
    for (int i=startIndex; i<wholeStr.length(); i++) {
        newString += wholeStr[i];
        if (i != startIndex && wholeStr[i] == '(')
            howMany++;
        else if (wholeStr[i] == ')') {
            if (howMany == 0)
                return newString;
            else
                howMany--;
        }
    }
}

string findNawiasOdKonca(string wholeStr, int startIndex) {
    int howMany = 0;
    string newString = "";
    for (int i=startIndex; i>0; i--) {
        newString = wholeStr[i] + newString;
        if (i != startIndex && wholeStr[i] == ')')
            howMany++;
        else if (wholeStr[i] == '(') {
            if (howMany == 0)
                return newString;
            else
                howMany--;
        }
    }
}

node* buildTree(string nawias) {
    node* newNode = new node;
    newNode->value = nawias[1];
    newNode->left = new node;
    newNode->right = new node;

    if (nawias[4] != '(') {
        newNode->left->value = nawias[4];
    } else {
        string newNawias = findNawias(nawias, 4);
        newNode->left = buildTree(newNawias);
    }

    if (nawias[nawias.length()-2] != ')') {
        newNode->right->value = nawias[nawias.length()-2];
    } else {
        string newNawias = findNawiasOdKonca(nawias, nawias.length()-2);
        newNode->right = buildTree(newNawias);
    }

    return newNode;
}

void in_order(node* n) {
    bool hasChildren = (n->left != nullptr || n->right != nullptr);
    if (hasChildren)
        cout << "(";

    if (n->left != nullptr)
        in_order(n->left);

    string space = (n->value == '*' || n->value == '+' || n->value == '-' || n->value == '/') ? " " : "";
    cout << space << n->value << space;

    if (n->right != nullptr)
        in_order(n->right);

    if (hasChildren)
        cout << ")";
}

void pre_order(node* n) {
    cout << n->value << " ";

    if (n->left != nullptr)
        pre_order(n->left);

    if (n->right != nullptr)
        pre_order(n->right);
}

void post_order(node* n) {
    if (n->left != nullptr)
        post_order(n->left);

    if (n->right != nullptr)
        post_order(n->right);

    cout << n->value << " ";
}

int main(int argc, char* argv[]) {
    string str; // = "(+, (*, 1, (-, 2, 3)), (+, 4, 5))";
    getline(cin, str);

    node* n = buildTree(str);

    cout << "\nIn-order - notacja wrostkowa\n";
    in_order(n);

    cout << "\nPre-order - notacja polska\n";
    pre_order(n);

    cout << "\nPost-order - odwrotna notacja polska\n";
    post_order(n);

    return 0;
}