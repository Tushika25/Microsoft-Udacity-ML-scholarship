#include <stdio.h>
#include <stdlib.h>

struct bst_node {                                           // struct for bst
    int key ;
    struct bst_node * left ;
    struct bst_node * right ;
    struct bst_node * parent ;
    int size ;
} ;

struct quue {                                               // quue to store the inorder keys of a partiular node
    int key ;
    struct quue * next ;
};

struct quue * rea = NULL ;
struct quue * front = NULL ;

void enque (int key) {                                      // enque func for quue
    struct quue * temp ;
    temp = (struct quue *)malloc(sizeof(struct quue)) ;
    temp->key = key ;
    temp->next = NULL ;
    if (front == NULL) {
        front = rea = temp ;
        return;
    }
    else {
        rea->next = temp ;
        rea = temp ;
        return ;
    }
}
void dequee () {                                            // deque func for quue
    struct quue * temp ;
    if (front == NULL) {
        return;
    }
    if (front == rea) {
        temp = front ;
        front = rea = NULL ;
        free(temp) ;
        return;
    }
    else {
        temp = front ;
        front = front->next ;
        free(temp) ;
        return ;
    }

}
void  inor_data (struct bst_node * root){           // func to store the data of bst in quue in inorder fashion
    if (root == NULL) {
        return ;
    }
    inor_data(root->left) ;
    enque(root->key) ;
    inor_data(root->right) ;
}

struct bst_node * join (struct bst_node * left, struct bst_node * right) {              // join function given in the assignment itself
    int n , m , r, total ;                                                              // with little modification to maintain the parent link
    if (left == NULL)
        m = 0 ;
    else 
        m = left->size ;
    if (right == NULL) 
        n = 0 ;
    else
        n = right->size ;
    total = n + m ;

    if (total == 0)
        return NULL ;
    r = (rand())%total ;
    if (r<m) {
        left->right = join(left->right,right);
        if (left->right!=NULL){
            (left->right)->parent = left ;                                          // maintaining parent link
        }
        return left;
    }
    else {
        right->left = join(left, right->left);
        if (right->left != NULL){
            (right->left)->parent = right ;                                         // maintaining parent link
        }
        return right ;
    }
}

struct bst_node * Find (struct bst_node * root , int key){                              // Standard Find function
    if (root == NULL) {
        return NULL ;                                                                   // returns NULL if the key not found
    }
    if (root->key == key) {
        return root ;
    }
    else if (key > root->key){
        return Find (root->right,key) ;

    }
    else {
        return Find(root->left,key) ;
    }
    
}

struct bst_node * delete (struct bst_node * root , int key){                            // delete funciton as mentioned in assignment along with modification to maintain parent link
    struct bst_node * dele_node = Find(root,key) ;
    if (dele_node != NULL) {                                                            // checking the node to deleted exists or not
        struct bst_node * temp ;
        temp = join(dele_node->left,dele_node->right);
        if(dele_node->parent == NULL){                                                  // case when the node to be deleted is tree root itself
            if (temp != NULL)                                                           // temp will be NULL if the node to be deleted has no child
                temp->parent = NULL ;                                                   // maintaining parent link which is null as the temp will be new tree root if there exists tree
            return temp ;
        }

        struct bst_node * parent = dele_node->parent ;                                  // case when node to be deleted is not tree root itself
        if (parent->key>dele_node->key){                                                // case when new bst has to left side of the parent of the node which is deleted
            parent->left = temp;
            if (temp!=NULL)                                                             // tackling the case where the node is leaf node
                temp->parent = parent ;                                                 // maitaining the parent link
            return root ;
        }
        else {
            parent->right = temp ;                                                      // case when new bst has to right side of the parent of the node which is deleted               
            if (temp!= NULL)                                                            // tackling the case where the node is leaf node
                temp->parent = parent ;                                                 // maitaining the parent link
            return root ;
        }

    }
    else {
        return root; 
    }

}

struct bst_node * insert (struct bst_node * root , int key){                            // standard insert function which inserts the node at leaf position
    if (root == NULL){
        struct bst_node * temp ;
        temp = (struct bst_node * )malloc(sizeof(struct bst_node)) ;
        temp->key = key ;
        temp->left = NULL ;
        temp->parent = NULL ;
        temp->right = NULL ;
        temp->size = 1 ;
        return temp ;
    }
    
    else {                                                      // If we are inserting in the BST
        struct bst_node * root_itr = root ;                     // iterator for finding the node where we have to insert
        struct bst_node * q = NULL ;                            // It stores the node to which the new node has to be attached

        while (root_itr != NULL){
            q = root_itr ;
            if (key > root_itr->key)
                root_itr = root_itr->right ;

            else if (key < root_itr->key)
                root_itr = root_itr->left ;
                
            else {
                return root ;                                   // If the key is already there then we will stop the insert function
            }
        }

        // Creating the new node
        struct bst_node * temp ;
        temp = (struct bst_node * )malloc(sizeof(struct bst_node)) ;
        temp->key = key ;
        temp->left = NULL ;
        temp->parent = q ;                  // Linking it to the parent q
        temp->right = NULL ;

        if (key > q->key)                   // Attaching it either as left or right child
            q->right = temp ;
        else
            q->left = temp ;

        return root ;                      // returning the root of the BST

    }
}

