#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Year;
  uint16_t Month;
  uint16_t Day;
};

uint16_t DataPrompt(const char *Message)
{
  uint16_t Num{0};

  cout<<Message;
  cin>>Num;
  
  return (Num);
}

stDate FeedData()
{
  stDate Date;

  Date.Year = DataPrompt("Enter Year: ");
  Date.Month = DataPrompt("Enter Month: ");
  Date.Day = DataPrompt("Enter Day: ");
  
  return (Date);
}

uint16_t GregorianCalc(stDate Date)
{
  uint16_t a = 0, y = 0, m = 0, Day;

  a = abs((14 - Date.Month) / 12);
  y = Date.Year - a;
  m = Date.Month + (12 * a) - 2;

  Day = (Date.Day + y + abs(y/4) - abs(y/100) + abs(y/400) + abs((31 * m) / 12)) % 7;
  
  return (Day);
}

int main(void)
{
  stDate Date;
  Date = FeedData();

  cout<<"\nDate(Entry): "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<'\n'<<endl;
  cout<<GregorianCalc(Date)<<endl;
  return (0);
}
