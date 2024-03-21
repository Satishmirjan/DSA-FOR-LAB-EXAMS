// use only one type of insertion method each time you run the code 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node* link;
};
int n=0;

typedef struct node* node;

// Function to create a new node
node getnode(int val){
    node temp=(node)malloc(sizeof(struct node));
    temp->item=val;
    temp->link=temp;
    n++;
    return temp;
}

// Function to insert an element at the front of the list
node insertfront(node last,int val){
    node temp=getnode(val);
    if(last==NULL){
        return temp;
    }
    temp->link=last->link;
    last->link=temp;
    return last;
}

// Function to insert an element at the rear of the list
node insertrear(node last,int val){
    node temp=getnode(val);
    if(last==NULL){
        return temp;
    }
    temp->link=last->link;
    last->link=temp;
    return temp;
}

// Function to delete an element from the front of the list
node deletefront(node last){
    if(last==NULL){
        printf("List is empty\n");
        return last; 
    }
    node cur=last->link;
    last->link=cur->link;
    n--;
    return last;
}

// Function to delete an element from the rear of the list
node deleterear(node last){
    if(last==NULL){
        printf("List is empty\n");
        return last; 
    }
    node cur=last->link;
    while(cur->link!=last){
        cur=cur->link;
    }
    cur->link=last->link;
    n--;
    return cur;
}

// Function to display the elements of the list
void display(node last){
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    // printf("number of elements%d\n",n); use this to verify your count is correct or not
    node first=last->link;
   
    do{
        printf("%d\t",first->item);
        first=first->link;
    }while(first!=last->link);
}

// Function to insert an element at a specific position
node insertpos(node last,int item,int pos){
    if(pos>n+1||pos<1){
        printf("Invalid position\n");
        return last;
    }
    else{
        
        if(pos==1){
            last=insertfront(last,item);
            return last;
        }
        else if(pos==n+1){
            return insertrear(last,item);
        }
        else{
            node temp=getnode(item);
            node cur=last->link;
            node prev=last->link;
            while(pos!=1){
                prev=cur;
                cur=cur->link;
                pos--;
            }
            if(cur==last->link){
                temp->link=last->link;
                last->link=temp;
                return temp;
            }
            prev->link=temp;
            temp->link=cur;
            return last;
        }
    }
}

// Function to delete an element by position
node deletebypos(node last,int pos){

    if(last==NULL){
        printf("List is empty\n");
        return last;
    }
    if(pos<1||pos>n){
        printf("Invalid position\n");
        return last;
    }
    else{
      
        if(pos==1){
            last=deletefront(last);
            return last;
        }
       
        else{
            node cur=last->link;
            node prev=last->link;
            while(pos!=1){
                prev=cur;
                cur=cur->link;
                pos--;
            }
            prev->link=cur->link;
             n--;
            return last;
        }
    }
}

// Function to search for an element and return its position
int search(node last,int item){
    int pos=1;
    if(last==NULL){
        printf("List is empty\n");
        return -1;
    }
    node cur=last->link;
   
    do{
        if(item==cur->item){
            return pos;
        }
        cur=cur->link;
        pos++;
    }while(cur!=last->link);
    return -1;
}

// Function to insert an element in sorted order
node insertbyorder(node last,int val){
    node temp=getnode(val);
    if(last==NULL){
        return temp;
    }
    node cur=last->link;
    node prev=last->link;
    node first=last->link;
    if(cur->item>val){
        return insertfront(last,val);
    }
    if(last->item<val){
        return insertrear(last,val);
    }
    else{
        while(cur->item<val&&cur->link!=last->link){
            prev=cur;
            cur=cur->link;
        }
        prev->link=temp;
        temp->link=cur;
        return last;
    }
}

// Function to search for an element by position and display it
void searchbypos(node last,int pos){
    if(pos<1||pos>n){
        printf("Invalid position\n");
        return;
    }
    node cur=last->link;
    while(pos!=1){
        cur=cur->link;
        pos--;
    }
    printf("The element at the given position is %d\n",cur->item);
}

// Main function
void main(){
    node last=NULL;
    int choice,val,item,pos,key;

    printf("Menu\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Insert by Position\n6. Delete by Position\n7. Search by Element\n8. Delete by Value\n9. Display\n10. Insert by Order\n11. Search by Position\n12. Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                last=insertfront(last,item);
                display(last);
                
                break;

            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                last=insertrear(last,item);
                display(last);
                
                break;

            case 3:
                last=deletefront(last);
                display(last);
                break;

            case 4:
                last=deleterear(last);
                display(last);
                break;

            case 5:
                printf("Enter the item and position: ");
                scanf("%d%d",&item,&pos);
                last=insertpos(last,item,pos);
                display(last);
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d",&pos);
                last=deletebypos(last,pos);
                display(last);
                break;

            case 7:
                printf("Enter the element to be searched: ");
                scanf("%d",&item);
                pos=search(last,item); 
                if(pos==-1){
              printf("Element not present\n");
                }
                else{
                    printf("The element %d found at position %d\n", item, pos);
                }
                break;

            case 8:
                printf("Enter the element to be deleted: ");
                scanf("%d",&item);
                pos=search(last,item);
                if(pos==-1){
                    printf("Element is not present\n");
                }
                else{
                    last=deletebypos(last,pos);
                    display(last);
                }
                break;

            case 9:
                display(last);
                break;

            case 10:
                printf("Enter element: ");
                scanf("%d",&item);
                last=insertbyorder(last,item);
                
                display(last);
                break;

            case 11:
                printf("Enter the position to be searched: ");
                scanf("%d",&pos);
                searchbypos(last,pos);
                break;

            case 12:
                printf("Thank you\n");
                exit(0);

            default:
                printf("Enter a valid choice\n");
        }
    }
}
