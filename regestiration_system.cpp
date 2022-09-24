#include <iostream>
#include <fstream>
#include <cstdlib>
#include<ctime>
#include<sstream>
class Fitness;
#include"Member.h"
#include"Fitness.h"
#include"Admin.h"
using namespace std;

void viewClassesWithVacancies(Fitness *fit){

int num = fit[0].getnum();
cout << num <<endl;
for (int i=0; i<num; i++){

    if (fit[i].getid()>0 && fit[i].getmax()!= fit[i].getmems()){
        fit[i].display();
    }
}
cout << "done" <<endl;
}


bool adcheck(Admin *arr, string user, string pass){
bool check;
int x;
int num = arr[0].getnum();

for (int i=0; i<=num; i++){
    if (arr[i].getuser() == user && arr[i].getpass() == pass){
        check = true;
        cout << "logged in successfully!"<<endl;
        return check;
        //break;
    }
}
    cout << "incorrect input"<<endl;
    cout << "exit = 0 / try again = 1: ";
    cin >> x;
    if (x==1){
      check = false;
      //break;
    }
     else {exit(0);}

return check;
}
bool memcheck (Member *arr, string user, string pass){
bool check;
int x;
int num = arr[0].getnum();

for (int i=0; i<=num; i++){
    if (arr[i].getuser() == user && arr[i].getpass() == pass){
        check = true;
        cout << "logged in successfully!"<<endl;
        return check;
        //break;
    }
}
    cout << "incorrect input"<<endl;
    cout << "exit = 0 / try again = 1: ";
    cin >> x;
    if (x==1){
      check = false;
      //break;
    }
     else {exit(0);}



return check;
}
void listCommands()
{
	cout<<"List of available operations for admins:"<<endl
		<<"1) register a new admin"<<endl
		<<"2) register a new member"<<endl
		<<"3) add fitness class"<<endl
		<<"4) delete fitness class"<<endl
		<<"5) update fitness class"<<endl
		<<"6) display class with vacancies"<<endl
		<<"7) quit"<<endl;
}
void mlistCommands()
{
	cout<<"List of available operations for members:"<<endl
		<<"1) book class"<<endl
		<<"2) cancel booking"<<endl
		<<"3) display class with vacancies"<<endl
		<<"4) quit"<<endl;
}
void adminlogin (Admin *arr, int a,Member *marr, Fitness *fit){

int com;
 do {
   listCommands();
   cout << "command number: ";
   cin >> com;
    if (com == 1) arr[a].registerAdmin(arr);
    else if (com == 2) arr[a].registerMember(marr);
    else if (com==3) arr[a].addFitnessClass(fit);
    else if (com==4) arr[a].deleteFitnessClass(fit);
    else if (com==5) arr[a].updateClassDetails(fit);
    else if (com==6) viewClassesWithVacancies(fit);
    }while (com != 7);

}
void memlogin (Member *marr, int m, Fitness *fit){
int com;
do {
    mlistCommands();
    cout << "command number: ";
    cin >> com;
    if (com==1) marr[m].bookAClass(marr,m,fit);
    else if(com==2) marr[m].cancelBooking(marr,m,fit);
    else if (com==3) viewClassesWithVacancies(fit);
    }while (com != 4);

}

string login (Admin *arr, int num, Member *marr, Fitness *fit){
string choice, user, pass, re;
int a, m;
cout << "enter your category (admin/member): ";
    cin >> choice;
    while ((choice != "admin") && (choice != "member")){
        cout << "wrong input, try again: ";
        cin >> choice;
    }
    cout << "enter user: ";
    cin >> user;
    cout << "enter pass: ";
    cin >> pass;
    if (choice == "admin"){
   while (adcheck(arr,user, pass)!=true){

    cout << "enter user: ";
    cin >> user;
    cout << "enter pass: ";
    cin >> pass;
   }
   for (int i=0; i<=arr[0].getnum(); i++){
    if (arr[i].getuser() == user && arr[i].getpass() == pass){
        a=i;
    }}
   adminlogin(arr, a, marr, fit);
    }
if (choice == "member"){

   while (memcheck(marr,user, pass)!=true){

    cout << "enter user: ";
    cin >> user;
    cout << "enter pass: ";
    cin >> pass;
   }
    for (int i=0; i<=marr[0].getnum(); i++){
    if (marr[i].getuser() == user && marr[i].getpass() == pass){
        m=i;
    }}
    memlogin(marr, m, fit);
}
return choice;
}





