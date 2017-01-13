#include <iostream>
using namespace std;
class Time
{
  private:
    int hour;
    int min;
    int sec;

  public:
    // sethour
    void set_hour(int h)
    {
        hour = h;
    }

    // set minutes
    void set_min(int m)
    {
        min = m;
    }

    // set second
    void set_sec(int s)
    {
        sec = s;
    }

    //overload + operator
    Time operator+(const Time &t)
    {
        Time temp;
        temp.sec = this->sec + t.sec;
        if (temp.sec > 60)
        {
            temp.sec -= 60;
            temp.min = this->min + t.min + 1;
            if (temp.min > 60)
            {
                temp.min -= 60;
                temp.hour = this->hour + t.hour + 1;
            }
            else
            {
                temp.hour = this->hour + t.hour;
            }
        }
        else
        {
            temp.min = this->min + t.min;
            if (temp.min > 60)
            {
                temp.min -= 60;
                temp.hour = this->hour + t.hour + 1;
            }
            else
            {
                temp.hour = this->hour + t.hour;
            }
        }
        return temp;
    };
    /*another for time
    time time::operator+(time t1)	//operator function  
{  
 time t;  
 int a,b;  
 a=s+t1.s;  
 t.s=a%60;  
 b=(a/60)+m+t1.m;  
 t.m=b%60;  
 t.h=(b/60)+h+t1.h;  
 t.h=t.h%12;  
 return t;  
}
*/

    // print time
    void print()
    {
        cout << hour << ":" << min << ":" << sec << endl;
    }
};
int main()
{
    int h1, m1, s1, h2, m2, s2;
    cout << "Enter the first time" << endl;
    cout << "Enter the hour(0-11) ";
    cin >> h1;

    //minutes
    cout << endl;
    cout << "Enter the minutes(0-59) ";
    cin >> m1;

    //second
    cout << endl;
    cout << "Enter the second(0-59) ";
    cin >> s1;

    // set hour, minutes, second
    Time time1;
    time1.set_hour(h1);
    time1.set_min(m1);
    time1.set_sec(s1);

    // now the second time
    cout << endl;
    cout << "Enter the second time" << endl;
    cout << "Enter the hour(0-11) ";
    cin >> h2;

    //minutes
    cout << endl;
    cout << "Enter the minutes(0-59) ";
    cin >> m2;

    //second
    cout << endl;
    cout << "Enter the second(0-59) ";
    cin >> s2;

    // set hour, minutes, second
    Time time2;
    time2.set_hour(h2);
    time2.set_min(m2);
    time2.set_sec(s2);

    // sum of time1 and time2
    Time time3 = time1 + time2;

    // print results
    cout << "First time ";
    time1.print();
    cout << "Second time ";
    time2.print();
    cout << "Sum of time ";
    time3.print();
    return 0;
}