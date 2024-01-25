#include<iostream>
#include<unistd.h>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
int bcount=0,pcount=0,ibcount=0;
class Book{
	public:
	char isbn[50],title[50],author[50],publisher[50];
	int copies,date;
		Book():isbn(""),title(""),author(""),publisher(""),copies(0),date(0){}
		char * getisbn(){return isbn;}												//for searchng through isbn

		char * gettitle(){return title;}											//for searching through title	

		char * getauthor(){return author;}											//for searching through author	

		char * getpublisher(){return publisher;}									//for searching through publisher

		int getdate(){return date;}													//for searching through year
		
		int getcopies(){return copies;}
		
		void getbook();																//getting book info from user     307                  
		void listview();															//showing total books             345                  
		void showbook();															//showing single book             322                  
		void header();																//header layout                   331                  
		void deletebook();															//deleting book                   181                  
		void bookcount();															//counting total books			  1233				
		~Book(){}
}b;

class Issuedbook{
	public:
	char type,Name[50],Cnic[14];
	int idate,imonth,rdate,rmonth,temp1,temp2,temp3,fine,iyear,ryear;
Issuedbook():Name(""),Cnic(""),idate(0),imonth(0),rdate(0),rmonth(0),fine(0){}
		void issuebooks();															//to issue book			          962		   				
		void ibheader();															//issue book header               338                  
		void iblistview();															//showing total issued books      349                    
		void showissue();															//showing single issued book	  1028					
		void issuedbookcount();														//counting issued books			  1238 					
		void deleteib();															//deleting issued book            271                 
		char * getname(){return Name;}
		char * setcnic(){return Cnic;}	
		~Issuedbook(){}
}ib;

class Person{
	public:
		string dob,session;
		char name[50],cnic[14],dept[50];
		int age; 
		Person():dob(""), name(""), cnic(""), age(0){}            
		void get(){
			cout<<"Enter your name, start with with a blank space : ";
			cin.ignore();
			cin.getline(name,50);
			cout<<"Enter new Id again, for student and teacher, end with s and t respectively : ";
			cin.getline(cnic,14);
			cout<<"Enter department : ";
			cin.getline(dept,50);
			cout<<"Enter session for student or job type for teacher : ";
			//cin.ignore();
			getline(cin,session);
			cout<<"Enter age : ";
			cin>>age;
			while(age<=0){
			cout<<"Enter age again : ";
			cin>>age;}
			cout<<"Enter date of birth : ";
			cin.ignore();
			getline(cin,dob);}
		
		void slistview();															//shows total users	            691
		void personcount();															//counts total users			1119
	char * Getname(){return name;}
	char * getcnic(){return cnic;}
		~Person(){}		
}p;

class Student:public Person{
	public:
		void getstudent();															//get student info from user	634                                  
		void showstudent();															////Read from file				709								  	
		void studentshow();															//shows total student           695                                  
		void deletestudent();														//deletes student	            865                                  
}s;

class Teacher:public Person{
	public:
		void getteacher();															//get teacher info from user    660                                
		void showteacher();															//shows single teacher			720							
		void deleteteacher();														//deletes teacher				891										
		void teachershow();															//show total teacher            702                                 
}t;

struct date{																		//fine ki dates ki calculation k lia
	int idate,imonth,rdate,rmonth,temp1=0,temp2,temp3,fine,iyear,ryear; 
	char c;
	bool b4,b5;
	void input(){
		start:
		cout<<"\nDo you want to enter details of issuing book or returning book (i/r) ??? ";
		cout<<"\nFirst enter issuing details then returning details !!! ";
		cin>>c;
		if(c=='i'){
		cout<<"Enter issue year ";
		cin>>iyear;
		ib.iyear=iyear;
		if((iyear%4)==0){b4=true;}
		cout<<"Enter issue month ";
		cin>>imonth;		
		while(imonth<=0 or imonth>12){
			cout<<"Enter issue month again ";
			cin>>imonth;}
		ib.imonth=imonth;						
		cout<<"Enter issue date ";
		cin>>idate;
		if(imonth==4 or imonth==6 or imonth==9 or imonth==11){
		while(idate<=0 or idate>30){
			cout<<"Enter issue date again ";
			cin>>idate;}}
		else if(imonth==2 and b4==true){
		while(idate<=0 or idate>29){
			cout<<"Enter issue date again ";
			cin>>idate;}}
		else if(imonth==2 and b4==false){
			while(idate<=0 or idate>28){
				cout<<"Enter issue date again : ";
				cin>>idate;}}
		else{
			while(idate<=0 or idate>31){
				cout<<"Enter issue date again : ";
				cin>>idate;}}
		ib.idate=idate;}
		else if(c=='r'){
		cout<<"Enter expected return year : ";
		cin>>iyear;
		ib.ryear=iyear;
		if((ryear%4)==0){b5=true;}
		cout<<"Enter expected return month ";
		cin>>imonth;
		while(imonth<=0 or imonth>12){
			cout<<"Enter return month again ";
			cin>>imonth;}
		ib.rmonth=imonth;	
				cout<<"Enter expected return date ";
		cin>>idate;
		if(imonth==4 or imonth==6 or imonth==9 or imonth==11){
		while(idate<=0 or idate>30){
			cout<<"Enter return date again ";
			cin>>idate;}}
		else if(imonth==2 and b4==true){
		while(idate<=0 or idate>29){
			cout<<"Enter return date again ";
			cin>>idate;}}
		else if(imonth==2 and b4==false){
			while(idate<=0 or idate>28){
				cout<<"Enter return date again : ";
				cin>>idate;}}
		else{
			while(idate<=0 or idate>31){
				cout<<"Enter return date again : ";
				cin>>idate;}}
	ib.rdate=idate;}
	else
	goto start;}
}d1,d2;

void temp(){
	cout<<"\n\nEnter searching method ";
	cout<<"\n\n1-> By Isbn\n2-> By Name\n3-> By Author\n4-> By Publisher\n";
	cout<<"5-> By Publishing date\n";
	cout<<"Enter method\n";}

void incopies(){++b.copies;}												//increments copies upon book return

