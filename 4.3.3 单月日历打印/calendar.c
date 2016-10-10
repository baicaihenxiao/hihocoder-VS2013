#include <stdio.h>
#include "calendar.h"

static const int START_YEAR = 2010;
static const int START_WEEKDAY = 5;

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


void PrintCalendar(int year, int month)
{
	int weekday, days_of_month;
	int i;
	weekday = CalculateFirstWeekday(year, month);
	days_of_month = CalculateDaysOfMonth(year, month);


}