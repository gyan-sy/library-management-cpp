#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class book
{public:char name[30],author[30],publisher[30];
float  price,no_of_copies,no_of_copies_issued;
long bookid;
void in()
{cout << '\n' << "Enter BookID, Name, Author, Publisher, Price, No. of copies, No. of copies issued = " << '\n';
    cin >> bookid;
    cin.ignore(); // Clear the newline character left in the input buffer
    cin.getline(name, sizeof(name));
    cin.getline(author, sizeof(author));
    cin.getline(publisher, sizeof(publisher));
    cin >> price >> no_of_copies >> no_of_copies_issued;
}
void out()
{cout<<'\n'<<"                  /// BOOK INFO ///                   ";
 cout<<'\n'<<" Bookid ="<<bookid<<endl;
 cout<<" Name ="<<name<<endl;
 cout<<" Author ="<<author<<endl;
 cout<<" Publisher ="<<publisher<<endl;
 cout<<" Price ="<<price<<endl;
 cout<<" No. of copies ="<<no_of_copies<<endl;
 cout<<" No.of copies issued ="<<no_of_copies_issued<<endl;
}
int get_bookid()
{return bookid;}
}b;
class member
{int bookidissued,memcode;
char address[20],email[20],memname[20],dateofissue[20],phone[20],bookissued[10];
public:void input()
{cout << '\n' << "Enter memcode, address, memname, email, phone, bookidissued, dateofissue = ";
    cin >> memcode;
    cin.ignore(); // Clear the newline character left in the input buffer
    cin.getline(address, sizeof(address));
    cin.getline(memname, sizeof(memname));
    cin.getline(email, sizeof(email));
    cin.getline(phone, sizeof(phone));
    cin >> bookidissued >> dateofissue;
}
void output()
{cout<<'\n'<<"                     /// MEMBER INFO ///                  ";
 cout<<'\n'<<" Memcode="<<memcode<<endl;
 cout<<" Address="<<address<<endl;
 cout<<" Memname="<<memname<<endl;
 cout<<" Email="<<email<<endl;
 cout<<" Phone="<<phone<<endl;
 cout<<" Bookidissued="<<bookidissued<<endl;
 cout<<" Dateofissue="<<dateofissue<<endl;
}
int get_memcode()
{return memcode;}
}m;
void show()
{ifstream x("book.dat",ios::binary);int k;
 cout<<'\n'<<"Enter bookid to show info = ";
 cin>>k;
 while(x.read((char*)&b,sizeof(b)))
 {if(k==b.get_bookid())
 b.out();}
 x.close();
 }
void mshow()
{ifstream x("member.dat",ios::app|ios::binary);int k;
 cout<<'\n'<<"Enter memcode to show info = ";
 cin>>k;
 while(x.read((char*)&m,sizeof(m)))
 {if(k==m.get_memcode())
 m.output();}
 x.close();
 }
