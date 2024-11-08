#ifndef __TREE_FUNCTIONS_H__
#define __TREE_FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "TreeGlobals.h"

Node_t* MakeRoot      (const data_t  elem);

Node_t* TreeInsert    (      Node_t* root,   const data_t  elem);
Node_t* MakeNode      (      Node_t* parent, const sides_t side, const data_t elem);
Node_t* NewNode       (      Node_t* parent, const sides_t side, const data_t elem);
int     LeafCheck     (const Node_t* parent, const sides_t side);

int     TreeDtor      (Node_t* node);

int     Print_inorder (const Node_t* node, FILE* file_ptr);

#endif
