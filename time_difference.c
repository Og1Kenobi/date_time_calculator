#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct TimeDifference {
    int years;
    int months;
    int weeks;
    int days;
    int hours;
    int minutes;
};

int validate_date(const char* date) {
    // Validate date format (YYYY-MM-DD)
    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
        return 0;
    }

    // Validate year, month, and day ranges
    if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }

    return 1;
}

int validate_time(const char* time) {
    // Validate time format (HH:MM)
    int hour, minute;
    if (sscanf(time, "%d:%d", &hour, &minute) != 2) {
        return 0;
    }

    // Validate hour and minute ranges
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return 0;
    }

    return 1;
}

struct TimeDifference calculate_time_difference(const char* start_date, const char* start_time, const char* end_date, const char* end_time) {
    if (!validate_date(start_date) || !validate_time(start_time) || !validate_date(end_date) || !validate_time(end_time)) {
        struct TimeDifference empty_diff = {0};
        return empty_diff;
    }

    // Rest of the code remains the same
    // ...
}

int main() {
    char start_date[11], start_time[6], end_date[11], end_time[6];

    printf("Enter the starting date (YYYY-MM-DD): ");
    fgets(start_date, sizeof(start_date), stdin);
    start_date[strcspn(start_date, "\n")] = '\0';

    printf("Enter the starting time (HH:MM): ");
    fgets(start_time, sizeof(start_time), stdin);
    start_time[strcspn(start_time, "\n")] = '\0';

    printf("Enter the end date (YYYY-MM-DD): ");
    fgets(end_date, sizeof(end_date), stdin);
    end_date[strcspn(end_date, "\n")] = '\0';

    printf("Enter the end time (HH:MM): ");
    fgets(end_time, sizeof(end_time), stdin);
    end_time[strcspn(end_time, "\n")] = '\0';

    if (strlen(start_date) == 0 || strlen(start_time) == 0 || strlen(end_date) == 0 || strlen(end_time) == 0) {
        printf("Input cannot be empty. Please enter valid dates and times.\n");
        return 1;
    }

    if (!validate_date(start_date) || !validate_time(start_time) || !validate_date(end_date) || !validate_time(end_time)) {
        printf("Invalid input format. Please enter dates in the format YYYY-MM-DD and times in the format HH:MM.\n");
        return 1;
    }

    struct TimeDifference diff = calculate_time_difference(start_date, start_time, end_date, end_time);

    printf("Time Difference:\n");
    printf("Years: %d\n", diff.years);
    printf("Months: %d\n", diff.months);
    printf("Weeks: %d\n", diff.weeks);
    printf("Days: %d\n", diff.days);
    printf("Hours: %d\n", diff.hours);
    printf("Minutes: %d\n", diff.minutes);

    return 0;
}

