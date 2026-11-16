#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    tree_t t1;
    init(&t1);
    int keys[] = {12,21,83,34,52};
    for(int i = 0; i<5; i++){
        insert(&t1,keys[i]);
    }
    display(&t1);
    deinit(&t1);
}