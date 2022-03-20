#include <stdio.h>

// variable to store maximum number of nodes
int total_nodes = 24;

// array to store the tree
int tree[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};

int left(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree && (2*index)<=total_nodes)
        return 2*index;
    // left child doesn't exist
    else
   return -1;
}

int right(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree && ((2*index)+1)<=total_nodes)
        return (2*index)+1;
    // right child doesn't exist
    else
      return -1;
}


void preorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index])
    {
        printf(" %d ",tree[index]); // visiting root
        preorder(left(index)); //visiting left subtree
        preorder(right(index)); //visiting right subtree
    }
}

void postorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index])
    {
        postorder(left(index)); //visiting left subtree
        postorder(right(index)); //visiting right subtree
        printf(" %d ",tree[index]); //visiting root
    }
}

void inorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index])
    {
        inorder(left(index)); //visiting left subtree
        printf(" %d ",tree[index]); //visiting root
        inorder(right(index)); // visiting right subtree
    }
}


int main()
{

    printf("Preorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");
     printf("skewed");

    return 0;
}
