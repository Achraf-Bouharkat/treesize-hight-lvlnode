#include <stdio.h>
#include <stdlib.h>
struct tree{
int data;
struct tree *left;
struct tree *right;
};
struct tree* adddata(int a){
struct tree* t=(struct tree*)malloc(sizeof(struct tree));
t->data=a;
t->left=NULL;
t->right=NULL;
return t;
}
int size (struct tree* root){
int count=1;
if(root == NULL){
return 0;
}
count+=size(root->left);
count+=size(root->right);
return count;
}
int hight(struct tree* root){
if(root == NULL){
return 0;
}
int i = 0;
int j = 0;
i+=hight(root->left);
j+=hight(root->right);
if(i < j){
return j+1;
}
else{
return i+1;
}
}
int lvlnode(int y,int lvl,struct tree* root){
if(root == NULL){
return -1;
}
if(root->data == y){
return lvl;
}
int lvell=lvlnode(y,lvl+1,root->left);
int lvelr=lvlnode(y,lvl+1,root->right);
if(lvell != -1){
return lvell;
}
else if(lvelr != -1){
return lvelr;
}
}
int main(){
struct tree* x;
x = adddata(5);
x->left=adddata(0);
x->left->right=adddata(1);
x->left->left=adddata(8);
printf("%d is the hight \n",hight(x));
printf("%d is the size \n",size(x));
printf("%d is the level of the node 5 ",lvlnode(5,0,x));
}
