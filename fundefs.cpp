#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Header1.h"

using namespace std;
class Date;
class obj;
class comment;
class users;
class Page;
class post;
class activity;

obj::obj() {
	id = 0;
}
int obj::getid() {
	return id;
}
void obj::setid(int x) {
	id = x;
};
Page::Page() {
	count = 0;
	likedpeople = new user * [20];
	posts = new activity * [20];
	postsids = new int[10];
	for (int i = 0; i < 20; i++) {
		likedpeople[i] = nullptr;
		posts[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		postsids[i] = 0;
	}

	name = "";
};
void Page::setid(int x) {
	obj::setid(x);

}
Page::Page(string names) {

	this->name = names;
};
void Page::setname(string a) {
	name = a;
}
string Page::getname() {
	return name;
}
void Page::setusers(user& obj) {
	static int x = 0;
	likedpeople[x] = &obj;

	//obj->
	x++;

}
activity* Page:: getposts(int a) {
	return posts[a];
}
void Page::setposts(activity& obj) {
	static int x = 0;
	posts[x] = &obj;

	//obj->
	x++;

}
void Page::print() {

		cout << getname() << endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < 10; i++) {
			if (posts[i] != nullptr) {
				posts[i]->print();
			}
		}
	

}
user::user() {
	countposts = 0;
	countfriends = 0;
	countpages = 0;
	firstname = "";
	lastname = "";
	pages = new Page * [10];
	friends = new user * [10];
	posts = new activity * [10];
	pagesids = new int[10];
	userids = new int[10];
	postsids = new int[10];
	//comm = new comment[10];
	activityx = 0;

	for (int i = 0; i < 10; i++) {
		pagesids[i] = 0;
		userids[i] = 0;
		postsids[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		pages[i] = nullptr;
		friends[i] = nullptr;
		posts[i] = nullptr;
	}


}
user::user(string ids, string lname, string fname) {
	//id = ids;
	this->firstname = fname;
	this->lastname = lname;
	pages = new Page * [10];
	for (int i = 0; i < 10; i++) {
		pages[i] = nullptr;
	}


}
void user::setnames(string a, string b) {
	firstname = a;
	lastname = b;

}
void user :: Timeline() {
	for (int i = 0; i < 10; i++) {
		if (posts[i] != nullptr) {
			posts[i]->print();
			cout << "...(";
			cout << posts[i]->getsharedpostDate()->getday() << "/";
			cout << posts[i]->getsharedpostDate()->getmonth() << "/";
			cout << posts[i]->getsharedpostDate()->getyear() << ")";
			cout << endl;
		}
		
	}
	

}
string user::getnames() {
	cout << "        ";
	return firstname;
}

void user::setid(int x) {
	obj::setid(x);

}
void user::printfriends() {
	cout << "Friends List : " << endl;
	cout << endl;
	for (int i = 0; userids[i] > 0; i++) {
		cout << "u" << friends[i]->obj::getid() << "--  ";
		cout << friends[i]->firstname << "  " << friends[i]->lastname << endl;

	}

}
string user::getfname() {
	string fullname = firstname + " " + lastname;
	return fullname;
}
void user::printposts() {
		for (int i = 0; i<10; i++) {
			if (posts[i] != nullptr) {
				posts[i]->print();

			}
		}
	
}
void user::printlikedpages() {
	cout << "Liked Pages : " << endl;
	cout << endl;
	for (int i = 0; pagesids[i] > 0; i++) {
		cout << "p" << pages[i]->obj::getid() << "--  ";
		cout << pages[i]->getname() << endl;

	}

}

void user::HOmepage(int day,int m,int y) {
	//int m = 10;
	//int y = 2017;
//	int day = 14;
	cout << "=======================" << endl;
	int cid = 7;
	
	for (int i = 0; i < 10; i++) {
		if( posts[i] != nullptr)
		{
			int d = posts[i]->getsharedpostDate()->getday();
			int month = posts[i]->getsharedpostDate()->getmonth();
			int year = posts[i]->getsharedpostDate()->getyear();
			if (d == day || d == (day-1) && month == m  && year == y )
			{
				posts[i]->print();
				cout << d << " /" << month << "/" << year << "\n";
				cout << endl << endl;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (friends[i] != nullptr) {
			for (int j = 0; j < 10; j++)
				if (friends[i]->posts[j] != nullptr)
				{
					int d = friends[i]->posts[j]->getsharedpostDate()->getday();

					int month = friends[i]->posts[j]->getsharedpostDate()->getmonth();

					int year = friends[i]->posts[j]->getsharedpostDate()->getyear();
					if (d == day || d == (day-1) && month == m  && year == y )
					{
						friends[i]->posts[j]->print();
						cout << d << " /" << month << "/" << year << "\n";
						cout << endl << endl;
					}
				}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (pages[i] != nullptr) {
			for (int j = 0; j < 10; j++)
				if (pages[i]->getposts(j) != nullptr)
				{
					int d = pages[i]->getposts(j)->getsharedpostDate()->getday();
					int month = pages[i]->getposts(j)->getsharedpostDate()->getmonth();
					int year = pages[i]->getposts(j)->getsharedpostDate()->getyear();
					if ((d == day || d == (day-1)) && month == m && year == y )
					{
						pages[i]->getposts(j)->print();
						cout << d << " /" << month << "/" << year << "\n";
						cout << endl << endl;
					}
				}
		}
	}


}
//void user::setcomm(comment obj) {
	//static int x = 0;
	//comm[x] = obj;
//	x++;
//}

void user::setposts(activity& obj) {


	posts[activityx] = &obj;
	activityx++;
	//obj->


}
string user:: getlname() {
	return lastname;
}
void user::setfriends(user& obj) {


	friends[countfriends] = &obj;
	//friends[countfriends]->setid(obj.getid());
	countfriends++;
	//obj->

}
void user::setpages(Page& obj) {


	pages[countpages] = &obj;
	//	pages[x].setid(obj.getid());
		//obj->
	countpages++;
}









Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
void Date::setday(int d)
{
	day = d;
}
int Date::getday()
{
	return day;
}
void Date::setmonth(int m)
{
	month = m;
}
int Date::getmonth()
{
	return month;
}
void Date::setyear(int y)
{
	year = y;
}
int Date::getyear()
{
	return year;
}
void Date::print() {
	cout << day << "/" << month << "/" << year << endl;
}

comment::comment()
{
	
		users = nullptr;
		pagename = nullptr;
		count = 0;
	
	des = "";
}
comment::comment(string des, user** users)
{
	this->des = des;
	//pagename = new activity*[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	
	//	pagename[i] = nullptr;
	//}
	users = nullptr;
	page = nullptr;
}
void comment::setid(int id)
{
	obj::setid(id);
}
void comment::setdes(string des)
{
	this->des = des;
}
string comment::getdes()
{
	return des;
}
void comment::setusers(user& obj)
{

	users = &obj;
	
}
//void comment::settexts(activity& obj)
//{
//	
//	pagename[count] = &obj;
//	count++;
//}

void comment::setpagename(Page&obj) {
	page = &obj;

}
void comment::print()
{
	if (users != nullptr) {
		cout << users->getfname() << ":  ";
	}
	else if (page != nullptr) {
		cout << page->getname() << ":  ";
	}
	cout << getdes() << endl;
	//	cout << "pagename:  "<< *pagename << " userid: "<< *users ;
}


Post::Post()
{
	countlikedpeople = 0;
	countlikedpages = 0;
	countcomments = 0;
	count = 0;
	description = "";
	likedpostsbyuser = new user * [5];
	likedpostbypage = new Page * [5];
	sharedpostbyuser = nullptr;
	sharedpostbypage = nullptr;
	for (int i = 0; i < 5; i++) {
		likedpostbypage[i] = nullptr;
		likedpostsbyuser[i] = nullptr;
	}
	commids = new int[10];
	commid = new comment * [12];
	for (int i = 0; i < 12; i++)
	{
		commid[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		commids[i] = 0;
	}
}
Post::Post(string des, user** likedposts)
{

	description = des;
	likedposts = new user * [11];

	for (int i = 0; i < 11; i++)
	{
		likedposts[i] = new user[4];
	}

	

}
void Post::setusercommentid(comment& obj)
{

	commid[countcomments] = &obj;//usercomid[q] = &id;
	countcomments++;
	//q++;
}
void Post::setlikedpost(Page& obj) {
	

	likedpostbypage[countlikedpages] = &obj;
	countlikedpages++;
}
void Post::setlikedpost(user& obj) {

	likedpostsbyuser[countlikedpeople] = &obj;
	countlikedpeople++;
}
void Post::setdate(Date& d) {
	shareddate = &d;
}
void Post::setsharedpost(user& obj) {
	sharedpostbyuser = &obj;
}
void Post::setsharedpost(Page& obj) {
	sharedpostbypage = &obj;
}
user* Post::getsharedpostbyuser() {
	return sharedpostbyuser;
}
Date* Post::getsharedpostDate() {
	return shareddate;
}
Page* Post::getsharedpostbypage() {
	return sharedpostbypage;
}
//void Post::setuser(user& obj)
//{
//	static int x = 0;
//	likedposts[x] = &obj;
//	x++;
//}

void Post::setdes(string des)
{
	this->description = des;
}
//int getid() {
//	return obj::getid();
//}

void Post::setid(int x) {
	obj::setid(x);

}
string Post::getdescription()
{
	return description;
}
void Post::printdate() {
	shareddate->print();
}
void Post::print2()
{
	for (int i = 0; i < 12; i++) {
		if (commid[i] != nullptr) {
			commid[i]->print();
		}
	}
}
void Post::likes() {
	cout << "Post liked by : " << endl;
	for (int i = 0; i < 5; i++) {
		if (likedpostbypage[i] != nullptr) {
			cout << likedpostbypage[i]->getname();
			cout << endl;
		}
		if (likedpostsbyuser[i] != nullptr) {
			cout <<"        "<< likedpostsbyuser[i]->getfname();
			cout << endl;
		}

	}

}
void Post::print() {
	//shareddate->print();
	//if (sharedpostbyuser != nullptr) {
	//	cout << "Post shared by: " << sharedpostbyuser->getnames();
	//}
	

	cout << "''";
	cout <<getdescription();
	cout << "''";
	cout << endl;
	
	cout << "Comment section:" << endl;
	for (int i = 0; i < 12; i++) {
		if (commid[i] != nullptr) {
			commid[i]->print();
		}
	}

}

activity::activity() {
	type = 0;
	value = "";
}
void activity::setvalue(string des)
{
	value = des;
}
int activity::gettype() {

	return type;

}
string activity::getvalue() {
	return value;
}

void activity::settype(int x) {
	type = x;
}
void activity::search(string name, activity* posts, user* u, Page* pages, comment* arr_comm) {
	int userids[10] = { 0 };
	int pageids[10] = { 0 };
	int found = -1;
	string description;
	cout << "Search for : " << name << endl;;
	cout << endl;
	for (int i = 0; i < 20; i++) {
		found = -1;
		string description = u[i].getfname();
		found = description.find(name);

		if (found == -1) {

		}
		else {
			cout << "p" << u[i].obj::getid() << "--  ";
			cout << u[i].getfname() << endl;
		}
	}

	string pagename;
	
	
	for (int i = 0; i < 11; i++) {
		found = -1;
		description = posts[i].getdescription();
		found = description.find(name);
		if (found == -1) {

		}
		else {
		
			posts[i].print();
		}

	}

	for (int i = 0; i < 12; i++) {
		found = -1;
		pagename = pages[i].getname();
		found = pagename.find(name);
		if (found == -1) {

		}
		else {
			cout << "p" << pages[i].obj::getid() << "--  ";
			cout << pages[i].getname() << endl;
		}

	}
}
void activity::run(activity* posts, user* u, Page* page, comment* arr_com,int noofcomms) {
	//u[0].setposts(posts[10]);
//	u[0].printposts();
	cout << "Comand : " << "   " << "set users(u7)" << endl;
	cout << u[6].getfname() << " succesfully set as current user" << endl;
	cout << "Comand : " << "  set current date as 15 11 2017" << endl;
	int m = 11;
	int y = 2017;
	int day = 15;
	cout << "Command" << "    " << "view Friends " << endl;//id=7 so we will write (id-1)=6 as array start from 0
	u[6].printfriends();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "   " << "view Pages liked " << endl;
	u[6].printlikedpages();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "   " << "view Post(5) likes " << endl;
	posts[4].likes();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "   " << "Like post(5)" << endl;
	posts[4].setlikedpost(u[6]);
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "   " << "view Post(5) likes " << endl;
	posts[4].likes();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "   " << "view Timeline liked " << endl;
	u[6].Timeline();

	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "      " << "view Page(1)" << endl;
	page[0].print();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "    " << "view Homepage" << endl;
	u[6].HOmepage(day,m,y);
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "    " << "comment(Post 4)(Good luck for your result)" << endl;
	string description = "Good luck for your result";
	arr_com[noofcomms].setdes(description);
	arr_com[noofcomms].setid(noofcomms + 1);
	arr_com[noofcomms].setusers(u[6]);
	posts[3].setusercommentid(arr_com[noofcomms]);
	noofcomms++;
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "      " << "view Post(4)" << endl;
	posts[3].print();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "    " << "comment(Post 8)(Thanku very much)" << endl;
	 description = "thanku very much";
	arr_com[noofcomms].setdes(description);
	arr_com[noofcomms].setid(noofcomms + 1);
	arr_com[noofcomms].setusers(u[6]);
	posts[7].setusercommentid(arr_com[noofcomms]);
	noofcomms++;
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "      " << "view Post(8)" << endl;
	posts[7].print();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "  " << "sharepost(5)" << endl;

	u[0].setposts(posts[4]);
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "  " << "View posts" << endl;
	u[0].printposts();
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "  " << "search(Birthday)" << endl;
	activity::search("Birthday", posts, u, page, arr_com);
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "command" << "  " << "search(Ali)" << endl;
	activity::search("Ali", posts, u, page, arr_com);
	cout << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;


};
void activity::print() {

	if (getsharedpostbyuser() != nullptr) {
	
		cout << getsharedpostbyuser()->getnames() << "  " << getsharedpostbyuser()->getlname()<<" ";
	}
	if (getsharedpostbypage() != nullptr) {
		cout << getsharedpostbypage()->getname()<<" ";
	}
				int t=activity::gettype();
				if (t == 1)
					cout << "is feeling";
				else if (t == 2)
					cout << "Thinking about ";
				else if (t == 3)
					cout << "is Making";
				else if (t == 4)
					cout << "is celebrating";
				else if(t==0)
					cout << " shared ";
				cout << activity::getvalue() << endl;
		
	Post::print();

}
 

Page:: ~Page() {

	delete[] likedpeople;
	likedpeople = nullptr;
	delete[]posts;
	posts = nullptr;

};
Post ::~Post() {

delete[]likedpostsbyuser;
likedpostsbyuser = nullptr;
delete[]likedpostbypage;
likedpostbypage = nullptr;
sharedpostbyuser = nullptr;
	 sharedpostbypage = nullptr;
	

		 shareddate = nullptr;

}
user::~user() {
	
	
	delete[] friends;
	friends=nullptr;
	delete[] posts;
	posts=nullptr;
	delete[] pages;
	pages=nullptr;
}
comment::~comment() {
	
	 users=nullptr;
	 delete []pagename;
	 pagename = nullptr;
}