void Book::deletebook(){
fstream rd,wr;
    rd.open("Book.txt",ios::in);
    wr.open("temp.txt",ios::app);
    temp();
    int y;
    char n[50],x,i[50],a[50],p[50];
    cin>>x;
    if(x=='1'){
    	cout<<"Enter ISBN of book : ";
    	cin>>i;	
    	while(rd.read((char*)this,sizeof(*this))){
    		if(strcmp(i,b.getisbn())==0){
    			cout<<endl;
				b.showbook();
    			char z;
        cout<<"\nBook found, do you want to delete this book ? ";
        cin>>z;    			
				if(z=='Y' or z=='y')
            cout<<"Book Removed"<<endl;
			else{
			cout<<"Book is not deleted\n";	
            wr.write((char *)this,sizeof(*this));}}
			else{
			wr.write((char *)this,sizeof(*this));}}}
    else if(x=='2'){
    cout<<"Enter name of the Book :";
    cin>>n;
	while(rd.read((char*)this,sizeof(*this))){
        if(strcmp(n,b.gettitle())==0)
        {char z;
        b.showbook();
        cout<<"\nBook found, do you want to delete this book ? ";
        cin>>z;        
        if(z=='Y' or z=='y')
            cout<<"Book Removed"<<endl;
			else{
			cout<<"Book is not deleted\n";	
            wr.write((char *)this,sizeof(*this));}}
			else{
			wr.write((char *)this,sizeof(*this));}}}
    else if(x=='3'){
    	cout<<"Enter Author name : ";
    	cin>>a;
    		while(rd.read((char*)this,sizeof(*this))){
        if(strcmp(a,b.getauthor())==0)
        {char z;
        b.showbook();
        cout<<"\nBook found, do you want to delete this book ? ";
        cin>>z;
        if(z=='Y' or z=='y')
            cout<<"Book Removed"<<endl;
			else{
			cout<<"Book is not deleted\n ";	
            wr.write((char *)this,sizeof(*this));}}
			else{wr.write((char*)this,sizeof(*this));}}}        
    else if(x=='4'){
    	cout<<"Enter Publisher name : ";
    	cin>>p;
    		while(rd.read((char*)this,sizeof(*this))){
        if(strcmp(p,b.getpublisher())==0)
        {char z;
        b.showbook();
        cout<<"\nBook found, do you want to delete this book ? ";
        cin>>z;
        	if(z=='Y' or z=='y')
            cout<<"Book Removed"<<endl;
			else{wr.write((char*)this,sizeof(*this));
			cout<<"Book is not deleted";}}
			else{wr.write((char*)this,sizeof(*this));}}}
	else if(x=='5'){
		cout<<"Enter publishing year of the Book :";
    cin>>y;
	while(rd.read((char*)this,sizeof(*this))){
        if(y==b.getdate())
        {char z;
        b.showbook();
        cout<<"\nBook found, do you want to delete this book ? ";
        cin>>z;
        if(z=='Y' or z=='y')
            cout<<"Book Removed"<<endl;
			else{wr.write((char *)this,sizeof(*this));
			cout<<"Book is not deleted";}}
			else{wr.write((char*)this,sizeof(*this));}}}		        
    rd.close();
    wr.close();
    remove("book.txt");
    rename("./temp.txt","book.txt");
	b.bookcount();}	

void Issuedbook::deleteib(){
	fstream rd,wr;
	fstream f("Book.txt", ios::in | ios::out);
    rd.open("Issued book.txt",ios::in);
    wr.open("temp.txt",ios::app);
    char n[50],z;
    bool b1=0;
    cout<<"Enter name of the Book :";
    cin>>n;
	while(rd.read((char*)this,sizeof(*this)))
    {
        if(strcmp(n,ib.getname())==0){
        	ib.ibheader();
        	ib.iblistview();        	
        	cout<<"\nBook found, do you want to delete it : ";
        	cin>>z;
        	if(z=='Y' or z=='y'){
            cout<<"\nBook Removed"<<endl;   b1=true;}
            else{wr.write((char*)this,sizeof(*this));
			cout<<"\nBook is not deleted \n";}}
			else{wr.write((char*)this,sizeof(*this));}}
    	while(f.read((char*)&b,sizeof(b))){
		if(b1==1){
			if(strcmp(n,b.gettitle())==0){
    		int pos=f.tellg();
            f.seekg(pos-sizeof(b));
            incopies();
			f.write((char*)&b,sizeof(b));
			break;}}}
	f.close();
    rd.close();
    wr.close();
    remove("Issued book.txt");
    rename("./temp.txt","Issued book.txt");
	ib.issuedbookcount();}

void Book::getbook(){
	cout<<"Enter book name : ";
	cin.getline(title,50);
	cout<<"Enter new isbn again : ";
	cin.getline(isbn,50);
	cout<<"Enter author name : ";
	cin.getline(author,50);
	cout<<"Enter publisher name : ";
	cin.getline(publisher,50);
	cout<<"Enter copies : ";
	cin>>copies;
	cout<<"Enter year of publishing : ";
	cin>>date;
	cout<<endl;}

void Book::showbook(){
	cout<<endl;
	cout<<"Book name is               : "<<title<<endl;
	cout<<"Isbn is                    : "<<isbn<<endl;
	cout<<"Author is                  : "<<author<<endl;
	cout<<"Publisher is               : "<<publisher<<endl;
	cout<<"Copies                     : "<<copies<<endl;
	cout<<"Year of publishing         : "<<date<<endl;}

void Book::header(){
	cout<<left<<setw(10)<<"Isbn "<<setw(25)<<"Book name "<<setw(17)<<"Author "<<setw(15)<<"Publisher ";
	cout<<setw(15)<<"Copies "<<setw(15)<<"Year "<<endl;
	for(int i=1; i<=87; i++)
		cout<<"=";
		cout<<endl;}

void Issuedbook::ibheader(){
cout<<left<<setw(20)<<"Book name"<<setw(14)<<"Id"<<setw(10)<<"Idate"<<setw(10)<<"Imonth"<<setw(10)<<"Iyear"<<setw(10)<<"Rdate"<<setw(10);
	cout<<"Rmonth"<<setw(10)<<"Ryear"<<setw(10)<<"Fine"<<endl;
	for(int i=1; i<=99; i++)
	cout<<"=";
	cout<<endl;}

