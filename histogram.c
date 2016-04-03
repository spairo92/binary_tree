#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "bst.h"
void print(bstnode bnode)
{
     printf("%ld\n",bst_data(bnode));
}
main()
{
      long number[100];
      int i=0,j;
      char table[100];
      char space[] = " ";
      char *tableptr=NULL;
      bstnode bnode;
      printf("Histogram\n");
      printf("Give data with space between them! The output will show how many times (frequency) you saw each input:\n");
      bst B = bst_create ();
      gets(table);
      
      tableptr = strtok(table,space);

      while(tableptr!=NULL)
      {
          number[i] = atol(tableptr);                               
          tableptr = strtok(NULL,space);
          i++;
      }  
      for(j=0; j<i; j++){    
          if( (bnode = bst_search(B,number[j])) == NULL)                                
             bst_insert(B,number[j],1);                     
          else  
             bst_setdata( bnode, bst_data(bnode)+1 );               
      }
      
      bst_inorder(B, print);  
      bst_destroy(B);  
      system("PAUSE");
      return 0;           
}
