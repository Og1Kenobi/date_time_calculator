#!/usr/bin/env python3

import datetime
import re

def validate_date(date):
    # Validate date format (YYYY-MM-DD)
    pattern = re.compile(r"\d{4}-\d{2}-\d{2}")
    return bool(pattern.match(date))

def validate_time(time):
    # Validate time format (HH:MM)
    pattern = re.compile(r"\d{2}:\d{2}")
    return bool(pattern.match(time))

def calculate_time_difference(start_date, start_time, end_date, end_time):
    if not validate_date(start_date) or not validate_time(start_time) or not validate_date(end_date) or not validate_time(end_time):
        raise ValueError("Invalid input format. Please enter dates in the format YYYY-MM-DD and times in the format HH:MM.")

    start_datetime = datetime.datetime.strptime(start_date + " " + start_time, "%Y-%m-%d %H:%M")
    end_datetime = datetime.datetime.strptime(end_date + " " + end_time, "%Y-%m-%d %H:%M")
    time_difference = end_datetime - start_datetime

    years = time_difference.days // 365
    months = time_difference.days // 30
    weeks = time_difference.days // 7
    days = time_difference.days
    hours = time_difference.seconds // 3600
    minutes = (time_difference.seconds // 60) % 60

    return years, months, weeks, days, hours, minutes

try:
    start_date = input("Enter the starting date (YYYY-MM-DD): ")
    start_time = input("Enter the starting time (HH:MM): ")
    end_date = input("Enter the end date (YYYY-MM-DD): ")
    end_time = input("Enter the end time (HH:MM): ")

    years, months, weeks, days, hours, minutes = calculate_time_difference(start_date, start_time, end_date, end_time)

    print("Time Difference:")
    print(f"Years: {years}")
    print(f"Months: {months}")
    print(f"Weeks: {weeks}")
    print(f"Days: {days}")
    print(f"Hours: {hours}")
    print(f"Minutes: {minutes}")

except ValueError as e:
    print("Error:", str(e))

