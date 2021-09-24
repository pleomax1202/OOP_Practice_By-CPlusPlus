#include <iostream>

using namespace std;
class AbstractEmployee
{
  virtual void AskForPromotion () = 0;
};

class Employee:AbstractEmployee
{
private:
  std::string Name;
  std::string Company;
  int Age;
public:
  void setName (string name)
  {
    Name = name;
  }
  string getName ()
  {
    return Name;
  }
  void setCompany (string company)
  {
    Company = company;
  }
  string getCompany ()
  {
    return Company;
  }
  void setAge (int age)
  {
    Age = age;
  }
  int getAge ()
  {
    return Age;
  }

  Employee (string name, string company, int age)
  {
    Name = name;
    Company = company;
    Age = age;
  }

  void IntroduceYourself ()
  {
    std::cout << Name << std::endl;
    std::cout << Company << std::endl;
    std::cout << Age << std::endl;
  }
  void AskForPromotion ()
  {
    if (Age > 30)
      std::cout << Name << " got promoted!" << std::endl;
    else
      std::cout << Name << ", sorry" << std::endl;
  }
  virtual void Work ()
  {
    std::
      cout << Name << " is checking email, task backlog, performing tasks..."
      << std::endl;
  }
};

class Developer:public Employee
{
public:
  string FavProgrammingLanguage;
  Developer (string name, string company, int age,
	     string favProgrammingLanguage):Employee (name, company, age)
  {
    FavProgrammingLanguage = favProgrammingLanguage;
  }
  void FixBug ()
  {
    std::
      cout << getName () << " fixed bug using " << FavProgrammingLanguage <<
      std::endl;
  }
  void Work ()
  {
    std::cout << getName () << " is doing something" << std::endl;
  }
};

class Teacher:public Employee
{
public:
  string Subject;
  Teacher (string name, string company, int age,
	   string subject):Employee (name, company, age)
  {
    Subject = subject;
  }
  void PrepareLesson ()
  {
    std::
      cout << getName () << " is preparing " << Subject << " lesson" << std::
      endl;
  }
  void Work ()
  {
    std::cout << getName () << " is teaching" << std::endl;
  }
};

int
main ()
{
  Developer d = Developer ("Saldina", "YT", 25, "C++");
  Teacher t = Teacher ("Kac", "School", 35, "History");

  Employee *e1 = &d;
  Employee *e2 = &t;

  e1->Work ();
  e2->Work ();
}
