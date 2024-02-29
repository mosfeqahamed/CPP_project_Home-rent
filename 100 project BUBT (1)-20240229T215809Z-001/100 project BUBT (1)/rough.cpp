

    fstream file;
    int f_area,range;
    string f_country,f_city,code;
    cout<<"\n\nFlat Code : ";
    cin>>code;
    cout<<"\n\nCountry : ";
    cin>>f_country;
    cout<<"\n\nCity : ";
    cin>>f_city;
    cout<<"\n\nArea of Flat(sq.feet) : ";
    cin>>area;
    cout<<"\n\nRange(taka) : ";
    cin>>range;
    file.open("flat1.txt",ios::out|ios::app);
    file<<" "<<code<<" "<<f_country<<" "<<f_city<<" "<<area<<" "<<range<<"\n";
    file.close();

    void bookshop::show_book()
{
    system("cls");
    fstream file;
    int f_area,range;
    string f_country,f_city,code;
    file.open("flat1.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile opening error....";
    }
    else
    {
        cout<<"\n\nFlat code    Country    city    Area of flat(sq.feet)    range(taka)\n";
        file>>code>>f_country>>f_city>>f_area>>range;
        while(!file.eof())
        {
            cout<<"  "<<code<<"     "<<f_country<<"      "<<f_city<<"           "<<f_area<<"      "<<range<<"\n";
           file>>code>>f_country>>f_city>>f_area>>range;
        }
        file.close();
    }
}
