#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct bst_node {
    char str[7] ;
    struct bst_node * parent;
    struct bst_node * left ;
    struct bst_node * right ;
} ;

int compare (char str1[], char str2[]){      // if string 1 is greter, then returns 1
    for (int i = 0 ; i<6; i++){              // if string 2 is greater then returns 2
        if ((int)str1[i]>(int)str2[i])
            return 1 ;
        if ((int)str1[i]<(int)str2[i])
            return 2 ;
    }

    return 0 ;
}

struct bst_node * create_node (char str1[]){
    struct bst_node * temp ;
    temp = (struct bst_node *)malloc(sizeof(struct bst_node)) ;
    temp->left = NULL ;
    temp->right = NULL; 
    temp->parent = NULL ;
    // strcpy((temp->str),str1) ;
    // (temp->str)[6] = '\0' ;
    for (int i = 0 ; i<6 ; i++){
        (temp->str)[i] = str1[i] ;
    }
    (temp->str)[6] = '\0' ;
    return temp ;
}

struct bst_node * insert_node (char str1[], struct bst_node * Head){
    struct bst_node * temp = create_node(str1) ;
    if (Head == NULL)
        return temp ;
    else {
        struct bst_node * itr = Head ;
        while (1){
            if (compare((itr->str),(temp->str)) == 1){
                if (itr->left == NULL){
                    itr->left = temp ;
                    temp->parent = itr ;
                    return Head ;
                }
                else {
                    itr = itr->left ;
                }
            }
            else {
                if (itr->right == NULL){
                    itr->right = temp ;
                    temp->parent = itr ;
                    return Head ;
                }
                else {
                    itr = itr->right ;
                }
            }
        }
    }
    
}

int existe (struct bst_node * Head, char str1[]){
    struct bst_node * itr = Head ;
    while (1){
        if (itr == NULL)
            return 0 ;
        else if (compare((itr->str),str1) == 1){
            itr = itr->left ;
        }
        else if (compare((itr->str),str1) == 2){
            itr = itr->right ;
        }
        else{
            return 1 ;
        }
    }
}

void path_print (struct bst_node * Head, char str1[]){
    struct bst_node * itr = Head ;
    while (1){
        if (itr == NULL)
            return ;
        else if (compare((itr->str),str1) == 1){
            itr = itr->left ;
            printf("L") ;
        }
        else if (compare((itr->str),str1) == 2){
            itr = itr->right ;
            printf("R") ;
        }
        else{
            return ;
        }
    }
}


int main(){
    struct bst_node * Head = NULL ;
  char* firstLine=NULL;
  char* inputLine=NULL;
  size_t length=0, counter=0, plateLength=6;
  char choice, numberPlate[7];

  // Fetching only the first line of input.
  length = getline(&firstLine,&length,stdin);

  // Parsing the string word by word. 
  while(counter<length){
    strncpy(numberPlate,&firstLine[counter],plateLength);
    numberPlate[plateLength] = '\0';
    counter += plateLength+1; // The +1 takes care of the space between words.

    // Call your BST Insert function here with argument: numberPlate
        Head = insert_node(numberPlate,Head) ;
    
  }

  // Main input handler to serve requests.
  while(getline(&inputLine, &length, stdin) != -1){
    sscanf(inputLine,"%c %s",&choice, numberPlate);
    if(choice=='S'){
      
      // Call your BST Search function here with argument: numberPlate
        if (existe(Head,numberPlate) == 0)
            printf("0\n") ;
        else {
            printf("1 ") ;
            path_print(Head,numberPlate) ;
            printf("\n") ;
        }
      
    }
    free(inputLine); inputLine=NULL;
    length=0;
  }
  return 0;
  
}