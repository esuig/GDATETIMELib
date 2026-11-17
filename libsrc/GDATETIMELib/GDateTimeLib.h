
#ifndef H_DATE_TIME_UTILS
#define H_DATE_TIME_UTILS

#pragma once
#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <vector>

namespace gdatetimelib
{
	namespace date_time_utilities
	{
		/**
		* @class CHour
		* @brief Represents a time expressed as hours and minutes.
		*/
		class CHour
		{
		public:
			/**
			* @brief Constructs a CHour object with specified hours and minutes.
			* @param f_hours   The hour value.
			* @param f_minutes The minutes value.
			*/
			CHour(const int f_hours, const int f_minutes) :
				m_hours(f_hours),
				m_minutes(f_minutes)
			{

			}
			/**
			* @brief Default constructor. Initializes hours and minutes to zero.
			*/
			CHour() :
				m_hours(0),
				m_minutes(0)
			{

			}

			/**
			* @brief Returns the time formatted as "HH_MM".
			* @return A formatted string.
			*/
			inline std::string GetHourStringUnderscore() const
			{
				std::string l_hour_string = std::to_string(m_hours);
				if (l_hour_string.size() < 2)
				{
					l_hour_string.insert(l_hour_string.begin(), '0');
				}
				std::string l_min_string = std::to_string(m_minutes);
				if (l_min_string.size() < 2)
				{
					l_min_string.insert(l_min_string.begin(), '0');
				}

				std::string l_out_string = l_hour_string + "_" + l_min_string;
				return l_out_string;
			}

			/**
			* @brief Gets the minutes component.
			* @return The minutes.
			*/
			inline int GetMinutes() const
			{
				return m_minutes;
			}
			/**
			* @brief Gets the hour component.
			* @return The hour.
			*/
			inline int GetHours() const
			{
				return m_hours;
			}

		private:
			int m_minutes;
			int m_hours;
		};

		/**
		* @class CDate
		* @brief Represents a calendar date (day, month, year).
		*/
		class CDate
		{
		public:
			/**
			* @brief Constructs a CDate with specified day, month, and year.
			* @param f_day   The day.
			* @param f_month The month.
			* @param f_year  The year.
			*/
			CDate(const int f_day, 
				  const int f_month, 
				  const int f_year):
						m_day(f_day),
						m_month(f_month),
						m_year(f_year)
			{

			}
			/**
			* @brief Default constructor. Initializes all components to zero.
			*/
			CDate() :
				m_day(0),
				m_month(0),
				m_year(0)
			{
			}

