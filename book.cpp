#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class Media
{
    char title[20];
    float price;
    int id;

    public:

    static int count;

    Media(char *t,float p)
    {
        strcpy(title,t);
        price=p;
        count++;
        id=count;
    }

    virtual void show_details();

};


int Media::count=0;

void Media::show_details()
{
    cout << "Title:" << title<<endl;
    cout << "Price:Rs."<<price<<endl;
}

class Book:public Media
{
    int pages;

    public:

    Book(char *t,float p,int num):Media(t,p)
    {
        pages=num;
    }

    void show_details()
    {
        Media::show_details();
        cout << "Number of Pages:"<<pages<<endl;
    }
};

class Tape:public Media
{
    int runtime;

    public:

    Tape(char *t,float p,int num):Media(t,p)
    {
        runtime=num;
    }

    void show_details()
    {
        Media::show_details();
        cout << "Running Time:"<<runtime<<endl;
    }
};


int main()
{
    int n=-1,num;
    char title[20];
    float price;

    Media **m=NULL;

    do
    {

    cout << "-----MEDIA STORE-----\n";
    cout << "1.Book Entry\n2.VideoTape Entry\n3.Search Media\n4.Exit\n>>";

    cin  >> n;

    cout << "\x1B[2J\x1B[H";

    switch(n)
    {
        case 1:
                cout << "Enter Title      :";
                cin >> title;
                cout << "Enter Price      :";
                cin >>price;
                cout << "Enter No.of Pages:";
                cin >>num;

                m=(Media**)realloc(m,sizeof(Media*)*(Media::count+1));

                m[Media::count-1]=new Book(title,price,num);

                break;

        case 2:
                cout << "Enter Title :";
                cin >> title;
                cout << "Enter Price :";
                cin >>price;
                cout << "Running Time:";
                cin >>num;

                m=(Media**)realloc(m,sizeof(Media*)*(Media::count+1));

                m[Media::count-1]=new Tape(title,price,num);

                break;

        case 3: cout << "Enter Media ID:";
                cin >> num;

                m[num-1]->show_details();

                break;

    }
    cout << endl;
    }while(n!=4);


    free(m);
}

