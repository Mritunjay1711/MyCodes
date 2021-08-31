#include<iostream>
#include<string.h>
using namespace std;

class book
{
    char *author;
    char *title;
    int price;
    char *publisher;
    int stock;
    public:

    void getdata(char *au, char *ti, int p, char *pub, int st)
    {
        author = new char[strlen (au) + 1]; 
        strcpy(author,au);
        title = new char[strlen (ti) + 1];
        strcpy(title,ti);
        price = p;
        publisher = new char[strlen (pub) + 1];
        strcpy(publisher,pub);
        stock = st;
    }

        void display()
        {
            cout << "\n------ The details of book are ---------\n";
            cout << "Author: " << author << endl;
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Stock: " << stock << endl;
        }

    friend void search( book *b, int n, char *au, char *ti);

};

    void search( book *b, int n, char *au, char *ti)
    {
        for (int i = 0; i < n; i++)
        {
            if (strcmp(b[i].author,au)==0  && strcmp(b[i].title,ti)==0 )
            {
                b[i].display();

                int no;
                cout<<"Enter the number of copies : "<<endl;
                cin>>no;

                if (b[i].stock>=no)
                {
                    int bill = no * b[i].price;
                    cout<<"The Total Bill is: Rs "<<bill<<endl;
                }
                else
                {
                cout<<" Requested copies not in stock "<<endl;    
                }
                return;
            }
        }
        cout<<"Requested Book is currently unavailable !"<<endl;
    }


int main(){
    
    char auth[30], tit[50], publish[30];
    int prc, stc;
    int n;
    cout<<" Enter the number of books: "<<endl;
    cin>> n;
    book b[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of author: ";
        getchar();
        gets(auth);
        cout << "Enter the name of book: ";
        gets(tit);
        cout << "Enter the price of book: ";
        cin >> prc;
        cout << "Enter the name of publisher: ";
        getchar();
        gets(publish);
        cout << "Enter the stock present: ";
        cin >> stc;
        b[i].getdata(auth, tit, prc, publish, stc);
    }

    for(int i = 0; i < n; i++)
        b[i].display();
    char sAuthor[30] ,sTitle[30];
    cout << "Enter the name of author to search: ";
    getchar();
    gets(sAuthor);
    cout << "Enter the name of book to search: ";
    gets(sTitle);
    search(b, n, sAuthor, sTitle);

    return 0;
}