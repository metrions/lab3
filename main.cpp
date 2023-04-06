#include <iostream>
#include "tree.h"
#include <fstream>
#include "st2.h"

using namespace std;
int main(){
    stack *st = new stack;
    ifstream input;
    input.open("file.txt");

    tree *t = BuildTree(&input);
    std::cout << vuvod_v1(t, &st) << std::endl;
    vuvod_st(st);
}