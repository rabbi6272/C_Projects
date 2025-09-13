#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char source[20];
    char destination[20];
    char start[6];
    char end[6];
} Train;

void Admin()
{
    int t = 1;
    while (t)
    {
        int achoice;
        printf("1. Add train info\n2. Update train info\n3. Delete train info\n4. Exit\n[ADMIN] Please enter your choice: ");
        scanf("%d", &achoice);
        switch (achoice)
        {
        case 1:
            FILE *train_info = fopen("train_info.bin", "ab+");
            if (!train_info)
            {
                train_info = fopen("train_info.bin", "wb+");
            }
            // creates a new train info.
            int id;
            printf("Enter train id: ");
            scanf("%d", &id);
            char source1[20], destination1[20], start1[6], end1[6];
            printf("Enter starting station: ");
            scanf("%s", source1);
            printf("Enter destination station: ");
            scanf("%s", destination1);
            printf("Enter departure time: ");
            scanf("%s", start1);
            printf("Enter ending time: ");
            scanf("%s", end1);
            Train train1;
            train1.id = id;
            strcpy(train1.source, source1);
            strcpy(train1.destination, destination1);
            strcpy(train1.start, start1);
            strcpy(train1.end, end1);
            int s = fwrite(&train1, sizeof(train1), 1, train_info);
            if (s == 1)
                printf("Train info added successfully...\n");
            else
                printf("Error adding train info!!!\n");
            fclose(train_info);
            break;
        case 2:
            int aid;
            printf("Enter the train id: ");
            scanf("%d", &aid);

            break;
        case 4:
            t = 0;
            break;
        }
    }
}
void User() {}

int main()
{
    // opens the train_info binary file. If its not there it gets created.
    FILE *train_info = fopen("train_info.bin", "ab+");
    if (!train_info)
    {
        train_info = fopen("train_info.bin", "wb+");
    }

    int t = 1;
    while (t)
    {
        int choice;
        printf("1. Admin\n2. User\n3. Exit\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Admin();
            break;
        case 2:
            User();
            break;
        case 3:
            t = 0;
            break;
        }
    }

    // char des[20];
    // scanf("%s", des);
    // Train read;
    // while (fread(&read, sizeof(Train), 1, train_info) == 1)
    // {
    //     if (strcmp(des, read.destination) == 0)
    //     {
    //         printf("%d ", read.id);
    //         printf("%s ", read.source);
    //         printf("%s ", read.destination);
    //         printf("%s ", read.start);
    //         printf("%s\n", read.end);
    //     }
    // }
    // fclose(train_info);

    return 0;
}