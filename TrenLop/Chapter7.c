#include <stdio.h>
#include <stdlib.h>
typedef struct Book bk;

struct Book
{
    char *title;
    char *author;
    char *subject;
    char *ID;
    int year;
}

// Another way to use typedef
typedef struct
{
    char *title;
    char *author;
    char *subject;
    char *ID;
    int year;
} Book;

void print_book(struct Book aBook)
{
    printf("Book title : %s\n", aBook.title);
    printf("Book author : %s\n", aBook.author);
    printf("Book subject : %s\n", aBook.subject);
    printf("Book book_id : %s\n", aBook.ID);
}

struct Book enter_book()
{
    struct Book aBook;
    printf("Enter the book title and year ");
    aBook.title = malloc(100);
    scanf("%s %d", aBook.title, &aBook.year);
    return aBook;
}

int main()
{
    struct Book book1 = {
        "Harry Potter", "JKRowling", "fiction", "Fi123", 2005};

    book1.author = "AAA";
    bk.title = "A";

    printf("Size of book struct is %lu \n", sizeof(Book));

    Book *p = &book1;
    printf("%s", (*p).title);
    printf("%s", p->title);

    struct Book fiction1 = {"Harry Potter", "JKRowling", "fiction", "Fi123", 2005};
    struct Book *boot_ptr = &fiction1;
    boot_ptr->subject = "HOANG DAT OC CHO";

    struct Book *tech1_ptr = (struct Book *)malloc(sizeof(struct Book));
    tech1_ptr->title = "Programming in C (4th Edition)";
    tech1_ptr->author = "Stephen Kochan";
    tech1_ptr->subject = "Basic programming";
    tech1_ptr->ID = "ProgC4";
    tech1_ptr->year = 2014;

    free(tech1_ptr);

    // Read File
    FILE *out_file = fopen("Skibidi.txt", "w");
    // w : Opens a text file for writing. If it does not exist, then a new
    // file is created.Here your program will start writing content from the beginning of the file

    // Copy file -> ram -> use pointer point to address have that content from the file

    while ((ch = fgetc(out_file)) != EOF)
        printf("%c", ch);
    return 0;
}