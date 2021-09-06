#include <iostream>
using namespace std;
class length
{
    int feet;
    int inches;
    static int count;

public:
    length(int a, int b)
    {
        feet = a;
        inches = b;
        ++count;
    }
    // length(const length &p)
    // {
    //     feet = p.feet;
    //     inches = p.inches;
    //     count++;
    // }
    void display()
    {
        cout << "larger length is " << feet << " feet and " << inches <<" inches "<< endl;
    }
    static void print()
    {
        cout<<"the no of object created is "<<count<<endl;
    }
    
    friend void compare(length p, length q);
     ~length()
     {
         cout<<"oject no destroyed is "<<count--<<endl;
     }

};
void compare(length p, length q)
{
    float d1 = p.feet + (p.inches) * 0.0833;
    float d2 = q.feet + (q.inches) * 0.0833;
    if (d1 > d2)
        p.display();
    q.display();
}

int length::count=0;
int main()
{
    int f1, i1, f2, i2;
    cout << "enter length 1" << endl;
    cin >> f1 >> i1;
    cout << "enter length 2" << endl;
    cin >> f2 >> i2;
    length l1(f1, i1);
    length l2(f2, i2);
    compare(l1, l2);
    length::print();

    return 0;
}