struct bst_node * mod_ins (struct bst_node * root , int key) {                  // modified insertion func. which uses biased coin toss.
    if (root == NULL){                                                          // if the tree is empty we create a new tree
        struct bst_node * temp ;
        temp = (struct bst_node *)malloc(sizeof (struct bst_node)) ;
        temp->key = key ;
        temp->left = NULL ;
        temp->right = NULL ;
        temp->parent = NULL ;
        temp->size = 1 ;
        return temp ;
    }

    int q = rand() ;                                                            // rando
    q %= (root->size) ;
    q++ ;                                                                       // random number from 1 to size of the root 
    if (q == root->size){                                                       // case when insertion is to be done at current root
        // create array and store the elements of the tree in it in inorder... then pass key then pass the array...
        // If the root is the actual root or child of the overall father.... and depending on it set the parent link ...
        // return the new root ....
        front = rea = NULL ;
        inor_data(root) ;
        struct bst_node * new_node = NULL ;
        new_node = insert(new_node,key) ;                   // creating a new bst rooted at our key
        while (front != NULL) {
            int valeo = front->key ;
            new_node = insert(new_node,valeo);
            dequee() ;
        }                                                   // inserting it in our bst
        if (root->parent == NULL) {                     // case when insertion is done at actual root of the whole bst
            return new_node ;
        }
        else {
            struct bst_node * parent = root->parent ;
            new_node->parent = parent ;
            return new_node ; 
        }


    }
    else {                                                      // recursive insert
        if (key > root->key){                                           
            if (root->right == NULL) {                         // recursive insert when next node is null
                struct bst_node * temp ;
                temp = (struct bst_node *)malloc(sizeof (struct bst_node)) ;
                temp->key = key ;
                temp->left = NULL ;
                temp->right = NULL ;
                temp->parent = root ;
                temp->size = 1 ;
                root->right = temp ;
                return root ;
            }
            else {
                root->right = mod_ins(root->right, key) ;      
                return root ;
            }
        }
        else {

            if (root->left == NULL){                        // recursive insert when next node is null
                struct bst_node * temp ;
                temp = (struct bst_node *)malloc(sizeof (struct bst_node)) ;
                temp->key = key ;
                temp->left = NULL ;
                temp->right = NULL ;
                temp->parent = root ;
                temp->size = 1 ;
                root->left = temp ;
                return root; 
            }
            else {
                root->left = mod_ins(root->left,key) ;
                return root ;
            }
        }
        
    }

    
    
}


struct upda {                           // struct to store the tree nodes
    struct bst_node * val ;
    struct upda * next ;
};

struct upda * Front_upda = NULL ;
struct upda * rear_upda = NULL ;

void enque_upda (struct bst_node * val) {                   // enque func for upda struct
    struct upda * temp ;
    temp = (struct upda *) malloc(sizeof (struct upda)) ;
    temp->next = NULL ;
    temp->val = val ;
    if (Front_upda == NULL) {
        Front_upda = rear_upda = temp ;        
    }
    else {
        rear_upda->next = temp ;
        rear_upda = temp ;
    }
}

void deque_upda () {                                    // deque func for upda struct
    if (Front_upda == NULL)
        return ;

    if (Front_upda == rear_upda) {
        Front_upda = rear_upda = NULL ;
        return ;
    }
    else {
        Front_upda = Front_upda->next ;
    }
}

int calcults (struct bst_node * root) {             // calcules the size of bst at current root
    if (root == NULL) {
        return 0 ;
    }


    int ans = calcults(root->left) + calcults(root->right) + 1;                 // size of bst at root = size of left subtree + right subtree + itself
    return ans ;

}

void tree_ad (struct bst_node * root) {                                     // func which stores the bst nodes in the upda struct que
    if (root == NULL)
        return ;


    tree_ad(root->left) ;
    enque_upda(root) ;
    tree_ad(root->right) ;
}

void updater (struct bst_node * root){                                  // updater function which updates the size of the nodes of bst
    Front_upda =rear_upda = NULL ;
    tree_ad(root) ;                                                         // get every nodes of bst

    while (Front_upda != NULL) {
        (Front_upda->val)->size = calcults(Front_upda->val) ;               //update every node
        deque_upda() ; 
    }

}

void Inorder_print(struct bst_node * root, FILE * filePointer_op) {       // Inorder printing   
    if (root == NULL)                                                       // If the BST is empty we do nothinhg
        return ;
    // Standard algo
    Inorder_print(root->left,filePointer_op);
    fprintf (filePointer_op, "%d ", root->key) ;
    Inorder_print(root->right,filePointer_op) ;
}

void postorder_print(struct bst_node * root, FILE * filePointer_op) {   // Postorder printing 
    if (root == NULL)                                                   // If the BST is empty we do nothinhg
        return ;

    postorder_print(root->left,filePointer_op);
    postorder_print(root->right,filePointer_op) ;
    fprintf (filePointer_op,"%d ", root->key) ;

}