void add()
{ofstream x("book.dat",ios::app|ios::binary);
b.in();
x.write((char*)&b,sizeof(b));
x.close();
}
void madd()
{ofstream x("member.dat",ios::app|ios::binary);
m.input();
x.write((char*)&m,sizeof(m));
x.close();
}
void copy()
{int k;
cout<<'\n'<<"Enter bookid = ";
cin>>k;
for(int i=0;i<=k;i++)
 {if(k==b.get_bookid())
 b.no_of_copies=b.no_of_copies+1;
 }
}
void modify_book_details()
{ifstream x("book.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<'\n'<<"Enter bookid to modify = ";
 cin>>a;
 while(x.read((char*)&b,sizeof(b)))
 {if(a==b.get_bookid())
 {cout<<'\n'<<"/// Enter modified data ///";
 b.in();}
 y.write((char*)&b,sizeof(b));
 }
 x.close();y.close();
 remove("book.dat");
 rename("temp","book.dat");
}
void member_modify_book_details()
{ifstream x("member.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<'\n'<<"Enter memcode to modify = ";
 cin>>a;
 while(x.read((char*)&m,sizeof(m)))
 {if(a==m.get_memcode())
 {cout<<'\n'<<"/// Enter modified data /// ";
 m.input();}
 y.write((char*)&m,sizeof(m));
 }
 x.close();y.close();
 remove("member.dat");
 rename("temp","member.dat");
}
void Delete()
{ifstream x("book.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<'\n'<<"Enter bookid to delete = ";
 cin>>a;
 while(x.read((char*)&b,sizeof(b)))
 {if(a!=b.get_bookid())
 y.write((char*)&b,sizeof(b));
 }
 x.close();y.close();
 remove("book.dat");
 rename("temp","book.dat");
}
void mDelete()
{ifstream x("member.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<'\n'<<"Enter memcode to delete = ";
 cin>>a;
 while(x.read((char*)&m,sizeof(m)))
 {if(a!=m.get_memcode())
 y.write((char*)&m,sizeof(m));
 }
 x.close();y.close();
 remove("member.dat");
 rename("temp","member.dat");
}
void issuebook()
{ifstream x("book.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<'\n'<<"Enter bookid to issue = ";
 cin>>a;
 while(x.read((char*)&b,sizeof(b)))
 {if(a==b.get_bookid())
  { b.no_of_copies_issued++;
   b.no_of_copies--;}
 y.write((char*)&b,sizeof(b));
 }
 x.close();y.close();
 remove("book.dat");
 rename("temp","book.dat");
 }
void search()
{ifstream x("book.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<'\n'<<"            /// SEARCH ///                      ";
 cout<<'\n'<<"Enter bookid to search = ";
 cin>>a;
 while(x.read((char*)&b,sizeof(b)))
 {if(a==b.get_bookid())
  {b.out();}
 }
 x.close();y.close();
 }
void msearch()
{ifstream x("member.dat",ios::binary);
 ofstream y("temp",ios::binary);
 int a;
 cout<<"            /// MEMBER SEARCH ///               ";
 cout<<"Enter bookid to search = ";
 cin>>a;
 while(x.read((char*)&m,sizeof(m)))
 {if(a==m.get_memcode())
  {m.output();}
 }
 x.close();y.close();
}
int main()
{int z;
cout<<'\n';
cout<<'\t'<<'\t'<<"///**************************************///";
cout<<'\n'<<'\t'<<'\t'<<"///*           //  MAIN MENU  //        *///";
cout<<'\n'<<'\t'<<'\t'<<"///**************************************///";
cout<<'\n'<<'\n'<<'\n'<<"MADE BY:Gyan singh yadav";
cout<<'\n'<<'\n'<<'\t';
cout<<"PRESS ANY TKEY TO CONTINUE .....";
cin.get();

do{cout<<'\n'<<'\t'<<"/////////////////////    Enter choice    /////////////////////"<<endl;
   cout<<'\n'<<"1. Add"<<'\n'<<"2. Copy"<<'\n'<<"3. Member add";
   cout<<'\n'<<"4. Modify book details"<<'\n'<<"5. Member modify book details";
   cout<<'\n'<<"6. Search"<<'\n'<<"7. Member search"<<'\n'<<"8. Delete";
   cout<<'\n'<<"9. Member delete"<<'\n'<<"10. Issue book"<<'\n'<<"11. Show book info";
   cout<<'\n'<<"12. Show member info"<<'\n'<<"13.Exit ";
   cout<<'\n'<<'\n'<<" ENTER CHOICE == ";
 cin>>z;
 switch(z)
  {case 1:add();break;
   case 2:copy();break;
   case 3:madd();break;
   case 4:modify_book_details();break;
   case 5:member_modify_book_details();break;
   case 6:search();break;
   case 7:msearch();break;
   case 8:Delete();break;
   case 9:mDelete();break;
   case 10:issuebook();break;
   case 11:show();break;
   case 12:mshow();break;
   case 13:break;}
   }while(z!=13);
   return 0;
}
