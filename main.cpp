#include <bits/stdc++.h>

using namespace std;

bool isLoggedin()
{
    string username,password,un,pw;
    cout<<"Enter your username: ";
    cin>>username;

    cout<<"Enter your password: ";
    cin>>password;
    cout<<endl;

    ifstream read(username+".txt");
    getline(read,un);
    getline(read,pw);

    if(un==username && pw==password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class cars
{
public:

    string name[10] = {"Volvo","BMW","Marcedes","Audi","Mini Cooper","Skoda","Volkswagen","Jaguar","Hyundai","Kia"};

    string model[10]= {"XC90","X5","S350D","A6","Convertible","Octavia","POLO GT","XF","Sonata","2016DF"};

    string color[10]= {"Red","Black","Black","Blue","Black","Brown","Red","Black","grey","white"};

    string mxspeed[10]= {"130 Km/h ","200 Km/h","140 Km/h","150 Km/h","130 Km/h","160 Km/h","180 Km/h","190 Km/h","170 Km/h","120 Km/h"};

    int price[10] = {18000,17000,32000,11000,14000,13000,9000,14000,17000,12000}; //per day
};

cars car;
void printCars()
{
   int index=1;
   cout<<"\nAVAILABLE CARS:"<<endl;

   for(int i=0; i<10; i++)
    {
        cout<<index<<"  -  "<<car.name[i]<<endl;
        index++;
    }
    cout<<endl;
}

void details(int carChoice)
{
    cout<<"\nFollowing are the details of the car: "<<endl;
    cout<<car.name[carChoice-1]<<endl;
    cout<<"Model : "<<car.model[carChoice-1]<<endl;
    cout<<"Color : "<<car.color[carChoice-1]<<endl;
    cout<<"Maximum Speed : "<<car.mxspeed[carChoice-1]<<endl;
    cout<<"Price : "<<car.price[carChoice-1]<<" per day"<<endl;
}

class customerDetails
{
public:
   string customer[10];
   string Lname[10];
   string id[10] ;
   int payment[10] ;
};
customerDetails cd;

void check(int j,int pay )
{
    if(pay>=(car.price[j]))
    {
        cout<<"Process has been completed successfully " <<endl<<endl;
    }
    else
    {
        cout<<"Invalid Payment"<<endl;
        exit(0);
    }
}

void user_input(int carChoice)
{
    int j=(carChoice-1) ;
    cout<<"Please enter your details - "<<endl;

    cout<<"First Name : ";
    cin>>cd.customer[j];

    cout<<"Last Name : ";
    cin>>cd.Lname[j];

    cout<<"ID : ";
    cin>>cd.id[j];

    cout<<"Amount : " ;
    cin>>cd.payment[j];
    int pay=cd.payment[j];

    check(j,pay);
}


int main()
{
    cars car;
    cout<<"WELCOME TO M.S CAR RENTALS!"<<endl<<endl;
    cout<<"If you are a new user, please REGISTER."<<endl;
    cout<<"If you already have an account please SIGN IN to continue."<<endl<<endl;

    int choice;
    cout<<"Press 1 to register"<<endl<<"Press 2 to SIGN IN"<<endl;
    cin>>choice;
    cout<<endl;

    int flag=0;

    if(choice==1)
    {
        string username,password;
        cout<<endl<<"Enter your new username: ";
        cin>>username;
        cout<<"Create a password: ";
        cin>>password;
        if(password.size()<8)
        {
            cout<<"The password must have atleast 8 characters"<<endl;
            cout<<"Please try again: ";
            cin>>password;
        }

        flag++;

        ofstream file;
        file.open(username+".txt");
        file<<username<<endl<<password;
        file.close();

        cout<<endl<<"Registered successfully!"<<endl;
    }
    else
    {
        bool status = isLoggedin();

        if(!status)
        {
            cout<<"Incorrect credentials"<<endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout<<"Logged in successfully!"<<endl;
            system("PAUSE");
            flag++;
        }
    }

    string decision;
    if(flag!=0)
    {
        //cout<<endl<<"Registered successfully!"<<endl;
        printCars();
        int carChoice;
        cout<<"Please enter the number corresponding to the choice of your car: ";
        cin>>carChoice;
        details(carChoice);

        cout<<"Do you want to rent this car(YES / NO / EXIT)? ";
        cin>>decision;

        int days=0;
        if(decision=="YES")
        {
            cout<<"Please enter the number of days you wish to rent the car: ";
            cin>>days;
            cout<<"Price per day: "<<car.price[carChoice-1]<<endl;
            cout<<"The total amount to be paid : "<<(days*car.price[carChoice-1])<<endl<<endl;
            cout<<"Do you wish to continue(YES/NO)? ";
            cin>>decision;
            if(decision=="NO")
            {
                exit(0);
            }
            else
            {
                user_input(carChoice);
                cout<<"---------------------------INVOICE---------------------------"<<endl;
                cout<<"  CAR           - "<<car.name[carChoice-1]<<endl;
                cout<<"  MODEL         - "<<car.model[carChoice-1]<<endl;
                cout<<"  DURATION      - "<<days<<endl;
                cout<<"  PAYMENT STATUS- PAID"<<endl;
            }
        }
        else
        {
            if(decision=="NO")
            {
                exit(0);
            }
            else if  (decision=="EXIT")
            {
                exit(0) ;
            }

        }
    }

    return 0;
}
