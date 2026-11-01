#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct bstTree{
    int data;
    struct bstTree *left, *right;
}*root = NULL;

struct Queue{
    struct bstTree *node;
    struct Queue *next;
}*front = NULL, *rear = NULL;

struct Stack{
    struct bstTree *node;
    struct Stack *next;
}*top = NULL;

void enqueue(struct bstTree *newNode){
    struct Queue *n = malloc(sizeof(struct Queue));
    n->node = newNode;
    n->next = NULL;

    if(front == NULL){
        front = rear = n;
    }else{
        rear->next = n;
        rear = n;
    }
}

struct bstTree *dequeue(){
    if(front == NULL){
        return NULL;
    }
    struct Queue *toDel = front;
    struct bstTree *popped = toDel->node;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }
    free(toDel);
    return popped;
}

bool isQueueEmpty(){
    return front == NULL;
}

void push(struct bstTree *node){
    struct Stack *newNode = malloc(sizeof(struct Stack));
    newNode->node = node;
    newNode->next = NULL;

    if(top == NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

struct bstTree *pop(){
    if(top == NULL){
        return NULL;
    }
    struct Stack *toDel = top;
    struct bstTree *poppped = toDel->node;
    top = top->next;

    free(toDel);
    return poppped;
    
}

bool isStackEmpty(){
    return top == NULL;
}

void createTree(){
    struct bstTree *temp = NULL;
    struct bstTree *ptr = NULL;
    int nodeValue;

    printf("Enter root value : ");
    scanf("%d", &nodeValue);

    if(nodeValue != -1){
        root = malloc(sizeof(struct bstTree));
        root->data = nodeValue;
        root->left = root->right = NULL;
        enqueue(root);
    }else{
        return;
    }
    
    while(!isQueueEmpty()){
        temp = dequeue();

        printf("Enter left child of %d : ", temp->data);
        scanf("%d", &nodeValue);

        if(nodeValue != -1){
            ptr = malloc(sizeof(struct bstTree));
            ptr->data = nodeValue;
            ptr->left = ptr->right = NULL;
            temp->left = ptr;
            enqueue(ptr);
        }
        printf("Enter right child of %d : ", temp->data);
        scanf("%d", &nodeValue);

        if(nodeValue != -1){
            ptr = malloc(sizeof(struct bstTree));
            ptr->data = nodeValue;
            ptr->left = ptr->right = NULL;
            temp->right = ptr;
            enqueue(ptr);
        }
    }
}

void levelOrder(){
    if(root == NULL){
        return;
    }
    enqueue(root);
    struct bstTree *temp;
    while(!isQueueEmpty()){
        temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left != NULL){
            enqueue(temp->left);
        }
        if(temp->right != NULL){
            enqueue(temp->right);
        }
    }
}

void preOrder(){
    if(root == NULL){
        return;
    }
    struct bstTree *temp = root;

    while(temp != NULL || !isStackEmpty()){
        if(temp != NULL){
            printf("%d ", temp->data);
            push(temp);
            temp = temp->left;
        }else{
            temp = pop();
            temp = temp->right;
        }
    }
}

void inOrder(){
    if(root == NULL){
        return;
    }
    struct bstTree *temp = root;
    while(temp != NULL || !isStackEmpty()){
        if(temp != NULL){
            push(temp);
            temp = temp->left;
        }else{
            temp = pop();
            printf("%d ", temp->data);
            temp = temp->right;
        }
    }
}

void postOrder(){
    if(root == NULL){
        return;
    }
    struct bstTree *temp = root;
    struct bstTree *lastVisited = NULL;
    while(temp != NULL || !isStackEmpty()){
        if(temp != NULL){
            push(temp);
            temp = temp->left;
        }else{
            struct bstTree *peek = top->node;
            if(peek->right != NULL && lastVisited != peek->right){
                temp = peek->right;
            }else{
                printf("%d ", peek->data);
                lastVisited = pop();
            }
        }
    }
}

int main(){
    createTree();
    printf("\n");
    levelOrder();
    printf("\n");
    preOrder();
    printf("\n");
    inOrder();
    printf("\n");
    postOrder();
}