void Book::listview(){
	cout<<left<<setw(10)<<isbn <<left<<setw(25)<<title <<left<<setw(20)<<author <<left<<setw(15)<<publisher ;
	cout<<left<<setw(12)<<copies<<left<<setw(6)<<date<<endl;}

void Issuedbook::iblistview(){
	cout<<left<<setw(20)<<Name <<left<<setw(15)<<Cnic <<left<<setw(10)<<idate <<left<<setw(9)<<imonth <<left<<setw(12)<<iyear; 
	cout<<left<<setw(10)<<rdate <<left<<setw(8)<<rmonth <<left<<setw(10)<<ryear <<setw(10)<<left<<fine <<endl;}

void drawline(char ch){							                    		//Line above and below Library Managemnet System		
	for(int i=1; i<=73; i++){
		if(i<=48)
	cout<<" ";
	else
	cout<<ch;}
	cout<<endl;}

void heading(){									                   			//Prints Library Management
	drawline('*');
	cout<<"\t\t\t\t\t\tLibrary Management System\n";
	drawline('*');
	cout<<endl;}

void addbook(){																			//writes book on file													
	char i[50];
	bool b1=true;
	cout<<"Enter new book isbn you want to add : ";
	cin.ignore();
	cin.getline(i,50);	
	ifstream fin("Book.txt");
	ofstream fout;
	fout.open("Book.txt",ios::app);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(i,b.getisbn())==0){
		cout<<"Book already exists ";    
		b1=false;
		break;}}
		if(b1==true){
	b.getbook();
	fout.write((char*)&b,sizeof(b));
	cout<<"Book added ";} 
	fout.close();
	b.bookcount();}

void displaybooks(){                                                                          //Displays total books
	ifstream fin("Book.txt");
	int rec=0;
	while(fin.read((char*)&b,sizeof(b))){
		if(rec<1)
		b.header();
		b.listview();
		rec++;}
	fin.close();
	cout<<"\nTotal "<<rec<<" records in the file so far \n";}

void searchbytitle(){																//Searches book through title		
	int flag=0;
	char Title[50];
	ifstream fin("Book.txt");
	cout<<"Enter book name : ";
	cin.ignore();
	cin.getline(Title,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(Title,b.gettitle())==0){
			b.showbook();
			flag++;}}
	fin.close();
	if(flag==0){
	cout<<"Book with title "<<Title<<" is not found \n";}}

void searchbyisbn(){																	//searches book through isbn								
	int flag=0,rec=0;
	char ISBN[50];
	ifstream fin("Book.txt");
	cout<<"Enter isbn : ";
	cin.ignore();
	cin.getline(ISBN,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(ISBN,b.getisbn())==0){
			if(rec<1)
			b.header();
			b.listview();
			flag++;
			rec++;}}
	fin.close();
	if(flag==0){
	cout<<"Book with isbn "<<ISBN<<" is not found \n";}}

void searchbypublisher(){																	//searches book through publisher
int flag=0,rec=0;
	char pub[50];
	ifstream fin("Book.txt");
	cout<<"Enter publisher : ";
	cin.ignore();
	cin.getline(pub,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(pub,b.getpublisher())==0){
			if(rec<1)
			b.header();
			b.listview();
			flag++;
			rec++;}}
	fin.close();
	if(flag==0)
	cout<<"Book with publisher "<<pub<<" is not found \n";}

void searchbydate(){																			//searches book through date
	int flag=0,rec=0,dat;
	ifstream fin("Book.txt");
	cout<<"Enter year : ";
	cin>>dat;
	while(fin.read((char*)&b,sizeof(b))){
		if(dat==b.getdate()){
			if(rec<1)
			b.header();
			b.listview();
			flag++;
			rec++;}}
	fin.close();
	if(flag==0)
	cout<<"Book with date "<<dat<<" is not found \n";}

void searchbyauthor(){																			//searches book through author
	int flag=0,rec=0;
	char aut[50];
	ifstream fin("Book.txt");
	cout<<"Enter author name : ";
	cin.ignore();
	cin.getline(aut,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(aut,b.getauthor())==0){
			if(rec<1)
			b.header();
			b.listview();
			flag++;
			rec++;}}
	fin.close();
	if(flag==0)
	cout<<"Book with author name "<<aut<<" is not found\n";}

void modify(){																						//edits existing books details
	int flag=0,pos;
	char i[50],i1[50],a[50],p[50],n[50],x;
	int y;
	bool b1=0;
	fstream fin("Book.txt", ios::in | ios::out);
	fstream fin1("Book.txt", ios::in | ios::out);
	temp();
	cin>>x;
	if(x=='1'){
		system("cls");		
	cout<<"Enter new isbn you want to add : ";
	cin.ignore();
	cin.getline(i,50);
	cout<<"Enter old isbn to search : ";
	cin.getline(i1,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(i,b.getisbn())==0){
			cout<<"ISBN already exists \n";
			b1=1;
			break;}}
			while(fin1.read((char*)&b,sizeof(b))){
			if(b1==0){
				if(strcmp(i1,b.getisbn())==0){
				pos=fin1.tellg();
			cout<<"This data will be modified \n";
			b.showbook();
			flag++;
			fin1.seekg(pos-sizeof(b));
			cout<<endl;
			b.getbook();
			fin1.write((char*)&b,sizeof(b));
			cout<<"Edited successfully";	
			break;}}}
			fin.close();
			fin1.close();
			if(flag==0 && b1==false)
			cout<<"Book not found so it cannot be edited \n";} 
	
	else if(x=='2'){
		system("cls");	
		cout<<"Enter book name : ";
		cin.ignore();
		cin.getline(n,50); 
	cout<<"\nEnter new isbn you want to add : ";
	cin.getline(i,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(i,b.getisbn())==0){
		cout<<"\nISBN already exists ";
		b1=1; 
		  break;}}
		  while(fin1.read((char*)&b,sizeof(b))){
		  if(b1==0){
		if(strcmp(n,b.gettitle())==0){
			pos=fin1.tellg();
				cout<<"\nThis data will be modified \n";
			b.showbook();
			flag++;
			fin1.seekg(pos-sizeof(b));
			cout<<endl;
			b.getbook();
			fin1.write((char*)&b,sizeof(b));
			cout<<"\nEdited successfully";
		break;}}}
		fin.close();
		fin1.close();
	if(flag==0 && b1==false)
	cout<<"\nBook not found so it cannot be edited \n";}	
	
	else if(x=='3'){
	system("cls");	
	cout<<"Enter author name : ";
	cin.ignore();
	cin.getline(a,50);
	cout<<"\nEnter new isbn you want to add : ";
	cin.getline(i,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(i,b.getisbn())==0){
		cout<<"\nISBN already exists ";
		b1=1; 
		  break;}}	
		  while(fin1.read((char*)&b,sizeof(b))){
		  if(b1==0){
		if(strcmp(a,b.getauthor())==0){
			pos=fin1.tellg();
				cout<<"\nThis data will be modified \n";
			b.showbook();
			flag++;
			fin1.seekg(pos-sizeof(b));
			cout<<endl;
			b.getbook();
			cout<<"\nEdited successfully";
		break;}}}
