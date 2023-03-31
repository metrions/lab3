#pragma once
#include "st2.h"
#include <fstream>
#include <iostream>

struct tree{
    char el;
    tree *right, *left;

};

tree *BuildTree()
{
    char c = 0;
    scanf("%c", &c);
    switch(c)
    {
        case '(': {
            tree *t = new tree;
            scanf("%c", &c);
            t->el = c;
            t->left = BuildTree();
            t->right = BuildTree();
            //std::cout << t->el;
            scanf("%c", &c);
            return t;
    }
        case ',': return BuildTree();
        case '0': return NULL;
        default: return BuildTree();
    }
    return NULL;
}

int findtree(tree *t, char x){
    int f = 0;
    if (t->el == x){
        return 1;
    }
    if (f!= 1 && t->right != NULL && t->left != NULL){
        if (t->left != NULL){
            t = t->left;
            f = findtree(t, x);}
        if (t->right != NULL){
            t = t->right;
            f = findtree(t, x);
        }
    }
    return f;
}

int vuvod(tree *t, stack **s){
    int f = 0;
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
    return f;
}
