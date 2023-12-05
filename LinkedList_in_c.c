//<------------------Linked list ---------------------------->
#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *add;
   
};struct node *start = NULL ,*new1,*temp ,*prev,*next;
void main(){
    int choice;
  do{
    printf("\n------------------------------Linked List Menu----------------------- ");
    printf("\n1. Create");
    printf("\n2. Display");
    printf("\n3. Insert First: ");
    printf("\n4. Insert Last:");
    printf("\n5. Insert Middle:");
    printf("\n6. Delete First:");
    printf("\n7. Delete Middle:");
    printf("\n8. Delete Last:");
    printf("\n9. Search Mode:");
    printf("\n10.Count Mode!");
    printf("\n11.Sort!");
    printf("\n12.Exit!");
    printf("\n------------------------------------------------------------------------");
    printf("\n Enter Your Choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:create();break;
    case 2:display();break;
    case 3:insert_first();break;
    case 4:insert_last();break;
    case 5:insert_middle();break;
    case 6:delete_first();break;
    case 7:delete_middle();break;
    case 8:delete_last();break;
    case 9:search();break;
    case 10:count();break;
    case 11:sort();break;
    default: printf("Invalid choice:)");
    }

    }while(choice!=12);
}
//<-------sort ---->
sort(){
    int temp1;
    if(start == NULL)
    printf("\n List not found:)");
    else{
        prev = start;
        while(prev != NULL){
            next = prev -> add;
            while(next != NULL){
                if(next->data < prev->data){
                    temp1=prev->data;
                    prev->data=next->data;
                    next->data=temp1;
                }
                next = next->add;

            }
            prev = prev->add;
            
        }
        printf("Element is sorted:)");
    }
}

//<------ Creating Linked list ------->
create(){
    int n;
    char ch;
    printf("\n Enter First Element: ");
    scanf("%d",&n);
    start = (struct node*)(malloc(sizeof(struct node)));
    start ->data = n;
    start ->add = NULL;
    temp = start;
    printf("\n Do you want to continue :");
    ch = getche();
    while(ch=='y'|| ch=='Y'){
        printf("\nEnter next element:");
        scanf("%d",&n);
        new1 =(struct node*)(malloc(sizeof(struct node*)));
        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = temp -> add;
    printf("\n Do you want to continue :");
    ch = getche();

    }
}
display(){
    if (start ==  NULL)
    printf("\n List not found!");
    else{
        temp = start;
        while(temp!=NULL){
            printf("%d\t",temp -> data);
            temp = temp -> add;
        }
    }
}
insert_first(){
    int n;
     if (start ==  NULL)
    printf("\n List not found!");
    else{
        printf("\n Enter element for insert :");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add = NULL;
        new1 -> add =start;
        start = new1;

    }
}
insert_last(){
    int n;
    if(start ==  NULL)
    printf("\n List is not found:)");
    else{
        printf("\nEnter element for insert: ");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add =NULL;
        temp = start;
        while (temp -> add != NULL){
            temp = temp -> add;
        }
        temp -> add =new1;

    }
}
insert_middle(){
    int n,pos,i=1;
    if(start == NULL)
    printf("\n List not found:)");
    else{
        printf("\n Enter element for insert:");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1 -> data = n;
        new1 -> add =NULL;
        printf("\n Enter position of middle:");
        scanf("%d",&pos);
        next = start;
        while(i<pos){
            prev = next;
            next = next -> add;
            i++;

        }
        prev -> add = new1;
        new1 -> add = next;

    }
}
delete_first(){
   
    if(start == NULL)
    printf("\nList not found:)");
   else{
    temp = start;
    start = start -> add;
    printf("\nDelete element in:%d",temp -> data);
    free(temp);
   }

    
}
delete_middle(){
    int pos,i=1;
    if(start == NULL)
    printf("\nList not found:)");
    else{
        printf("\nEnter the position:");
        scanf("%d",&pos);
        temp = start;
        while(i<pos){
            prev = temp;
            temp = temp -> add;
            i++;
        }
        next = temp -> add;
        prev -> add = next;
        printf("\nDeleted element is:%d",temp -> data);
        free(temp);
    }
    
}
delete_last(){
   
    if(start == NULL)
    printf("\n List not found:)");
    else{
        temp = start;
        while(temp -> add != NULL){
            prev = temp;
            temp = temp -> add;
        }
        prev -> add = NULL;
        printf("\nDelete element is:%d",temp->data);
        free(temp);
    }
 
    
}
//-------Searching element------------------>
search(){
    int s,f=0;
    if(start==NULL)
    printf("\nList not found!");

    else{
        printf("\nEnter an element for search:");
        scanf("%d",&s);
        temp=start;
        while(temp!= NULL){
            if(s == temp -> data )
            {
                f=1;
                break;
            }
            temp = temp -> add;
        }
        if(f==1)
        printf("\nSerching sussesfully !");
        else
        printf("\nSearching not sussesfully!");
        
    }
}

//<------count------------------>
count(){
    int count = 0;
    if(start == NULL){
        printf("\nList not found!");
    }else{

    
    temp = start;
    while (temp!=NULL){
        count++;
        temp = temp->add;

        }
         printf("\nTotal node is:%d",count);
    }
   
}

//<-------------reverse the element ----------->
// reverse(){
//     int i;
//     if(start == NULL){
//         printf("List not found!");

//     }
//     else{
//         i=0;
//         temp=start;
//         while(temp!=NULL)
//         {
//             ar[i] = temp;
//             i++;
//             temp = temp->add;
//         }
//         i--;
//         printf("Reverse elements!");
//         while(i>=0){
//             printf("%d",ar[i] -> data);
//             i--;
//         }
//     }
// }



