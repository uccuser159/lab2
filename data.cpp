#include "data.h"
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


double data::cbmi(){ 
	
	return mass/pow(height,2); 
}

void data::get(){	
	
	string ch;
		
	ifstream inFile("file.in",ios::in);
	if(!inFile){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
			
	getline(inFile,ch);

	while(ch!="0 0")
	{
		
		height = stod(ch.substr(0,ch.find_first_of(" ",0)));  //找空白並將字串改成double形式
		
		height/=100; //轉換公尺

		mass=stod(ch.substr(ch.find_first_of(" ",0),ch.length()));

		getline(inFile,ch);

		cout << fixed<< setprecision(2) << cbmi() << '\t' << category(cbmi()) << endl; 
	
		set();
		}
        

	       	}

string data::category(double a) {
			if(a<15){
				return "Very severely underweight";
			}
			else if(a>=15 && a<16){
				return "Severely underweight";
			}
			else if(a>=16 && a<18.5){
				return"Underweight";
			}
			else if(a>=18.5 && a<25){
				return"Normal";
			}
			else if(a>=25 && a<30){
				return"Overweight";
			}
			else if(a>=30 && a<35){
				return"Obese Class I(Moderately obese)";
			}
			else if(a>=35 && a<40){
				return"Obese Class II(Severely obese)";
			}
			else {
				return"Obese Class III(Very severely obese)";
			}
		}



void data::set(){ 	

		ofstream outFile("file.out",ios::app);
		if(!outFile){
			cerr<<"Failed opening"<<endl;
			exit(1);
		}
		
		//限制只顯示小術後兩位的BMI值
		outFile << fixed << setprecision(2) << cbmi() << '\t' <<category(cbmi()) << endl; 
		
		}
