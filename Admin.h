#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

using namespace std;
class Admin
{
	private:
		int adid;
		string firstName, lastName, userName, pass;
		static int numberofadm;
	public:
		Admin();
		bool check(string user, string pass);
		void registerAdmin(Admin *arr);
		void registerMember(Member *arr);
		void addFitnessClass(Fitness *fit);
		void deleteFitnessClass(Fitness *fit);
		void updateClassDetails(Fitness *fit);
        int getnum(){return numberofadm;};
        string getuser (){return userName;};
        string getpass (){return pass;};
        string getfirst (){return firstName;};
        string getlast (){return lastName;};
        int getid (){return adid;};
		void setid (int id){adid = id;};
        void setuser (string u){userName = u;};
        void setpass (string p){pass = p;};
        void setfirst (string f){firstName = f;};
        void setlast (string l){lastName = l;};
};
#endif // ADMIN_H_INCLUDED
