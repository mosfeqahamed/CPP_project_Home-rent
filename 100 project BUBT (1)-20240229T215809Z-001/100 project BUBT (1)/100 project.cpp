#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
using namespace std;
class flat
{
public:
    void menu();
    void admin();
    void customer();
    void change_pass();
    void help_line();
    void add_flat();
    void display_flat();
    void check_flat();
    void edit_flat();
    void delete_flat();
    void add_sflat();
    void add_rflat();
    void d_sflat();
    void d_rflat();
    void check_rflat();
    void check_sflat();
    void edit_sflat();
    void edit_rflat();
    void delete_sflat();
    void delete_rflat();
    void pass();
    void password();
    void ccr();
    void ccs();
    void brent();
    void bbuy();
    void bookings();
    void booking_sale();
    void booking_rent();
};
void flat::menu()
{
p:
    system("cls");
    system("color 8F");
    int choice;
    cout<<"\n\t\t\t**********************************";
    cout<<"\n\n\t\t\t\tControl Panel";
    cout<<"\n\t\t\t**********************************";
    cout<<"\n\n\n\n\t1.Admin";
    cout<<"\n\t2.Customer";
    cout<<"\n\t3.Exit";
    cout<<"\n\nEnter Your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        pass();

    case 2:
        customer();
    case 3:
        exit(0);
    default:
        cout<<"\n\n Invalid value ....please try again";
    }
    getch();
    goto p;

}
void flat::pass()
{
    system("cls");
    int i=0;
    char ch,st[21],ch1[21]= {"pass"};
    cout<<"\n\n\n\n\n\t\t\t\t\t\tEnter Password : ";
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            cout<<"*";
            st[i]=ch;
            i++;
        }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0; st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0'; i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {

        admin();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();

        menu();
    }
}
void flat::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]= {"pass"};
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            cout<<"*";
            st[i]=ch;
            i++;
        }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0; st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0'; i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        fflush(stdin);
        i=0;
        while(1)
        {
            j++;
            ch=getch();
            if(ch==13)
            {
                for(i=0; st[i]!=' '&&st[i]!='\0'; i++);
                if(j>20 || st[i]==' ')
                {
                    cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                    getch();
                    system("cls");
                    password();
                    admin();
                }
                st[i]='\0';
                break;
            }
            else if(ch==8&&i>0)
            {
                i--;
                cout<<"\b \b";
            }
            else
            {
                cout<<"*";
                st[i]=ch;
                i++;
            }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        admin();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n";
        cout<<"\n\t\tEnter 1 for retry or 2 for menu";
        cin>>i;
        if(i==1)
        {
            system("cls");
            password();
        }
        else
        {
            admin();
        }
    }
}
void flat::add_sflat()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_city,code,adr,details;
    cout<<"\n\nFlat Code : ";
    cin>>code;
    cout<<"\n\nCity : ";
    cin>>f_city;
    cout<<"\n\nAddress : ";
    cin>>adr;
    cout<<"\n\nArea of Flat(sq.feet) : ";
    cin>>f_area;
    cout<<"\n\nCost(taka) : ";
    cin>>range;
    cout<<"\n\nDetails about Flat :";
    cin>>details;
    file.open("flat1.txt",ios::out|ios::app);
    file<<" "<<code<<" "<<f_city<<" "<<adr<<" "<<f_area<<" "<<range<<" "<<details<<"\n";
    file.close();
}
void flat::add_rflat()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_city,code,adr,details;
    cout<<"\n\nFlat Code : ";
    cin>>code;
    cout<<"\n\nCity : ";
    cin>>f_city;
    cout<<"\n\nAddress : ";
    cin>>adr;
    cout<<"\n\nArea of Flat(sq.feet) : ";
    cin>>f_area;
    cout<<"\n\nRent(taka) : ";
    cin>>range;
    cout<<"\n\nDetails about Flat :";
    cin>>details;
    file.open("flat2.txt",ios::out|ios::app);
    file<<" "<<code<<" "<<f_city<<" "<<adr<<" "<<f_area<<" "<<range<<" "<<details<<"\n";
    file.close();
}
void flat::add_flat()
{
    int choice;
    system("cls");
    cout<<"\n\n\t\t\t\tADD Flat Panel";
    cout<<"\n\n1.Add Flat for Sale";
    cout<<"\n2.Add Flat for Rent";
    cout<<"\n\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        add_sflat();
        break;
    case 2:
        add_rflat();
        break;
    default:
        cout<<"\n\n Invalid choice....";
    }

}
void flat::d_sflat()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_city,code,adr,details;
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\n\nFlat code    city   Address    Area of flat(sq.feet)    range(taka)      details\n";
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            cout<<"  "<<code<<"      "<<f_city<<"      "<<adr<<"       "<<f_area<<"          "<<range<<"    "<<details<<"\n";
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
    }
}
void flat::d_rflat()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_city,code,adr,details;
    file.open("flat2.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\n\nFlat code    city   Address    Area of flat(sq.feet)    range(taka)      details\n";
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            cout<<"  "<<code<<"      "<<f_city<<"      "<<adr<<"       "<<f_area<<"          "<<range<<"    "<<details<<"\n";
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
    }
}

