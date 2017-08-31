#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct menu
{
char first[20], last[20],zip[5];
float score;
};
struct node {
struct menu data;
struct node* next;
};
struct node* head;

void Insert(struct menu x)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->data.score = x.score;
strcpy(temp->data.first, x.first);
strcpy(temp->data.last, x.last);
temp->next=head;
strcpy(temp->data.zip,x.zip);
temp->next = NULL;
if(head ==NULL)
{
head=temp;
return;
}
else if(head->next ==NULL)
{
    head->next = temp;
}
else{
   struct node  *temp1=head;
   struct node  *temp2= head->next;
while(temp2 !=NULL)
{

    temp2 = temp2->next;
    temp1 = temp1->next;
}
temp1->next= temp;
}
}

void print()
{
struct node *temp=head;
while(temp!=NULL)
{
printf("Firstname: %s ",temp->data.first);
printf("Lastname: %s ",temp->data.last);
printf("Score: %f ",temp->data.score);
printf("Zipcode: %s ",temp->data.zip);
temp=temp->next;
printf("\n\n");
}
}

void addrecord()
{
struct menu students;
scanf("%s %s %f %s",students.first,students.last,&students.score,students.zip);
Insert(students);
}
int indx(char *last)
{
int n = 0;
struct node *temp1 = head;
while(temp1 != NULL)
{
if ((strcmp(temp1->data.last, last))==0)
{
 return n;
}
n++;
temp1 = temp1->next;
}
return -1;
}

void swap(struct node *a, struct node *b)
{
    float temp = 0;
    char first[20], last[20], zip1[20];
    temp= a->data.score;
    a->data.score = b->data.score;
    b->data.score = temp;
    strcpy(first, a->data.first);
    strcpy(a->data.first,b->data.first);
    strcpy(b->data.first, first);
    strcpy(last, a->data.last);
    strcpy(a->data.last, b->data.last);
    strcpy(b->data.last, last);
    strcpy(zip1,a->data.zip);
    strcpy(a->data.zip, b->data.zip);
    strcpy(b->data.zip,zip1);
}

void deletenode(int n){
struct node *temp1 = head;
if (n==1){
head = temp1->next; //head now points to the second node
free(temp1);
return;
}
int i;
for(i=0;i<n-2;i++){
temp1=temp1->next; //temp1 points to (n-1)th node
}
struct node *temp2 = temp1->next; //nth node
temp1->next = temp2->next; //(n+1)th node
free(temp2); //delete temp2
}

void deleterecord()
{
char last[20];
printf("Please enter the lastname:");
scanf("%s", last);
int n = indx(last);
while(n != -1)
{
    deletenode(n+1);
    n = indx(last);

}

}




void zipcode(){
char zip1[20];
printf("Enter zipcode:");
scanf("%s", zip1);
struct node* temp1 = head;
while(temp1 != NULL)
{
    if((strcmp(temp1->data.zip, zip1))==0)
    {
        printf("Firstname: %s ",temp1->data.first);
        printf("Lastname: %s ", temp1->data.last);
        printf("Score: %f ", temp1->data.score);
        printf("Zipcode: %s\n\n", temp1->data.zip);
    }
    temp1 = temp1->next;
}
}

void scorerange(){
int max;
printf("Enter max score:");
scanf("%d", &max);
int min;
printf("Enter min score:");
scanf("%d", &min);
struct node* temp1 = head;
while(temp1 != NULL)
{
    if((temp1->data.score >= min)&&(temp1->data.score <=max))
    {
        printf("Firstname: %s ",temp1->data.first);
        printf("Lastname: %s ", temp1->data.last);
        printf("Score: %f ", temp1->data.score);
        printf("Zipcode: %s\n\n", temp1->data.zip);
    }
    temp1  = temp1->next;
}
}
void median(int n){

int swapped;
struct node* temp1;
struct node* temp2 = NULL;

do{
    swapped = 0;
    temp1 = head;
    
    while(temp1->next != NULL)
    {
        if(temp1->data.score > temp1->next->data.score)
        {
            swap(temp1, temp1->next);
            swapped = 1;
        }else{
        temp1 = temp1->next;
	
    }

}

    temp2 = temp1;
}while(swapped);
float a[n],median=0;
int i=0;
temp1=head;
 while(temp1->next != NULL)
    {
        a[i]=temp1->data.score;
temp1 = temp1->next;
i++;
}
if ( n % 2 == 0)                                        
        {median = (a[n/2] + a[n/2+1])/2.0;}                   
        else                                                    
        {median = a[n/2 + 1];}                                 
        printf("\nMedian is %f \n\n", median);    
}


int main()
{
	int n,i,j,choice=100;
	struct menu students[15];
	printf("How many records do you want to store:");
	scanf("%d",&n);
	printf("Enter students record in this format(first_name last_name score zipcode) and enter a new line after each record:\n");
	for(i=0;i<n;i++)
		{
		scanf("%s %s %f %s",students[i].first,students[i].last,&students[i].score,students[i].zip);
		Insert(students[i]);
		}
	while(choice!=0)
		{
		printf("Please choose from the following options:\n");
		printf("Print records (Press 1)\n");
		printf("Add a new record (Press 2)\n");
		printf("Delete records (Press 3)\n");
		printf("Search by zip code (Press 4)\n");
		printf("Search by score range (Press 5)\n");
		printf("Find median score (Press 7)\n");
		printf("Exit the program(Press 0)\n\n\n\n");
		scanf("%d",&choice);
		if(choice==0)
			{
			exit(0);
			}
		else if(choice==1)
			{
			print();
			}
		else if(choice==2)
			{
			addrecord();
			}
		else if(choice==3)
			{
			deleterecord();
			}
		else if(choice==4)
			{
			zipcode();
			}
		else if(choice==5)
			{
			scorerange();
			}
		else if(choice==7)
			{
			median(n);
			}

		}
return 0;
}

