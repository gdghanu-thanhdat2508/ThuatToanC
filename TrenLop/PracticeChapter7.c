#include <stdio.h>
#include <string.h>

struct Item
{
    char name[20];
    int price;
    int quantity;
};

int findItemByName(struct Item items[], char *name)
{
    for (int i = 0; i < sizeof(struct Item); i++)
    {
        if (strcmp(items[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Item items[100];
    int choice;
    int itemCount = 1;

    while (1)
    {
        printf("\n1. Add/Update Item\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char name[20];
            int price, quantity;

            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item price: ");
            scanf("%d", &price);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);

            int index = findItemByName(items, name);
            if (index == 1)
            {
                items[index].price = price;
                items[index].quantity += quantity;
                printf("Item updated -> %s", items[index].name);
            }
            else
            {

                strcpy(items[itemCount].name, name);
                items[itemCount].price = price;
                items[itemCount].quantity = quantity;
                itemCount++;
                printf("Item added: %s", items[itemCount].name);
                break;
            }
            // Display the item
            printf("Name: %s\n", name);
            printf("Price: %d\n", price);
            printf("Quantity: %d\n", quantity);
            break;
        }

        case 2:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            // Invalid choice
            printf("INVALID CHOICE. Please try again.\n");
            break;
        }
    }

    return 0;
}