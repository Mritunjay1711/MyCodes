#include<iostream>

using namespace std;

class sample
{
    int a;
    public:
        void setData(int b)
        {
            a = b;
        }
        void display()
        {
            cout << a << "\n";
        }
};

int main()
{
    sample *s;
    s = new sample;
    s->setData(10);
    s->display();
    return 0;
}