#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <cstdio>
using namespace std;

int r;
int chkacc(int a);
int chkac(int b);

COORD coord = {0,0};

void gotoxy(int a, int b){
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void design(int x, int y) {
    for (int i = 0; i <= x; i++)
        cout<<(char)y;
}

class bms{
    //data encaptulation
    protected: // data hiding
        char id[20], password[15];
    private:
        int m;
    public: // data abstraction
        bms(){ //constructor
            system("color f4");
            gotoxy(26, 4);
            design(15, 177);
            cout<<" WELCOME TO MANAGEMENT STUDENT SYSTEM ";
            design(15, 177);
            gotoxy(50, 8);
            cout<<"ACCOUNT TYPE";
            gotoxy(44, 10);
            cout<<"[1] . ADMINISTRATOR ";
            gotoxy(44, 12);
            //cout<<"[2] . USER ";
            gotoxy(44, 15);
            cout<<"Enter Your Choice .... ";
            cin>>m;
            if (m != 1 && m != 2) {
                system("cls");
                bms();
            }
            system("cls");
            authenticate();
        }

        void authenticate(){
            system("color f4");
            gotoxy(26, 4);
            design(15, 177);
            cout<<" WELCOME TO MANAGEMENT STUDENT SYSTEM ";
            design(15, 177);
            login();
            if (verify() == 1) {
                if (m == 1)
                    study();
                else
                    transactions();
            } else if (verify() == 0) {
                system("cls");
                gotoxy(35, 17);
                design(48, 45);
                gotoxy(43, 16);
                cout<<"Incorrect Username / Password !!!!";
                authenticate();
            }
        }

        void login(){ // Takes the user-name and password .
            int j;
            char c;
            // gotoxy(44, 10);
            // cout<<"Enter The Username : ";
            // cin>>id;
            // gotoxy(44, 12);
            // cout<<"Enter The Password : ";
            // cin>>password;
            gotoxy(44, 10);
            cout <<"Enter The Username: ";
            for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
            {	if ( c == '\b')
                {
                    cout << '\b';
                    cout << " ";
                    cout <<'\b';
                    j = j-2;
                }
                else
                {
                    id[j] = c;
                    cout<<id[j];
                }
            }
            id[j]='\0';//admin loing system
            if(!strcmpi(id,"admin"))
                cout << " ";
            else
            {	
                gotoxy(50, 11);
                cout <<"Error User\n";
                //goto lab;
            }
            lab1:
            gotoxy(44, 13);
            cout <<"Enter The password: ";
            for( j=0;j < 79 && (c = getch()) != '\r'; j++ )
            {	if ( c == '\b')
                {
                    cout << '\b';
                    cout << " ";
                    cout <<'\b';
                    j = j-2;
                }
                else
                {
                    password[j] = c;
                    std::cout<<"*";
                }
            }
            password[j]='\0';
            if(!strcmpi(password, "admin"))
                cout << " ";
            else
            {	
                verify();
            }

        }

        int verify(){ // verifies the user-name and password .
            if (m == 1) {
                if ((strcmpi(id, "admin") == 0 && strcmpi(password, "admin") == 0)) {
                    gotoxy(35, 17);
                    design(48, 45);
                    gotoxy(38, 16);
                    cout<<"You Have Successfully Logged In : "<<'"'<<id<<'"'<<endl;
                    time_t t;
                    time(&t);
                    gotoxy(39, 18);
                    cout<<"Logged In Time : "<<ctime(&t);
                    gotoxy(44, 22);
                    cout<<"Press any key to continue .... ";
                    getch();
                    return 1;
                } else
                    return 0;
            } else if (m == 2) {
                if (strcmpi(id, "user") == 0 && strcmpi(password, "user") == 0) {
                    gotoxy(35, 17);
                    design(48, 45);
                    gotoxy(38, 16);
                    cout<<"You Have Successfully Logged In : "<<'"'<<id<<'"'<<endl;
                    time_t t;
                    time(&t);
                    gotoxy(39, 18);
                    cout<<"Logged In Time : "<<ctime(&t);
                    gotoxy(44, 22);
                    cout<<"Press any key to continue .... ";
                    getch();
                    return 1;
                } else
                    return 0;
            }
            return 0;
        }
        
        void study(){ //module for searching account ( 2 types by number and name )
            system("cls");
            int a;
            gotoxy(28, 4);
            design(25, 177);
            cout<<" WELCOME TO MAIN MENU ";
            design(25, 177);
            gotoxy(49, 10);
            cout<<"[1] . Confirmation of study ";
            gotoxy(49, 13);
            cout<<"[2] . Confirmation of Degree ";
            gotoxy(49, 16);
            cout<<"[3] . Log Out";
            gotoxy(49, 18);
            cout<<"Enter Your Choice [1-3] : ";
            scanf("%d", &a);
            system("cls");
            if (a == 1) {
                menu();
            } else if (a == 2) {
                degree();
            } else if (a== 3){
                menuexit();
            }else 
                study();
        }

        void degree(){ // displays the main user interface screen of program .
            system("cls");
            gotoxy(28, 4);
            design(20, 177);
            cout<<" WELCOME TO MAIN MENU ";
            design(20, 177);
            gotoxy(44, 8);
            cout<<"[1] . View Degree List";
            gotoxy(44, 9);
            cout<<"[2] . Enter Degree Data Student";
            gotoxy(44, 10);
            cout<<"[3] . Edit Degree Student";
            gotoxy(44, 11);
            cout<<"[4] . Delete Degree Student";
            gotoxy(44, 12);
            cout<<"[5] . Search Degree Student";
            gotoxy(44, 13);
            cout<<"[6] . Log Out !!! ";
            gotoxy(44, 14);
            cout<<"[7] . Back Main Menu";
            gotoxy(44, 20);
            cout<<"Please Enter Your Choice [1-7] : ";
            opt();
        }

        void opt() { // takes user choice and goes to desired function .
            int p;
            cin>>p;
            system("cls");
            switch (p) {
                case 1:
                    vie();
                    break;
                case 2:
                    ad();
                    break;
                case 3:
                    edi();
                    break;
                case 4:
                    de();
                    break;
                case 5:
                    src();
                    break;
                case 6:
                    menuexit();
                    break;
                case 7:
                    study();
                    break;
                default:
                    degree();
            }
        }

        void search_ID();
        void search_nam();
        void vie();
        void ad();
        void edi();
        void de();
        
        void src(){
            system("cls");
            int b;
            gotoxy(28, 4);
            design(25, 177);
            cout<<" SEARCH MENU ";
            design(25, 177);
            gotoxy(49, 10);
            cout<<"[1] . Search By ID ";
            gotoxy(49, 12);
            cout<<"[2] . Search By Name ";
            gotoxy(47, 17);
            cout<<"Enter Your Choice [1-2] : ";
            scanf("%d", &b);
            system("cls");
            if (b == 1) {
                search_ID();
            } else if (b == 2) {
                search_nam();
            } else
                degree();
        }

        void menu(){ // displays the main user interface screen of program .
            system("cls");
            gotoxy(28, 4);
            design(20, 177);
            cout<<" WELCOME TO MAIN MENU ";
            design(20, 177);
            gotoxy(44, 8);
            cout<<"[1] . View Customer Student";
            gotoxy(44, 9);
            cout<<"[2] . Customer Student Registration";
            gotoxy(44, 10);
            cout<<"[3] . Edit Customer Student";
            gotoxy(44, 11);
            cout<<"[4] . Delete Customer Student";
            gotoxy(44, 12);
            cout<<"[5] . Search Customer Student";
            gotoxy(44, 13);
            cout<<"[6] . Log Out !!! ";
            gotoxy(44, 14);
            cout<<"[7] . About US ";
            gotoxy(44, 15);
            cout<<"[8] . Back Main Menu";
            gotoxy(43, 20);
            cout<<"Please Enter Your Choice [1-8] : ";
            option();
        }

        void option() { // takes user choice and goes to desired function .
            int i;
            cin>>i;
            system("cls");
            switch (i) {
                case 1:
                    view();
                    break;
                case 2:
                    add();
                    break;
                case 3:
                    edit();
                    break;
                case 4:
                    del();
                    break;
                case 5:
                    srch();
                    break;
                case 6:
                    menuexit();
                    break;
                case 7:
                    about();
                    break;
                case 8:
                    study();
                    break;
                default:
                    menu();
            }
        }

        void view();
        void add();
        void edit();
        void del();

        void srch(){ //module for searching account ( 2 types by number and name )
            system("cls");
            int a;
            gotoxy(28, 4);
            design(25, 177);
            cout<<" SEARCH MENU ";
            design(25, 177);
            gotoxy(49, 10);
            cout<<"[1] . Search By Account ";
            gotoxy(49, 12);
            cout<<"[2] . Search By Name ";
            gotoxy(47, 17);
            cout<<"Enter Your Choice [1-2] : ";
            scanf("%d", &a);
            system("cls");
            if (a == 1) {
                search_acc();
            } else if (a == 2) {
                search_name();
            } else
                menu();
        }
        void search_acc();
        void search_name();

        void transactions(){ // displays screen for the transaction options and takes the user choice .
            system("CLS");
            gotoxy(25, 4);
            design(25, 177);
            cout<<" TRANSACTION MENU ";
            design(25, 177);
            gotoxy(49, 9);
            cout<<"[1] . View List Student";
            gotoxy(49, 10);
            cout<<"[2] . View Degree Student";
            if (m == 1) {
                gotoxy(49, 11);
                cout<<"[2] . Main Menu";
            } else {
                gotoxy(49, 11);
                cout<<"[3] . Exit";
            }
            gotoxy(45, 13);
            cout<<"Please Enter Your Choice [1-3] : ";
            int a;
            scanf("%d", &a);
            switch (a) {
                case 1:
                    system("cls");
                    show();
                    break;
                case 2:
                    system("cls");
                    sh();
                    break;
                case 3:
                        menuexit();
                        break;
                default:
                    transactions();
            }
        }
        void sh();//show data list degree student
        void show();//show data list Confirmation of study
        void menuexit();//exit program

        void about(){
            gotoxy(30, 4);
            design(25, 177);
            cout<<" ABOUT US ";
            design(25, 177);
            gotoxy(14, 9);
            cout<<"It is a Simple Student Management System Project for our 2nd Semester based on C++ programming language.";
                    gotoxy(45, 12);
                    cout<<"Members of Team Warriors: ";
                    gotoxy(28, 13);
                    design(65, 205);
                    gotoxy(48, 15);
                    cout<<"[1] . Panha";
                    gotoxy(48, 16);
                    cout<<"[2] . Rady";
                    gotoxy(48, 17);
                    cout<<"[3] . Vifon";
                    gotoxy(48, 18);
                    cout<<"[4] . DaVid";
                    gotoxy(48, 19);
                    cout<<"[5] . Piseth";
                    gotoxy(48, 20);
                    cout<<"[6] . Neit";
                    gotoxy(48, 21);
                    cout<<"[7] . SengHor";
                    gotoxy(48, 22);
                    cout<<"[8] . Lilay";
                    gotoxy(41, 23);
                    design(42, 196);
                    gotoxy(42,24);
                    cout<<"Press any key to return back to main menu. ";
                    char z = getch();
                    if (z == 13) {
                    menu();
            }
        }
};

class degre{
    public:
        char na[25];
        int id;
        char uni[10];
        int d,m,y;
        char posi[20];
        char addre[25];
        int userId[35];
        char mas[25];
};

void bms::sh(){//show in user login 
    int i = 7;
    degre deg;
    //read from the file
    ifstream f;
    f.open("degree.bin", ios::in | ios::binary); //open file for read only
    gotoxy(25, 3);
    design(25, 177);
    cout<<" CUSTOMERS LIST ";
    design(25, 177);
    gotoxy(5, 5);
    cout<<"A/C No.";
    gotoxy(15, 5);
    cout<<"University";
    gotoxy(30,5);
    cout<<"Name";
    gotoxy(40,5);
    cout<<"DD/MM/YY";
    gotoxy(50,5);
    cout<<"Degree";
    gotoxy(60, 5);
    cout<<"UserID";
    gotoxy(75, 5);
    cout<<"Position";
    gotoxy(95, 5);
    cout<<"Address";
    gotoxy(5, 6);
    design(109, 205);
    while (f.read(reinterpret_cast<char*>(&deg), sizeof(deg))) {
        gotoxy(7, i);
        cout<<deg.id;
        gotoxy(15, i);
        cout<<deg.uni;
        gotoxy(30,i);
        cout<<deg.na;
        gotoxy(40,i);
        cout<<deg.d<<"/"<<deg.m<<"/"<<deg.y;
        gotoxy(50,i);
        cout<<deg.mas;
        gotoxy(60, i);
        for (r = 0; r < 6; r++) {
            cout<<(int)deg.userId[r];
        }
        gotoxy(75, i);
        cout<<deg.posi;
        gotoxy(95, i);
        cout<<deg.addre;
        i++;
    }
    f.close();
    int x;
    gotoxy(42, i + 5);
    cout<<"Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        transactions();
    } else
        sh();
}

