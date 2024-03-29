
//  QlCal -- R interface to QuantLib Calendars
//
//  Copyright (C) 2002 - 2021  Dirk Eddelbuettel <edd@debian.org>
//
//  This file is part of QlCal
//
//  QlCal is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  QlCal is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with QlCal.  If not, see <http://www.gnu.org/licenses/>.

// Taken from RQuantLib and adapted

// [[Rcpp::interfaces(r, cpp)]]

#include "qlcal_types.h"

namespace ql = QuantLib;

ql::BusinessDayConvention getBusinessDayConvention(const int n) {
    switch (n) {
    case 0:
        return ql::Following;
        break;
    case 1:
        return ql::ModifiedFollowing;
        break;
    case 2:
        return ql::Preceding;
        break;
    case 3:
        return ql::ModifiedPreceding;
        break;
    case 4:
        return ql::Unadjusted;
        break;
    case 5:
        return ql::HalfMonthModifiedFollowing;
        break;
    case 6:
        return ql::Nearest;
        break;
    default:
        return ql::Unadjusted;
    }
}

ql::BusinessDayConvention getBusinessDayConvention(const std::string& s) {
    if (s == "Following")
        return ql::Following;
    else if (s == "ModifiedFollowing")
        return ql::ModifiedFollowing;
    else if (s == "Preceding")
        return ql::Preceding;
    else if (s == "ModifiedPreceding")
        return ql::ModifiedPreceding;
    else if (s == "Unadjusted")
        return ql::Unadjusted;
    else if (s == "HalfMonthModifiedFollowing")
        return ql::HalfMonthModifiedFollowing;
    else if (s == "Nearest")
        return ql::Nearest;
    else
        return ql::Unadjusted;
}

ql::Frequency getFrequency(const int n) {
    switch (n) {
    case -1:
        return ql::NoFrequency;
        break;
    case 0:
        return ql::Once;
        break;
    case 1:
        return ql::Annual;
        break;
    case 2:
        return ql::Semiannual;
        break;
    case 3:
        return ql::EveryFourthMonth;
        break;
    case 4:
        return ql::Quarterly;
        break;
    case 6:
        return ql::Bimonthly;
        break;
    case 12:
        return ql::Monthly;
        break;
    case 13:
        return ql::EveryFourthWeek;
        break;
    case 26:
        return ql::Biweekly;
        break;
    case 52:
        return ql::Weekly;
        break;
    case 365:
        return ql::Daily;
        break;
    default:
        return ql::OtherFrequency;
    }
}

ql::TimeUnit getTimeUnit(const int n) {
    switch (n) {
    case 0:
        return ql::Days;
        break;
    case 1:
        return ql::Weeks;
        break;
    case 2:
        return ql::Months;
        break;
    case 3:
        return ql::Years;
        break;
    case 4:
        return ql::Hours;
        break;
    case 5:
        return ql::Seconds;
        break;
    case 6:
        return ql::Minutes;
        break;
    case 7:
        return ql::Milliseconds;
        break;
    case 8:
        return ql::Microseconds;
        break;
    default:
        Rcpp::stop("Wrong TimeUnit value\n");
        break;
    }
}

ql::TimeUnit getTimeUnit(const std::string& s) {
    if (s == "Days")
        return ql::Days;
    else if (s == "Weeks")
        return ql::Weeks;
    else if (s == "Months")
        return ql::Months;
    else if (s == "Years")
        return ql::Years;
    else if (s == "Hours")
        return ql::Hours;
    else if (s == "Seconds")
        return ql::Seconds;
    else if (s == "Minutes")
        return ql::Minutes;
    else if (s == "Milliseconds")
        return ql::Milliseconds;
    else if (s == "Microseconds")
        return ql::Microseconds;
    else
        Rcpp::stop("Wrong TimeUnit value\n");
}