fin1.write((char*)&b,sizeof(b));		
		fin.close();
		fin1.close();
	if(flag==0 && b1==false)
	cout<<"\nBook not found so it cannot be edited \n";}
	
	else if(x=='4'){
	system("cls");	
	cout<<"Enter new isbn you want to add : ";
	cin.ignore();
	cin.getline(i,50);
	cout<<"\nEnter publisher name : ";
	cin.getline(p,50);
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(i,b.getisbn())==0){
		cout<<"\nISBN already exists ";
		b1=1; 
		  break;}}
		  while(fin1.read((char*)&b,sizeof(b))){
		  if(b1==0){
		if(strcmp(p,b.getpublisher())==0){
			pos=fin1.tellg();
				cout<<"\nThis data will be modified \n";
			b.showbook();
			flag++;
			fin1.seekg(pos-sizeof(b));
			cout<<endl;
			b.getbook();
			fin1.write((char*)&b,sizeof(b));
			cout<<"\nEdited successfully";
		break;}}}
	fin.close();
	if(flag==0 && b1==false)
	cout<<"\nBook not found so it cannot be edited \n";}
	
	else if(x=='5'){
	system("cls");	
	cout<<"Enter new isbn you want to add : ";
	cin.ignore();
	cin.getline(i,50);
	cout<<"\nEnter publishing date : ";
	cin>>y;
	while(fin.read((char*)&b,sizeof(b))){
		if(strcmp(i,b.getisbn())==0){
		cout<<"\nISBN already exists ";
		b1=1; 
		  break;}}
		  while(fin1.read((char*)&b,sizeof(b))){
		  if(b1==0){
		if(y==b.getdate()){
			pos=fin1.tellg();
				cout<<"\nThis data will be modified \n";
			b.showbook();
			flag++;
			fin1.seekg(pos-sizeof(b));
			cout<<endl;
			b.getbook();
			fin1.write((char*)&b,sizeof(b));
			cout<<"\nEdited successfully";
		break;}}}
	fin.close();
	if(flag==0 && b1==false)
	cout<<"\nBook not found so it cannot be edited \n";}}

void Student::getstudent(){	
Person::get();
sleep(2);}
				
void addstudent(){																					//writes student on file
	bool b1=true;
	char c[14];
	cout<<"\nEnter new id of student you want to add, end with s : ";
	cin.ignore();
	cin.getline(c,14);
	ifstream fin("Student.txt");
	ofstream fout;
	fout.open("Student.txt",ios::app);
	while(fin.read((char*)&s,sizeof(s))){
		if(strcmp(c,s.getcnic())==0){
			cout<<"Student already exists ";
			sleep(2);
			b1=false;
			break;}}
		if(b1==true){
	s.getstudent();
	fout.write((char*)&s,sizeof(s));
	cout<<"Student added ";}
	fout.close();
	p.personcount();}

void Teacher::getteacher(){
Person::get();
sleep(2);}  

void addteacher(){																					//writes teacher on file		
	bool b1=true;
	char c[14];
	cout<<"\nEnter new id of teacher you want to add, end with t : ";
	cin.ignore();
	cin.getline(c,14);
	ifstream fin("Teacher.txt");
	ofstream fout;
	fout.open("Teacher.txt",ios::app);
	while(fin.read((char*)&t,sizeof(t))){
		if(strcmp(c,t.getcnic())==0){
			cout<<"Teacher already exists ";
			sleep(2);
			b1=false;
			break;}}
		if(b1==true){
	t.getteacher();
	fout.write((char*)&t,sizeof(t));
	cout<<"Teacher added ";}
	fout.close();
	p.personcount();}

void sheader(){
cout<<endl;																							//header layout for showing user
cout<<left<<setw(25)<<"Name "<<setw(14)<<"Id "<<setw(25)<<"Department "<<setw(25)<<"Session / Job type "<<setw(10)<<"Age "<<setw(15)<<"Date of birth "<<endl;
	for(int i=1; i<=113; i++)
	cout<<"=";
	cout<<endl;}

void Person::slistview(){																						
cout<<left<<setw(25) <<name <<left<<setw(14)<<cnic <<left<<setw(25)<<dept <<left<<setw(25)<<session <<left<<setw(10) <<age <<left<<setw(15) <<dob <<endl;}

void Student::studentshow(){
	cout<<endl;
	cout<<"Name is                    : "<<name<<endl;
	cout<<"Id is                      : "<<cnic<<endl;
	cout<<"Department is              : "<<dept<<endl;
	cout<<"Session is                 : "<<session<<endl;
	cout<<"Age is                     : "<<age<<endl;
	cout<<"Date of birth is           : "<<dob<<endl;}

