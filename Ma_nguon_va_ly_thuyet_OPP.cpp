#include<iostream>
using namespace std;

//lop truu tuong
class Borrowable {
public:
virtual void borrow() = 0;
virtual void returnItem() = 0;
virtual bool isAvailable() const = 0;
virtual ~Borrowable() = default;
};

//Lop book
class Book : public Borrowable{
	private:
		std:string title;
		std:string author;
		std:string ISBN;
		bool available;
	
	public:
	    Book(std::string t, std::string a, std::string i):title(std::move(t)), authour(std::move(a)),ISBN(std::move(i)),available(true){}
		
		void brrow() override{
		   if (available){
		   	available=false;
		   	std::cout<<"Sach "<<title<<"da duoc muon."<<std::endl;
		   else{
		   	std::cout<<"sach "<<title<<"K=khong có san de muon."<<std::endl;
		   }	
		}
		
		void returnItem() override{
		   available=true;
		   std::cout<<"sach "<<title<<"da duoc tra lai."<<std::endl;
		}
		
		bool isAvailable() const override{
		  return available;
		  
		} 
		
		std::string getTitle() const {return title;}
		std::string getAuthor() const {return author;} 
		std::string getISBN() const {return ISBN;}
	};
	
//lop DVD
class DVD : public Borrowable {
	private: 
	   std:string title;
	   std:string director;
	   int duration;
	   bool available;
	   
	public:
	   DVD(std::string t, std::string d,int dur):title(std::move(t)),director(std::move(d)),duration(dur),available(true){}
};

//Lop Library

class Library{
private:
    std::vector<std::unique_ptr<Borrowable>>items;

public:
    void addItem(std::unique_ptr<Borrowable>item){
	    items.push_back(std::move(item));
	}
	
	void borrowItem(const std::string& title){
		auto it=std::find_if(items.begin(),items.end(),[&title](const auto& item){
		if(auto book=dynamic_cast<Book*>(item.get())){
		    return book->getTitle()==title;
		}
		if (auto dvd= dynamic_cast<DVD*>(item.get())){
		    return dvd->getTitle()==title;
		}
		  return false;
	});
	
	if(it != items.end()){
		(*it)->borrow();
	}
	else{
		std::cout<<"khong tim thay muc"<<title<<"trong thu vien"<<std::endl;
		
	
	}
}	
	  	  		
	
	
	
	
	
	
	
	
	
	
				
};	      
















int main(){


    return 0;
}


