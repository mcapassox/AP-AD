#include <iostream>
#include <string>
#include <ostream>

enum class month_enum{jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

// Define the date class
class date {
  private:
    unsigned int day, year;
    month_enum month;

  public:
    //Constructors
    date(const unsigned int x, const month_enum y, const unsigned int z);

    //Accessors
    unsigned int get_day() const {return day;}
    month_enum get_month() const {return month;}
    unsigned int get_year() const {return year;}

    //Modifiers
    void set_day(unsigned int x){day = x;}
    void set_month(month_enum x){month = x;}
    void set_year(unsigned int x){year = x;}
    void add_days(const unsigned int n);
    bool is_leap(const int y);

};
// Constructor
date::date(unsigned int x, month_enum y, unsigned int z){
    day = x;
    month = y;
    year = z;
}

// Function to add days to date
void date::add_days(const unsigned int n){
  unsigned int day_temp = day, days_in_month;
    // Do depending on current month
    switch (int(month)) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        days_in_month = 31;
        break;
      case 4: case 6: case 9: case 11:
        days_in_month = 30;
        break;
      default:
          if(is_leap(year))
            days_in_month = 29;
          else
            days_in_month = 28;
      }
    // Increase month/year depending on the current month/number of added days
    if (n>days_in_month-day) {
      day = 1;
      if (month == month_enum(12)) {
        month = month_enum(1);
        year++;
      }
      else
        month = month_enum(int(month)+1);
      add_days(n-(days_in_month-day_temp+1));
    }
    else
      day = day+n;
}

bool date::is_leap(const int y){
  return ((y%4 == 0)&&((y%100==0)==(y%400==0)));
}

// Define comparison operator for date
bool operator==(const date& lhs, const date& rhs){
  return  ((lhs.get_day() == rhs.get_day())&&(lhs.get_month() == rhs.get_month())&&(lhs.get_year() == rhs.get_year()));
}
// Define inequality operator for the date
bool operator!=(const date& lhs, const date& rhs){
  return !(lhs == rhs);
}

//Can't get it to work, segfault. It tries to access an illegal memory address
std::istream& operator>>(std::istream& is, month_enum& m){
  is >> m;
  return is;
}

std::ostream& operator<<(std::ostream& os, const date& d){
  os << d.get_day() << " " << int(d.get_month()) << " " << d.get_year() << std::endl;
  return os;
}


int main() {
  // Declare day, month, year and days to be added
  unsigned int d, y, ad;
  // can't solve the problem with the >> overloading, gives segmentation fault
  unsigned int m_temp;
  month_enum m;
  // Ask user for input
  std::cout << "What's the date today? Format: dd mm yyyy" << std::endl;
  std::cin >> d; std::cin >> m_temp; std::cin >> y;
  m = month_enum(m_temp);
  date today_date(d,m,y);

  std::cout << "How many days do you wanna add? ";
  std::cin >> ad;

  // Add days to current date
  today_date.add_days(ad);
  // Print out the result of the addition
  std::cout << today_date.get_day() << " " << int(today_date.get_month()) << " " << today_date.get_year() << std::endl;
  std::cout << "is leap" << '\n';
  std::cout << today_date.is_leap(today_date.get_year());
  //Ask user for a date to be compared with current date
  std::cout << "What's a date you want to compare? Format: dd mm yyyy" << std::endl;
  std::cin >> d; std::cin >> m_temp; std::cin >> y;
  m = month_enum(m_temp);
  date another_date(d,m,y);
  std::cout << "The two dates are the same/different (0 for false, 1 for true): ";
  std::cout << (another_date == today_date) << std::endl;
  //std::cout << (another_date != today_date);

  //Printout another_date
  std::cout << another_date;
  return 0;
}
