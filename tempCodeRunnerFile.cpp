#include<iostream>
#include<stdio.h>

#include<cstring>
#include<string.h>

using namespace std;
class item
{
    private:
        char code[50];
        char name[50];
        float price,total;
        int quantity;
        static int count;
    public:
	void input( char *c, char *n, float p, int q, float t )
	{
    strcpy(code,c);
	strcpy(name,n);
	price=p;
	quantity=q;	
	total=t;
	}
	void display()
	{     
	 cout<<count++<<"\t\t"<<code<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<quantity<<"\t\t"<<total<<endl;
	 cout<<"--------------------------------------------------------------------------------------"<<endl;
	  
//cout<<"SL.No"<<""<<"Code"<<""<<"Name"<<""<<"Price"<<""<<"Quantity"<<""<<"Total"<<endl;
	  
	}

	friend void cal(item *p, int a);   
	
};

int item :: count;

void cal(item *p, int a)
{
    double x;
    for(int i = 0; i < 2; i++)
    {
        x += p[i].total;
    }
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t      Total Bill = "<<x<<endl;
}

int main()
{
	item p[100];
	int i,qtity;
	float pr,tot;
	char a[50],b[10];
	
	
	for(i=0;i<2;i++)
    {
    cout<<"Enter the code= "<<endl;
    cin>>b;
    cout<<"Enter the name of the item "<<i+1<<" = ";
    getchar();
    gets(a);
    //scanf("%[^/n]s",a);
    cout<<"Enter the price= "<<endl;
    cin>>pr;
    cout<<"Enter the quantity= "<<endl;
    cin>>qtity;
    cout<<"Enter the total= "<<endl;
    cin>>tot;
     p[i].input(b,a,pr,qtity,tot);
    }
    
    cout<<"Sl No.\t\t";
    cout<<"Code";
    cout<<"\tName of items";
    cout<<"\titem price ";
    cout<<"\t\tQuantity ";
    cout<<"\tTotal"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    
    for(int i = 0; i < 2; i++)
    {
        p[i].display();
    }
    
       
    cal(p, 2);
        
}