int main (){
    Admin admin;
    Admin * arr= new Admin[100];
    Member * marr= new Member[100];
    Fitness *fit = new Fitness [100];
    int num = admin.getnum();
    int com(0);
    bool yes=true;
    string c;
    ofstream lol1;
    lol1.open("AdminsTable.txt");
	 if (lol1.fail()) {
        cerr << "Error opening the file \n";
    }
    ofstream lol2;
    lol2.open("MembersTable.txt");
	 if (lol2.fail()) {
        cerr << "Error opening the file \n";
    }
     ofstream lol3;
    lol3.open("FitnessClassesTable.txt");
	 if (lol3.fail()) {
        cerr << "Error opening the file \n";
    }
    cout << "welcome to the system" << endl;
    while (yes){
    while (c!="y" || c!="n"){
    cout << "login? (y/n): ";
    cin >> c;
    if (c=="y"){yes=true; break;}
    else if (c=="n") {
    yes=false;
    for (int i =0; i<arr[0].getnum();i++){
        lol1<<arr[i].getid() << "," << arr[i].getfirst()<<","<<arr[i].getlast()<<","<<arr[i].getuser()<<","<<arr[i].getpass()<<endl;
    }
    for (int i =0; i<marr[0].getnum();i++){
        lol2<<marr[i].getid() << "," << marr[i].getname()<<","<<marr[i].getlast()<<","<<marr[i].getuser()<<","<<marr[i].getpass()<<endl;
    }
    for (int i =0; i<fit[0].getnum();i++){
        lol3<<fit[i].getid() << "," << marr[i].getname()<<","<<fit[i].getdate()<<","<<fit[i].gettime()<<","<<fit[i].getmax()<<","<<fit[i].getrm()<<endl;
    }

    exit(0);}
    else {
        cout << "incorrect input, try again"<<endl;
    }
    }
    login(arr, num, marr, fit);


}
delete [] arr;
delete [] marr;
delete [] fit;
lol1.close();
lol2.close();
lol3.close();
return 0;
}


Admin::Admin(){

this-> adid = 1;
this -> firstName= "admin";
this -> lastName= "admin";
this -> userName= "admin1";
this -> pass= "admin1";
this->numberofadm++;
}

void Admin::registerAdmin(Admin *arr){
    Admin admin;
    srand ( time(NULL) );
    string first, last;
    int num = admin.getnum()-1;
    cout << num<<endl;
    cout << "enter first name: ";
    cin >> first;
    cout << "enter last name: ";
    cin >> last;
    arr[num].firstName=first;
    arr[num].lastName=last;
    string ran1 = to_string(rand()%10) + to_string(rand()%10)+ to_string(rand()%10)+ to_string(rand()%10);
    string ran2 = to_string(rand()%10) + to_string(rand()%10)+ to_string(rand()%10)+ to_string(rand()%10);
    arr[num].setid(stoi(ran1));
    string f2, l2;
    for (int i = 0; i < first.length(); i++){
        f2 += tolower(first[i]);
    }
        for (int i = 0; i < last.length(); i++){
        l2 += tolower(last[i]);
    }
    arr[num].setuser(f2+ran1);
    arr[num].setpass (l2+ran2);
    cout << "admin created!"<<endl;
    cout << "user: "<< arr[num].getuser() << endl<<"pass: "<<arr[num].getpass()<<endl;
}

void Admin::registerMember(Member *arr){
    arr[0].numberofmem ++;
    srand ( time(NULL) );
    string first, last;
    int num = arr[0].getnum()-1;
    cout << num<<endl;
    cout << "enter first name: ";
    cin >> first;
    cout << "enter last name: ";
    cin >> last;
    arr[num].setfirst(first);
    arr[num].setlast(last);
    string ran1 = to_string(rand()%10) + to_string(rand()%10)+ to_string(rand()%10)+ to_string(rand()%10);
    string ran2 = to_string(rand()%10) + to_string(rand()%10)+ to_string(rand()%10)+ to_string(rand()%10);
    arr[num].setid(stoi(ran1));
    string f2, l2;
    for (int i = 0; i < first.length(); i++){
        f2 += tolower(first[i]);
    }
        for (int i = 0; i < last.length(); i++){
        l2 += tolower(last[i]);
    }
    arr[num].setuser(f2+ran1);
    arr[num].setpass (l2+ran2);
    cout << "member created!"<<endl;
    cout << "user: " <<arr[num].getuser() << endl<<"pass: "<<arr[num].getpass()<<endl;
}
void Admin:: addFitnessClass (Fitness *fit){
    int id, max, rmnum;
    fit[0].numberofc ++;
    bool check=true;
    int num = fit[0].getnum()-1;
    string name, date, time;
    cout << "enter class ID: ";
    cin >> id;
    fit[num].setid(id);
    cout << "enter class name: ";
    cin >> name;
    fit[num].setname(name);
    cout << "enter class date: ";
    cin >> date;
    fit[num].setdate(date);
    cout << "enter class time: ";
    cin>>time;
    fit[num].settime(time);
    cout << "enter max capacity: ";
    cin >> max;
    fit[num].setmax(max);
    cout << "enter room number: ";
    cin >> rmnum;
    fit[num].setrm(rmnum);
    fit[num].create (max);

cout << "class created!" <<endl;
}
void Admin::deleteFitnessClass(Fitness *fit){

int num = fit [0].getnum();
int id;
bool del=false;
cout << "enter ID to delete: ";
cin >> id;
for (int i= 0; i< num; i++){

    if (id==fit[i].getid()){

        fit[i].setid(-i);
        del=true;
        cout << "deleted!"<<endl;
    }
}
if (del==false){

    cout << "no valid id, pls try again";
    deleteFitnessClass(fit);
}
}

