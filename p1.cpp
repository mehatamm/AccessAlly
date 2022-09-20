#include <iostream>
using namespace std;
int main(){
	int d;
	cin >> d;
	int h=12;
	int m1=0;
	int m2=0;
	int count=0;
	if(d>720){
		count+= (d/720)*31; //hardcoded number of sequences in 12h
		d=d%720;
	}
	while(d>=0){
		if(h>=10){
			if(1-(h%10)==h%10-m1 && h%10-m1==m1-m2){
				++count;
				//cout << h << m1 << m2 << endl;
			}
		}
		else if(h-m1==m1-m2){
			++count;
			//cout << h << m1 << m2 << endl;
		}
		++m2;
		if(m2==10){
			m2=0;
			++m1;
			if(m1==6){
				m1=0;
				++h;
				if(h==13){
					h=1;
				}
			}
		}
		--d;
	}
	cout << count;
}