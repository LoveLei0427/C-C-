#include <iostream>
using namespace std;
class Base{
public:
    void setxy(int n,int m)
    {
        x = n;
        y = m;
    }
    void showxy()
    {
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
    }
private:
    int x;
protected:
    int y;
};

class Derive1:public Base
{
public:
    void setxyz(int n,int m,int r)
    {
        setxy(n,m);
        z = r;
    }
    void showxyz()
    {
        showxy();
        cout<<"z = "<<z<<endl;
    }
private:
    int z;
};

int main()
{
    Derive1 op1;
    op1.setxyz(1,2,3);
    op1.showxy();
    op1.showxyz();
    return 0;
}