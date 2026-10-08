#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BOOK_NAME 64
#define LANGUAGE_CODE 4
#define SERIES 7


struct key {
    char name[BOOK_NAME];
    double price;
    int pages;
    char language[LANGUAGE_CODE];
    float weight;
    int publication_date;
};

struct List {
    struct key *value;
    struct List *next;

};

struct key * listSearch(struct List *, char []);
void bookInput(struct key *);
void bookInformation(const struct key *);
void seriesInformation(const struct List *);
void listInsert(struct List **, struct key *);
void listDelete(struct List **, char []);
void freeList(struct List *head);


int main(void) {

    struct key books[SERIES], * book;
    struct List * head = NULL;

    char title[BOOK_NAME];
    int i = 0, option;

    while (1) {

        printf("Choose the option you want to pursue\n"
               "1 - to insert the book    2 - to search the book"
               "    3 - to delete the book    4 - to finish"
               "    \nAny other digit - to check out the list of series"
               "\n");

        if (scanf("%d", &option) != 1)
            break;

        if (option == 4)
            break;

        switch (option) {
            case 1:
                if (i >= SERIES) {
                    printf("The series is full\n");
                    break;
                }
                printf("Provide the information about the book -> #%d\n", i + 1);
                bookInput(books + i);
                listInsert(&head, books + i);
                ++i;
                break;
            case 2:
                printf("Enter the book, information of which you are looking for ->");
                scanf(" %63[^\n]", title);
                book = listSearch(head, title);
                if (book != NULL) {
                    printf("The book you looked for ->\n");
                    bookInformation(book);
                } else
                    printf("Book not found\n");
                break;
            case 3:
                printf("Enter the book you wish to delete from list -> ");
                scanf(" %63[^\n]", title);
                listDelete(&head, title);
                break;
            default:
                seriesInformation(head);
                break;
        }
    }

    printf("Well done, here is a list of series you filled up\n");
    seriesInformation(head);
    freeList(head);

    return 0;
}

void bookInput(struct key * book) {
    printf("title -> ");
    scanf(" %63[^\n]", book->name);
    printf("price in $ -> ");
    scanf("%lf", &book->price);
    printf("pages -> ");
    scanf("%d", &book->pages);
    printf("language -> ");
    scanf("%3s", book->language);
    printf("weight in g. -> ");
    scanf("%f", &book->weight);
    printf("publication date yyyy -> ");
    scanf("%d", &book->publication_date);
}

void bookInformation(const struct key * book) {
    printf("Book overview:\n title -> %s\n", book->name);
    printf("price -> %f\n", book->price);
    printf("pages -> %d\n", book->pages);
    printf("language -> %s\n", book->language);
    printf("weight -> %f\n", book->weight);
    printf("publication date -> %d\n", book->publication_date);
}

void seriesInformation(const struct List * head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    const struct List *current = head;
    while (current != NULL) {
        bookInformation(current->value);
        current = current->next;
    }
}

void listInsert(struct List **head, struct key *book) {
    struct List *new_node = malloc(sizeof(struct List));
    if (new_node == NULL)
        return;
    new_node->value = book;
    new_node->next = *head;
    *head = new_node;
}

void listDelete(struct List **head, char name[]) {
    struct List *prev = NULL;
    struct List *current = *head;

    while (current != NULL && strcmp(current->value->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    if (prev != NULL)
        prev->next = current->next;
    else
        *head = current->next;

    free(current);

}


struct key *listSearch(struct List *head, char name[]) {
    struct List *current = head;
    while (current != NULL && strcmp(current->value->name, name) != 0)
        current = current->next;

    if (current == NULL)
        return NULL;

    return current->value;
}

void freeList(struct List *head) {
    struct List *next;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}