void flat::display_flat()
{
    int choice;
    system("cls");
    cout<<"\n\n\t\t\t\tDisplay Panel";
    cout<<"\n\n1.Display Flat for sale";
    cout<<"\n2.Display flat for rent";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        d_sflat();
        break;
    case 2:
        d_rflat();
        break;
    default:
        cout<<"\n\n Invalid choice....";
    }

}
void flat:: check_rflat()
{
    system("cls");
    fstream file;
    int f_area,range,c=0;
    string f_country,f_city,code,codee,adr,details;
    cout<<"\n\n\t\t\t\tCheck Specific Flat for Rent";
    file.open("flat2.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\nFlat cade : ";
        cin>>codee;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(codee==code)
            {
                system("cls");
                cout<<"\n\n\t\t\t\tCheck Specific Flat for Rent";
                cout<<"\n Flat code : "<<code;
                cout<<"\n City : "<<f_city;
                cout<<"\n Address : "<<adr;
                cout<<"\n Area(In sq.feet) :"<<f_area;
                cout<<"\n Range : "<<range;
                cout<<"\n Details : "<<details;
                c++;
                break;

            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
        if(c==0)
        {
            cout<<"\n\nFlat code not found.....";
        }
    }

}
void flat:: check_sflat()
{
    system("cls");
    fstream file;
    int f_area,range,c=0;
    string f_city,code,codee,adr,details;
    cout<<"\n\n\t\t\t\tCheck Specific Flat for Sell";
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\nFlat cade : ";
        cin>>codee;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(codee==code)
            {
                system("cls");
                cout<<"\n\n\t\t\t\tCheck Specific Flat for Rent";
                cout<<"\n Flat code : "<<code;
                cout<<"\n City : "<<f_city;
                cout<<"\n Address : "<<adr;
                cout<<"\n Area(In sq.feet) :"<<f_area;
                cout<<"\n Range : "<<range;
                cout<<"\n Details : "<<details;
                c++;
                break;

            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
        if(c==0)
        {
            cout<<"\n\nFlat code not found.....";
        }
    }
}
void flat::check_flat()
{
    int choice;
    system("cls");
    cout<<"\n\n\t\t\t\tchecking Panel";
    cout<<"\n\n1.Check Specific Flat for Sale";
    cout<<"\n2.Check Specific Flat for Rent";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        check_sflat();
        break;
    case 2:
        check_rflat();
        break;
    default:
        cout<<"\n\n Invalid choice....";
    }
}
void flat::edit_sflat()
{
    system("cls");
    fstream file,file1;
    int f_area,range,c=0,f_area1,range1,count=0;
    string f_city,code,f_city1,code1,details,adr,details1,adr1;
    cout<<"\n\n\t\t\t\tEdit Flat Record";
    file1.open("flatt.txt",ios::out|ios::app);
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error...";
    }
    else
    {
        cout<<"\n\nFlat code : ";
        cin>>code1;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(code1==code)
            {
                system("cls");
                cout<<"\n\n\t\t\t\tEdit Flat Record";
                cout<<"\n\nNew city name : ";
                cin>>f_city1;
                cout<<"\n\n Area : ";
                cin>>f_area1;
                cout<<"\n\nAddress : ";
                cin>>adr1;
                cout<<"\n\n cost : ";
                cin>>range1;
                cout<<"Details : ";
                cin>>details1;
                file1<<"  "<<code1<<"     "<<f_city1<<"      "<<adr1<<"      "<<f_area1<<"           "<<range1<<"     "<<details1<<"\n";
                count++;
            }
            else
            {
                file1<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"      "<<f_area<<"           "<<range<<"     "<<details<<"\n";
            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        if(count==0)
        {
            cout<<"\n\nFlat Code not found....";
        }
    }
    file.close();
    file1.close();
    remove("flat1.txt");
    rename("flatt.txt","flat1.txt");
}
void flat:: edit_rflat()
{
    system("cls");
    fstream file,file1;
    int f_area,range,c=0,f_area1,range1,count=0;
    string f_city,code,f_city1,code1,adr,adr1,details,details1;
    cout<<"\n\n\t\t\t\tEdit Flat Record";
    file1.open("flatt.txt",ios::out|ios::app);
    file.open("flat2.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error...";
    }
    else
    {
        cout<<"\n\nFlat code : ";
        cin>>code1;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(code1==code)
            {
                system("cls");
                cout<<"\n\n\t\t\t\tEdit Flat Record";
                cout<<"\n\nNew city name : ";
                cin>>f_city1;
                cout<<"\n\n Area : ";
                cin>>f_area1;
                cout<<"\n\nAddress : ";
                cin>>adr1;
                cout<<"\n\n cost : ";
                cin>>range1;
                cout<<"Details : ";
                cin>>details1;
                file1<<"  "<<code1<<"     "<<f_city1<<"      "<<adr1<<"      "<<f_area1<<"           "<<range1<<"     "<<details1<<"\n";
                count++;
            }
            else
            {
                file1<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"      "<<f_area<<"           "<<range<<"     "<<details<<"\n";
            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        if(count==0)
        {
            cout<<"\n\nFlat Code not found....";
        }
    }
    file.close();
    file1.close();
    remove("flat2.txt");
    rename("flatt.txt","flat2.txt");
}
void flat::edit_flat()
{
    int choice;
    system("cls");
    cout<<"\n\n\t\t\t\tEditing Panel";
    cout<<"\n\n1.Edit Flat for Sale";
    cout<<"\n2.Edit Flat for Rent";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        edit_sflat();
        break;
    case 2:
        edit_rflat();
        break;
    default:
        cout<<"\n\n Invalid choice....";
    }
}
void flat::delete_sflat()
{
    system("cls");
    fstream file,file1;
    int f_area,range,count=0;
    string f_city,code,code1,adr,details;
    cout<<"\n\n\t\t\t\tDelete Flat Record";
    file1.open("flatt.txt",ios::out|ios::app);
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error...";
    }
    else
    {
        cout<<"\n\nFlat code : ";
        cin>>code1;
        file>>code>>f_city>>adr>>f_area>>range>>details;// 1   4 6 7
        while(!file.eof())
        {
            if(code1==code)
            {
                system("cls");
                cout<<"\n\n\t\t\t\tDELETE FLAT RECORD";
                cout<<"\n\nOne Flat is Deleted Successfully....";
                count++;
            }
            else
            {
                file1<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"    "<<f_area<<"           "<<range<<"     "<<details<<"\n";
            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        if(count==0)
        {
            cout<<"\n\nFlat Code not found....";
        }
    }
    file.close();
    file1.close();
    remove("flat1.txt");
    rename("flatt.txt","flat1.txt");
}
void flat::delete_rflat()
{
    system("cls");
    fstream file,file1;
    int f_area,range,count=0;
    string f_city,code,code1,adr,details;
    cout<<"\n\n\t\t\t\tDelete Flat Record";
    file1.open("flatt.txt",ios::out|ios::app);
    file.open("flat2.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error...";
    }
    else
    {
        cout<<"\n\nFlat code : ";
        cin>>code1;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(code1==code)
            {
                system("cls");
                cout<<"\n\n\t\t\t\tDELETE FLAT RECORD";
                cout<<"\n\nOne Flat is Deleted Successfully....";
                count++;
            }
            else
            {
                file1<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"    "<<f_area<<"           "<<range<<"     "<<details<<"\n";
            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        if(count==0)
        {
            cout<<"\n\nFlat Code not found....";
        }
    }
    file.close();
    file1.close();
    remove("flat2.txt");
    rename("flatt.txt","flat2.txt");
}
void flat::delete_flat()
{
    int choice;
    system("cls");
    cout<<"\n\n\t\t\t\tDeleting Panel";
    cout<<"\n\n1.Delete Flat for Sale";
    cout<<"\n2.Delete Flat for Rent";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        delete_sflat();
        break;
    case 2:
        delete_rflat();
        break;
    default:
        cout<<"\n\n Invalid choice....";
    }
}
void flat::booking_sale()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_city,code,adr,details;
    file.open("bbuy.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\n\nFlat code    city   Address    Area of flat(sq.feet)    range(taka)      details\n";
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            cout<<"  "<<code<<"      "<<f_city<<"      "<<adr<<"       "<<f_area<<"          "<<range<<"    "<<details<<"\n";
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
    }
}
void flat::booking_rent()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_city,code,adr,details;
    file.open("brent.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\n\nFlat code    city   Address    Area of flat(sq.feet)    range(taka)      details\n";
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            cout<<"  "<<code<<"      "<<f_city<<"      "<<adr<<"       "<<f_area<<"          "<<range<<"    "<<details<<"\n";
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
    }
}
void flat::bookings()
{
    system("cls");
    int choice;
    cout<<"\n\n\n1.Record for Sale Flat ";
    cout<<"\n2.Record for rent Flat ";
    cout<<"\n3.Goto Menu";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        booking_sale();
        break;
    case 2:
        booking_rent();
        break;
    case 3:
        menu();
    default:
        cout<<"\n\n Invalid choice....";
    }

}
void flat::admin()
{
p:
    int choice;
    system("cls");
    system("color 4B");
    cout<<"\n\t\t\t===========================";
    cout<<"\n\n\t\t\t\tAdmin Panel";
    cout<<"\n\t\t\t===========================";
    cout<<"\n\n\n\n1.Add Flat";
    cout<<"\n2.Display Flat";
    cout<<"\n3.Check Specific Flat";
    cout<<"\n4.Edit Flat";
    cout<<"\n5.Delete Flat";
    cout<<"\n6.Bokings";
    cout<<"\n7.Change Password";
    cout<<"\n8.Go Back";
    cout<<"\nEnter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        add_flat();
        break;
    case 2:
        display_flat();
        break;
    case 3:
        check_flat();
        break;
    case 4:
        edit_flat();
        break;
    case 5:
        delete_flat();
        break;
    case 6:
        bookings();
        break;
    case 7:
        password();
    case 8:
        menu();
    default:
        cout<<"\n\n Invalid choice....";
    }
    getch();
    goto p;
}
void flat::ccr()
{
    system("cls");
    fstream file;
    int f_area,range,c=0,a=0,b=0,k=0,d=0,e=0;
    string f_city,code,codee,adr,details,f_city1;
    cout<<"\n\n\t\t\t\t Flat for Rent";
    file.open("flat2.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\nCity : ";
        cin>>f_city1;
        cout<<"\n\n";
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if((f_city1.compare(f_city))==0)
            {
                cout<<"\n Flat code : "<<code;
                cout<<"\n City : "<<f_city;
                cout<<"\n Address : "<<adr;
                cout<<"\n Area(In sq.feet) :"<<f_area;
                cout<<"\n Range : "<<range;
                cout<<"\n Details : "<<details;
                cout<<"\n--------------------------------------------------------\n";
                c++;

            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
        if(c==0)
        {
            cout<<"\n\nFlat code not found.....";
        }
    }
}
void flat::ccs()
{
    system("cls");
    fstream file;
    int f_area,range,c=0,a=0,b=0,k=0,d=0,e=0;
    string f_city,code,codee,adr,details,f_city1;
    cout<<"\n\n\t\t\t\t Flat for Buy";
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\nCity : ";
        cin>>f_city1;
        cout<<"\n\n";
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if((f_city1.compare(f_city))==0)
            {
                cout<<"\n Flat code : "<<code;
                cout<<"\n City : "<<f_city;
                cout<<"\n Address : "<<adr;
                cout<<"\n Area(In sq.feet) :"<<f_area;
                cout<<"\n Range : "<<range;
                cout<<"\n Details : "<<details;
                cout<<"\n--------------------------------------------------------\n";
                c++;

            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        file.close();
        if(c==0)
        {
            cout<<"\n\nFlat code not found.....";
        }
    }
}
void flat::brent()
{
    system("cls");
    fstream file,file1,file3;
    int f_area,range,count=0;
    string f_city,code,code1,adr,details;
    file3.open("brent.txt",ios::out|ios::app);
    file1.open("flatt.txt",ios::out|ios::app);
    file.open("flat2.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error...";
    }
    else
    {
        cout<<"\n\nFlat code : ";
        cin>>code1;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(code1==code)
            {
                file3<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"    "<<f_area<<"           "<<range<<"     "<<details<<"\n";
                count++;
                cout<<"Flat is successfully booked...."<<endl;
            }
            else
            {
                file1<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"    "<<f_area<<"           "<<range<<"     "<<details<<"\n";
            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        if(count==0)
        {
            cout<<"\n\nFlat Code not found....";
        }
    }
    file.close();
    file1.close();
    remove("flat2.txt");
    rename("flatt.txt","flat2.txt");
}
void flat::bbuy()
{
    system("cls");
    fstream file,file1,file3;
    int f_area,range,count=0;
    string f_city,code,code1,adr,details;
    file3.open("bbuy.txt",ios::out|ios::app);
    file1.open("flatt.txt",ios::out|ios::app);
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error...";
    }
    else
    {
        cout<<"\n\nFlat code : ";
        cin>>code1;
        file>>code>>f_city>>adr>>f_area>>range>>details;
        while(!file.eof())
        {
            if(code1==code)
            {
                file3<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"    "<<f_area<<"           "<<range<<"     "<<details<<"\n";
                count++;
                cout<<"Flat is successfully booked...."<<endl;
            }
            else
            {
                file1<<"  "<<code<<"     "<<f_city<<"      "<<adr<<"    "<<f_area<<"           "<<range<<"     "<<details<<"\n";
            }
            file>>code>>f_city>>adr>>f_area>>range>>details;
        }
        if(count==0)
        {
            cout<<"\n\nFlat Code not found....";
        }
    }
    file.close();
    file1.close();
    remove("flat1.txt");
    rename("flatt.txt","flat1.txt");
}
void flat::customer()
{
p:
    int choice;
    system("cls");
    system("color E4");
    cout<<"\n\n\t\t\t\tCustomer Panel";
    cout<<"\n\n\n1.Check Flat for Rent";
    cout<<"\n2.Check flat for Buy";
    cout<<"\n3.book flat for rent";
    cout<<"\n4.book flat for buy";
    cout<<"\n5.Help Line";
    cout<<"\n6.Go Back";
    cout<<"\nEnter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        ccr();
        break;
    case 2:
        ccs();
        break;
    case 3:
        brent();
        break;
    case 4:
        bbuy();
        break;
    case 5:
        help_line();
        break;
    case 6:
        menu();
    default:
        cout<<"\n\n Invalid choice....";
    }
    getch();
    goto p;
}

void flat::help_line()
{
    system("cls");
    system("color 0F");
    cout<<"\n\n\t\t\t\tWelcome to our Help Service. ";
    cout<<"\n\nIf you have any specific QUERY please feel free to contact us.\n\nWe are always available for you!";
    cout<<"\n\nHotline Number : +8801770011111  \n\nThank you.\n";
}
void intro()
{
    system("cls");
    system("color A0");
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t==============================";
    cout<<"\n\t\t\t==============================";
    cout<<"\n\n\t\t\t\t";
    cout<<"\n\n\n\t\t\t Bismillahir Rahmanir Rahim";
    cout<<"\n\n\t\t\t ";
    cout<<"\n\n\t\t\t==============================";
    cout<<"\n\t\t\t==============================";
    getch();
    system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t==============================";
    cout<<"\n\t\t\t==============================";
    cout<<"\n\n\t\t\t  FLAT RENT AND BUY SERVICE";
    cout<<"\n\n\n\t\t\t\t";
    cout<<"\n\n\t\t\t==============================";
    cout<<"\n\t\t\t==============================";
    getch();

}
int main()
{
    flat f;
    intro();
    f.menu();
    return 0;
}
