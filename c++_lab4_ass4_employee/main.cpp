#include <iostream>
#include<string.h>

using namespace std;
// class notation for line 49
class Employee;

class Person
{
	char fname[10];
	char lname[10];
	double netsal;
public:
	Person()
	{
		strcpy(fname, "");
		strcpy(lname,"");
		netsal = 0;
	}
	Person(char _fname[], char _lname[] , int _netsalary)
	{
		strcpy(fname,_fname);
		strcpy(lname, _lname);
		netsal = _netsalary;

	}

	void setfname(char _fname[])
	{
		strcpy(fname, _fname);
	}
	void setlname(char _lname[])
	{
		strcpy(lname ,_lname);
	}
	void setnetsalary(int netsalary)
	{
		netsal=netsalary;
	}
	void show()
	{
	    cout <<"\nPerson Data: "<< endl;
		cout <<"\tPerson First Name : "<< fname<<endl;
		cout << "\tPerson Last Name : "<<lname << endl;
		cout << "\tPerson Net Salary : "<<netsal << endl;
	}

	// function prototype to be implemented outside the class
	operator Employee();
};

class Employee
{
	char fullname[20];
	int salary;
	int overtime;
public:
	Employee()
	{
		strcpy(fullname,"") ;
		salary = 0;
		overtime = 0;
	}

	Employee(char _fullname[] ,int _salary ,int _overtime)
	{
		strcpy(fullname,_fullname) ;
		salary = _salary;
		overtime = _overtime;

	}
	void setFullname(char fulln[])
	{
		strcpy(fullname,fulln);
	}
	void setSalary(int _salary)
	{
		salary=_salary;
	}
	void setOvertime(int ovtime)
	{
		overtime = ovtime;
	}
	void print()
	{
        cout <<"\nEmployee Data : " <<endl;
		cout << "\tEmployee Full Name : " << fullname << endl;
		cout << "\tEmployee Salary : " << salary << endl;
		cout << "\tEmployee Overtime : " << overtime << endl;
	}

	// this function is used to convert employee to person
	operator Person()
	{

		Person p;
		// this function extract string up to specified delimiter
        char *stringArray = strtok(fullname, " ");
        if(stringArray != NULL)
        {
             p.setfname(stringArray);

            stringArray = strtok(NULL, " ");

             p.setlname(stringArray);
        }

        p.setnetsalary(salary+overtime);
          return p;
	}
};
// this function convert person to employee
Person::operator Employee()
{
	Employee e1;
	char fullname[20] ={};
	strcat(fullname, fname);
	strcat(fullname, " ");
	strcat(fullname, lname);

	e1.setFullname(fullname);
	e1.setSalary(netsal*0.8);
	e1.setOvertime(netsal*0.2);

	return e1;
}

int main()
{
	Person p1("Hany", "Safwat", 20000),p2;
	Employee e1,e2("mahmoud ahmed",12000,3000);

	cout << "1)" ;
	p1.show();
	cout << "\n\n-after casting to employee : \n\n" ;
	e1=(Employee)p1;
	e1.print();
	cout << "***********************************************************" << endl;
	cout << "2)" ;
	e2.print();
    cout << "\n\n-after casting to person : \n\n" ;
    p2=(Person)e2;
    p2.show();
	return 0;
}
