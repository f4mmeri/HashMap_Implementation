#include <bits/stdc++.h>
using namespace std;

template <typename data_type>
struct Stack {

    struct StackNode {
        data_type data;
        StackNode* next;

        StackNode(data_type data) : data(data), next(nullptr) {}
    };

    StackNode* _top;
    int _size;

    Stack() {
        _top = nullptr;
        _size = 0;
    }

    // evita copias superficiales (shallow copy) que compartirian punteros
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        while (!empty()) pop();
    }

    void push(data_type value) {
        StackNode* new_node = new StackNode(value);
        new_node -> next = _top;
        _top = new_node;
        ++_size;
    }

    void pop() {
        if (_top != nullptr) {
            StackNode* temp = _top;
            _top = _top -> next;
            delete temp;
            --_size;
        }
    }

    data_type top() {
        return _top == nullptr ? data_type() : _top -> data;
    }

    bool empty() {
        return _top == nullptr;
    }

    int size() const {
        return _size;
    }
};

bool match(char open, char close) {
    if (open == '(') return close == ')';
    if (open == '[') return close == ']';
    return close == '}';
}

bool balanceado(const string& s) {
    Stack<char> pila;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pila.empty() || !match(pila.top(), c)) {
                return false;
            }
            pila.pop();
        }
    }
    return pila.empty();
}

 
