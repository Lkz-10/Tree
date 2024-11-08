#ifndef __TREE_GLOBALS_H__
#define __TREE_GLOBALS_H__

#define TREE_INSERT(root, elem)                   \
    if (TreeInsert(root, elem) == NULL) return -1;

typedef int data_t;

struct Node_t
{
    int     data;
    Node_t* left;
    Node_t* right;
    Node_t* parent;
};

enum sides_t
{
    NO_SIDE = -1,
    LEFT    =  0,
    RIGHT   =  1
};

#endif