void Teacher::teachershow(){
	cout<<endl;
	cout<<"Name is                    : "<<name<<endl;
	cout<<"Id is                      : "<<cnic<<endl;
	cout<<"Department is              : "<<dept<<endl;
	cout<<"Job type                   : "<<session<<endl;
	cout<<"Age is                     : "<<age<<endl;
	cout<<"Date of birth is           : "<<dob<<endl;}

void Student::showstudent(){
ifstream fin("Student.txt");
int rec=0;
while(fin.read((char*)this,sizeof(*this))){
	if(rec<1)
	sheader();
	s.slistview();
	rec++;}
fin.close();
cout<<"\nTotal "<<rec<<" records found "<<endl;}

void Teacher::showteacher(){
ifstream fin("Teacher.txt");
int rec=0;
while(fin.read((char*)this,sizeof(*this))){
	if(rec<1)
	sheader();
	t.slistview();
	rec++;}
fin.close();
cout<<"\nTotal "<<rec<<" records found "<<endl;}

void studentsearchname(){																				//search student through name
	int flag=0;
	char Name[50];
	ifstream fin("Student.txt");
	cout<<"Enter name : ";
	cin.ignore();
	cin.getline(Name,50);
	while(fin.read((char*)&s,sizeof(s))){
		if(strcmp(Name,s.Getname())==0){
			s.studentshow();
			flag++;}}
	fin.close();
	if(flag==0)
	cout<<"Student with name "<<Name<<" is not found \n";} 

void teachersearchname(){																			//search teacher through name																			
	int flag=0;																					
	char Name[50];
	ifstream fin("Teacher.txt");
	cout<<"Enter name : ";
	cin.ignore();
	cin.getline(Name,50);
	while(fin.read((char*)&t,sizeof(t))){
		if(strcmp(Name,t.Getname())==0){
			t.teachershow();
			flag++;}}
	fin.close();
	if(flag==0)
	cout<<"Teacher with name "<<Name<<" is not found \n";}

void studentsearchcnic(){																	//search student through cnic		
	int flag=0;
	char Cnic[14];
	ifstream fin("Student.txt");
	cout<<"Enter Id : ";
	cin.ignore();
	cin.getline(Cnic,14);
	while(fin.read((char*)&s,sizeof(s))){
		if(strcmp(Cnic,s.getcnic())==0){
			s.studentshow();
			flag++;}}
	fin.close();
	if(flag==0){
	cout<<"Student not found \n";}}

void teachersearchcnic(){															//search teacher through cnic
	int flag=0;
	char Cnic[14];
	ifstream fin("teacher.txt");
	cout<<"Enter Id : ";
	cin.ignore();
	cin.getline(Cnic,14);
	while(fin.read((char*)&t,sizeof(t))){
		if(strcmp(Cnic,t.getcnic())==0){
			t.teachershow();
			flag++;}}
	fin.close();
	if(flag==0){
	cout<<"Teacher not found \n";}}

void studentsearchmenu(){										//menu for seaching student
	system("color 70");
	int ch=0;
	while(ch!=3){
		start:
		system("cls");
		cout<<"1-> By name\n2-> By Id\n3-> Back\n";
		cout<<"Enter search method : ";
		cin>>ch;
		system("cls");
		switch(ch){
			case 1: studentsearchname(); system("pause"); break;
			case 2: studentsearchcnic(); system("pause"); break;
			case 3: break;		 
			default: goto start;}}}
			
void teachersearchmenu(){																							//menu for searching teacher
	system("color 70");
	int ch=0;
	while(ch!=3){
		start:
		system("cls");
		cout<<"1-> By name\n2-> By Id\n3-> Back\n";
		cout<<"Enter search method : ";
		cin>>ch;
		system("cls");
		switch(ch){
			case 1: teachersearchname(); system("pause"); break;
			case 2: teachersearchcnic(); system("pause"); break;	
			case 3: break;	 
			default: goto start;}}}			
			
void Temp(){
	cout<<"\n1-> By name\n2-> By ID\nEnter search method : ";}			
			
void studentmodify(){																					//edits existing student info
	bool b1=0;
	int flag=0,pos;
	char c[14],i[14],n[50],x;
	fstream fin("Student.txt", ios::in | ios::out);
	fstream fin1("Student.txt", ios::in | ios::out);
	Temp();
	cin>>x;
	if(x=='1'){
	cout<<"Enter name to search : ";
	cin.ignore();
	cin.getline(n,50);
	cout<<"Enter new id you want to add : ";
	cin.getline(i,14);		
	while(fin.read((char*)&s,sizeof(s))){
		if(strcmp(i,s.getcnic())==0){
			cout<<"\nId already exists\n";
			b1=true;
			break;}}
	while(fin1.read((char*)&s,sizeof(s))){		
			if(b1==0){
			if(strcmp(n,s.Getname())==0){
			pos=fin1.tellg();
			cout<<"\nThis data will be modified \n";
			s.studentshow();
			cout<<endl;
			flag++;
			fin1.seekg(pos-sizeof(s));
			s.getstudent();
			fin1.write((char*)&s,sizeof(s));
			cout<<"Edited successfully \n";  break;}}}
	fin.close();
	fin1.close();
	if(flag==0 && b1==false)
	cout<<"Student not found so it cannot be edited \n";
	}
	else if(x=='2'){
	cout<<"\nEnter old Id to search : ";
	cin.ignore();
	cin.getline(c,14);
	cout<<"Enter new id you want to add : ";
	cin.getline(i,14);
	while(fin.read((char*)&s,sizeof(s))){
		if(strcmp(i,s.getcnic())==0){
			cout<<"\nId already exists\n";
			b1=true;
			break;}}
	while(fin1.read((char*)&s,sizeof(s))){		
			if(b1==0){
			if(strcmp(c,s.getcnic())==0){
			pos=fin1.tellg();
			cout<<"\nThis data will be modified \n";
			s.studentshow();
			cout<<endl;
			flag++;
			fin1.seekg(pos-sizeof(s));
			s.getstudent();
			fin1.write((char*)&s,sizeof(s));
			cout<<"Edited successfully \n";  break;}}}
	fin.close();
	fin1.close();
	if(flag==0 && b1==false)
	cout<<"Student not found so it cannot be edited \n";}}			