			/**
			* @brief Returns the date formatted as "YYYY_MM_DD".
			* @return A formatted date string.
			*/
			inline std::string GetDateStringUnderscore() const
			{
				std::string l_year_string = std::to_string(GetYear());
				std::string l_month_string = std::to_string(GetMonth());
				if (l_month_string.size() < 2)
				{
					l_month_string.insert(l_month_string.begin(), '0');
				}
				std::string l_day_string = std::to_string(GetDay());
				if (l_day_string.size() < 2)
				{
					l_day_string.insert(l_day_string.begin(), '0');
				}

				return l_year_string + "_" + l_month_string + "_" + l_day_string;
			}
			/**
			* @brief Gets the day component.
			* @return The day.
			*/
			inline int GetDay() const
			{
				return m_day;
			}
			/**
			* @brief Gets the month component.
			* @return The month.
			*/
			inline int GetMonth() const
			{
				return m_month;
			}
			/**
			* @brief Gets the year component.
			* @return The year.
			*/
			inline int GetYear() const
			{
				return m_year;
			}
			/**
			* @brief Gets the month name in Italian.
			* @param f_abbrev If true, returns the three-letter abbreviation.
			* @return The month name as a string.
			*/
			inline std::string GetMonthNameString(const bool f_abbrev = false) const
			{
				std::string l_month_name;

				switch (m_month)
				{
				case 1:
					if (f_abbrev)
					{
						l_month_name = "Gen";
					}
					else
					{
						l_month_name = "Gennaio";
					}
					break;
				case 2:
					if (f_abbrev)
					{
						l_month_name = "Feb";
					}
					else
					{
						l_month_name = "Febbraio";
					}
					break;
				case 3:
					if (f_abbrev)
					{
						l_month_name = "Mar";
					}
					else
					{
						l_month_name = "Marzo";
					}
					break;
				case 4:
					if (f_abbrev)
					{
						l_month_name = "Apr";
					}
					else
					{
						l_month_name = "Aprile";
					}
					break;
				case 5:
					if (f_abbrev)
					{
						l_month_name = "Mag";
					}
					else
					{
						l_month_name = "Maggio";
					}
					break;
				case 6:
					if (f_abbrev)
					{
						l_month_name = "Giu";
					}
					else
					{
						l_month_name = "Giugno";
					}
					break;
				case 7:
					if (f_abbrev)
					{
						l_month_name = "Lug";
					}
					else
					{
						l_month_name = "Luglio";
					}
					break;
				case 8:
					if (f_abbrev)
					{
						l_month_name = "Ago";
					}
					else
					{
						l_month_name = "Agosto";
					}
					break;
				case 9:
					if (f_abbrev)
					{
						l_month_name = "Set";
					}
					else
					{
						l_month_name = "Settembre";
					}
					break;
				case 10:
					if (f_abbrev)
					{
						l_month_name = "Ott";
					}
					else
					{
						l_month_name = "Ottobre";
					}
					break;
				case 11:
					if (f_abbrev)
					{
						l_month_name = "Nov";
					}
					else
					{
						l_month_name = "Novembre";
					}
					break;
				case 12:
					if (f_abbrev)
					{
						l_month_name = "Dic";
					}
					else
					{
						l_month_name = "Dicembre";
					}
					break;
				default:
					l_month_name = "month_noname";
					break;
				};

				return l_month_name;
			}
			/**
			* @brief Compares two dates for equality.
			* @param f_other_date The date to compare with.
			* @return True if equal, false otherwise.
			*/
			inline bool operator == (const CDate& f_other_date) const
			{
				if ((f_other_date.GetDay() == GetDay()) &&
					(f_other_date.GetMonth() == GetMonth()) &&
					(f_other_date.GetYear() == GetYear()))
				{
					return true;
				}
				return false;
			}
			/**
			* @brief Assignment operator.
			* @param f_date The date to assign.
			* @return Reference to this.
			*/
			inline CDate& operator = (const CDate& f_date)
			{
				m_day = f_date.GetDay();
				m_month = f_date.GetMonth();
				m_year = f_date.GetYear();

				return *this;
			}
			/**
			* @brief Checks if this date occurs after the specified date.
			* @param f_date The date to compare against.
			* @return True if this date is later, false otherwise.
			*/
			inline bool IsAfter(const CDate& f_date) const
			{
				if (m_year > f_date.GetYear())
				{
					return true;
				}
				else if (m_year == f_date.GetYear())
				{
					if (m_month > f_date.GetMonth())
					{
						return true;
					}
					else if (m_month == f_date.GetMonth())
					{
						if (m_day > f_date.GetDay())
						{
							return true;
						}
					}
				}
				return false;
			}
			/**
			* @brief Provides a formatted date string in "DD-Mon-YYYY" format.
			* @param f_formatted_date Output string reference.
			*/
			inline void GetFormattedDate(std::string& f_formatted_date) const
			{
				f_formatted_date = std::to_string(GetDay()) + "-";
				f_formatted_date += GetMonthNameString(true) + "-";
				f_formatted_date += std::to_string(GetYear());
			}

		private:
			int m_day;
			int m_month;
			int m_year;
		};

