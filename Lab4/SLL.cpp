#include <iostream>
#include <cstdlib>

class linkedlist{
    struct node{
        int data;
        struct node* next;
    };
    struct node *head;
public:
    linkedlist(){
        head = NULL;
};

    int insertbeg(int data){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        return 0;      
    }


    int insertend(int data){
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (head==NULL){
            head = newnode;
            return 0;
        }
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        temp = NULL;
        return 0;
        }



        int insertpos(int data, int pos){
            struct node *newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = NULL;
        
            if (pos == 1 || head == NULL) {
                insertbeg(data);
                return 0;
            }
        
            struct node *temp = head;
            for (int i = 1; i < pos - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Position out of range.\n");
                return 0;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        
            return 0;
        }
        


    int deletbeg(){
        if (head == NULL){
            printf("List is empty. \n");
            return 0;
        }

        struct node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        return 0;
    }

    int deletend(){
        if (head == NULL) {
            printf("List is empty.\n");
            return 0;
        }    
        if (head->next == NULL) {
            free(head);
            head = NULL;
            printf("List contained only one element, now it is empty.\n");
            return 0;
        }
    
        struct node *temp = head;
        while (temp->next->next != NULL) { 
            temp = temp->next;
        }
    
        free(temp->next);
        temp->next = NULL;
    
        return 0;
    }


    int deletpos(int pos){
        if (head == NULL){
            printf("List is empty.\n");
            return 0;
        }
    
        struct node *temp = head;
    
        if (pos == 1) {
            head = head->next;
            free(temp);
            return 0;
        }
    
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range.\n");
            return 0;
        }
    
        struct node *todelete = temp->next;
        temp->next = todelete->next;
        free(todelete);
        
        return 0;
    }
    


    int display(){
    struct node *temp = head;
    if (head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("Null \n");
    return 0;
    }

    int search(int val){
        struct node *temp = head;
        int position = 1;
        while(temp != NULL){
            if (temp->data == val){
                printf("Data found at position %d\n", position);
                return 0; 
            }
            temp = temp->next;
            position++;
        }
        printf("Data not found.\n");
        return 0;
    }

    void display_reverse(struct node* temp) {
        if (temp == NULL) return;
        display_reverse(temp->next);
        printf("%d->", temp->data);
    }
    
    int display_reverse_list() {
        if (head == NULL) {
            printf("List is empty.\n");
            return 0;
        }
        printf("Reverse List: ");
        display_reverse(head);
        printf("NULL\n");
        return 0;
    }
    
    int reverselink(){
        struct node *prev = NULL;
        struct node *current = head;
        struct node *next =NULL;
        
        while(current!=NULL){
            next = current->next;
            current->next=prev;
            prev = current;
            current = next;
        }
        head = prev;
        printf("Successful.\n");
        return 0;
    }

};
int main(){
    class linkedlist list;

    int data, pos, key, choice;
    do{

        printf("1.Insert begining\n2.Insert end\n3.Insert at position\n4.Delete begining\n5.Delete end\n6.Delete at position\n");
        printf("7.Search\n8.Display\n9.Reverse link\n10.Display Reverse\n11.Exit\n");
        printf("Enter choice from(1-11): ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to insert at begining: ");
                scanf("%d",&data);
                list.insertbeg(data);
                break;

            case 2:
                printf("Enter the data to insert at end: ");
                scanf("%d",&data);
                list.insertend(data);
                break;

            case 3:
                printf("Enter the data and position to insert: ");
                scanf("%d %d", &data, &pos);
                break;

            case 4:
                list.deletbeg();
                break;

            case 5:
                list.deletend();
                break;

            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                break;
            
            case 7:
                printf("Enter the value to check if it exists in the list: ");
                scanf("%d", &key);
                break;

            case 8:
                list.display();
                break;

            case 9:
                list.reverselink();
                break;
            case 10:
                list.display_reverse_list();
                break;
            

            case 11:
                printf("Thank you.. exiting...\n");
                break;

            default:
                printf("Enter choice between(1-11) only.\n");
                break;
        }


    }while(choice != 11);


    return 0;
}


