#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

int main()
{
	int year, month;

	Welcome();
	year = GetYear();
	month = GetMonth();
	PrintCalendar(year, month);
	return 0;
}