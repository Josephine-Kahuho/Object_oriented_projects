#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct skewed node;
typedef struct skewed
{
    int data;
    struct skewed *right, *left;
};

void insertnode( node **tree, int value)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node*)malloc(sizeof(node));
        temp->left= temp->right = NULL;
        temp->data = value;
        *tree = temp;
        return;
    }
    if(value< (*tree)->data)
    {
        insertnode(&(*tree)->left, value);
    }
    else if (value> (*tree)->data)
    {
        insertnode(&(*tree)->right,value);
    }


}

void preorder(node *tree)
{
    if(tree)
    {
        printf("%d\t", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(node *tree)
{
    if(tree)
    {
      inorder(tree->left);
      inorder(tree->right);
      printf("%d\t", tree->data);
    }
}

void postorder(node *tree)
{
    if(tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t", tree->data);
    }
}

void main()
{
    node *root;
    node *tmp;

    //insert nodes into the tree
    root= NULL;
    insertnode(&root,90);
     insertnode(&root,80);
      insertnode(&root,62);
       insertnode(&root,58);
        insertnode(&root,38);

//print tree nodes
printf("Pre Order nodes are:\n\n\n\n");
preorder(root);

printf("In order nodes are:\n\n\n\n");
inorder(root);

printf("Post Order nodes are:\n\n\n\n");
postorder(root);
}

