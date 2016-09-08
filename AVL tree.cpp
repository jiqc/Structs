#include<iostream>
using namespace std;

typedef int T;

struct AVLnode{
  T val;
  AVLnode* left;
  AVLnode* right;
  int height;
  
  AVLnode(T v, int h=0, AVLnode* l=NULL,AVLnode* r=NULL):
    val(v),
    left(l),
    right(r),
    height(h)
  {
  }
  
}

int Height(AVLnode * P){
  if(P==NULL){
    return -1;
  }else{
    return P->height;
  }
} 

AVLnode* SingleRotateWithLeft(AVLnode* K2){
  AVLnode* K1;
  
  K1=K2->left;
  K2-left=K1->right;
  K1->right=K2;
  
  K2->heigth=max(Height(K2->left),Height(K2->right))+1;
  K1->heigth=max(Height(K1->left),Height(K1->right))+1;
  
  return K1;
}

AVLnode* SingleRotateWithRight(AVLnode* K2){
  AVLnode* K1;
  
  K1=K2->right;
  K2-left=K1->left;
  K1->left=K2;
  
  K2->heigth=max(Height(K2->left),Height(K2->right))+1;
  K1->heigth=max(Height(K1->left),Height(K1->right))+1;
  
  return K1;
}

AVLnode* DoubleRotateWithLeft(AVLnode* K3){
  K3->left=SingleRotateWithRight(K3->left);
  return SingleRotateWithLeft(K3);
}

AVLnode* DoubleRotateWithRight(AVLnode* K3){
  K3->left=SingleRotateWithLeft(K3->left);
  return SingleRotateWithRight(K3);
}

AVLnode* Insert(T v, AVLnode* P){
  if(P==NULL){
    P=new AVLnode(v);
  }else{
    if(v<P->val){
      P->left=Insert(v,P->left);
      if(Height(P->left)-Height(P->right)==2){
        if(v<P->left->val){
          P=SingleRotateWithLeft(P);
        }else{
          P=DoubleRotateWithLeft(P);
        }
      }
    }else{
      if(v>P->val){
        P->right=Insert(v,P->right);
        if(Height(P->right)-Height(P->left)==2){
          if(v<P->right->val){
            P=SingleRotateWithRight(P);
          }else{
            P=DoubleRotateWithRight(P);
          }
        }
      }
    }
  }
  
  P->height=max(Height(P->height),Height(P->right))+1;
  return P;
}

AVLnode* MakeEmpty(AVLnode* P){
  if(P!=NULL){
    P->left=MakeEmpty(P->left);
    P->right=MakeEmpty(P->right);
    
    delete P;
    P=NULL;
  }
  return P;
}

AVLnode* Delete(T v, AVLnode* P){
  if(P!=NULL){
    if(v<P->val){
      P->left=Delete(v, P->left);
    }else{
      if(v>P->val){
        P->right=Delete(v, P->right);
      }else{
        
      }
    }
  }
}




