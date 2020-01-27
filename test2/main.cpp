#include <iostream>
#include <string.h>

using namespace std;

class base
{
public:
	void say() {cout << "\n I’m base \n";}
};
class derived:public base
{
public:
	void say() {cout << "\n I’m derived \n";}
};

int main( )
{
    /*
base *pb;
base mybase;
derived myderived;

pb=&mybase;
pb->say();
pb=&myderived;
pb->say();*/


return 0 ;
}
