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

int main()
{
    // opens the train_info binary file. If its not there it gets created.
    FILE *train_info = fopen("train_info.bin", "rb+");
    if (!train_info)
    {
        train_info = fopen("train_info.bin", "wb+");
    }

    // creates a new train info.
    //  int id;
    //  scanf("%d", &id);
    //  char source1[20], destination1[20], start1[6], end1[6];
    //  printf("Enter starting station: ");
    //  scanf("%s", source1);
    //  printf("Enter destination station: ");
    //  scanf("%s", destination1);
    //  scanf("%s", start1);
    //  scanf("%s", end1);
    //  Train train1;
    //  train1.id = id;
    //  strcpy(train1.source, source1);
    //  strcpy(train1.destination, destination1);
    //  strcpy(train1.start, start1);
    //  strcpy(train1.end, end1);
    //  fwrite(&train1, sizeof(train1), 1, train_info);
    //  rewind(train_info);

    char des[20];
    scanf("%s", des);

    Train read;
    while (fread(&read, sizeof(Train), 1, train_info) == 1)
    {
        if (strcmp(des, read.destination) == 0)
        {
            printf("%d ", read.id);
            printf("%s ", read.source);
            printf("%s ", read.destination);
            printf("%s ", read.start);
            printf("%s\n", read.end);
        }
    }
    fclose(train_info);

    return 0;
}