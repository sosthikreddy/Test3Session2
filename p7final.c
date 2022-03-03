#include<stdio.h>
struct _fraction{
int num,den;
};
typedef struct _fraction Fraction;
int gcd(int a,int b)
{
  int t;
  while (b!=0)
    {
      t=b;
      b=a%b;
      a=t;
    }
  return a;
}
Fraction input_fraction()
{
  Fraction a;
  printf ("please enter the numerator :: ");
  scanf ("%d",&a.num);
  printf ("please enter the denomintaor :: ");
  scanf ("%d",&a.den);
  return a;
} 
Fraction add_fractions(Fraction f1,Fraction f2)
{
  Fraction sum;
  sum.num=f1.num*f2.den+f2.num*f1.den;
  sum.den=f1.den*f2.den;
  int g=gcd(sum.num,sum.den);
  sum.num=sum.num/g;
  sum.den=sum.den/g;
  return sum;
}
void output(Fraction f1,Fraction f2,Fraction sum)
{
  sum=add_fractions(f1,f2);
  printf (" the sum of two fraction is %d/%d",sum.num,sum.den);
}
int main()
{
  Fraction f1,f2,sum;
  f1=input_fraction();
  f2=input_fraction();
  output(f1,f2,sum);
}