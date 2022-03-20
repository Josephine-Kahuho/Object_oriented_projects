#include <stdio.h>
#include <stdlib.h>

typedef struct bintree node;
struct bintree
{
    int data;
    struct bintree *right, *left;
};

 //function to insert a node int the tree
void insertnode( node **tree, int value) //use of a double pointer. the first pointer= pointer to the second pointer; second pointer is the pointer to a variable
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node*)malloc(sizeof(node));  //allocated memory space to temp
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

void inorder(node *tree)  //in order traversal of the tree
{
    if(tree)
    {
      inorder(tree->left);
      printf("%d\t", tree->data);
      inorder(tree->right);

    }
}

void postorder(node *tree)  //post order traversal of the tree
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

    root= NULL;
    insertnode(&root,90);
     insertnode(&root,80);
      insertnode(&root,95);
       insertnode(&root,78);
        insertnode(&root,81);
         insertnode(&root,90);
          insertnode(&root,96);
           insertnode(&root,76);
            insertnode(&root,79);
             insertnode(&root,75);
              insertnode(&root,82);
               insertnode(&root,80);
                insertnode(&root,91);
                 insertnode(&root,85);
                  insertnode(&root,97);
                   insertnode(&root,68);
                    insertnode(&root,77);
                     insertnode(&root,75);
                      insertnode(&root,81);
                       insertnode(&root,70);
                        insertnode(&root,76);
                         insertnode(&root,72);
                          insertnode(&root,83);
                           insertnode(&root,70);
                            insertnode(&root,81);
                             insertnode(&root,60);
                              insertnode(&root,92);
                               insertnode(&root,52);
                                insertnode(&root,86);
                                 insertnode(&root,40);
                                  insertnode(&root,98);

//print tree nodes
printf("Pre Order nodes are:\n\n");
preorder(root);
printf("\n\n\n");

printf("In order nodes are:\n\n");
inorder(root);
printf("\n\n\n");

printf("Post Order nodes are:\n\n");
postorder(root);
}
