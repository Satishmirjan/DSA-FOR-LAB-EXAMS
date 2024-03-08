/*In exams, remember: Insertion methods - insertion by giving position or insertion by order are usually asked separately. For insertion by order, no need for sorting, just insert each element in order specified. Streamline your strategy for efficient preparation. Good luck!*/

#include<stdio.h>
#include<stdlib.h>
int ne=0; 
int *x;
int size;


void disp()
{
    int i;
    if(ne==0)
    {
        printf("Array empty\n");
        return;
    }
    printf("The Array elements you Entered are : \n");
    for(i=0;i<ne;i++)
    printf("%d\t",*(x+i));
    printf("\n");
}

void insert_by_pos()
{
    int i,pos,ele;
    if(ne==size)
    {
        printf("Array is full.\n");
        printf("Reallocating Array\n");
        size++;
        x=(int*)realloc(x,size*sizeof(int));
    }
    printf("Enter The element to be inserted : \n");
    scanf("%d",&ele);
    printf("Enter The position where The elements should be inserted\n");
    scanf("%d",&pos);
    if(pos>=1&&pos<=ne+1)
    {
        for(i=ne-1;i>=pos-1;i--)
        {
            *(x+i+1)=*(x+i);
        }
        *(x+i+1)=ele;
        ne++;
    }
    else
    printf("invalid position\n");
}

void insert_by_order()
{
    int i,ele;
    if(ne==size)
    {
        printf("Array is full.\n");
        printf("Reallocating Array \n");
        size++;
        x=(int*)realloc(x,size*sizeof(int));
    }
    printf("Enter The element to be inserted : ");
    scanf("%d",&ele);
    i=ne-1;
    while(i>=0&&*(x+i)>ele)
    {
        *(x+i+1)=*(x+i);
        i--;
    }
    *(x+i+1)=ele;
    ne++;
}

void delete_by_pos()
{
    int i,pos;
    if(ne==0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter The position from where elements should be deleted\n");
    scanf("%d",&pos);
    if(pos>=1&&pos<=ne)
    {
        for(i=pos-1;i<ne-1;i++)
        {
            *(x+i)=*(x+i+1);
        }
        ne--;
    }
    else
    printf("invalid position.\n");
}

void delete_by_ele()
{
    int i,ele;
    if(ne==0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter The elements that should be deleted\n");
    scanf("%d",&ele);
    for(i=0;i<ne&&*(x+i)!=ele;i++);
    if(i==ne)
    {
        printf("element not found in The Array list\n");
        return;
    }
    for(;i<ne-1;i++)
    {
        *(x+i)=*(x+i+1);
    }
    ne--;
}

void search_by_key()
{
    int i,ele,f=0;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter The element that should be searched\n");
    scanf("%d",&ele);
    for(i=0;i<ne;i++)
    {
        if(*(x+i)==ele)
        {
            printf("element found at position %d\n",i+1);
            f=1;
            break;
        }
    }
        if(f==0)
        printf("element not found\n");
}

void search_by_pos()
{
    int pos,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter The position from where element should be searched\n");
    scanf("%d",&pos);
    if(pos>=1&&pos<=ne)
    {
        i=pos-1;
        printf("element at %d is %d\n",pos,*(x+i));
    }
    else
    printf("invalid position\n");
}

void reverse()
{
    int t,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    for(i=0;i<ne/2;i++)
    {
        t=*(x+i);
        *(x+i)=*(x+ne-i-1);
        *(x+ne-i-1)=t;
    }
}
void main()
{
 
    int choice;
    printf("Enter The size\n");
    scanf("%d",&size);
    x=(int *)malloc(size*sizeof(int)); 
    printf("Menu\n1.Read\n2.Display\n3.Insert by position\n4.Insert by order\n5.Delete by position\n6.Delete by element\n7.Search by key\n8.Search by position\n9.Reverse\n10.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: read();
                    disp();
                    break;
            case 2: disp();
                    break;
            case 3: insert_by_pos();
                    disp();
                    break;
            case 4: insert_by_order();
                    disp();
                    break;
            case 5: delete_by_pos();
                    disp();
                    break;
            case 6: delete_by_ele();
                    disp();
                    break;
            case 7: search_by_key();
                    break;
            case 8: search_by_pos();
                    break;
            case 9: reverse();
                    disp();
                    break;
            case 10 :       
                     exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
