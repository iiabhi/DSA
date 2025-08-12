#include<stdio.h>
#include<stdlib.h>

//struct definition:(Node)
struct Node{
    int data;
    struct Node* next;
};

//insert at beginning
void insertAtBegin(struct Node** head, int val){
    //new Node crartion
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    //end

    newNode->next = *head;
    *head = newNode;

}

//insert at end
void insertAtEnd(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head==NULL){
        *head = newNode;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}

//delete value
void deleteNode(struct Node** head, int val){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while(temp!=NULL && temp->data != val){
        prev = temp;
        temp = temp->next;
    }
    if(!temp) return;
    prev->next = temp->next;
    free(temp); 
}

//search
int search(struct Node** head, int val){
    struct Node* temp = *head;
    while(temp!=NULL){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//reverse(iterative)

struct Node* reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next; //curr = next
    }
    return prev; //(head)
}

//loop deetction
int cycle(struct Node** head){
    struct Node* slow = *head;
    struct Node* fast = *head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
    
}

//remove cycle
void removeCycle(struct Node** head){
    struct Node* slow = *head;
    struct Node* fast = *head;
    do{
        if(!fast && !fast->next) return;
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    slow = *head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast->next = NULL;

}

//merge two sorted
struct Node* merge(struct Node* a, struct Node* b){
    if(!a) return b;
    if(!b) return a;

    if(a->data < b->data){
        a->next = merge(a->next, b);
        return a;

    }else{
        b->next = merge(a, b->next);
        return b;
    }
}

//print
void print(struct Node** head){
    struct Node* temp = *head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

//delete nth from end(single pass)
void delnEnd(struct Node** head, int n){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for(int i=0; i<n-1; i++){
        if(temp==NULL){
            printf("N less that length of LL");
            return;
        }
        prev = temp;
        temp= temp->next;
    }
    prev->next = temp->next;
    temp->next = NULL;
    free(temp);

    
}

int main(){
    struct Node* head = NULL;
    insertAtBegin(&head, 1);
    insertAtBegin(&head, 2);
    insertAtBegin(&head, 3);
    insertAtEnd(&head, 4);


    print(&head);
    printf("\n");
    struct Node* newHead = reverse(&head);

    print(&newHead);
    printf("\n");


    //switch


    

    return 0;
}