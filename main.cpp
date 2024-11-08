#include <stdio.h>
#include <stdlib.h>

#include "TreeGlobals.h"
#include "TreeFunctions.h"

int main()
{
    Node_t* root = MakeRoot(50);
    if (!root) return -1;

    TREE_INSERT(root, 148);
    TREE_INSERT(root, 12);
    TREE_INSERT(root, 60);
    TREE_INSERT(root, 1925);
    TREE_INSERT(root, 17);
    TREE_INSERT(root,  5);

    FILE* file_ptr = fopen("Out.txt", "w");

    Print_inorder(root, file_ptr);
    fprintf(file_ptr, "\n");

    fclose(file_ptr);

    TreeDtor(root);

    return 0;
}
