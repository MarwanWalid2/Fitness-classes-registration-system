#ifndef FITNESS_H_INCLUDED
#define FITNESS_H_INCLUDED
using namespace std;
class Fitness
{
    private:
        int cid, max, rmnum;
        string name, date, time;
        static int numberofc;
        Member *marr;
        static int mems;

    public:
        friend class Admin;
         friend class Member;
        Fitness();
        void setid (int id){cid = id;};
        void setname (string u){name = u;};
        void setdate (string p){date = p;};
        void settime (string f){time = f;};
        void setmax (int m){max = m;};
        void setrm (int r) {rmnum = r;};
        string getname (){return name;};
        string getdate (){return date;};
        string gettime (){return time;};
        int getrm (){return rmnum;};
        int getid (){return cid;};
        int getnum(){return numberofc;};
        int getmax (){return max;};
        void create(int x) {marr=new Member[x];};
        Member* getarr (){return marr;};
        void display();
        int getmems(){return mems;};
};

#endif // FITNESS_H_INCLUDED
