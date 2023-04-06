#include <iostream>
#include "tree.h"
#include <fstream>
#include "st2.h"

using namespace std;

stack *create_t(tree *t);
void obh_r(tree **t, stack **s);
tree *sort_tree(tree *t);
void print_Tree(tree * p,int level);

int main(){
    ifstream input;
    input.open("file.txt");
    tree *s = BuildTree(&input);
    stack *t = new stack;
    vuvod(s, &t);
    s = sort_tree(s);
    cout << endl;
    cout << " " << s->el << endl;
    cout << s->left->el << s->right->el << endl;
    cout << s->left->left->el << s->right->left->el << s->right->right->el << endl;
    cout << s->right->left->right->el << s->right->right->left->el << s->right->right->right->el << endl;


}

stack *create_t(tree **t){
    stack *s = new stack;
    stack *q = new stack;
    vuvod(*t, &s);  //ввод в стека значений из дерева
    vuvod(*t, &q);
    int k = 0;
    while (q != NULL){  //количество значений в стеке
        k +=1;
        pop(q);
    }
    k = k -1;
    char *a = new char[k];//массив с значениями из дерева
    for (int i=0; i<k; i++){
        a[i] = pop(s);
    }
    for (int i=0; i<k; i++){//сортровка массива
        for (int j=0; j<k-i-1; j++){
            if (a[j] > a[j+1]){
                char c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
            }
        }
    }
    for (int i=0; i<k; i++){
        s = push(a[i], s);
    }
    return s;
}

tree *sort_tree(tree *t){
    stack *s = create_t(&t);
    obh_r(&t, &s); //запись значений из стека
    return t;
}

void obh_r(tree **t, stack **s){
    if ((*t)->left != NULL){
        obh_r(&(*t)->left, &(*s));
    }
    (*t)->el = pop(*s);
    if ((*t)->right != NULL){
        obh_r(&(*t)->right, &(*s));
    }
}





