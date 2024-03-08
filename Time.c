#include<stdio.h>
#include<stdlib.h>
struct time{
    int hr,sec,min;
};
void read(struct time *t){
   printf("Enter the time in hour minute second format\n");
   scanf("%d%d%d",&t->hr,&t->min,&t->sec);

}
void display(struct time* t){
    printf("Time is %d\t%d\t%d\n",t->hr,t->min,t->sec);

}

void update(struct time* t){
    t->sec++;
    if(t->sec>=60){
        t->min++;
        t->sec=t->sec%60;
        if(t->min>=60){
            t->hr++;
            t->min=t->min%60;
            if(t->hr>=24){
                t->min=t->hr=t->sec=0;
            }

        }
    }
    

}
void add(struct time* t1,struct time* t2,struct time* t3){
    (t3->sec)=(t1->sec)+(t2->sec);
     (t3->min)=(t1->min)+(t2->min);
      (t3->hr)=(t1->hr)+(t2->hr);

          if(t3->sec>=60){
        t3->min++;
        t3->sec=t3->sec%60;
        if(t3->min>=60){
            t3->hr++;
            t3->min=t3->min%60;
            if(t3->hr>=24){
                t3->min=t3->hr=t3->sec=0;
            }

        }
    }
    if(t3->min>=60){
            t3->hr++;
            t3->min=t3->min%60;
            if(t3->hr>=24){
                t3->min=t3->hr=t3->sec=0;
            }

        }
         if(t3->hr>=24){
                t3->min=t3->hr=t3->sec=0;
            }

      
}
void main(){
    struct time t1,t2,t3,t4;
    int choice;

    while(1){
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the time 1");
            read(&t1);
            printf("entered time is\n");
            display(&t1);
            printf("enter the time 2");
            read(&t2);
            printf("entered time is\n");
            display(&t2);
            break;
            case 2:
            printf("enter the time to be updated \n");
            read(&t3);
            printf("before update\n");
            display(&t3);
            update(&t3);
             printf("after update\n");
             display(&t3);
             break;
             case 3:
             add(&t1,&t2,&t4);
                printf("The sum of time t1 and t2 is ");
                display(&t3);
                break;
            case 4:
            exit(0);
            default:
            printf("enter the valid choice\n");
        
        }
    }
}