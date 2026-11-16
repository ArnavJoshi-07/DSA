#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main(){
    tree_t t1;
    init(&t1);
    int a1[] = {1, 3,5,7,9,11,15,19};
    for(int i = 0; i<8; i++){
        insert(&t1, a1[i]);
    }
    disp(&t1);
    deinit(&t1);
}