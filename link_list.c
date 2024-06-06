#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int no;
    int age;
    struct student *next;
};

struct student *head = NULL;
struct student *tail = NULL;

int addNode(int a, int b)
{
    if (head == NULL)
    {
        struct student *new = (struct student *)malloc(sizeof(struct student));
        new->age = b;
        new->no = a;
        new->next = NULL;

        head = tail = new;
    }
    else
    {
        struct student *new = (struct student *)malloc(sizeof(struct student));
        new->age = b;
        new->no = a;
        new->next = NULL;

        tail->next = new;

        tail = new;
    }

    return 0;
}

int addNodeHead(int a, int b)
{
    if (head == NULL)
    {
        struct student *new = (struct student *)malloc(sizeof(struct student));
        new->age = b;
        new->no = a;
        new->next = NULL;

        head = tail = new;
    }
    else
    {
        struct student *new = (struct student *)malloc(sizeof(struct student));
        new->age = b;
        new->no = a;

        new->next = head;
        head = new;
    }

    return 0;
}

int deleteNode(int a, int b)
{
    struct student *index = head;
    struct student *prev = NULL;

    while (index->no != a && index->age != b)
    {
        prev = index;
        index = index->next;
    }
    if (index->no==head->no&&index->age==head->age)
    {
        struct student *t = head;
        head = head->next;
        free(t);
        return 1;
    }
        else if(tail->no==index->no&&tail->age==index->age)
    {
        tail=prev;
    }
    else{
        prev->next = index->next;
    
    }
    tail->next=NULL;
    free(index);
    return 0;
}

int print()
{
    struct student *index = head;
    while (index != NULL)
    {
        printf("%d - ", index->no);
        printf("%d\n", index->age);
        index = index->next;
    }

    return 0;
}

int main()
{

    addNode(66, 20);
    addNode(31, 323);
    addNode(2, 54);
    addNode(67, 21);
    addNode(8, 88);
    addNode(10, 99);

    addNodeHead(22, 1);

        deleteNode(10, 99);
    print();
    return 0;
}