void bms::vie(){
    int i = 7;
    int totalMaster = 0;
    degre deg;
    //read from the file
    ifstream f;
    f.open("degree.bin", ios::in | ios::binary); //open file for read only
    gotoxy(25, 3);
    design(25, 177);
    cout<<" CUSTOMERS LIST ";
    design(25, 177);
    gotoxy(5, 5);
    cout<<"A/C No.";
    gotoxy(15, 5);
    cout<<"University";
    gotoxy(30,5);
    cout<<"Name";
    gotoxy(45,5);
    cout<<"DD/MM/YY";
    gotoxy(55,5);
    cout<<"Degree";
    gotoxy(65, 5);
    cout<<"UserID";
    gotoxy(75, 5);
    cout<<"Position";
    gotoxy(95, 5);
    cout<<"Address";
    gotoxy(5, 6);
    design(109, 205);
    while (f.read(reinterpret_cast<char*>(&deg), sizeof(deg))) {
        ++totalMaster;
        gotoxy(7, i);
        cout<<deg.id;
        gotoxy(15, i);
        cout<<deg.uni;
        gotoxy(30,i);
        cout<<deg.na;
        gotoxy(45,i);
        cout<<deg.d<<"/"<<deg.m<<"/"<<deg.y;
        gotoxy(55,i);
        cout<<deg.mas;
        gotoxy(65, i);
        for (r = 0; r < 6; r++) {
            cout<<(int)deg.userId[r];
        }
        gotoxy(75, i);
        cout<<deg.posi;
        gotoxy(95, i);
        cout<<deg.addre;
        i++;
    }
    f.close();
    cout<<endl;
    gotoxy(42, i+10);
    design(42, 196);
    gotoxy(42, i+11);
    cout<<"Total Degree => "<<totalMaster<<endl;
    gotoxy(42, i+12);
    design(42, 196);
    int x;
    gotoxy(42, i + 15);
    cout<<"Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        degree();
    } else
        vie();

}

