#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "person.h"

int StudentReadTxt(Person *s, FILE *in) {
    fscanf(in, "%s", s->lastName);
    fscanf(in, "%s", s->io);
    fscanf(in, "%s", s->gender);
    fscanf(in, "%d", &(s->schoolNum));
    fscanf(in, "%s", s->isMedal);
    fscanf(in, "%d", &(s->Math));
    fscanf(in, "%d", &(s->Rus));
    fscanf(in, "%d", &(s->Inf));
    fscanf(in, "%s", s->essay);
    return !feof(in);
}

void StudentWriteBin(Person *s, FILE *out) {
    fwrite(s->lastName, sizeof(char), 50, out);
    fwrite(s->io, sizeof(char), 50, out);
    fwrite(s->gender, sizeof(char), 50, out);
    fwrite(&(s->schoolNum), sizeof(int), 1, out);
    fwrite(s->isMedal, sizeof(char), 3, out);
    fwrite(&(s->Math), sizeof(int), 1, out);
    fwrite(&(s->Rus), sizeof(int), 1, out);
    fwrite(&(s->Inf), sizeof(int), 1, out);
    fwrite(s->essay, sizeof(char), 3, out);
}

void StudentPrint(Person *s){
    printf("         -------------|------|----------------|-------------|-----------|--------|-------|-------|---------\n");
    printf("%20s  |", s->lastName);
    printf("  %s  |", s->io);
    printf("   %8s     |", s->gender);
    printf("%8d\t    |", (s->schoolNum));
    printf("%7s\t|", s->isMedal);
    printf("%5d\t |", (s->Math));
    printf("%5d\t |", (s->Rus));
    printf("%5d\t |", (s->Inf));
    printf("%6s\n", s->essay);
}

int StudentReadBin(Person *s, FILE *in2) {
    fread(s->lastName, sizeof(char), 50, in2);
    fread(s->io, sizeof(char), 50, in2);
    fread(s->gender, sizeof(char), 50, in2);
    fread(&(s->schoolNum), sizeof(int), 1, in2);
    fread(s->isMedal, sizeof(char), 3, in2);
    fread(&(s->Math), sizeof(int), 1, in2);
    fread(&(s->Rus), sizeof(int), 1, in2);
    fread(&(s->Inf), sizeof(int), 1, in2);
    fread(s->essay, sizeof(char), 3, in2);
    return !feof(in2);
}

bool IsStudExists(Person *student, FILE *in2) {
    int i = 0;
    while (StudentReadBin(student, in2)) {
        if (strcmp(student->isMedal, "yes") == 0 && student->Math <= 2){
            i++;
        }
    }
    if (i == 0)
        return 0;
    else
        return 1;
}