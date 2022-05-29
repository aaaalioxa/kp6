#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "person.h"

void Usage() {
    printf("Wrong input!\n");
    printf("Usage: -f <input file> (for printing database)\n");
    printf("       -p <input file> (for finding students)\n");
    exit(404);
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    if (argc != 3) {
        Usage();
    }
    Person student;
    FILE *fIn2 = fopen(argv[2], "w");
    FILE *fOut = fopen("output.txt", "w");
    if (!fIn2 || !fOut) {
        printf("Can't open file!\n");
    }
    Random(fIn2);
    fclose(fIn2);
    FILE *fIn = fopen(argv[2], "r");
    fseek(fIn, 0, SEEK_SET);
    if (strcmp(argv[1],"-f") == 0) {
        printf("            Surname   |  IO  |     Gender     |    School   |   Medal   |  Math  |  Rus  |  Inf  |  Essay\n");
        while (StudentReadTxt(&student, fIn)) {
            StudentPrint(&student);
        }
        //StudentPrint(&student);
        fclose(fIn);
        fclose(fOut);
        return 0;
    }
    else if (strcmp(argv[1],"-p") == 0) {
        while (StudentReadTxt(&student, fIn)) {
            StudentWriteBin(&student, fOut);
        }
        StudentWriteBin(&student, fOut);
        fclose(fOut);
        fclose(fIn);
        FILE *in2 = fopen("output.txt", "r");
        fseek(in2, 0, SEEK_SET);
        if (IsStudExists(&student, in2)) {
            fseek(in2, 0, SEEK_SET);
            printf("            Surname   |  IO  |     Gender     |    School   |   Medal   |  Math  |  Rus  |  Inf  |  Essay\n");
            while (StudentReadBin(&student, in2)) {
                if (strcmp(student.isMedal, "yes") == 0 && student.Math <= 2) {
                    StudentPrint(&student);
                }
            }
        }
        else {
            printf("No such students\n");
        }
        fclose(in2);
        return 0;
    }
    else
        Usage();
    return 0;
}
