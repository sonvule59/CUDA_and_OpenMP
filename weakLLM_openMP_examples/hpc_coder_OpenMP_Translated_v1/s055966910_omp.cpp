#include <iostream>
#include <omp.h>
using namespace std;

int main(){

	int Num;
	int SubNum;
	#pragma omp parallel for private(SubNum)
	for(Num=1;Num<10;Num++)
	{for(SubNum=1;SubNum<10;SubNum++){
	cout<<Num<<"x"<<SubNum<<"="<<Num*SubNum<<endl;
	}}

return 0;
}