void preorder_print(struct bst_node * root, FILE * filePointer_op) {   //  preorder printing 
    if (root == NULL)                                                   // If the BST is empty we do nothinhg
        return ;

    fprintf (filePointer_op,"%d ", root->key) ;
    preorder_print(root->left,filePointer_op);
    preorder_print(root->right,filePointer_op) ;
}

void print_tree(struct bst_node * root, FILE * filePointer_op) {    // Print tree function
    if (root == NULL)                                              // If the BST is empty we print NULL Tree to output.txt
        return ;
        //fprintf (filePointer_op,"NULL Tree\n") ;
    else {
        fprintf(filePointer_op,"Inorder: ") ;
        Inorder_print(root, filePointer_op) ;
        fprintf (filePointer_op,"\n") ;

        fprintf(filePointer_op,"Preorder: ") ;
        preorder_print(root,filePointer_op) ;
        fprintf(filePointer_op,"\n") ;

        fprintf(filePointer_op,"Postorder: ") ;
        postorder_print(root,filePointer_op) ;
        fprintf(filePointer_op,"\n") ;
    }
}

void print_subtree (struct bst_node * root , int key, FILE * filePointer_op){   // Printing the subtree
    struct bst_node *  q = Find(root,key) ;                                     // We find the node having the key value
    print_tree(q,filePointer_op) ;                                              // We pass it in to the print_tree function
}


void CalculateImbalance (struct bst_node * root, int key, FILE * filePointer_op) {  // Calculating the differnce between left and right subtree
    struct bst_node * q = Find(root,key) ;                                          // We the node having the key value
    if (q == NULL)
        return ;                                                                  // If the key is invalid then
        //fprintf (filePointer_op,"Invalid key") ;

    else {
        int left = 0 ;                                                      // intially left and right nodes are 0
        int right = 0 ;
        left = calcults(q->left) ;
        right = calcults(q->right);
        fprintf(filePointer_op,"%d\n",left - right) ;                   // we print left - right to the output.txt

    }
}

int depth (struct bst_node * root , int key) {                          // depth function
    int depth = 0 ;                                                     // we use parent link to traverse back to root
    struct bst_node * q = Find(root,key) ;
    while (q->parent!=NULL) {
        depth++ ;
        q = q->parent ;
    }

    return depth ;                                                      //returning the depth
}


int main(void) {                                                            

    FILE * filePointer_in ;                                            // opening the input.txt 
    filePointer_in = fopen("input.txt", "r");

    FILE * filePointer_op ;                                            // Creating or writting to output.txt
    filePointer_op = fopen("output.txt","w") ;

    int N ;                                                             // Number of queries
    int type ;                                                          // type of queries
    int key ;                                                           // Key value
    struct bst_node * root = NULL ;                                     // Creating the tree root and initialising it to NULL

    fscanf(filePointer_in,"%d",&N) ;                                    // Input of N 

    for (int i = 0 ; i<N ; i++) {

        fscanf(filePointer_in,"%d",&type) ;                             // Type input

        switch (type) {

            case 1 :                                                    // If type 1 then we input key value and insert it in the BST
                fscanf(filePointer_in,"%d",&key) ;
                if (Find(root,key) == NULL){
                root = mod_ins (root,key) ;
                updater(root) ;
                }
                if (Find(root,key)==NULL)                               // We check using Find function whether the key value exists in BST or not
                    fprintf(filePointer_op,"false\n") ;

                else 
                    fprintf(filePointer_op,"true\n") ;

                break ;

            case 2 :
                fscanf(filePointer_in,"%d",&key) ;                  // Type 2 deleting the key value
                if (Find(root,key)){
                root = delete(root,key) ;
                updater(root) ;
                }

                if (Find(root,key)==NULL)                               //  We check using Find function whether the key value exists in BST or not
                    fprintf(filePointer_op,"true\n") ;

                else 
                    fprintf(filePointer_op,"false\n") ;

                break ;

            case 3 :
                fscanf(filePointer_in,"%d",&key) ;                  // Type 3 Finding the key value node

                if (Find(root,key)==NULL)
                    fprintf(filePointer_op,"false\n") ;

                else 
                    fprintf(filePointer_op,"true, depth=%d\n",depth(root,key)) ;      //If the node exists the printing its depth along with it
        
                break ;

            case 4 :                                                // Type 4 printing the whole tree
                print_tree(root,filePointer_op) ;
                break ;

            case 5 :                                                // Type 5 printing the subtree

                fscanf(filePointer_in,"%d",&key) ;
                print_subtree(root,key,filePointer_op) ;
                break;
            
            case 6 :                                                // Type 6 calculating the differnce
                fscanf(filePointer_in,"%d",&key) ;
                CalculateImbalance(root,key,filePointer_op) ;
                break ;            

        }
    }

    fclose(filePointer_in) ;
    fclose(filePointer_op) ;


    return 0;
}
