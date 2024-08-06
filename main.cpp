#include "solution.hpp"

using namespace std;

int main(){

	//CODIGO INTELIGENTE DE ORDEN MULTIPLE
	vector<string> orders={"neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"};
	vector<vector<int>> grid={{0,1,2},{3,4,5},{6,7,8}};
	vector<int> output;
	vector<int> values={0,1,4,4,8};
	neighborSum* obj=nullptr;

	for(int i=0; i<orders.size(); i++){
		if(orders[i]=="neighborSum"){
			obj=new neighborSum(grid);
			output.push_back(-1);
		}
		if(orders[i]=="adjacentSum"){
			int param_1=obj->adjacentSum(values[i]);
			output.push_back(param_1);
		}
		if(orders[i]=="diagonalSum"){
			int param_2=obj->diagonalSum(values[i]);
			output.push_back(param_2);
		}
	}

	cout<<"ANSWER = "<<endl;
	for(int i=0; i<output.size(); i++){
		if(output[i]==-1){
			cout<<"null, ";
		}else{
			cout<<output[i]<<", ";
		}
	}
	cout<<endl;

	delete obj;

	return 0;
}