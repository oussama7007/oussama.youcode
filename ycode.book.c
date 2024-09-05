
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

char titles[MAX_BOOKS][MAX_TITLE_LENGTH];
char authors[MAX_BOOKS][MAX_AUTHOR_LENGTH];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];

int book_count = 0;

void add_book() 
{
    if (book_count >= MAX_BOOKS) 
    {
        printf("Stock is full. Can't add more books.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    printf("Enter book title: ");
    scanf(" %[^\n]", title);

    int i = 0;
    while (i < book_count) 
    {
        if (strcmp(titles[i], title) == 0) 
        {
            printf("The book '%s' already exists in the library.\n", title);
            return;
        }
        i++;
    }

    strcpy(titles[book_count], title);
    printf("Enter author name: ");
    scanf(" %[^\n]", authors[book_count]);
    printf("Enter book price: ");
    scanf("%f", &prices[book_count]);
    printf("Enter quantity in stock: ");
    scanf("%d", &quantities[book_count]);
    
    book_count++;
    printf("Book added successfully.\n");
}

void show_books() {
    if (book_count == 0) {
        printf("No books in stock.\n");
        return;
    }

    int i = 0;
    while (i < book_count) {
        printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
               titles[i], authors[i], prices[i], quantities[i]);
        i++;
    }
}

void update_quantity() {
    char title[MAX_TITLE_LENGTH];
    int new_quantity;

    printf("Enter the title of the book: ");
    scanf(" %[^\n]", title);

    int i = 0;
    while (i < book_count) {
        if (strcmp(titles[i], title) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            quantities[i] = new_quantity;
            printf("Quantity updated successfully.\n");
            return;
        }
        i++;
    }

    printf("Book not found.\n");
}

void remove_book() {
    char title[MAX_TITLE_LENGTH];

    printf("Enter the title of the book to remove: ");
    scanf(" %[^\n]", title);

    int i = 0;
    while (i < book_count) {
        if (strcmp(titles[i], title) == 0) {
            int j = i;
            while (j < book_count - 1) 
            {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
                j++;
            }
            book_count--;
            printf("Book removed successfully.\n");
            return;
        }
        i++;
    }

    printf("Book not found.\n");
}

void total_books() {
    int total = 0;
    int i = 0;

    while (i < book_count) {
        total += quantities[i];
        i++;
    }

    printf("Total number of books in stock: %d\n", total);
}

int main() {
    int choice;

    while (true) 
    {
        printf("\nBookstore Management System\n");
        printf("1. Add a book to stock\n");
        printf("2. Show all available books\n");
        printf("3. Update the quantity of a book\n");
        printf("4. Remove a book from stock\n");
        printf("5. Show total number of books in stock\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_book();
        } else if (choice == 2) {
            show_books();
        } else if (choice == 3) {
            update_quantity();
        } else if (choice == 4) {
            remove_book();
        } else if (choice == 5) {
            total_books();
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
