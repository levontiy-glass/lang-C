#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct Node** head, int data)
{
    struct Node* new_node = create_node(data);
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    
    struct Node* current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void print_forward(struct Node* head)
{
    printf("Прямой обход: ");
    struct Node* current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_backward(struct Node* head)
{
    printf("Обратный обход: ");
    struct Node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void free_list(struct Node* head)
{
    struct Node* current = head;
    while(current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Node* head = NULL;
    int n, value;
    
    printf("Введите количество элементов списка: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        printf("Введите элемент %d: ", i + 1);
        scanf("%d", &value);
        add_node(&head, value);
    }
    
    print_forward(head);
    print_backward(head);
    
    free_list(head);
    return 0;
}