//module for adding degree.
void bms::ad(){
    char c;
    degre deg;
    //app = append binary / write data to the file
    ofstream f;
    f.open("degree.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
    // first we evaluate body and check condition
    do {
        system("cls");
        gotoxy(24, 4);
        design(20, 177);
        cout<<" CUSTOMER ACCOUNT LIST STUDENT ";
        design(20, 177);
        gotoxy(36, 8);
        cout<<"[1] . Enter Your University     : ";
        cin>>deg.uni;
        gotoxy(36, 9);
        cout<<"[2] . Enter Your Student Number : ";
        scanf(" %d", &deg.id);
        gotoxy(36, 10);
        cout<<"[3] . Enter Your Name           : ";
        cin.ignore();
        cin.getline(deg.na,25);
        gotoxy(36, 11);
        cout<<"[4] . Enter Your Birthday       : ";
        cin >>deg.d >> deg.m >>deg.y;
        gotoxy(36, 12);
        cout<<"[5] . Enter Your Degree         : ";
        cin>>deg.mas;
        gotoxy(36, 13);
        cout<<"[6] . Enter Your Position       : ";
        cin>>deg.posi;
        gotoxy(36, 14);
        cout<<"[7] . Enter Your Address        : ";
        cin>>deg.addre;
        gotoxy(36, 15);
        time_t t;
        time(&t);
        gotoxy(36, 16);
        cout<<"Verify to Day : "<<ctime(&t);
        srand(time(0)); //random number
        for (r = 0; r < 6; r++) {
            deg.userId[r] = rand() % 10;
        }
        //write() = for writing binary data
        // reinterpret_cast - casting one pointer data type to another pointer data type
        //This helps to write contents in a class variable in the file and stores it in the variable rec.
        f.write(reinterpret_cast<char*>(&deg), sizeof(deg)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
        gotoxy(38, 18);
        cout<<"CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL";
        i++;
        gotoxy(36, 19);
        cout<<"Do You Want To Add Another Record ? (Y/N) : ";
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
    f.close();
    gotoxy(40, 22);
    cout<<"Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13) {
        degree();
    } else
        add();

}

//module to check whether the entered account is in the database or not
int chkac(int b) {
    degre deg;
    //read binary
    ifstream f;
    f.open("degree.bin", ios::in | ios::binary);
    while (!f.eof(  )) {
        f.read(reinterpret_cast<char*>(&deg),sizeof(deg)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

        if (b == deg.id) {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}

void bms::edi(){
    degre deg;
    ifstream f1;
    ofstream f2;
    int b, c;
re: //label for goto
    gotoxy(23, 4);
    design(25, 177);
    cout<<" EDIT CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 7);
    cout<<"Enter Your Account Number To Edit : ";
    scanf("%d", &b);
    if (chkac(b) == 1) {
        f1.open("degree.bin", ios::in | ios::binary); //read
        f2.open("temp.bin", ios::app | ios::binary); //write
        while (f1.read(reinterpret_cast<char*>(&deg),sizeof(deg))) {
            if (deg.id != b)
                f2.write(reinterpret_cast<char*>(&deg),sizeof(deg));
            else if (deg.id == b) {
                gotoxy(41, 20);
                design(42, 45);
                gotoxy(52, 21);
                cout<<"Account Number Matched";
                gotoxy(41, 22);
                design(42, 45);
                gotoxy(51, 10);
                cout<<"Enter Your Details";
                gotoxy(28, 11);
                design(65, 205);
                gotoxy(31, 12);
                cout<<"[1] . Enter Your University     : ";
                cin>>deg.uni;
                gotoxy(31, 13);
                cout<<"[2] . Enter Your Student Number : ";
                scanf(" %d", &deg.id);
                gotoxy(31, 14);
                cout<<"[3] . Enter Your Name           : ";
                cin.ignore();
                cin.getline(deg.na,25);
                gotoxy(31, 15);
                cout<<"[4] . Enter Your Birthday       : ";
                cin >>deg.d >> deg.m >>deg. y;
                gotoxy(31, 16);
                cout<<"[5] . Ener Your Degree          :";
                cin>>deg.mas;
                gotoxy(31, 17);
                cout<<"[6] . Enter Your Position       : ";
                cin>>deg.posi;
                gotoxy(31, 18);
                cout<<"[7] . Enter Your Address        : ";
                cin>>deg.addre;
                f2.write(reinterpret_cast<char*>(&deg),sizeof(deg));
            }
        }
        f1.close();
        f2.close();
    }
    if (chkac(b) == 0) {
        system("CLS");
        gotoxy(41, 20);
        design(42, 45);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 45);
        goto re; // unconditional jump statement goto <label>
    }
    remove("degree.bin");
    rename("temp.bin", "degree.bin");
    gotoxy(45, 21);
    cout<<"LIST UPDATE SUCCESSFULL";
    gotoxy(42, 24);
    cout<<"Press any key to return back to main menu . ";
    getch();
    degree();

}

//module for deleting List
void bms::de(){
    degre deg;
    ifstream f1;
    ofstream f2;
    int b, c;
re:
    gotoxy(23, 4);
    design(25, 177);
    cout<<" DELETE CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(41, 9);
    cout<<"Enter Your List Number To Delete : ";
    scanf("%d", &b);
    if (chkac(b) == 1) {
        f1.open("degree.bin", ios::in | ios::binary);
        f2.open("temp.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&deg), sizeof(deg))) {
            if (deg.id != b)
                f2.write(reinterpret_cast<char*>(&deg), sizeof(deg));
        }
                f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("degree.bin", ios::out | ios::binary); // write only
        f2.open("temp.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&deg), sizeof(deg)))
            f1.write(reinterpret_cast<char*>(&deg), sizeof(deg));
        f1.close();
        f2.close();
    } else if (chkac(b) == 0) {
        system("CLS");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(51, 15);
        cout<<"Account Doesn't Exist";
        gotoxy(41, 16);
        design(42, 196);
        goto re;
    }
    gotoxy(41, 14);
    design(42, 196);
    gotoxy(44, 15);
    cout<<"CUSTOMER ACCOUNT DELETED SUCCESSFULLY";
    gotoxy(41, 16);
    design(42, 196);
    gotoxy(42, 18);
    cout<<"Press any key to return back to main menu. ";
    getch();
    degree();

}

void bms::search_ID(){ //funtion search by my id
    degre deg;
    ifstream f;
    int c = 0;
    int b, x;
re:
    gotoxy(23, 4);
    design(25, 177);
    cout<<" SEARCH CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 6);
    cout<<"Enter Your ID Number To Search : ";
    scanf("%d", &b);
    if (chkac(b) == 1) {
        f.open("degree.bin", ios::in | ios::binary);
        while (f.read(reinterpret_cast<char*>(&deg), sizeof(deg))) {
            if (deg.id == b) {
                gotoxy(41, 21);
                design(42, 196);
                gotoxy(52, 22);
                cout<<"Account Number Matched";
                gotoxy(41, 23);
                design(42, 196);
                gotoxy(45, 9);
                cout<<"Detail Information of "<< deg.na;
                gotoxy(28, 10);
                design(65, 205);
                gotoxy(37, 11);
                cout<<"[1] . List Number     : "<< deg.id;
                gotoxy(37, 12);
                cout<<"[2] . University      : "<< deg.uni;
                gotoxy(37, 13);
                cout<<"[3] . Name            : "<< deg.na;
                gotoxy(37, 14);
                cout<<"[4] . Birthdat        : "<< deg.d<<"/"<<deg.m<<"/"<<deg.y;
                gotoxy(37, 15);
                cout<<"[5] . Degree          : "<< deg.mas;
                gotoxy(37, 16);
                cout<<"[6] . UserID          : ";
                for (r = 0; r < 6; r++) {
                    cout<<(int)deg.userId[r];
                }
                gotoxy(37, 17);
                cout<<"[7] . Position        : "<< deg.posi;
                gotoxy(37, 18);
                cout<<"[8] . Address         : "<< deg.addre;
            } else
                c = 1;
        }
        f.close();
    }
    if (chkac(b) == 0) {
        system("CLS");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        goto re;
    }
    gotoxy(42, 24);
    cout<<"Press [ENTER] to return back to main menu. ";
    char z = getch();
    if (z == 13)
        degree();
    else
        src();

}

void bms::search_nam(){//funtion search by my name
   int i = 0, c, x;
    char m[25];
    gotoxy(23, 4);
    design(25, 177);
    cout<<" SEARCH CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 6);
    cout<<"Enter Your Full Name To Search : ";
    cin.ignore();
    cin.getline(m,25);
    degre deg;
    ifstream f;
    f.open("degree.bin", ios::in | ios::binary);
    while (f.read(reinterpret_cast<char*>(&deg), sizeof(deg))) {
        c = 0;
        strupr(deg.na);
        strupr(m);
        if (strcmp(deg.na, m) == 0) {
            gotoxy(41, 21);
            design(42, 196);
            gotoxy(52, 22);
            cout<<"Account Number Matched";
            gotoxy(41, 23);
            design(42, 196);
            gotoxy(45, 9);
            cout<<"Detail Information of "<< deg.na;
            gotoxy(28, 10);
            design(65, 205);
            gotoxy(37, 11);
            cout<<"[1] . List Number     : "<< deg.id;
            gotoxy(37, 12);
            cout<<"[2] . University      : "<< deg.uni;
            gotoxy(37, 13);
            cout<<"[3] . Name            : "<< deg.na;
            gotoxy(37, 14);
            cout<<"[4] . Birthdat        : "<< deg.d<<"/"<<deg.m<<"/"<<deg.y;
            gotoxy(37, 15);
            cout<<"[5] . Degree          : "<< deg.mas;
            gotoxy(37, 16);
            cout<<"[6] . UserID          : ";
            for (r = 0; r < 6; r++) {
                cout<<(int)deg.userId[r];
            }
            gotoxy(37, 17);
            cout<<"[7] . Position        : "<< deg.posi;
            gotoxy(37, 18);
            cout<<"[8] . Address         : "<< deg.addre;
        } else
            c = 1;
    }
    f.close();
    if (c == 1) {
        system("cls");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        search_name();
    }
    gotoxy(42, 24);
    cout<<"Press [ENTER] to return back to main menu. ";
    char z = getch();
    if (z == 13)
        degree();
    else
        src();

}

class record{ //inheritance
    public:
        char name[25];
        int account;
        char sex[10];
        char phone[15];
        char address[25];
        char email[35];
        char citiz[20];
        char clas[10];
        char pos[20];
        char UserID[10];
};

void bms::show(){//show in user login
    int i = 7;
    record rec;
    //read from the file
    ifstream f;
    f.open("record.bin", ios::in | ios::binary); //open file for read only
    gotoxy(25, 3);
    design(25, 177);
    cout<<" CUSTOMERS LIST ";
    design(25, 177);
    gotoxy(5, 5);
    cout<<"A/C No.";
    gotoxy(13, 5);
    cout<<"Account Name";
    gotoxy(27,5);
    cout<<"Gender";
    gotoxy(35,5);
    cout<<"Class";
    gotoxy(45, 5);
    cout<<"UserID";
    gotoxy(65, 5);
    cout<<"Email Address";
    gotoxy(85, 5);
    cout<<"Phone No.";
    gotoxy(99, 5);
    cout<<"Position";
    gotoxy(5, 6);
    design(109, 205);
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        gotoxy(7, i);
        cout<<rec.account;
        gotoxy(13, i);
        cout<<rec.name;
        gotoxy(27,i);
        cout<<rec.sex;
        gotoxy(35,i);
        cout<<rec.clas;
        gotoxy(45, i);
        for (r =1; r < 9; r++) {
            cout<<(int)rec.UserID[r];
        }
        gotoxy(65, i);
        cout<<rec.email;
        gotoxy(85, i);
        cout<<rec.phone;
        gotoxy(99, i);
        cout<<rec.pos;
        i++;
    }
    f.close();
    int x;
    gotoxy(42, i + 5);
    cout<<"Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        transactions();
    } else
        show();

}
// module for viewing account details
void bms:: view(){
    int i = 7;
    int totalStudent = 0;
    record rec;
    //read from the file
    ifstream f;
    f.open("record.bin", ios::in | ios::binary); //open file for read only
    gotoxy(25, 3);
    design(25, 177);
    cout<<" CUSTOMERS LIST ";
    design(25, 177);
    gotoxy(5, 5);
    cout<<"A/C No.";
    gotoxy(13, 5);
    cout<<"Account Name";
    gotoxy(27,5);
    cout<<"Gender";
    gotoxy(35,5);
    cout<<"Class";
    gotoxy(45, 5);
    cout<<"UserID";
    gotoxy(60, 5);
    cout<<"Email Address";
    gotoxy(85, 5);
    cout<<"Phone No.";
    gotoxy(99, 5);
    cout<<"Position";
    gotoxy(5, 6);
    design(109, 205);
    /* f.read() = for reading binary data
     This reads the contents of a class variable from the file and stores it in the variable rec.
     The f.read() function will keep returning 1 until there are records in the file.
     As soon as the EOF is encountered fread() will return a value less than 1 and
     the condition in the while loop become false and the control comes out of the while loop.
    */
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        ++totalStudent;
        gotoxy(7, i);
        cout<<rec.account;
        gotoxy(13, i);
        cout<<rec.name;
        gotoxy(27,i);
        cout<<rec.sex;
        gotoxy(35,i);
        cout<<rec.clas;
        gotoxy(45, i);
        for (r = 1; r < 9; r++) {
            cout<<(int)rec.UserID[r];
        }
        gotoxy(60, i);
        cout<<rec.email;
        gotoxy(85, i);
        cout<<rec.phone;
        gotoxy(99, i);
        cout<<rec.pos;
        i++;
    }
    f.close();
    cout<<endl;
    gotoxy(42, i+10);
    design(42, 196);
    gotoxy(42, i+11);
    cout<<"Total Student => "<<totalStudent<<endl;
    gotoxy(42, i+12);
    design(42, 196);
    int x;
    gotoxy(42, i + 15);
    cout<<"Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        menu();
    } else
        view();
}

//module for adding accounts.
void bms:: add(){
    char c;
    record rec;
    //app = append binary / write data to the file
    ofstream f;
    f.open("record.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
    // first we evaluate body and check condition
    do {
        system("cls");
        gotoxy(24, 4);
        design(20, 177);
        cout<<" CUSTOMER ACCOUNT REGISTRATION ";
        design(20, 177);
        gotoxy(36, 8);
        cout<<"[1] . Enter Your Name           : ";
        cin.ignore();
        cin.getline(rec.name,25);
        gotoxy(36, 9);
        cout<<"[2] . Enter Your Account Number : ";
        scanf(" %d", &rec.account);
        gotoxy(36, 10);
        cout<<"[3] . Enter Your Gender         : ";
        cin>>rec.sex;
        gotoxy(36, 11);
        cout<<"[4] . Enter Your Class          : ";
        cin>>rec.clas;
        gotoxy(36, 12);
        cout<<"[5] . Enter Your Phone Number   : ";
        cin>>rec.phone;
        gotoxy(36, 13);
        cout<<"[6] . Enter Your Address        : ";
        cin>>rec.address;
        gotoxy(36, 14);
        cout<<"[7] . Enter Your E-mail         : ";
        cin>>rec.email;
        gotoxy(36, 15);
        cout<<"[8] . Enter Your Citizenship No.: ";
        cin>>rec.citiz;
        gotoxy(36, 16);
        cout<<"[9] . Enter Your Position       : ";
        cin>>rec.pos;
        srand(time(0)); //random number
        for (r = 1; r < 9; r++) {
            rec.UserID[r] = rand() % 10;
        }
        //write() = for writing binary data
        // reinterpret_cast - casting one pointer data type to another pointer data type
        //This helps to write contents in a class variable in the file and stores it in the variable rec.
        f.write(reinterpret_cast<char*>(&rec), sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
        gotoxy(38, 18);
        cout<<"CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL";
        i++;
        gotoxy(36, 20);
        cout<<"Do You Want To Add Another Record ? (Y/N) : ";
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
    f.close();
    gotoxy(40, 22);
    cout<<"Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13) {
        menu();
    } else
        view();
}

//module to check whether the entered account is in the database or not
int chkacc(int a) {
    record rec;
    //read binary
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (!f.eof(  )) {
        f.read(reinterpret_cast<char*>(&rec),sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

        if (a == rec.account) {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}

// module for editing details.
void bms::edit(){
    record rec;
    ifstream f1;
    ofstream f2;
    int a, c;
re: //label for goto
    gotoxy(23, 4);
    design(25, 177);
    cout<<" EDIT CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 7);
    cout<<"Enter Your Account Number To Edit : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary); //read
        f2.open("new.bin", ios::app | ios::binary); //write
        while (f1.read(reinterpret_cast<char*>(&rec),sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec),sizeof(rec));
            else if (rec.account == a) {
                gotoxy(41, 20);
                design(42, 45);
                gotoxy(52, 21);
                cout<<"Account Number Matched";
                gotoxy(41, 22);
                design(42, 45);
                gotoxy(51, 10);
                cout<<"Enter Your Details";
                gotoxy(28, 11);
                design(65, 205);
                gotoxy(31, 12);
                cout<<"[1] . Enter Your Name           : ";
                cin.ignore();
                cin.getline(rec.name,25);
                gotoxy(31, 13);
                cout<<"[2] . Enter Your Account Number : ";
                scanf(" %d", &rec.account);
                gotoxy(31, 14);
                cout<<"[3] . Enter Your Gender         : ";
                cin>>rec.sex;
                gotoxy(31, 15);
                cout<<"[4] . Enter Your Class          : ";
                cin>>rec.clas;
                gotoxy(31, 16);
                cout<<"[5] . Enter Your Phone Number   : ";
                cin>>rec.phone;
                gotoxy(31, 17);
                cout<<"[6] . Enter Your Address        : ";
                cin>>rec.address;
                gotoxy(31, 18);
                cout<<"[7] . Enter Your E-mail         : ";
                cin>>rec.email;
                gotoxy(31, 19);
                cout<<"[8] . Enter Your Citizenship No : ";
                cin>>rec.citiz;
                f2.write(reinterpret_cast<char*>(&rec),sizeof(rec));
            }
        }
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(41, 20);
        design(42, 45);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 45);
        goto re; // unconditional jump statement goto <label>
    }
    remove("record.bin");
    rename("new.bin", "record.bin");
    gotoxy(45, 21);
    cout<<"CUSTOMER ACCOUNT UPDATE SUCCESSFULL";
    gotoxy(42, 24);
    cout<<"Press any key to return back to main menu . ";
    getch();
    menu();
}

//module for deleting account
void bms::del(){
    record rec;
    ifstream f1;
    ofstream f2;
    int a, c;
re:
    gotoxy(23, 4);
    design(25, 177);
    cout<<" DELETE CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(41, 9);
    cout<<"Enter Your Account Number To Delete : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        }
                f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("record.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&rec), sizeof(rec)))
            f1.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        f1.close();
        f2.close();
    } else if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(51, 15);
        cout<<"Account Doesn't Exist";
        gotoxy(41, 16);
        design(42, 196);
        goto re;
    }
    gotoxy(41, 14);
    design(42, 196);
    gotoxy(44, 15);
    cout<<"CUSTOMER ACCOUNT DELETED SUCCESSFULLY";
    gotoxy(41, 16);
    design(42, 196);
    gotoxy(42, 18);
    cout<<"Press any key to return back to main menu. ";
    getch();
    menu();
}

void bms::search_acc() { //search by my id
        record rec;
        ifstream f;
        int b = 0;
        int a, x;
    re:
        gotoxy(23, 4);
        design(25, 177);
        cout<<" SEARCH CUSTOMER ACCOUNT ";
        design(25, 177);
        gotoxy(43, 6);
        cout<<"Enter Your Account Number To Search : ";
        scanf("%d", &a);
        if (chkacc(a) == 1) {
            f.open("record.bin", ios::in | ios::binary);
            while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
                if (rec.account == a) {
                    gotoxy(41, 21);
                    design(42, 196);
                    gotoxy(52, 22);
                    cout<<"Account Number Matched";
                    gotoxy(41, 23);
                    design(42, 196);
                    gotoxy(45, 9);
                    cout<<"Detail Information of "<< rec.name;
                    gotoxy(28, 10);
                    design(65, 205);
                    gotoxy(37, 11);
                    cout<<"[1] . Account Number  : "<< rec.account;
                    gotoxy(37, 12);
                    cout<<"[2] . Name            : "<< rec.name;
                    gotoxy(37, 13);
                    cout<<"[3] . Gender          : "<< rec.sex;
                    gotoxy(37, 14);
                    cout<<"[4] . Class           : "<< rec.clas;
                    gotoxy(37, 15);
                    cout<<"[5] . UserID          : ";
                    for (r = 1; r < 9; r++) {
                        cout<<(int)rec.UserID[r];
                    }
                    gotoxy(37, 16);
                    cout<<"[6] . Phone Number    : "<< rec.phone;
                    gotoxy(37, 17);
                    cout<<"[7] . Address         : "<< rec.address;
                    gotoxy(37, 18);
                    cout<<"[8] . E-mail          : "<< rec.email;
                    gotoxy(37, 19);
                    cout<<"[9] . Citizenship No  : "<< rec.citiz;
                    gotoxy(37, 20);
                    cout<<"[10] .Current Position: "<< rec.pos;
                } else
                    b = 1;
            }
            f.close();
        }
        if (chkacc(a) == 0) {
            system("CLS");
            gotoxy(41, 20);
            design(42, 196);
            gotoxy(52, 21);
            cout<<"Account Doesn't Exist. ";
            gotoxy(41, 22);
            design(42, 196);
            goto re;
        }
        gotoxy(42, 24);
        cout<<"Press [ENTER] to return back to main menu. ";
        char z = getch();
        if (z == 13)
            menu();
        else
            srch();
}

void bms::search_name() { //funtion search by my name
    int i = 0, b, x;
    char nam[30];
    gotoxy(23, 4);
    design(25, 177);
    cout<<" SEARCH CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 6);
    cout<<"Enter Your Full Name To Search : ";
    cin.ignore();
    cin.getline(nam,30);
    record rec;
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        b = 0;
        strupr(rec.name);
        strupr(nam);
        if (strcmp(rec.name, nam) == 0) {
            gotoxy(41, 21);
            design(42, 196);
            gotoxy(52, 22);
            cout<<"Account Number Matched";
            gotoxy(41, 23);
            design(42, 196);
            gotoxy(45, 9);
            cout<<"Detail Information of "<< rec.name;
            gotoxy(28, 10);
            design(65, 205);
            gotoxy(37, 11);
            cout<<"[1] . Account Number  : "<< rec.account;
            gotoxy(37, 12);
            cout<<"[2] . Name            : "<< rec.name;
            gotoxy(37, 13);
            cout<<"[3] . Gender          : "<< rec.sex;
            gotoxy(37, 14);
            cout<<"[4] . Class           : "<< rec.clas;
            gotoxy(37, 15);
            cout<<"[5] . UserID          : ";
            for (r = 1; r < 9; r++) {
                cout<<(int)rec.UserID[r];
            }
            gotoxy(37, 16);
            cout<<"[6] . Phone Number    : "<< rec.phone;
            gotoxy(37, 17);
            cout<<"[7] . Address         : "<< rec.address;
            gotoxy(37, 18);
            cout<<"[8] . E-mail          : "<< rec.email;
            gotoxy(37, 19);
            cout<<"[9] . Citizenship No  : "<< rec.citiz;
            gotoxy(37, 20);
            cout<<"[10]. Current Position: "<< rec.pos;
        } else
            b = 1;
    }
    f.close();
    if (b == 1) {
        system("cls");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        search_name();
    }
    gotoxy(42, 24);
    cout<<"Press [ENTER] to return back to main menu. ";
    char z = getch();
    if (z == 13)
        menu();
    else
        srch();
}

void bms::menuexit(){ //module for logging out of the program.
    system("cls");
        gotoxy(30, 4);
        design(25, 177);
        cout<<" THANK YOU ";
        design(25, 177);
        gotoxy(42, 12);
        cout<<"USER            :: "<< id;
        time_t t;
        time(&t);
        gotoxy(42, 14);
        cout<<"Logged Out Time :: "<< ctime(&t);
        fflush(stdin);
        getch();
        gotoxy(0, 26);
        exit(0);
}

int main()
{
    system("cls");
    bms w;
    return 0;
}