		/**
		* @brief Thread-safe conversion of time_t to local tm.
		* @param t Pointer to time_t.
		* @return A populated tm structure.
		*/
		inline tm SafeLocalTime(const time_t* t)
		{
			tm result{};

#if defined(_WIN32)
			localtime_s(&result, t);
#else
			localtime_r(t, &result);
#endif

			return result;
		}
		/**
		* @brief Converts a string "DD/MM/YYYY" to a tm structure.
		* @param f_date_string The input string.
		* @return A tm date structure.
		*/
		inline std::tm StringToDate(const std::string& f_date_string)
		{
			tm date = {};
			std::stringstream ss(f_date_string);
			ss >> std::get_time(&date, "%d/%m/%Y");
			return date;
		}
		/**
		* @brief Converts a tm structure into a "DD/MM/YYYY" formatted string.
		* @param date The tm date.
		* @return A formatted string.
		*/
		inline std::string DateToString(const tm& date)
		{
			std::stringstream ss;
			ss << std::put_time(&date, "%d/%m/%Y");
			return ss.str();
		}
		/**
		* @brief Adds the given number of days to a tm date.
		* @param f_date The starting date.
		* @param f_days_to_add Days to add.
		* @return The resulting tm date.
		*/
		inline std::tm AddDays(const tm& f_date, int f_days_to_add)
		{
			time_t rawtime = mktime(const_cast<tm*>(&f_date));
			rawtime += f_days_to_add * 24 * 60 * 60;
			tm newDate = SafeLocalTime(&rawtime);
			return newDate;
		}
		/**
		* @brief Subtracts the given number of days from a tm date.
		* @param f_date The starting date.
		* @param f_days_to_remove Days to subtract.
		* @return The resulting tm date.
		*/
		inline std::tm RemoveDays(const tm& f_date, int f_days_to_remove)
		{
			time_t l_raw_time = std::mktime(const_cast<tm*>(&f_date));
			l_raw_time -= f_days_to_remove * 24 * 60 * 60;
			tm l_new_date = SafeLocalTime(&l_raw_time);
			return l_new_date;
		}
		/**
		* @brief Converts a tm structure into a CDate.
		* @param f_date The tm structure.
		* @return A CDate instance.
		*/
		inline CDate DateToCDate(std::tm& f_date)
		{
			int l_day = f_date.tm_mday;
			int l_month = f_date.tm_mon + 1;
			int l_year = f_date.tm_year + 1900;

			return CDate(l_day, l_month, l_year);
		}
		/**
		* @brief Converts a CDate into a tm structure.
		* @param f_date The CDate object.
		* @return A tm structure.
		*/
		inline std::tm CDateToDate(const CDate& f_date)
		{
			tm l_out_date = {};

			int l_day = f_date.GetDay();
			int l_month = f_date.GetMonth();
			int l_year = f_date.GetYear();

			std::string l_date_string = std::to_string(l_day) + "/" + std::to_string(l_month) + "/" + std::to_string(l_year);
			std::stringstream ss(l_date_string);
			ss >> std::get_time(&l_out_date, "%d/%m/%Y");
			return l_out_date;
		}
		/**
		* @brief Returns today's date as a CDate.
		* @return The current date.
		*/
		inline CDate GetTodayDate()
		{
			auto now = std::chrono::system_clock::now();
			auto today = std::chrono::system_clock::to_time_t(now);

			std::tm tm_now = SafeLocalTime(&today);

			int l_week_day = tm_now.tm_wday;
			int l_month_day = tm_now.tm_mday;
			int l_month = tm_now.tm_mon + 1;
			int l_year = tm_now.tm_year + 1900;

			int k = 0;

			return CDate(l_month_day, l_month, l_year);
		}
		/**
		* @brief Returns the seven dates following the given date.
		* @param f_start_date The reference date.
		* @return Vector of seven subsequent dates.
		*/
		inline std::vector<CDate> GetSevenSubsequentDates(const CDate& f_start_date)
		{
			std::vector<CDate> l_next_dates;
			l_next_dates.reserve(7);
			tm l_start_date = CDateToDate(f_start_date);

			for (int i = 1; i <= 7; ++i)
			{
				tm l_next_date = AddDays(l_start_date, i);
				CDate l_out_date = DateToCDate(l_next_date);
				l_next_dates.push_back(l_out_date);
			}

			return l_next_dates;
		}
		/**
		* @brief Returns the seven dates preceding the given date (so the 
		* returned vector will start from the date immediately before f_start_date
		* and will go backward)
		* @param f_start_date The reference date.
		* @return Vector of seven previous dates.
		*/
		inline std::vector<CDate> GetSevenPreviousDates(const CDate& f_start_date)
		{
			std::vector<CDate> l_prev_dates;
			l_prev_dates.reserve(7);
			tm l_start_date = CDateToDate(f_start_date);

			for (int i = 1; i <= 7; ++i)
			{
				tm l_prev_date = RemoveDays(l_start_date, i);
				CDate l_out_date = DateToCDate(l_prev_date);
				l_prev_dates.push_back(l_out_date);
			}

			return l_prev_dates;
		}
		/**
		* @brief Returns all dates of the current week.
		* @param f_start_sunday If true, week begins on Sunday instead of Monday.
		* @return Vector of seven dates.
		*/
		inline std::vector<CDate> GetCurrentWeekDates(const bool f_start_sunday = false)
		{
			auto now = std::chrono::system_clock::now();
			auto today = std::chrono::system_clock::to_time_t(now);

			std::tm tm_now = SafeLocalTime(&today);

			int current_day_of_week = tm_now.tm_wday;

			int l_days_to_monday = current_day_of_week - 1;
			if (f_start_sunday)
			{
				l_days_to_monday += 1;
			}

			std::tm tm_monday = RemoveDays(tm_now, l_days_to_monday);
			std::string l_date_string = DateToString(tm_monday);

			std::vector<CDate> l_dates;
			l_dates.reserve(7);
			for (int i = 0; i < 7; ++i)
			{
				std::string l_date_string = DateToString(tm_monday);
				CDate l_date = DateToCDate(tm_monday);
				l_dates.emplace_back(l_date);

				tm_monday = AddDays(tm_monday, 1);
			}
			return l_dates;
		}
		/**
		* @brief Calculates the weekday of a date.
		* @param f_day_num   Day (1–31).
		* @param f_month_num Month (1–12).
		* @param f_year_num  Year.
		* @return 0 = Sunday, 1 = Monday, …, 6 = Saturday.
		*/
		inline int CalculateDayOfWeek(int f_day_num, int f_month_num, int f_year_num)
		{
			static int t[] = { 0, 3, 2, 5, 0, 3,
							   5, 1, 4, 6, 2, 4 };
			f_year_num -= f_month_num < 3;
			return (f_year_num + f_year_num / 4 - f_year_num / 100 + f_year_num / 400 + t[f_month_num - 1] + f_day_num) % 7;

		}
		/**
		* @brief Returns all dates of the week to which the given date belongs.
		* @param f_date The input date.
		* @return Vector of seven dates starting from Sunday.
		*/
		inline std::vector<CDate> GetWeekDatesOfCurrentDate(const CDate& f_date)
		{
			std::tm l_input_date = CDateToDate(f_date);
			std::time_t l_time = std::mktime(&l_input_date);
			int l_day_of_week = l_input_date.tm_wday;
			int l_days_to_subtract = 0;
			if (l_day_of_week != 0)
			{
				l_days_to_subtract = l_day_of_week;
			}
			l_time -= l_days_to_subtract * 24 * 3600;
			std::tm l_prev_sunday = SafeLocalTime(&l_time);

			return GetSevenSubsequentDates(DateToCDate(l_prev_sunday));
		}
		/**
		* @brief Gets the English day name from day number (1=Mon,…,7=Sun).
		* @param f_day_name Output string.
		* @param f_day_num Day number.
		* @param f_abbreviation If true, returns 3-letter abbreviation.
		*/
		inline void GetDayNameFromNumber(std::string& f_day_name, 
										 const int f_day_num, 
										 const bool f_abbreviation = false)
		{
			if ((f_day_num > 7) || (f_day_num < 1))
			{
				return;
			}
			switch (f_day_num)
			{
			case 1:
				f_day_name = "Monday";
				break;
			case 2:
				f_day_name = "Tuesday";
				break;
			case 3:
				f_day_name = "Wednesday";
				break;
			case 4:
				f_day_name = "Thursday";
				break;
			case 5:
				f_day_name = "Friday";
				break;
			case 6:
				f_day_name = "Saturday";
				break;
			case 7:
				f_day_name = "Sunday";
				break;
			};

			if (f_abbreviation)
			{
				f_day_name = f_day_name.substr(0, 3);
			}
		}

