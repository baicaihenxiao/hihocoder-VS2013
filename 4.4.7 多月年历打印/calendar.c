#include <stdio.h>
#include "calendar.h"

static const int START_YEAR = 2000;
static const int START_WEEKDAY = 6;


void Welcome()
{
	printf("This program receives a year and a month, and then prints the calendar.\n");
}

int GetYear()
{
	int year;
	printf("Please input the year:");
	scanf("%d", &year);

	while (year < START_YEAR)
	{
		printf("The year cannot be earlier than %d! \n", START_YEAR);
		printf("please input the year:");
		scanf("%d", &year);
	}

	return year;
}


int GetMonth()
{
	int month;
	printf("Please input the month:");
	scanf("%d", &month);

	while (month < 1 || month > 12)
	{
		printf("The month should be between 1 ~ 12. \n");
		printf("please input the month:");
		scanf("%d", &month);
	}

	return month;
}

void PrintCalendarForOneYear(int year)
{
	int i = 0;
	for (i = 0; i < 3; ++ i)
	{
		PrintCalenderWith4Month(year, i * 4 + 1);
	}
}

void PrintCalenderWith4Month(int year, int beginMonth)
{
	int i = 0, j = 0;
	int days_of_month[4], weekday[4], currentDay[4];
	for (i = 0; i < 4; ++i)
	{
		days_of_month[i] = CalculateDaysOfMonth(year, beginMonth + i);
		weekday[i] = CalculateFirstWeekday(year, beginMonth + i);
		currentDay[i] = 1;
	}
	for (i = 0; i < 4; ++ i)
	{
		printf("   Calendar %4d-%2.2d  ", year, beginMonth + i);
	}

	printf("\n -------------------------------------------------------------------------------------\n");
	printf(" Mo Tu We Th Fr Sa Su Mo Tu We Th Fr Sa Su Mo Tu We Th Fr Sa Su Mo Tu We Th Fr Sa Su\n");
	printf(" ---------------------------------------------------------------------------------------\n");

	for (i = 0; i < 4; ++i)
	{
		for (j = 1; j < weekday[i]; ++ j)
		{
			printf("   ");
		}
		for (j = weekday[i]; j <= 7; ++ j)
		{
			printf("%3d", currentDay[i]);
			++currentDay[i];
		}
	}
	printf("\n");

	while (currentDay[0] <= days_of_month[0] || currentDay[1] <= days_of_month[1] || currentDay[2] <= days_of_month[2] || currentDay[3] <= days_of_month[3])
	{
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 7; ++j)
			{
				if (currentDay[i] <= days_of_month[i])
				{
					printf("%3d", currentDay[i]);
					++currentDay[i];
				}
				else
				{
					printf("   ");
				}
			}
		}
		printf("\n");
	}
	
	printf(" ---------------------------------------------------------------------------------------\n");

}



BOOL IsLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int CalculateDaysBefore(int year)
{
	int i;
	int days_before = 0;
	
	if (year == START_YEAR)
		return 0;
	else
	{
		for (i = START_YEAR; i < year; ++ i)
		{
			if (IsLeapYear(i))
			{
				days_before += 366;
			}
			else
			{
				days_before += 365;
			}
		}
	}

	return days_before;
}

int CalculateDaysOfMonth(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month != 2)
		return 30;
	else
		return 28 + (int)IsLeapYear(year);
}

int CalculateFirstWeekday(int year, int month)
{
	int i, days_before;
	days_before = CalculateDaysBefore(year);

	if (month >= 2)
	{
		for (i = 1; i < month; ++ i)
		{
			days_before += CalculateDaysOfMonth(year, i);
		}
	}

	int res = (days_before + START_WEEKDAY) % 7;

	if (res == 0)
		return 7;
	else
		return res;
}