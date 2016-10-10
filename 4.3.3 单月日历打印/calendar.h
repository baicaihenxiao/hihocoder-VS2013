typedef enum __BOOL {FALSE, TRUE} BOOL;

void Welcome();

int GetYear();

int GetMonth();

void PrintCalendar(int year, int month);

BOOL IsLeapYear(int year);

int CalculateDaysBefore(int year);

int CalculateDaysOfMonth(int year, int month);

int CalculateFirstWeekday(int year, int month);