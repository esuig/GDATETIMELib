# GDateTimeLib

A lightweight, single-header C++ library of date and time utilities: simple
date and time types, conversions to and from `std::tm`, day arithmetic, week
calculations, formatted strings, and a breakdown of a number of hours into
years, months, weeks, days, hours and minutes.

No dependencies beyond the standard library.

> **Project status:** this library is at version 0.0.1, an early release. It
> is still being tested and will be further developed, so its API may change
> in future versions. Feedback and bug reports are welcome.
>
> This library has been tested only on Windows and compiled with MSVC 2022 so far

## Features

- **Simple types**: `CDate` (day, month, year) and `CHour` (hours, minutes).
- **Formatted strings**: `YYYY_MM_DD` and `HH_MM` (handy for file names),
  `DD-Mon-YYYY` and `DD/MM/YYYY`.
- **Day arithmetic**: add or subtract days, get the seven days after or before
  a date.
- **Weeks**: the dates of the current week or of the week containing a given
  date; the day of the week of any date.
- **Calendar helpers**: number of days in a month (leap years included), day
  and month names.
- **Duration breakdown**: `CHoursDownBreaker` turns a number of hours into a
  readable string such as `1 M 1 W 4 d 5 h 56 m (1000.500000 h)`.
- **Thread-safe local time**: conversions use `localtime_s` / `localtime_r`.

## Getting started

Copy `GDateTimeLib.h` into your project and include it:

```cpp
#include "GDateTimeLib.h"

using namespace gdatetimelib::date_time_utilities;
```

Requires C++11 or later.

## Examples

### Dates and formatted strings

```cpp
CDate today = GetTodayDate();

CDate date(18, 11, 2026);                          // day, month, year
std::string file_tag = date.GetDateStringUnderscore();   // "2026_11_18"

std::string formatted;
date.GetFormattedDate(formatted);                  // "18-Nov-2026"

CHour time(9, 5);                                  // hours, minutes
std::string time_tag = time.GetHourStringUnderscore();   // "09_05"

bool later = date.IsAfter(CDate(1, 1, 2026));      // true
```

### Day arithmetic and weeks

```cpp
// The seven days after a date (the date itself excluded)
std::vector<CDate> next = GetSevenSubsequentDates(CDate(28, 3, 2026));
// 29/03, 30/03, ..., 04/04/2026

// The seven days before a date, going backward
std::vector<CDate> prev = GetSevenPreviousDates(CDate(1, 11, 2026));
// 31/10, 30/10, ..., 25/10/2026

// The dates of the current week, starting on Monday (or Sunday)
std::vector<CDate> week = GetCurrentWeekDates();
std::vector<CDate> week_from_sunday = GetCurrentWeekDates(true);

// Day of the week: 0 = Sunday, 1 = Monday, ..., 6 = Saturday
int dow = CalculateDayOfWeek(18, 11, 2026);        // 3 (Wednesday)

int days = GetNumberOfDaysInMonth(2, 2024);        // 29
```

### Conversions with std::tm

```cpp
std::tm tm_date = StringToDate("18/11/2026");      // parse DD/MM/YYYY
std::string text = DateToString(tm_date);          // "18/11/2026"

std::tm in_ten_days = AddDays(tm_date, 10);
CDate c = DateToCDate(in_ten_days);                // 28/11/2026
std::tm back = CDateToDate(c);
```

### Breaking down a number of hours

```cpp
CHoursDownBreaker breakdown(1000.5);

std::string text;
breakdown.GetTimeFormattedString(text);
// "1 M 1 W 4 d 5 h 56 m (1000.500000 h)"

int weeks = breakdown.GetWeeks();                  // 1
```

## API overview

| Function / class                                        | Description                                                                                        |
| ------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| `CDate`                                                 | Calendar date (day, month, year), with formatting, comparison (`==`, `IsAfter()`) and month names. |
| `CHour`                                                 | Time of day (hours, minutes), with `HH_MM` formatting.                                             |
| `GetTodayDate()`                                        | Today's date in local time.                                                                        |
| `StringToDate()` / `DateToString()`                     | Convert between `DD/MM/YYYY` strings and `std::tm`.                                                |
| `DateToCDate()` / `CDateToDate()`                       | Convert between `std::tm` and `CDate`.                                                             |
| `AddDays()` / `RemoveDays()`                            | Add or subtract a number of days to a `std::tm` date.                                              |
| `GetSevenSubsequentDates()` / `GetSevenPreviousDates()` | The seven days after or before a date.                                                             |
| `GetCurrentWeekDates()`                                 | The dates of the current week (Monday or Sunday first).                                            |
| `GetWeekDatesOfCurrentDate()`                           | The dates of the week containing a given date.                                                     |
| `CalculateDayOfWeek()`                                  | Day of the week of a date (0 = Sunday ... 6 = Saturday).                                           |
| `GetDayNameFromNumber()`                                | English day name from a day number (1 = Monday ... 7 = Sunday).                                    |
| `GetNumberOfDaysInMonth()`                              | Number of days in a month, leap years included.                                                    |
| `SafeLocalTime()`                                       | Thread-safe conversion of `time_t` to local `std::tm`.                                             |
| `CHoursDownBreaker`                                     | Breaks a number of hours down into years, months, weeks, days, hours and minutes.                  |

## Notes

- **Local time**: functions that use the current time or convert through
  `time_t` work in the local time zone of the machine.
- **Month names are in Italian**: `CDate::GetMonthNameString()` (and therefore
  `GetFormattedDate()`) returns Italian names and abbreviations ("Gennaio",
  "Gen", ...), while `GetDayNameFromNumber()` returns English day names.
- **Day numbering**: `CalculateDayOfWeek()` uses 0 = Sunday ... 6 = Saturday,
  while `GetDayNameFromNumber()` uses 1 = Monday ... 7 = Sunday.
- **Average month and year lengths**: `CHoursDownBreaker` uses 30.44 days per
  month and 365.25 days per year, so its months and years are averages, not
  calendar months.
- **No validation**: dates are not checked for validity (e.g. 31/02 is
  accepted by `CDate`), and `StringToDate()` does not report parse errors.

## License

Released under the [Boost Software License 1.0](LICENSE).

SPDX: `BSL-1.0`
