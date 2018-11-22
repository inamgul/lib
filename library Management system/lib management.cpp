#include<iostream>
#include<fstream>
#include<string.h>


using namespace std;
void objfilling();

class book{
	private:
		char bookname[20];
		char publisher[20];
		int edition;
	public:
		book(){
			
		}
		book(char bknam[20],char pushr[20],int edi){
			strcpy(bookname,bknam);
			strcpy(publisher,pushr);
			edition=edi;
		}
		
		int fedition(){
			return edition;
		}
		char *fbookname(){
			return bookname;
		}
		char *fpushr(){
			return publisher;
		}
		void print(){                                      //printing book name,publisher,edition of book...
			cout<<"book name:"<<bookname<<endl;
			cout<<"publisher name:"<<publisher<<endl;
			cout<<"edition:"<<edition<<endl;
		}
}; 
class type:public book{
	private:
		char booktype[20];
	public:
		type(){
			
		}
		type(char bknam[20],char pushr[20],int edi,char bktype[20]):book(bknam,pushr,edi){
			strcpy(booktype,bktype);
		}
		char *fbooktype(){
			return booktype;
		}
		void print(){
			cout<<"book type:"<<booktype<<endl;
			book::print();
		}
};
class fiction:public type{
	private:
		char level;
	public:
		fiction(){
		}
		fiction(char bknam[20],char pushr[20],int edi,char bktype[20],char lvl):type(bknam,pushr,edi,bktype){
			level=lvl;
		}
		char flevel(){
			return level;
		}
		void print(){
			cout<<"level:"<<level<<endl;
			type::print();
		}
};
class nonfiction:public type{
	private:
		char catagory[20];
	public:
		nonfiction(){
			
		}
		nonfiction(char bknam[20],char pushr[20],int edi,char bktype[20],char cat[20]):type(bknam,pushr,edi,bktype){
			strcpy(catagory,cat);
		}
		char *fcatagory(){
			return catagory;
		}
		void print(){
			cout<<"catagory:"<<catagory<<endl;
			type::print();
		}
};
int main(){

	objfilling();
}
void objfilling(){
	char bnfc[20]={"where the things"};             //fiction book1...
	char pbfc[20]={"m sendak"};
	char tfc[20]={"fiction"};
	fiction f1(bnfc,pbfc,1,tfc,'c');
	char bnfa[20]={"where the things1"};            //fiction book2....    
	char pbfa[20]={"m sendak"};
	char tfa[20]={"fiction"};
	fiction f2(bnfa,pbfa,1,tfa,'a');
	char bnnfm[20]={"where the things2"};            //non fiction book1...
	char pbnfm[20]={"m sendak"};
	char tnfm[20]={"fiction"};
	nonfiction nf1(bnnfm,pbnfm,1,tnfm,"Maths");
	char bnnfu[20]={"where the things2"};             //nonfiction book2...
	char pbnfu[20]={"m sendak"};
	char tnfu[20]={"fiction"};
	nonfiction nf2(bnnfu,pbnfu,1,tnfu,"urdu");
	char bnnfs[20]={"where the things"};             //nonficition book3...
	char pbnfs[20]={"m sendak"};
	char tnfs[20]={"fiction"};
	nonfiction nf3(bnnfs,pbnfs,1,tnfs,"science");
	
	fstream fil;
	fil.open("inam.dat",ios::out|ios::in|ios::binary);
	fil.write(reinterpret_cast<char*>(&f1),sizeof(f1));
	f1=f2;
	fil.write(reinterpret_cast<char*>(&f1),sizeof(f1));
	fstream file;
	file.open("binary.txt",ios::out|ios::in|ios::binary);
	file.write(reinterpret_cast<char*>(&nf1),sizeof(nf1));
	nf1=nf2;
	file.write(reinterpret_cast<char*>(&nf1),sizeof(nf1));
	nf1=nf3;
	file.write(reinterpret_cast<char*>(&nf1),sizeof(nf1));
	fil.seekg(0);
	for(int i=0;i<2;i++){
	fil.read(reinterpret_cast<char*>(&f1),sizeof(f1));
	f1.print();
	}
	file.seekg(0);
	for(int i=0;i<3;i++){
		file.read(reinterpret_cast<char*>(&nf1),sizeof(nf1));
		nf1.print();
	}
	fil.close();
	file.close();
}