		/**
		* @brief Returns the number of days in the given month.
		* @param f_month Month (1–12)(January = 1).
		* @param f_year  Year.
		* @return The number of days.
		*/
		inline int GetNumberOfDaysInMonth(const int f_month, const int f_year)
		{
			if (f_month == 2)
			{
				if ((f_year % 4 == 0 && f_year % 100 != 0) || (f_year % 400 == 0))
				{
					return 29;
				}
				else
				{
					return 28;
				}
			}
			if (f_month == 4 || f_month == 6 || f_month == 9 || f_month == 11)
			{
				return 30;
			}

			return 31;
		}

		/**
		* @class CHoursDownBreaker
		* @brief Breaks down a number of hours into years, months, weeks, days,
		*        hours, and minutes (using average month/year lengths).
		*/
		class CHoursDownBreaker
		{
		public:
			/**
			* @brief Constructor.
			* @param f_hours_to_break_down The total hours to decompose.
			*/
			CHoursDownBreaker(const double f_hours_to_break_down):
								m_minutes_per_hour(60.0),
								m_hours_per_day(24.0),
								m_days_per_week(7.0),
								m_days_per_month(30.44),
								m_days_per_year(365.25)
			{
				m_hours_per_week = m_days_per_week * m_hours_per_day;
				m_hours_per_month = m_days_per_month * m_hours_per_day;
				m_hours_per_year = m_days_per_year * m_hours_per_day;

				m_hours_to_break_down = f_hours_to_break_down;

				BreakDownHours();
			}

