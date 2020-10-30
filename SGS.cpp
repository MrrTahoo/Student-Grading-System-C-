#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <string.h>
#include <ctime>


using namespace std; 

void welcome();
void login();
void adminmenu();
void studentmenu();
void programend();

main()
{ 
    welcome();
    login();
}

void welcome()
{
    system ("CLS");
    system ("COLOR 0B");
    cout<<" __________________________________________________________________________________________ "<<endl;
    cout<<"|                                                                                          | "<<endl;
    cout<<"|                                                                                          | "<<endl;
    cout<<"|                       Student Result and Grading Management Software                     |"<<endl;
    cout<<"|                                                                                          |"<<endl;
    cout<<"|                                                                   Coded by Muhammad Taha |"<<endl;
    cout<<"|__________________________________________________________________________________________|"<<endl;
    cout<<"                                                                                            "<<endl;
                                                system ("PAUSE");
}
void login()
{
    int a,p1,p2;
    char res ('y'),start,start1,start2;
    start:
    cout<<"                                        _________________________ "<<endl;
    cout<<"                                       |                         |"<<endl;
    cout<<"                                       |    1. Administrator     |"<<endl;
    cout<<"                                       |    2. Student           |"<<endl;
    cout<<"                                       |    3. Exit              |"<<endl;
    cout<<"                                       |_________________________|"<<endl;
    cout<<"                                                                 "<<endl;
    cout<<"                                       Enter you desired choice : ";
    cin>>a;
    system ("CLS");
        switch(a)
        {
    case 1:
    {
        start1:
        cout<<"Please enter your password : ";
        cin>>p1; 
        if (p1==1234)
        {
            cout<<"Login Successful"<<endl;
            cout<<"\n";
            cout<<"Welcome Administrator"<<endl;
            system ("PAUSE");
            adminmenu();
        }
        if (p1!=1234)
        {
            cout<<"Incorrect Password"<<endl;
            cout<<"Login Failed! Invalid Credentials."<<endl;
            cout<<"Would you like to try again y/n : ";
            cin>>res;
            if(res=='n' || res=='N')
            {
                goto start;
                break;
            }
            if(res=='y' || res == 'Y' )
            {
                goto start1;
                break;

            }
        }
        break;
    }
     
    case 2:
    {
        start2:
        cout<<"Please enter password : ";
        cin>>p2; 
        if (p2==1122)
        {
            cout<<"Login Successful"<<endl;
            cout<<"\n";
            system ("PAUSE");
            studentmenu();
        }
        if (p2!=1122)
        {
            cout<<"Incorrect Password"<<endl;
            cout<<"Login Failed! Invalid Credentials."<<endl;
            cout<<"Would you like to try again y/n : ";
            cin>>res;
            if(res=='n' || res=='Y')
            {
                goto start;
                break;
            }
            if(res=='y' || res == 'Y' )
            {
                goto start2;
                break;
            }
        }
        break;
        
    }
    case 3:
    {
        programend();
        break;
    }
    default:
    {
        cout<<"Sorry Invalid choice entered. PLease try again."<<endl;
        cin.get();
        cin.ignore();
        system ("PAUSE");
        system ("CLS");
        login();
    }
    }
}
void adminmenu()
{
    int c,clas,roll;
    float maths,phy,chem,urdu,computer,eng,total=600,obt,percent;
    char admin,res ('y');
    admin:
    cout<<"                                            _________________________________"<<endl;
    cout<<"                                           | 1. Student Result Calculation   |"<<endl;
    cout<<"                                           | 2. View Student Results         |"<<endl;
    cout<<"                                           | 3. View Student Login Record    |"<<endl;
    cout<<"                                           | 4. Exit to main menu            |"<<endl;
    cout<<"                                           |_________________________________|"<<endl;
    cout<<"                                                   Enter your choice : ";
    cin>>c;
    switch (c)
    {
    case 1:
    {
        do
        {
        int fcoun=0;
        string sname1;
        ofstream Student_data;
        Student_data.open("Student Result.txt",ios::out | ios::app);
        cout<<" __________________________________________________________________________________________ "<<endl;
        cout<<"|                                                                                          | "<<endl;
        cout<<"|                                                                                          | "<<endl;
        cout<<"|                                   Student Result Calculation                             |"<<endl;
        cout<<"|                                                                                          |"<<endl;
        cout<<"|__________________________________________________________________________________________|"<<endl;
        cout<<"                                                                                            "<<endl;
        cout<<"Enter Student's name : ";
        cin.ignore();
        getline(cin,sname1);
        cout<<"Enter Roll no. : ";
        cin>>roll;
        cout<<"Enter Students Class : ";
        cin>>clas;
        cout<<"Enter Marks of the following subjects "<<endl;
        cout<<"1. Mathematics : ";
        cin>>maths;
        cout<<"2. Chemistry : ";
        cin>>chem;
        cout<<"3. Physics : ";
        cin>>phy;
        cout<<"4. English : ";
        cin>>eng;
        cout<<"5. Urdu : ";
        cin>>urdu;
        cout<<"6. Computer : ";
        cin>>computer;
        cout<<"____________________________________________________________________________________________________"<<endl;
        Student_data<<" __________________________________________________________________________________________ "<<endl;
        Student_data<<"|                                                                                          | "<<endl;
        Student_data<<"|                                                                                          | "<<endl;
        Student_data<<"|                                    Student Result Calculation                            |"<<endl;
        Student_data<<"|                                                                                          |"<<endl;
        Student_data<<"|__________________________________________________________________________________________|"<<endl;
        Student_data<<"                                                                                            "<<endl;
        Student_data<<"     Student's Name                                 |                "<<sname1<<endl;
        Student_data<<"     Student's Roll no.                             |                "<<roll<<endl;
        Student_data<<"     Student's Class                                |                "<<clas<<endl;
        Student_data<<"                                         Final Semester Result"<<endl;
        Student_data<<"     Mathematics                                    |                "<<maths<<endl;
        Student_data<<"     Chemistry                                      |                "<<chem<<endl;
        Student_data<<"     Physics                                        |                "<<phy<<endl;
        Student_data<<"     English                                        |                "<<eng<<endl;
        Student_data<<"     Urdu                                           |                "<<urdu<<endl;
        Student_data<<"     Computer                                       |                "<<computer<<endl;
        obt = maths+phy+chem+urdu+computer+eng;
        percent = obt/total*100;
        Student_data<<"     Obtained Marks                                 |                "<<obt<<endl;
        Student_data<<"     Percentage                                     |                "<<percent<<endl;
        Student_data<<" ___________________________________________________|______________________________________ "<<endl;
        if(percent>=90)
        {
            Student_data<<"Grade : A+"<<endl;
            Student_data<<"Student Remarks : Outstanding Performance.";
        }
        else if(percent>=80)
        {
            Student_data<<"Grade : A"<<endl;
            Student_data<<"Student Remarks : Excellent Performance.";
        }
        else if(percent>=70)
        {
            Student_data<<"Grade : B "<<endl;
            Student_data<<"Student Remarks : Very Good but needs improvement.";
        }
        else if(percent>=60)
        {
            Student_data<<"Grade : C"<<endl;
            Student_data<<"Good performance but needs to improve him/hersself.";
        }
        else if(percent>=50)
        {
            Student_data<<"Grade : D"<<endl;
            Student_data<<"Satisfactory Performance. Needs loads of improvement.";
        }
        else if (percent<50)
        {
            Student_data<<"Grade : F --> You are Jannati"<<endl;
            Student_data<<"Try again. Better luck next time."<<endl;
            fcoun++;
        }
        Student_data<<"Number of failed students : "<<fcoun<<endl;
        Student_data<<"                                                                                  "<<endl;
        Student_data<<"__________________________________________________________________________________"<<endl;
        Student_data<<"                                                                                  "<<endl;
        cout<<"                  Would you like to calculate another student's result Y/N ?";
        cin>>res; 
        Student_data.close(); 
        }while(res=='y'||res=='Y');
    goto admin;
    break;
    
    }
    case 2:
    {
    
    system("color 0B");
    char ch5;
    ifstream Student_data;
    Student_data.open("Student Result.txt");
    ch5=Student_data.get();
    while(!Student_data.eof())
    {
        cout<<ch5;
        ch5=Student_data.get();
    }
    cout<<" __________________________________________________________________________________________ "<<endl;
    cout<<" ______________________________________END OF RESULTS______________________________________"<<endl;
    cout<<"                                                                                           "<<endl;
    system ("PAUSE");
    system ("CLS");
    goto admin;
    break;
    }
    case 3:
    {
        cout<<"                             The Student Login Records are as follows                        "<<endl;
        ifstream  Student_login;
        char ch6;
        system("color 0B");
        Student_login.open("Student Login Record.txt");
        ch6= Student_login.get();
        while(! Student_login.eof())
        {
            cout<<ch6;
            ch6= Student_login.get();
        }
        cout<<" __________________________________________________________________________________________"<<endl;
        cout<<" ______________________________________END OF RECORDS______________________________________"<<endl;
        cout<<"                                                                                           "<<endl;
        system ("PAUSE");
        system ("CLS");
        Student_login.close();
        goto admin;
        break;
    }
    case 4:
    {
        login();
        break;
    }
    default:
    {
        cout<<"Sorry Invalid choice entered. PLease try again."<<endl;
        system ("PAUSE");
        system ("CLS");
        goto admin;
    }

}
}
void studentmenu()
{
    int rol,clas2;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    fstream Student_login;
    Student_login.open("Student Login Record.txt",ios::out | ios::in | ios::app);
    string sname2;
    cout<<"Please enter you name : ";
    cin.ignore();
    getline(cin,sname2);
    cout <<"Enter your roll no. : ";
    cin>>rol;
    cout<<"Enter you class : ";
    cin>>clas2;
    Student_login<<"________________________________________________________________________________________ "<<endl;
    Student_login<<"Student's Name                      |                     "<<sname2<<endl;
    Student_login<<"Student's Roll no.                  |                     "<<rol<<endl;
    Student_login<<"Student's Class                     |                     "<<clas2<<endl;
    Student_login<<"Date                                |                     "<<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    Student_login<<"Time                                |                     "<<(timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    Student_login<<"____________________________________|____________________________________________________"<<endl;
    cout<<                   "Welcome   " <<  sname2       <<"    of Class    "   <<      clas2      <<endl;
    system ("PAUSE");
    system ("CLS");
    cout<<"                              Search your result in the list below                          "<<endl;
    cout<<"____________________________________________________________________________________________"<<endl;
    cout<<"                                                                                            "<<endl;
    ifstream Student_data;
    char ch5;
    system("color 0B");
    Student_data.open("Student Result.txt");
    ch5=Student_data.get();
    while(!Student_data.eof())
    {
        cout<<ch5;
        ch5=Student_data.get();
    }
    Student_data.close();
    system ("PAUSE");
    system ("CLS");
    login();
}
void programend()
{
    cout<<"  ___________________________________________________________________________________________________ "<<endl;
    cout<<" |                                   Thank you for using my software !                               |"<<endl;
    cout<<" |___________________________________________________________________________________________________|"<<endl;
    system ("PAUSE");
}