void teachermodify(){
bool b1=0;																						//edits existing teacher info
	int flag=0,pos;
	char c[14],i[14],x,n[50];
	fstream fin("Teacher.txt", ios::in | ios::out);
	fstream fin1("Teacher.txt", ios::in | ios::out);	
	Temp();
	cin>>x;
	if(x=='1'){
	cout<<"Enter name to search : ";
	cin.ignore();
	cin.getline(n,50);
	cout<<"Enter new id you want to add : ";
	cin.getline(i,14);		
	while(fin.read((char*)&t,sizeof(t))){
		if(strcmp(i,t.getcnic())==0){
			cout<<"\nId already exists\n";
			b1=true;
			break;}}
	while(fin1.read((char*)&t,sizeof(t))){		
			if(b1==0){
			if(strcmp(n,t.Getname())==0){
			pos=fin1.tellg();
			cout<<"\nThis data will be modified \n";
			t.teachershow();
			cout<<endl;
			flag++;
			fin1.seekg(pos-sizeof(t));
			t.getteacher();
			fin1.write((char*)&t,sizeof(t));
			cout<<"Edited successfully \n";  break;}}}
	fin.close();
	fin1.close();
	if(flag==0 && b1==false)
	cout<<"Teacher not found so it cannot be edited \n";}
	
	else if(x=='2'){
	cout<<"\nEnter old Id to search : ";
	cin.ignore();
	cin.getline(c,14);
	cout<<"\nEnter new id you want to add : ";
	cin.getline(i,14);
	while(fin.read((char*)&t,sizeof(t))){
		if(strcmp(i,t.getcnic())==0){
			cout<<"\nId already exists \n";
			b1=true;
			break;}}
	while(fin1.read((char*)&t,sizeof(t))){		
			if(b1==0){
			if(strcmp(c,t.getcnic())==0){
			pos=fin1.tellg();
			cout<<"This data will be modified \n";
			t.teachershow();
			flag++;
			fin1.seekg(pos-sizeof(t));
			t.getteacher();
			fin1.write((char*)&t,sizeof(t));
			cout<<"Edited successfully \n";   break;}}}
	fin.close();
	fin1.close();
	if(flag==0 && b1==0)
	cout<<"\nTeacher not found so it cannot be edited \n";}}		

void Student::deletestudent(){
	fstream rd,wr,f;
	bool b1=0;
	char i[14],n[50],x;
    rd.open("Student.txt",ios::in);
    wr.open("./temp.txt",ios::app);
    f.open("Issued book.txt",ios::in);
    Temp();
    cin>>x;
    if(x=='1'){
    cout<<"Enter name of the student :";
    cin>>n;
    cout<<"Enter id of the student to check for issued books : ";
    cin.ignore();
    cin.getline(i,14);
    while(f.read((char*)&ib,sizeof(ib))){
    	if(strcmp(i,ib.setcnic())==0){
    		b1=true;
    		break;}}
    		if(b1==0){
	while(rd.read((char*)&s,sizeof(s)))
    {
        if(strcmp(n,s.Getname())==0)
        {char z;
        s.studentshow();
        cout<<"\nStudent found, do you want to delete this record : ";
        cin>>z;
        if(z=='y' or z=='Y'){
		cout<<"\nStudent Removed"<<endl;}
		else{wr.write((char *)this,sizeof(*this));
		cout<<"\nRecord not deleted\n";}}
        else
        {wr.write((char *)this,sizeof(*this));}}}
        if(b1==true){
        cout<<"Return the issued book first to delete this student \n";
		wr.write((char *)this,sizeof(*this));}}
	else if(x=='2'){
    cout<<"Enter id of the student :";
    cin.ignore();
    cin>>n;
  //  cout<<"Enter id of the student to check for issued books : ";
   // cin.getline(i,14);
    while(f.read((char*)&ib,sizeof(ib))){
    	if(strcmp(n,ib.setcnic())==0){
    		b1=true;
    		break;}}
    		if(b1==0){
	while(rd.read((char*)&s,sizeof(s)))
    {
        if(strcmp(n,s.getcnic())==0)
        {char z;
        s.studentshow();
        cout<<"\nStudent found, do you want to delete this record : ";
        cin>>z;
        if(z=='y' or z=='Y'){
		cout<<"\nStudent Removed"<<endl;}
		else{wr.write((char *)this,sizeof(*this));
		cout<<"\nRecord not deleted\n";}}
        else
        {wr.write((char *)this,sizeof(*this));}}}
        if(b1==true){
        cout<<"Return the issued book first to delete this student \n";
		wr.write((char *)this,sizeof(*this));}}	
    rd.close();
    f.close();
    wr.close();
    remove("Student.txt");
    rename("./temp.txt","Student.txt");
	p.personcount();}

void Teacher::deleteteacher(){
fstream rd,wr,f;
bool b1=0;
    rd.open("Teacher.txt",ios::in);
    wr.open("./temp.txt",ios::app);
    f.open("Issued book.txt",ios::in);
    char n[50],i[14],x;
    Temp();
	cin>>x;
	if(x=='1'){
    cout<<"Enter name of the Teacher :";
    cin>>n;
    cout<<"Enter id of the teacher to check for issued books : ";
    cin.ignore();
    cin.getline(i,14);
    while(f.read((char*)&ib,sizeof(ib))){
    	if(strcmp(i,ib.setcnic())==0){b1=true;   break;}}
    	if(b1==0){
	while(rd.read((char*)&t,sizeof(t)))
    {
        if(strcmp(n,t.Getname())==0){char z;
        t.teachershow();
        cout<<"Teacher found, do you want to delete this record : ";
        cin>>z;
		if(z=='y' or z=='Y'){
		cout<<"Teacher Removed"<<endl;}
		else{wr.write((char *)this,sizeof(*this));
		cout<<"Record not deleted\n";}}
        else
        {wr.write((char *)this,sizeof(*this));}}}
        if(b1==true){cout<<"Return issued book first to delete this teacher \n";
		wr.write((char *)this,sizeof(*this));}}
	else if(x=='2'){
    cout<<"Enter id of the Teacher :";
	cin.ignore();  
    cin>>n;
 //   cout<<"Enter id of the teacher to check for issued books : ";
 //   cin.getline(i,14);
    while(f.read((char*)&ib,sizeof(ib))){
    	if(strcmp(n,ib.setcnic())==0){b1=true;   break;}}
    	if(b1==0){
	while(rd.read((char*)&t,sizeof(t)))
    {
        if(strcmp(n,t.getcnic())==0){char z;
        t.teachershow();
        cout<<"Teacher found, do you want to delete this record : ";
        cin>>z;
		if(z=='y' or z=='Y'){
		cout<<"Teacher Removed"<<endl;}
		else{wr.write((char *)this,sizeof(*this));
		cout<<"Record not deleted\n";}}
        else
        {wr.write((char *)this,sizeof(*this));}}}
        if(b1==true){cout<<"Return issued book first to delete this teacher \n";
		wr.write((char *)this,sizeof(*this));}}	
    rd.close();
    f.close();
    wr.close();
    remove("Teacher.txt");
    rename("./temp.txt","Teacher.txt");
	p.personcount();}

