#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

int main()
{
	int year, month;

	Welcome();
	year = GetYear();
	PrintCalendarForOneYear(year);
	return 0;
}