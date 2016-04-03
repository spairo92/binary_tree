#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

struct bst_rep{
       bstnode root;
};

struct bstnode_rep{
      bstdataT data;
      bstkeyT key;
      bstnode leftchild,rightchild;
};

bst bst_create()
{
      struct bst_rep *ret; 
      ret=(bst)malloc(sizeof(struct bst_rep));
      if(!ret){
               fprintf(stderr,"Not enough memory!\n");
               abort();
      }
      ret->root = NULL;
      return ret;
}

void bst_des(bstnode t)
{
    if(t == NULL)
      return;
     bst_des(t->leftchild); 
     bst_des(t->rightchild); 
     free(t);  
}

void bst_destroy ( bst B )
{
     bst t;
     if(!B)
          return;
     bst_des(B->root); 
     free(B);
} 

bstnode bst_search_new ( bst B, bstkeyT bkeyT)
{
     bstnode t = B->root; 
     bstnode temp = t;
     while( t != NULL ){
          if( t->key ==  bkeyT){
              break;
          }
          else if(t->key > bkeyT){
              temp = t;
              t = t->leftchild;
          }
          else if( t->key < bkeyT ){
              temp = t;
              t = t->rightchild;
          }
     }
     if( t == NULL)
        return temp;
     else
        return t;   
}

void bst_insert ( bst B, bstkeyT keyT, bstdataT dataT )
{            
     bstnode newnode = (bstnode)malloc(sizeof(struct bstnode_rep));
     newnode->key = keyT;
     newnode->data= dataT;
     newnode->leftchild = NULL; 
     newnode->rightchild = NULL;

     bstnode tempNode = bst_search_new( B, keyT);
     if(tempNode == NULL){
         B->root = newnode; 
     }    
     else if( tempNode->key >= keyT )
        tempNode->leftchild = newnode;
     else if ( tempNode->key < keyT )
        tempNode->rightchild = newnode;       
}

bstnode bst_search ( bst B, bstkeyT bkeyT)
{
     bstnode t = B->root; 
     while( t != NULL ){
          if( t->key ==  bkeyT){
              break;
          }
          else if(t->key > bkeyT)
              t = t->leftchild;
          else if( t->key < bkeyT )
              t = t->rightchild;
     }
     return t;   
}


bstdataT bst_data ( bstnode rootf) 
{
      return  rootf->data;      
}

void bst_setdata ( bstnode rootf, bstdataT dataf)
{
     rootf->data=dataf; 
}

bstkeyT bst_key ( bstnode rootf)
{
      return  rootf->key; 
}

void bst_in(bstnode n,void (*f)(bstnode) )
{
    if(n==NULL)
       return ;   
    bst_in(n->leftchild,f); 
    f(n);
    bst_in(n->rightchild,f);         
}

void bst_inorder ( bst B, void (*Bst)(bstnode) ) 
{
    bst_in(B->root,Bst);       
}
