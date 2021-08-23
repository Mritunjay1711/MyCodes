#include<iostream>
using namespace std;

class person{
    int age;
    public:
        person(int a)
        {
            age = a;
        }
        max_age(person p2);
        void display()
        {
            cout << age;
        }
};

person :: max_age(person p2)
{
    person temp;
    if(age > p2.age)
        temp.age = age;
    else
        temp.age = p2.age;
    
    return temp;
}

int main(){
    person p1(2);
    person p2(5);
    person p3 = p1.max_age(p2);
    p3.display();
}