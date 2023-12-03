#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int x,y,z,a,b,sum;
int m=1;
void Findfunctions(string s)
{
    for(int i=0; i<s.size(); i++)
      {
          if(s[i] == '(' && s[i-1] != 'n' && s[i-2] != 'i' && s[i-4] != 'm'&& s[i+1] == 'i')
          {
              cout<<"Function-"<<m<<": "<<s[i-3]<<s[i-2]<<s[i-1]<<endl;
              m++;
          }
      }
}
void Findoperators(string s)
{
    for(int i=0; i<s.size(); i++)
      {
            if(s[i] == '+')
            {x++;}
           else if(s[i] == '-')
            {y++;}
             else if(s[i] == '*')
            {z++;}
             else if(s[i] == '/')
            {a++;}
             else if(s[i] == '=')
            {b++;}
      }
      //For Optimization:
            if(x > 0){x=1;}
            if(y > 0){y=1;}
            if(z > 0){z=1;}
            if(a > 0){a=1;}
            if(b > 0){b=1;}

        sum=x+y+z+a+b;
}
int main ()
{
  fstream myfile;
  myfile.open ("program.cpp");
  string s;
  int n=1;
  myfile.close();
  myfile.open ("program.cpp");
  while (getline(myfile, s))
  {
      Findfunctions(s);
  }
  myfile.close();
  cout<<"Total number of the user defined function: "<<m-1<<endl;
    myfile.open ("Program.cpp");
    while (getline(myfile, s))
    {
        Findoperators(s);
    }
    myfile.close();
    for(int i=0; i<sum; i++)
    {
            if(x > 0)
                {cout<<"Operator-"<<n<<": addition"<<endl;n++;}
            if(y > 0)
                {cout<<"Operator-"<<n<<": subtraction"<<endl;n++;}
            if(z> 0)
                {cout<<"Operator-"<<n<<": multiplication"<<endl;n++;}
            if(a > 0)
                {cout<<"Operator-"<<n<<": division"<<endl;n++;}
            if (b > 0)
                {cout<<"Operator-"<<n<<": assignment"<<endl;n++;}

            break;
    }
   cout<<"Total number of the operators: "<<sum<<endl;
   return 0;
}

