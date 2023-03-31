#include <iostream>
#include "tree.h"
#include <fstream>
#include "st2.h"


int main(){
    std::ifstream input;
    input.open("file.txt");
    stack *st = new stack;
    tree *t = BuildTree();
    std::cout << vuvod(t, &st);
    std::cout << "\n";
    vuvod(st);
}