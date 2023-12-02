#include <iostream>

const int N = 100;

int length(char text[N]) {
    int i = 0;
    while (text[i] != '\0') {
        i++;
    }
    return i;
}

void insert(char text[N], int index, int data) {
    char tmp;

    int len = length(text);

    for (int i = len; i > index; i--) {
        text[i] = text[i-1];
    }
    text[index] = data;
    text[len+1] = '\0';
}

void pop(char text[N], int index) {

    int len = length(text);
    for (int i = index; i < len; i++) {
        text[i] = text[i+1];
    }
}

int get_rand(int max) {
    return std::rand() % (96) + 32;
}


char encoded_letter(char letter, int key) {
    if (letter >= 0 && letter <= 31) {
        return letter;
    }
    bool flag = false;

    key = (key >= 128 ? key - 128*(key / 128): key);
    key = (key <= -128 ? key + 128*(key / 128): key);

    if (key < 0) {
       key += 128;
       flag = true;
    }

    letter = (letter + key) % 128;
    if (letter >= 0 && letter <= 31) {
        if (flag) {
            letter += 128 - 32;
        } else {
            letter += 32;
        }
    }
    
    return letter;
}

char decoded_letter(char letter, int key) {
    return encoded_letter(letter, -key);
}

void print(char text[N]) {
    for (int i = 0; i < length(text); i++) {
        std::cout << text[i];
    }
    std::cout << '\n';
}

// let each second symbol be random

void encode(char text[N], int key) {

    int len = length(text);
    for (int i = 1; i < len; i++) {
        insert(text, i*2-1, (char)get_rand(key));
    }
    

    for (int i = 0; i < length(text); i++) {
        text[i] = encoded_letter(text[i], key);
    }
}

void decode(char text[N], int key) {

    int len = length(text);
    for (int i = len - 2; i > 0; i -= 2) {
        pop(text, i);
    }

    for (int i = 0; i < length(text); i++) {
        text[i] = decoded_letter(text[i], key);
    }
}

int main() {
    char text[N] = "asdfghjtk";
    // char text[N] = "3Y%86[8e)c7q8\#^)[7";

    int key = 40;

    decode(text, key);

}