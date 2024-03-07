#include<stdio.h>
#include<stdlib.h>

int size,n;
struct student{
    char name[100];
    int rollnumber;
    float avg;
    int marks[3];

}*st;

void read(){
    printf("enter the number of students\n");
    scanf("%d",&n);
    if(n>size){
        printf("reallocating");
        size=n;
        st=(struct student *)realloc(st,n*sizeof(struct student));
        
        
    }
    for(int i=0;i<n;i++){
        printf("enter the details of %d\n",(i+1));
        printf("enter the name and  register number\n");
        scanf("%s%d",(st+i)->name,&(st+i)->rollnumber);
        printf("enter the marks in 3 subject\n");
        for(int j=0;j<3;j++){
            scanf("%d",&(st+i)->marks[j]);
            
            
        }
    }
    printf("\n");
}
void avg(){
    
    int sum=0;


    if(n==0){
        printf("no details present\n");
        return;
        
        
    }
    for(int i=0;i<n;i++){
        printf(" the details of %d\n",(i+1));
        printf(" the name students is \t%s  regpster  number %d\n",(st+i)->name,(st+i)->rollnumber);
      //  scanf("%s%d",(st+i)->name,(st+i)->rollnumber);
      printf("marks in 3 sub\n");
        for(int j=0;j<3;j++){
            printf("%d\t",(st+i)->marks[j]);
            
            
        }
          int min=(st+i)->marks[0];
          for(int j=0;j<3;j++){
              if((st+i)->marks[j]<min){
                min=(st+i)->marks[j];
              }
              

                  
              }
            sum=(st+i)->marks[0]+(st+i)->marks[1]+(st+i)->marks[2]-min;
            (st+i)->avg=(float)(sum)/2;
            printf("\n the average marks is %f\n",(st+i)->avg);
            
        }
            printf("\n");
        
    }
  void display(){
   
    if(n==0){
        printf("empry\n");
        return;
        
        
    }
    for(int i=0;i<n;i++){
        printf(" the details of %d\n",(i+1));
        printf(" the name of student is \t%s    register number is   %d\n",(st+i)->name,(st+i)->rollnumber);
      //  scanf("%s%d",(st+i)->name,(st+i)->rollnumber);
      printf("marks in 3 subject\n");
        for(int j=0;j<3;j++){
            printf("%d\t",(st+i)->marks[j]);
            
            
        }
        
            
        }
            printf("\n");
        
    }


    void main(){
        int choice;
        printf("enter the size\n");
        scanf("%d",&size);
        st=(struct student*)malloc(size*sizeof(struct student));
        
        while(1){
            printf("enter your choice \n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                read();
                break;
                case 2:
                avg();
                break;
                case 3:
                display();
                break;
                case 4:
                exit(0);
                default:
                printf("Enter the valid choice\n");

            }
        }
    }
