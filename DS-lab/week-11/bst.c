#include<stdio.h>
typedef struct node {
  int data;
  struct node* left;
  struct node* right;
}*NODE;

NODE insertNode(NODE root, int x) {
  if(root == NULL) {
  NODE temp = (struct node*)malloc(sizeof(struct node));
  temp->right = temp->left = NULL;
  temp->data = x;
  return temp;
  }
  else if(x > root->data) {
    root->right = insertNode(root->right,x);
  }
  else if(x < root->data) {
    root->left = insertNode(root->left,x);
  }
  else {
    printf("Duplicate nodes not allowed!\n");
    exit(0);
  }
  return root;
}

NODE deleteNode(NODE root, int key) {
  if(root == NULL)
    return root;
  if(key > root->data)
    root->right = deleteNode(root->right, key);
  else if(key < root->data)
    root->left = deleteNode(root->left, key);
  else {
    if(root->left == NULL) {
    NODE temp = root->right;
    free(root);
    return temp;
    }
    else if(root->right == NULL) {
      NODE temp = root->left;
      free(root);
      return temp;
    }
    NODE cur = root->right;
    while(cur->left != NULL)
      cur = cur->left;
    root->data = cur->data;
    root->right = deleteNode(root->right, cur->data);
  }
  return root;
}
void display(NODE root) {
  if(root) {
    display(root->left);
    printf(" %d ",root->data);
    display(root->right);
  }
  else
    return;
}
int main() {
  NODE root = NULL;
  root = insertNode(root,50);
  root = insertNode(root,20);
  root = insertNode(root,70);
  root = insertNode(root,30);
  root = insertNode(root,80);
  display(root);
  root = deleteNode(root,50);
  printf("\n");
  display(root);
  return 0;

}
