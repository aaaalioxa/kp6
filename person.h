#ifndef KP6_PERSON_H
#define KP6_PERSON_H

typedef struct Person{
    char lastName[50];
    char io[50];
    char gender[50];
    int schoolNum;
    char isMedal[3];
    int Math, Rus, Inf;
    char essay[3];
} Person;

int StudentReadTxt(Person *s, FILE *in);
void StudentWriteBin(Person *s, FILE *out);
void StudentPrint(Person *s);
int StudentReadBin(Person *s, FILE *in2);
bool IsStudExists(Person *student, FILE *in2);

#endif //KP6_PERSON_H
