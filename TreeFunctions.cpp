#include "TreeFunctions.h"

Node_t* TreeInsert(Node_t* root, const data_t elem)
{
    Node_t* node   = root;
    Node_t* parent = root;
    sides_t side   = NO_SIDE;

    while (node != NULL)
    {
        if (elem <= node->data)
        {
            parent = node;
            node   = node->left;
            side   = LEFT;

            continue;
        }

        parent = node;
        node   = node->right;
        side   = RIGHT;
    }

    return MakeNode(parent, side, elem);
}

Node_t* MakeNode(Node_t* parent, const sides_t side, const data_t elem)
{
    if ((parent == NULL && side != NO_SIDE) || (parent != NULL && side == NO_SIDE))
    {
        fprintf(stderr, "Error: parent %p doesn't have side %d", parent, side);

        return NULL;
    }

    switch (side)
    {
        case LEFT:
        {
            parent->left = NewNode(parent, side, elem);

            return parent->left;
        }
        case RIGHT:
        {
            parent->right = NewNode(parent, side, elem);

            return parent->right;
        }
        case NO_SIDE:
        {
            Node_t* node = NewNode(NULL, side, elem);

            return node;
        }
        default:
        {
            fprintf(stderr, "Error: Unknown side: %d!\n", side);
            return NULL;
        }
    }
}

Node_t* NewNode(Node_t* parent, const sides_t side, const data_t elem)
{
    Node_t* node = (Node_t*) calloc(1, sizeof(*node));

    if (!node)
    {
        fprintf(stderr, "Memory error!\n");
        return NULL;
    }

    node->data = elem;

    node->left  = NULL;
    node->right = NULL;

    if (!parent) return node;

    if (LeafCheck(parent, side) != 0) return NULL;

    node->parent = parent;

    return node;
}

int LeafCheck(const Node_t* parent, const sides_t side)
{
    assert(parent);

    if (side == LEFT)
    {
        if (parent->left)
        {
            fprintf(stderr, "Error: parent node already has left branch!\n");
            return -1;
        }

        return 0;
    }

    if (parent->right)
    {
        fprintf(stderr, "Error: parent node already has right branch!\n");
        return -1;
    }

    return 0;
}

Node_t* MakeRoot(const data_t elem)
{
    return TreeInsert(NULL, elem);
}

int TreeDtor(Node_t* node)
{
    if (!node) return 0;

    TreeDtor(node->left);
    TreeDtor(node->right);

    free(node);
    node = NULL;

    return 0;
}

int Print_inorder(const Node_t* node, FILE* file_ptr)
{
    if (!node) return 0;

    Print_inorder(node->left, file_ptr);

    fprintf(file_ptr, "%d ", node->data);

    Print_inorder(node->right, file_ptr);

    return 0;
}