void addmenu(){																					//decides whether student or teacher is to be added
	int pass;
	start1:
	cout<<"Enter password : ";												//Password=12345
	cin>>pass;
	if(pass==12345){
	char c;
	while(c!='E'){
		start:
	system("cls");
	heading();			
		cout<<"Enter person type you want to add (S/T) ? Press E to exit ";
		cin>>c;
		switch(c){
			case 'S': addstudent();    break;
			case 'T': addteacher();    break;
			case 'E': break;
			default: goto start; }}}
else{
cout<<"Incorrect password, try again\n";
cout<<"\a";
goto start1;}}

int countLeapYears(date d){
    int years = d.iyear;
    if (d.imonth <= 2)							// Check if the current year is leap year
    years--;
    return years / 4 - years / 100 + years / 400;}					//leap year is a multiple of 4 and 400 but not 100
    
const int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int getDifference(date dt1, date dt2)
{   
    long int n1 = dt1.iyear * 365 + dt1.idate;
    for (int i = 0; i < dt1.imonth - 1; i++)							// days calculate krna k lia 
    n1 += days[i];
    n1 += countLeapYears(dt1);      									// leap year ki waga sa 1 day ki addition 													 
    long int n2 = dt2.iyear * 365 + dt2.idate;
    for (int i = 0; i < dt2.imonth - 1; i++)
        n2 += days[i];
    n2 += countLeapYears(dt2);
	return (n2 - n1);}     					// return difference

void reducecopies(){--b.copies;}						//book ki copies decrease krna k lia	

void Issuedbook::issuebooks(){									
	fstream f("Book.txt",ios::in | ios::out );
	fstream f1("Student.txt", ios::in );
	fstream f2("Teacher.txt", ios::in );
	fstream f3("Issued book.txt",ios::in | ios::app);
	bool b3,b2,b4=0,b5=0,b6;					//b3=check person      b2=check book   b4=checking leap issue year   b5=checking leap return year
	int x,y=0;
	cout<<"Are you a student or teacher (S/T) ";
	cin>>type;
	if(type=='S'){b6=false;}
	else if(type=='T'){b6=true;}
	cout<<"Enter book name you want to issue ";
	cin.ignore();
	cin.getline(Name,50);
	cout<<"Enter Id ";
	cin.getline(Cnic,14);
	while(f.read((char*)&b,sizeof(b))){
		if(strcmp(Name,b.gettitle())==0){
		b2=true;
		if(b.getcopies()>0)
		b4=true;
		break;}
		else
		b2=false;}
		if(b2==true && b4==true){
		int pos=f.tellg();
		f.seekg(pos-sizeof(b));		
		reducecopies();
		f.write((char*)&b,sizeof(b));}	
	f.close();
	if(b6==false){
		while(f1.read((char*)&s,sizeof(s))){
			if(strcmp(Cnic,s.getcnic())==0){
				b3=true;
				break;}
			else
			b3=false;}}
	else if(b6==true){
		while(f2.read((char*)&t,sizeof(t))){
			if(strcmp(Cnic,t.getcnic())==0){
			b3=true;
			break;}
			else
			b3=false;}}
			f1.close();
			f2.close();
	if(b3==true && b2==true && b4==true){
		d1.input();
		d2.input();
		x=getDifference(d1,d2);
		if(x<0){y=y+1;}
		if(y==0){
		if(b6==true){
			if(x>181)
		fine=300;
		else 
		fine=0;}
		else if(b6==false){
			if(x>21)
		fine=500;  
		else 
		fine=0;}
		f3.write((char*)&ib,sizeof(ib));}}
	else if(b2==true && b4==false)
	cout<<"No copies available, come back after few days !!! ";
	else
	cout<<"User or book not found ";
	if((y==1) && b2==true)
	cout<<"\nBook is not issued, please enter valid dates !!!";
	f3.close();
	ib.issuedbookcount();}

void Issuedbook::showissue(){
	ifstream fin("Issued book.txt");
	int rec=0;
	while(fin.read((char*)this,sizeof(*this))){
		if(rec<1)
		ib.ibheader();
		ib.iblistview();
		rec++;}
	fin.close();
	cout<<endl<<"Total "<<rec<<" records found "<<endl;
	cout<<"Users with fine greater than 0 are DEFAULTERS !!!\n";}

void showmenu(){																			//decides whether student or teacher is to be displayed
	char c;
	while(c!='E'){
		start:
	system("cls");
	heading();			
		cout<<"Enter person type you want to show (S/T) ? Press E to exit ";
		cin>>c;
		switch(c){
			case 'S': s.showstudent();  system("pause");  break;			
			case 'T': t.showteacher();  system("pause");  break;			
			case 'E': break;			
			default: goto start; }}}

