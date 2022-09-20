#include <iostream>
using namespace std;
int main(){
	int blood[2][4];
	int patients[2][4];
	for(int i=0;i<4;++i){
		cin >> blood[0][i];
		cin >> blood[1][i];
	}
	for(int i=0;i<4;++i){
		cin >> patients[0][i];
		cin >> patients[1][i];
	}
	int sat=0;
	for(int k=0;k<2;++k){
	for(int i=0;i<4;++i){
			int ai=i;
			int ak=k;
			while(ai>=0){
				if(!(i==2 && ai==1)){ //avoid type a going to b
					if(blood[ak][ai] <= patients[k][i]){ //more patients than blood
						patients[k][i]-=blood[ak][ai];
						sat+=blood[ak][ai];
						blood[ak][ai]=0;
					}
					else{ //more blood than patients
						sat+=patients[k][i];
						blood[ak][ai]-=patients[k][i];
						patients[k][i]=0;
					}
				}
				--ai;
				if(ai==-1 && ak==1){ //dip into negative pool from positive
					ai=i;
					ak=0;
				}
			}
		}
	}
	cout << sat << endl;
}