void Admin::updateClassDetails(Fitness *fit){
    int cid;
    int num = fit[0].getnum();
    int id, max, rmnum;
    string choice,name, date, time;
    cout << "enter class id: ";
    cin >> cid;
    for (int i=0; i<num; i++){
        if (cid==fit[i].getid()){

            cid=i;
        }
    }
    cout << "what do you wanna update (id/name/time/date/roomNumber/maxCap): ";
    cin >> choice;

    if (choice=="name"){
        cout<<"enter new name: ";
        cin >> name;
        fit[cid].setname(name);}
    else if (choice=="id"){
        cout<<"enter new id: ";
        cin >> id;
        fit[cid].setid(id);}
   else if (choice=="time"){
        cout<<"enter new time: ";
        cin >> time;
        fit[cid].settime(time);}
    else if (choice=="date"){
        cout<<"enter new date: ";
        cin >> date;
        fit[cid].setdate(date);}
    else if (choice=="roomNumber"){
        cout<<"enter new room: ";
        cin >> rmnum;
        fit[cid].setrm(rmnum);}
    else if (choice=="maxCap"){
        cout<<"enter new max: ";
        cin >> max;
        fit[cid].setmax(max);}

    fit[cid].display();


}


Member::Member(){

}
Fitness::Fitness(){

};
void Fitness::display (){
cout << "id: " << getid() <<endl
<<"name: "<<getname()<<endl
<<"date: " <<getdate()<<endl
<<"time: "<<gettime()<<endl
<<"room: "<<getrm()<<endl
<<"max cap: "<<getmax()<<endl
<<"members: ";
for (int i=0; i<getmax(); i++){

    cout << (getarr()[i]).getname()<<endl;
}

}

void Member::bookAClass(Member *marr, int m,Fitness *fit){
    int cid;
    bool valid=false;
    bool booked=false;
    char c='y';
    int num = fit[0].getnum();
    cout << "enter class id to book: ";
    cin>>cid;
    for (int i=0; i<num; i++){

        if (cid==fit[i].getid()){
            valid=true;
            cid=i;
        }

    }
    if (valid==false){
        cout << "not a valid id, try again"<<endl;
        bookAClass(marr,m,fit);
    }
    int mnum=fit[cid].getmems();
    for (int i= 0; i<fit[cid].getmax();i++){

        if (((fit[cid].getarr())[i]).getid()==marr[m].getid()){

            cout << "you already booked this!"<<endl;
            booked=true;
        }
    }
    if (booked==false){
    if (fit[cid].getmems()<fit[cid].getmax()){
    ((fit[cid].getarr())[mnum]) = marr[m];
      fit[cid].mems++;
    fit[cid].display();
    }
     else {
        while (c!='y' || c!= 'n'){
        cout << "fully booked!, try another class? (y/n)";
        cin >> c;
        if (c=='y'){
        bookAClass(marr,m,fit);
        }
        else if (c=='n'){break;}
     }
     }
    }
}

void Member::cancelBooking(Member *marr, int m,Fitness *fit){
    int cid,mid;
    bool valid=false;
    bool booked=false;
    char c='y';

    int num = fit[0].getnum();
    cout << "enter class id to cancel: ";
    cin>>cid;
    for (int i=0; i<num; i++){

        if (cid==fit[i].getid()){
            valid=true;
            cid=i;
        }

    }
    if (valid==false){
        cout << "not a valid id, try again"<<endl;
        cancelBooking(marr,m,fit);
    }

    for (int i= 0; i<=fit[cid].getmax();i++){
        if (((fit[cid].getarr())[i]).getid()== marr[m].getid()){
            //cout << "you have no booking in here!"<<endl;
            booked=true;
        }

    }
    if (booked == false){

        cout << "you have no booking in here!"<<endl;
    }
    else if (booked==true){
    for (int i= 0; i<fit[cid].getmax();i++){

        if (((fit[cid].getarr())[i]).getid()==marr[m].getid()){

           mid=i;
        }
    }
    for (int i = mid; i<fit[cid].getmax()-1; i++){

        ((fit[cid].getarr())[mid]) = ((fit[cid].getarr())[mid+1]);
    }
    Member x;
    ((fit[cid].getarr())[fit[cid].getmax()-1])=x;
    fit[cid].mems--;
    fit[cid].display();
    }



}

int Member ::numberofmem=0;
int Admin ::numberofadm=-100;
int Fitness ::numberofc=0;
int Fitness::mems=0;

