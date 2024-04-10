#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    char answer[20];
    char currentMonth[20];
    printf("Are we on a regular year or a leap one?\n");
    scanf("%s", answer);
    int february, Month, todayNum, todayWeek, newDay, newMonth, distance, sum = 0, factor;
    bool found = false;

    if (strcasecmp(answer, "leap") == 0)
    {
        february = 29;
    }

    else if (strcasecmp(answer, "regular") == 0)
    {
        february = 28;
    }

    else
    {
        printf("Invalid answer\n");
        return 1;
    }

    int monthDays[] = {31, february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {"January", "February", "March",     "April",   "May",      "June",
                      "July",    "August",   "September", "October", "November", "Decebember"};
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("What month is it?\n");
    if (!scanf("%s", currentMonth))
    {
        printf("Invalid month\n");
        return 2;
    }

    for (int i = 0; i < 12; i++)
    {
        if (strcasecmp(currentMonth, months[i]) == 0)
        {
            found = true;
            Month = i;
        }
    }

    if (found == false)
    {
        printf("Invalid month\n");
        return 3;
    }

    found = false;

    printf("What day of the month is it?\n");

    if (!scanf("%i", &todayNum) || (todayNum < 1 || todayNum > monthDays[Month]))
    {
        printf("Invalid day\n");
        return 4;
    }

    printf("What day of the week is it?\n");

    if (!scanf("%s", answer))
    {
        printf("Invalid day\n");
    }

    for (int i = 0; i < 7; i++)
    {
        if (strcasecmp(answer, week[i]) == 0)
        {
            found = true;
            todayWeek = i;
        }
    }

    if (found == false)
    {
        printf("Invalid day\n");
        return 5;
    }

    found = false;

    printf("What day of which month do you want to know? (Write day number and then the month's "
           "name?)\n");
    if (!scanf("%i %s", &newDay, answer))
    {
        printf("Invalid answer\n");
        return 6;
    }

    for (int i = 0; i < 12; i++)
    {
        if (strcasecmp(answer, months[i]) == 0)
        {
            newMonth = i;
            found = true;
        }
    }

    if (found == false)
    {
        printf("Invalid month\n");
        return 7;
    }

    if (newDay < 1 || newDay > monthDays[newMonth])
    {
        printf("Invalid month\n");
        return 8;
    }

    distance = monthDays[Month] - todayNum;

    if (Month == newMonth)
    {
        sum = 0;
        distance = 0;
        newDay -= todayNum;
    }

    else if (Month > newMonth)
    {
        if (Month - 1 == newMonth)
        {
            sum = 0;
        }
        else
            for (int i = Month - 1; i > newMonth; i--)
            {

                sum += monthDays[i];
            }
    }

    else if (Month < newMonth)
    {
        if (Month + 1 == newMonth)
        {
            sum = 0;
        }
        else
            for (int i = Month + 1; i < newMonth; i++)
            {

                sum += monthDays[i];
            }
    }

    factor = (distance + sum + newDay) % 7;

    if (todayWeek + factor < 0)
    {
        printf("This day is a %s\n", week[todayWeek + (7 + factor)]);
    }

    else if (todayWeek + factor > 6)
    {
        printf("This day is a %s\n", week[todayWeek + factor - 7]);
    }

    else
    {
        printf("This day is a %s\n", week[todayWeek + factor]);
    }
}
