#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Patient{
    int patientID;
    char name[100];
    int severity;
};

struct StackNode{
    struct Patient patientData;
    struct StackNode *next;
}*top = NULL;

struct bstNode{
    struct Patient patientData;
    struct bstNode *left, *right;
}*bstRoot = NULL;

void pushOperation(struct Patient newPatient){
    struct StackNode *newNode = malloc(sizeof(struct StackNode));
    newNode->patientData = newPatient;
    newNode->next = NULL;
    if(top == NULL){
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void insertBST(struct Patient newPatient){
    struct bstNode *temp = bstRoot;
    struct bstNode *tail,*ptr;

    if(bstRoot == NULL){
        bstRoot = malloc(sizeof(struct bstNode));
        bstRoot->patientData = newPatient;
        bstRoot->left = bstRoot->right = NULL;
        return;
    }

    while(temp != NULL){
        tail = temp;
        if(newPatient.patientID < temp->patientData.patientID){
            temp = temp->left;
        }else if(newPatient.patientID > temp->patientData.patientID){
            temp = temp->right;
        }else{
            printf("Patient already exists. Can't add");
            return;
        }
    }
    ptr = malloc(sizeof(struct bstNode));
    ptr->patientData = newPatient;
    ptr->left = ptr->right = NULL;

    if(ptr->patientData.patientID < tail->patientData.patientID){
        tail->left = ptr;
    }else{
        tail->right = ptr;
    }
}

struct Patient popOperation(){
    struct Patient popped = {0};
    if(top == NULL){
        printf("Stack is empty");
        return popped;
    }
    struct StackNode *temp = top;
    popped = temp->patientData;
    top = top->next;
    free(temp);
    return popped;
}

bool checkDuplicateInStack(struct Patient p){
    if(top == NULL){
        return false;
    }
    struct StackNode *temp = top;
    while(temp != NULL){
        if(p.patientID == temp->patientData.patientID){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool searchBST(int patientID){
    if(bstRoot == NULL){
        return false;
    }
    struct bstNode *temp = bstRoot;
    while(temp != NULL){
        if(patientID < temp->patientData.patientID){
            temp = temp->left;
        }else if(patientID > temp->patientData.patientID){
            temp = temp->right;
        }else{
            return true;
        }
    }
    return false;
}
void searchPatientID(int patientID){
    if(bstRoot == NULL){
        printf("Tree is empty");
        return;
    }
    struct bstNode *temp = bstRoot;
    while(temp != NULL){
        if(patientID < temp->patientData.patientID){
            temp = temp->left;
        }else if(patientID > temp->patientData.patientID){
            temp = temp->right;
        }else{
            printf("Patient ID : %d\n", temp->patientData.patientID);
            printf("Patient Name : %s\n", temp->patientData.name);
            printf("Patient Severity : %d\n", temp->patientData.severity);
            return;
        }
    }
    printf("Patient Not found\n");
}

void addPatients(){
    struct Patient p;
    printf("Enter Patient ID : ");
    scanf("%d", &p.patientID);
    printf("Enter Patient Name : ");
    scanf(" %[^\n]", p.name);
    printf("Enter Patient Severity : ");
    scanf("%d", &p.severity);

    if(checkDuplicateInStack(p) || searchBST(p.patientID)){
        printf("Patient already exists. Enter a new patient");
        return;
    }

    pushOperation(p);
    printf("Patient added to stack successfully\n");
}

void admitPatient(){
    if(top == NULL){
        printf("Stack is empty");
        return;
    }
    struct Patient p = popOperation();
    insertBST(p);
    printf("Patient Admitted Successfully\n");
}

void displayWaitingPatients(){
    if(top == NULL){
        printf("No patient in waiting queue\n");
        return;
    }
    struct StackNode *temp = top;
    while(temp != NULL){
        printf("Patient ID : %d\n", temp->patientData.patientID);
        printf("Patient Name : %s\n", temp->patientData.name);
        printf("Patient Severity : %d\n", temp->patientData.severity);
        temp = temp->next;
    }
}

void inorderTraversal(struct bstNode *temp){
    if(temp){
        inorderTraversal(temp->left);
        printf("Patient ID : %d\n", temp->patientData.patientID);
        printf("Patient Name : %s\n", temp->patientData.name);
        printf("Patient Severity : %d\n", temp->patientData.severity);
        inorderTraversal(temp->right);
    }
}

int main(){
    int choice, patientID;
    do{
        printf("\n----Patient Operations----\n");
        printf("1. Add Patient\n");
        printf("2. Admit Patient\n");
        printf("3. Display Waiting Patients\n");
        printf("4. Search for a Patient\n");
        printf("5. Display Admitted Patients\n");
        printf("6. Exit");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1 : 
                addPatients();
                break;
            case 2:
                admitPatient();
                break;
            case 3:
                displayWaitingPatients();
                break;
            case 4:
                printf("Enter the patient ID you wish to find : ");
                scanf("%d", &patientID);
                searchPatientID(patientID);
                break;
            case 5 : 
                inorderTraversal(bstRoot);
                break;
        }
    }while(choice != 6);
}