			/**
			* @brief Get the year component
			* @return The year component
			*/
			inline int GetYears() const
			{
				return m_years;
			}
			/**
			* @brief Get the number of months
			* @return The number of months
			*/
			inline int GetMonths() const
			{
				return m_months;
			}
			/**
			* @brief Get the number of weeks
			* @return The number of weeks
			*/
			inline int GetWeeks() const
			{
				return m_weeks;
			}
			/**
			* @brief Get the number of days
			* @return The number of days
			*/
			inline int GetDays() const
			{
				return m_days;
			}
			/**
			* @brief Get the number of hours
			* @return The number of hours
			*/
			inline int GetHours() const
			{
				return m_hours;
			}
			/**
			* @brief Get the number of minutes
			* @return The number of minutes
			*/
			inline int GetMinutes() const
			{
				return m_minutes;
			}
			/**
			* @brief Formats the broken-down time in:
			*        "xx Y xx M xx W xx D xx h xx m (total h)"
			* @param f_string Output string.
			*/
			inline void GetTimeFormattedString(std::string& f_string) const
			{
				if (m_calculated)
				{
					if (m_years != 0)
					{
						f_string += std::to_string(m_years) + " Y ";
					}
					if (m_months != 0)
					{
						f_string += std::to_string(m_months) + " M ";
					}
					if (m_weeks != 0)
					{
						f_string += std::to_string(m_weeks) + " W ";
					}
					if (m_days != 0)
					{
						f_string += std::to_string(m_days) + " d ";
					}
					if (m_hours != 0)
					{
						f_string += std::to_string(m_hours) + " h ";
					}
					if (m_minutes != 0)
					{
						f_string += std::to_string(m_minutes) + " m ";
					}

					std::string l_formatted_tot_hours = std::to_string(m_hours_to_break_down);
					f_string += "(";
					f_string += l_formatted_tot_hours;
					f_string += " h)";
				}
			}

		private:

			/**
			* @brief Performs the actual breakdown of hours into components.
			*/
			inline void BreakDownHours()
			{
				if (m_hours_to_break_down > 0.0)
				{
					m_years = int(m_hours_to_break_down / m_hours_per_year);
					double l_remaining_hours_after_years = m_hours_to_break_down - (m_years * m_hours_per_year);
					m_months = int(l_remaining_hours_after_years / m_hours_per_month);
					double l_remaining_hours_after_months = l_remaining_hours_after_years - (m_months * m_hours_per_month);
					m_weeks = int(l_remaining_hours_after_months / m_hours_per_week);
					double l_remaining_hours_after_weeks = l_remaining_hours_after_months - (m_weeks * m_hours_per_week);
					m_days = int(l_remaining_hours_after_weeks / m_hours_per_day);
					double l_remaining_hours_after_days = l_remaining_hours_after_weeks - (m_days * m_hours_per_day);
					m_hours = int(l_remaining_hours_after_days);
					m_minutes = int((l_remaining_hours_after_days - m_hours) * m_minutes_per_hour);
				}
				m_calculated = true;
			}

			/** @brief Minutes in one hour */
			const double m_minutes_per_hour;
			/** @brief Hours per day */
			const double m_hours_per_day;
			/** @brief Days per week */
			const double m_days_per_week;
			/** @brief Average days per month */
			const double m_days_per_month;
			/** @brief Average days per year */
			const double m_days_per_year;

			/** @brief Derived constant: hours in one week (m_days_per_week * m_hours_per_day) */
			double m_hours_per_week;
			/** @brief Derived constant: average hours in one month (m_days_per_month * m_hours_per_day) */
			double m_hours_per_month;
			/** @brief Derived constant: average hours in one year (m_days_per_year * m_hours_per_day) */
			double m_hours_per_year;

			/** @brief True once the breakdown has been computed by BreakDownHours() */
			bool m_calculated;

			/** @brief Whole years extracted from the total hours */
			int m_years;
			/** @brief Whole months extracted after subtracting years */
			int m_months;
			/** @brief Whole weeks extracted after subtracting months */
			int m_weeks;
			/** @brief Whole days extracted after subtracting weeks */
			int m_days;
			/** @brief Whole hours extracted after subtracting days */
			int m_hours;
			/** @brief Remaining minutes after hours are removed */
			int m_minutes;

			/** @brief Total hours that will be decomposed */
			double m_hours_to_break_down;
		};
	}
}

#endif H_DATE_TIME_UTILS