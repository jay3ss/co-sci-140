// Specification file for the NumDays class
#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays
{
private:
   double hours;
   double days;
public:
   NumDays(double h = 0)
         { hours = h; days = h / 8; }

   void setHours(double h)
         { hours = h; days = h / 8; }

   double getHours() const
         { return hours; }

   void setDays(double d)
         { days = d; hours = d * 8; }

   double getDays() const
         { return days; }

   NumDays operator + (NumDays &);
   NumDays operator - (NumDays &);
   NumDays operator ++ ();       // Prefix ++
   NumDays operator ++ (int);    // Postfix ++
   NumDays operator -- ();       // Prefix ++
   NumDays operator -- (int);    // Postfix ++
};

#endif