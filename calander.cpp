// this program is designed to convert gergorian calender to ethiopian calender
#include<iostream>
using namespace std;
int main()
{
		cout<< "*******well come to calander conversion system in c++ @ 2018************* "<<endl; 
		int monthett,mon,dy,donthett;;//dy=gergorian day & mon = gergorian month & monthett= month in ethiopia
		cout<<"\t\t out put format";
		cout<<"\t\tDD/MM/YYYY E.c:"<<endl;//where DD=Day  MM=month YYYY E.c=Year in Ethiopia
		cout<<endl;
		cout<< "list of Gergorian month's'"<<endl;
		cout<<"1. january\t\t"; cout<<"2. February\t\t";cout<<"3. march\t\t"<<endl;
		cout<<"4. April\t\t";  cout<<"5. may\t\t" ; cout<<"\t6. june\t\t"<<endl;
		cout<<"7. july\t\t";  cout<<  "\t8. August\t\t"; cout<<"9. september\t\t"<<endl;
		cout<<"10. october\t\t"; cout<<"11. November\t\t"; cout<<"12. december\t\t"<<endl;
		top:
		cout<<"enter   month in Gergorian Calander provided Above(in number) =";
		cin>>mon;
switch(mon)
{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	monthett=mon+4;
	break;
	case 9:
	case 10:
	case 11:
	case 12:
	monthett=mon-8;
	break;
	default:
	cout<<"please enter the correct month!!"<<endl;
	goto top;
}
head:
 cout<<"please enter Gergorian  day   = ";
 cin>>dy;
if(mon==1)
{

if(dy<1||dy>31)//month one(january) has 31 days
{
cout<<"invalid day is entered!"<<endl;
goto head;
}
else if(dy>=1&&dy<=8)
{
donthett=dy+22;
}
  else if(dy>8&&dy<=31)
{
donthett=dy-8;
}
}
 if(mon==2)//month two has 28 days
 {
 	if(dy<1||dy>28)
 	{
 		cout<<"invalid day is entered!"<<endl;
 		goto head;
	 }
  else if(dy>=8&&dy<=28)
{
donthett=dy-7;
}
else if(dy>=1&&dy<=7)
{
donthett=dy+23;
}
}
 if(mon==3||mon==12)//month three and month 12  has 31 days
 {
 if(dy<1||dy>31)
 {
 	cout<<"invalid day is entered!"<<endl;
 	goto head;
 }
  else if(dy>=10&&dy<=31)
{
donthett=dy-9;
}
else if(dy>=1&&dy<=9)
{
donthett=dy+21;
}
}
 if(mon==4)//month four has 30 days
 {
 	if(dy<1||dy>30)
 	{
 			cout<<"invalid date is entered!"<<endl;
 			goto head;
	 }
  else if(dy>=9&&dy<=30)
{
donthett=dy-8;
}
else if(dy>=1&&dy<=8)
{
donthett=dy+22;
}
}
if(mon==5)//month five has 31 days
 {
 	if(dy<1||dy>31)
 	{
 		cout<<"invalid day is entered"<<endl;
 		goto head;
	 }
  else if(dy>=9&&dy<=31)
{
donthett=dy-8;
}
else if(dy>=1&&dy<=8)
{
donthett=dy+22;
}
}
if(mon==6)//month six has 30 days
{

 if(dy<1||dy>30)
 {
 	cout<<"invalid day is entered"<<endl;
 		goto head;
 }
 else if(dy>=8&&dy<=30)
{
donthett=dy-7;
}
else if(dy>=1&&dy<=7)
{
donthett=dy+23;
}
}
if(mon==7)//month seven has 31 days
 {
 	 if(dy<1||dy>31)
 {
 	cout<<"invalid day is entered"<<endl;
 		goto top;	
 }
  else if(dy>=8&&dy<=31)
{
donthett=dy-7;
}
else if(dy>=1&&dy<=7)
{
donthett=dy+23;
}
}
if(mon==8)//month eight has 31 days
 {
 	 if(dy<1||dy>31)
 {
 	cout<<"invalid day is entered"<<endl;
 		goto head;	
 }
 else if(dy>=7&&dy<=31)
{
donthett=dy-6;
}
else if(dy>=1&&dy<=6)
{
donthett=dy+24;
}
}
if(mon==9)//month nine has 30 days
 {
 	 if(dy<1||dy>30)
 {
 	cout<<"invalid day is entered"<<endl;
 		goto head;	
 }
  else if(dy>=6&&dy<=10)
{
donthett=dy-5;
}
else if(dy>=11&&dy<=30)
{
donthett=dy-10;
}
else if(dy>=1&&dy<=7)
{
donthett=dy+25;
}
}
if(mon==10)//month ten  has 31 days
 {
 	 if(dy<1||dy>31)
 {
 	cout<<"invalid day is entered"<<endl;
 			goto head;	
 }
  else if(dy>=11&&dy<=31)
{
donthett=dy-10;
}
else if(dy>=1&&dy<=10)
{
donthett=dy+20;
}
}
if(mon==11)//month Eleven has 30 days
 {
 	 if(dy<1||dy>30)
 {
 	cout<<"invalid day is entered"<<endl;
 			goto head;
 }
 else if(dy>=10&&dy<=30)
{
donthett=dy-9;
}
else if(dy>=1&&dy<=9)
{
donthett=dy+21;
}
}
 int Gc,Ec;//where GC=Gergorian  calander Year   Ec=Ethiopian  calander Year 
 cout<<"enter year in Gergorian[>=1753]==";
 cin>>Gc;
 Ec=Gc-8;
 if(Gc<=1753)
 {
 cout<<"error";
 return 0;
}
  cout<<"lists of Ethiopian calender month's"<<endl;
 cout<<"##############################################################"<<endl;

 cout<<"1. september\t\t"; cout<<"2. october\t\t";cout<<"3. November\t\t"<<endl;
     cout<<"4. december\t\t";  cout<<"5.  january\t\t" ; cout<<"6. February\t\t"<<endl;
   cout<<" 7. march\t\t";  cout<<  "8. April\t\t"; cout<<"9.  may\t\t"<<endl;
   cout<<"10.june\t\t"; cout<<"      11. july\t\t";   cout<<"       12. August\t\t"<<endl;
    cout<<"##############################################################"<<endl;
   cout<< "the over all calander will be";
   cout<<"------------------>";
 cout<<donthett<<"/"<<monthett<<"/"<<Ec<<"E.c"<<endl;
 std::string choice;
 
 	for (int i = 0;; i++) {
 		cout << "do you want to continue [y\\n]: \n";
 		cin >>choice;
 		if (choice != "y" && choice != "Y" && choice != "n" && choice != "N") {
 			cout << "please enter the correct input : \n";
 			
		 }
		 else if (choice == "n" || choice == "N")
		 {
		 }
		 //exit(1);
		 else
		 	goto top;
		 
	 }
}




