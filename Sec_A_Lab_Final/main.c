#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[20];
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
        printf("\n1. Add train info\n2. Update train info\n3. Delete train info\n4. Exit\n[ADMIN] Please enter your choice: ");
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
            char name1[20], source1[20], destination1[20], start1[6], end1[6];
            printf("Enter train name: ");
            scanf("%s", name1);
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
            strcpy(train1.name, name1);
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
            FILE *train_info1 = fopen("train_info.bin", "ab+");
            if (!train_info1)
            {
                printf("No train info available to update...\n");
                break;
            }
            FILE *train_info_tmp = fopen("train_info_tmp.bin", "ab+");
            int aid;
            printf("Enter the train id: ");
            scanf("%d", &aid);
            Train read;
            while (fread(&read, sizeof(Train), 1, train_info1) == 1)
            {
                if (aid != read.id)
                {
                    fwrite(&read, sizeof(Train), 1, train_info_tmp);
                }
                else
                {
                    char name1[20], source1[20], destination1[20], start1[6], end1[6];
                    printf("Enter updated train name: ");
                    scanf("%s", name1);
                    printf("Enter updated starting station: ");
                    scanf("%s", source1);
                    printf("Enter updated destination station: ");
                    scanf("%s", destination1);
                    printf("Enter updated departure time: ");
                    scanf("%s", start1);
                    printf("Enter updated ending time: ");
                    scanf("%s", end1);
                    Train train1;
                    train1.id = aid;
                    strcpy(train1.name, name1);
                    strcpy(train1.source, source1);
                    strcpy(train1.destination, destination1);
                    strcpy(train1.start, start1);
                    strcpy(train1.end, end1);
                    int s = fwrite(&train1, sizeof(Train), 1, train_info_tmp);
                    if (s == 1)
                        printf("Train info updated successfully...\n");
                    else
                        printf("Error updating train info!!!\n");
                }
            }
            fclose(train_info1);
            fclose(train_info_tmp);
            remove("train_info.bin");
            rename("train_info_tmp.bin", "train_info.bin");
            break;

        case 3:
            FILE *train_info2 = fopen("train_info.bin", "ab+");
            if (!train_info2)
            {
                printf("No train info available to delete...\n");
                break;
            }
            FILE *train_info_tmp1 = fopen("train_info_tmp.bin", "ab+");
            int did;
            printf("Enter the train id: ");
            scanf("%d", &did);
            Train read1;
            while (fread(&read1, sizeof(Train), 1, train_info2) == 1)
            {
                if (did != read1.id)
                {
                    fwrite(&read1, sizeof(Train), 1, train_info_tmp);
                }
            }
            printf("Train info deleted successfully...\n");
            fclose(train_info2);
            fclose(train_info_tmp1);
            remove("train_info.bin");
            rename("train_info_tmp.bin", "train_info.bin");
            break;

        case 4:
            t = 0;
            break;
        }
    }
}

void User()
{
    int t = 1;
    while (t)
    {
        int uchoice;
        printf("Welcome to train management system.\n");

        printf("1. Filter train info\n2. Search train info\n3. Exit\n[USER] Plaese enter your choice: ");
        scanf("%d", &uchoice);

        switch (uchoice)
        {
        case 1:
            FILE *train_info = fopen("train_info.bin", "rb+");
            if (!train_info)
            {
                printf("No available train info!!!\n");
            }
            Train read2;
            char start[20], end[20];
            printf("Enter start station: ");
            scanf("%s", start);
            printf("Enter end station: ");
            scanf("%s", end);
            printf("\n");

            int sl = 1;
            while (fread(&read2, sizeof(Train), 1, train_info) == 1)
            {
                if (strcmp(read2.source, start) == 0 && strcmp(read2.destination, end) == 0)
                {
                    printf("%d. ", sl++);
                    printf("%d ", read2.id);
                    printf("%s ", read2.name);
                    printf("%s ", read2.start);
                    printf("%s\n", read2.end);
                }
            }
            fclose(train_info);
            break;

        case 2:
            int utid;
            printf("Enter train id to search: ");
            scanf("%d", &utid);
            FILE *train_info2 = fopen("train_info.bin", "rb+");
            if (!train_info2)
            {
                printf("No available train info!!!\n");
            }
            Train read3;
            while (fread(&read3, sizeof(Train), 1, train_info2) == 1)
            {
                if (read3.id == utid)
                {
                    printf("%d ", read3.id);
                    printf("%s ", read3.name);
                    printf("%s ", read3.source);
                    printf("%s ", read3.destination);
                    printf("%s ", read3.start);
                    printf("%s\n", read3.end);
                }
            }
            fclose(train_info2);
            break;

        case 3:
            t = 0;
            break;
        }
    }
}

int main()
{
    int t = 1;
    while (t)
    {
        int choice;
        printf("\n1. Admin\n2. User\n3. Exit\nPlease enter your choice: ");
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
    return 0;
}