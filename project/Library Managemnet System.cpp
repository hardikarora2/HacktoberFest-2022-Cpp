#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct library
{
	char bookname[50];
	char author[50];
	int pages;
	float price;
};

int main()
{
	struct library l[100];
	char author_name[50], book_name[50];
	int i, j, result;
	i = j = result = 0;
	
	while(j != 6)
	{
		printf("\n1. Add Book Information\n");
		printf("2. Display Book Information \n");
		printf("3. List All The Books Of Given Author \n");
		printf("4. List the Title Of Specified Book \n");
		printf("5. List the Count of Books in the Library \n");
		printf("6. Exit! \n");
		
		printf("\n Enter one of the above : ");
		scanf("%d", &j);
		
		switch (j)
		{
			case 1:
				printf("Enter Book name: ");
				scanf("%s", l[i].bookname);
				
				printf("Enter the author name: ");
				scanf("%s", l[i].author);
				
				printf("Enter the number of Pages: ");
				scanf("%d", &l[i].pages);
				
				printf("Enter The price of the book: ");
				scanf("%f", &l[i].price);
				result++;
				
				break;
				
			case 2:
					printf("\n You have entered the following details\n");
					for(i=0; i<result; i++)
					{
						printf("\nBook Name : %s", l[i].bookname);
						
						printf("\t Author Name : %s", l[i].author);
						
						printf("\t Pages : %d", l[i].pages);
						
						printf("\t Price Of the book : %f\n", l[i].price);
					}
					break;
					
			case 3:
				
					printf("Enter the author name = ");
					scanf("%s", &author_name);
					for(i=0; i<result; i++)
					{
						if(strcmp(author_name, l[i].author) == 0)
						{
							printf("\n%s %s %d %f \n", l[i].bookname, l[i].author, l[i].pages, l[i].price);
						}
					}
				break;
				
			case 4:
				printf("Enter the Book Name: ");
				scanf("%s", book_name);
				for(i<0; i<result; i++)
				{
					if(strcmp(book_name, l[i].bookname) == 0)
					printf("\n%s %s %d %f\n", l[i].bookname, l[i].author, l[i].pages, l[i].price);
				}
			    break;
			    
			case 5:
				printf("\n No.of books in the Library = %d", result);
				break;
						
			case 6:
				printf("EXIT!!!");
				exit(0);

			
			default:
				printf("Invalid Input!!!! Please enter between 1 to 6");
				exit(0);
				break;
				
				}
				
		}
		return 0;
		
	}