void modifymenu(){																			//decides whether student or teacher is to be modified
	char c;
	int p;
	while(c!='E'){
		start1:
			cout<<"Enter password : ";
			cin>>p;
			if(p==12345){
	system("cls");
	heading();			
		cout<<"Enter person type you want to edit (S/T) ? Press E to exit ";
		cin>>c;
		switch(c){
			case 'S': studentmodify();  system("pause");  break;		
			case 'T': teachermodify();  system("pause");  break;	
			case 'E': break;			
			default: goto start1; }}
			else goto start1;}}

void Searchmenu(){																			//decides whether student or teacher is to be searhed
	char c;
	int p;
	while(c!='E'){
		start1:
		cout<<"Enter password : ";
		cin>>p;
		if(p==12345){
		start:
	system("cls");	
	cout<<endl<<endl;	
	heading();	
		cout<<"Enter person type you want to search (S/T) ? Press E to exit ";
		cin>>c;
		switch(c){
			case 'S': studentsearchmenu();    break;			
			case 'T': teachersearchmenu();    break;			
			case 'E': break;			
			default: goto start; }}
			else goto start1;}}

void searchmenu(){																			//decides method of searching book
	system("color 70");
	int ch=0;
	while(ch!=6){
		start:
		system("cls");
		heading();
		cout<<"1-> By isbn\n2-> By title\n3-> By publisher\n";
		cout<<"4-> By author\n5-> By publishing year\n6-> Back\n";
		cout<<"Enter search method : ";
		cin>>ch;
		system("cls");
		heading();
		switch(ch){
			case 1: searchbyisbn(); system("pause"); break;
			case 2: searchbytitle(); system("pause"); break;			
			case 3: searchbypublisher(); system("pause"); break;		
			case 4: searchbyauthor(); system("pause"); break;			
			case 5: searchbydate(); system("pause"); break;		 			
			case 6: break;			
			default: goto start;}}}

void deletemenu(){																							//decides whether student or teacher is to be deleted
	char c;
	int p;
	while(c!='E'){
		start1:
		cout<<"Enter password : ";
		cin>>p;
		if(p==12345){
		start:
	system("cls");	
	heading();		
		cout<<"Enter person type you want to delete (S/T) ? Press E to exit ";
		cin>>c;
		switch(c){
			case 'S': s.deletestudent();  system("pause");  break;			
			case 'T': t.deleteteacher();  system("pause");  break;
			case 'E': break;
			default: goto start; }}
			else goto start1;}}

void Person::personcount(){
	int s=0,p=0;
	ifstream fin("Student.txt");
	ifstream fin1("Teacher.txt");
	while(fin.read((char*)this,sizeof(*this))){s++;}
	while(fin1.read((char*)this,sizeof(*this))){p++;}
	pcount=s+p;}	
		
void menu(){																					//main menu
	system("color B0");
	int ch;
	while(ch!=-1){
		start:
		system("CLS");
		system("color B0");
		cout<<endl<<endl<<endl;
		heading();
		cout<<"\n   0-> Add new book (Total books : "<<bcount<<" )\n"; 
		cout<<"   1-> Edit book\n";
		cout<<"   2-> Delete book\n";					
		cout<<"   3-> Search book\n";
		cout<<"   4-> Add library user (Total users : "<<pcount<<" )\n";  
		cout<<"   5-> Delete library user\n";
		cout<<"   6-> Search library user\n";
		cout<<"   7-> Edit library user\n";
		cout<<"   8-> Issue book\n";
		cout<<"   9-> Delete issue book\n";
		cout<<"   10-> Show users\n";
		cout<<"   11-> Show books\n";
		cout<<"   12-> Show issued books (Total issued books :"<<ibcount<<" )\n";  
		cout<<"   -1-> Exit program\n";
		cout<<"   Enter your choice :\n ";
		cin>>ch; 	
		system("cls");
		heading();	
		
		if(ch==0){
			system("color 70");
			addbook();
			sleep(2);
			goto start;} 
		
		else if(ch==1){
			system("color 70");
			modify();
			sleep(2);
			goto start;}
		
		else if(ch==2){
			system("color 70");
			b.deletebook();
			sleep(2);
			goto start;}
		
		else if(ch==3){
			system("color 70");
			searchmenu();
			goto start;}
		
		else if(ch==4){
			 	system("color 70");
			 	addmenu();
			 	goto start;}
			 
		else if(ch==5){
			 	system("color 70");
			 	deletemenu();
			 	//sleep(2);
			 	goto start;}
			 
		else if(ch==6){
				system("color 70");
			 	Searchmenu();
			 	//sleep(2);
			 	goto start;}
			 
		else if(ch==7){
			 	system("color 70");
			 	modifymenu();
			 	//sleep(2);
			 	goto start;}
			 
		else if(ch==8){
			 	system("color 70");
			 	ib.issuebooks();
			 	sleep(1);
			 	goto start;}
			 
		else if(ch==9){
			 	system("color 70");
			 	ib.deleteib();
			 	sleep(1);
			 	goto start;}
			 
		else if(ch==10){
			 	system("color 70");
			 	showmenu();
			 	goto start;}
			 
		else if(ch==11){
				system("color 70");
			 	displaybooks();
			 	system("pause");
			 	goto start;}
			 
		else if(ch==12){
			 	system("color 70");
			 	ib.showissue();
			 	system("pause");
			 	goto start;   }}}
			 
void Book::bookcount(){
	bcount=0;
	ifstream fin("Book.txt");
	while(fin.read((char*)this,sizeof(*this))){bcount++;}}

void Issuedbook::issuedbookcount(){
	ibcount=0;
	ifstream fin("Issued book.txt");
	while(fin.read((char*)this,sizeof(*this))){ibcount++;}}			 						
int main(){
	system("color a0");
	cout<<endl<<endl<<endl;
	system("pause");
	system("cls");
	cout<<"\n\n\n";
	heading();
		cout<<"\n\n\n\t\t\t\t\t\t\tBy Group 2\n";
	system("color a0");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t LOADING, PLEASE WAIT !!!\n";
for(int i=1; i<=5; i++){
	if(i==1)
	cout<<"\n\n\n\t\t\t\t\t\t      *  ";
	else
	cout<<"*  ";
	sleep(2);}
b.bookcount();
p.personcount();
ib.issuedbookcount();
menu();}                
