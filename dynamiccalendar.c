#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

int main()
{
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char *weekDay = malloc(sizeof(char) * 10), *time;
    int monthDay, respectiveDay, newDay;
    bool found = false;

    printf("What day of the month is it?\n");
    if(!scanf("%i", &monthDay) || (monthDay < 1 || monthDay > 31))
    {
        printf("Invalid day\n");
        free(weekDay);
        return 1;
    }

    printf("What day of the week is it?\n");
    scanf("%s", weekDay);

    for(int i = 0; i < 7; i++)
    {
    if(strcasecmp(weekDay, week[i]) == 0)
    {
        found = true;
        respectiveDay = i;
    }
    }

    if(found == false)
    {
        printf("Invalid day\n");
        free(weekDay);
        return 2;

    }

    printf("What day do you want to know?\n");
    if(!scanf("%i", &newDay) || (newDay < 1 || newDay > 31))
    {
        printf("Invalid day\n");
        free(weekDay);
        return 3;
    }

    int factor = (newDay - monthDay) % 7;

    if(newDay - monthDay == 0)
    {
        printf("This is today!\n");
        free(weekDay);
        return 4;
    }

    if(factor > 0)
    {
        time = "is going to be";
    }
    else if(factor < 0)
    {
        time = "was";
    }

    else
    {
        printf("This day is the same as today\n");
        free(weekDay);
        return 5;
    }

    if(respectiveDay + factor < 0)
    {
        printf("This day %s a %s\n", time, week[respectiveDay + (7 + factor)]);
    }

    else if(respectiveDay + factor > 6)
    {
        printf("This day %s a %s\n", time, week[respectiveDay + factor - 7 ]);
    }

    else
    {
    printf("This day %s a %s\n", time, week[respectiveDay + factor]);
    }
    free(weekDay);
}
