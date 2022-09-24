#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

using namespace std;

class Member
{
	private:
		int memid;
        static int numberofmem;
		string firstName, lastName, userName, pass;
	public:
	    Member();
        friend class Admin;
        friend class Fitness;
        int getnum(){return numberofmem;};
        void bookAClass(Member *marr, int m,Fitness *fit);
        void cancelBooking(Member *marr, int m,Fitness *fit);
        string getuser (){return userName;};
        string getpass (){return pass;};
        string getname (){return firstName;};
        string getlast (){return lastName;};
        int getid (){return memid;};
        void setid (int id){memid = id;};
        void setuser (string u){userName = u;};
        void setpass (string p){pass = p;};
        void setfirst (string f){firstName = f;};
        void setlast (string l){lastName = l;};
};

#endif // MEMBER_H_INCLUDED
