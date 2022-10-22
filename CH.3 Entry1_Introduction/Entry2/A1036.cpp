//Boys vs Girls(it's not fair!)
#include <stdio.h>

struct stu
{
    char name[12];
    char sex;
    char id[12];
    int grade;
} highest, lowest, temp;

void init()
{
    highest.sex = 'F';
    highest.grade = -1;

    lowest.sex = 'M';
    lowest.grade = 101;
}

int main()
{
    init();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %c %s %d", &temp.name, &temp.sex, &temp.id, &temp.grade);
        if (temp.sex == highest.sex && temp.grade >= highest.grade)
            highest = temp;
        if (temp.sex == lowest.sex && temp.grade <= lowest.grade)
            lowest = temp;
    }

    highest.grade == -1 ? printf("Absent\n") : printf("%s %s\n", highest.name, highest.id);

    lowest.grade == 101 ? printf("Absent\n") : printf("%s %s\n", lowest.name, lowest.id);

    (highest.grade == -1 || lowest.grade == 101) ? printf("NA") : printf("%d", highest.grade - lowest.grade);

    return 0;
}