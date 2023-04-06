#pragma once
#include "st2.h"
#include <fstream>
#include <iostream>

struct tree{
    char el;
    tree *right, *left;

};
using namespace std;

tree *BuildTree(ifstream *a)
{  
    while (!(*a).eof()){
    char c;
    (*a) >> c;
    switch(c)
    {
        case '(': {
            tree *t = new tree;
            (*a) >> c;
            t->el = c;
            t->left = BuildTree(a);
            t->right = BuildTree(a);
            //std::cout << t->el;
            (*a) >> c;
            return t;
    }
        case ',': return BuildTree(a);
        case '0': return NULL;
        default: return BuildTree(a);
    }
    return NULL;}
    return NULL;
}

int vuvod_v1(tree *t, stack **s){
    int f = 0;
    if (t->right == NULL && t->left == NULL){
        f = f + 1;
        *s = push(t->el, *s);
        return f;
    }
    if (t->left != NULL){
        f = f + vuvod_v1(t->left, s);
    }
    if (t->right != NULL){
        f = f + vuvod_v1(t->right, s);
    }
    return f;
}

int vuvod(tree *t, stack **s){
    int f = 0;
    if (t == NULL){
        return 0;
    }
    if (t->right == NULL && t->left == NULL){
        f = f + 1;
        *s = push(t->el, *s);
        return f;
    }
    if (t->left != NULL){
        f = f + vuvod(t->left, s);
    }
    if (t->right != NULL){
        f = f + vuvod(t->right, s);
    }
    *s = push(t->el, *s);
    return f;
}

