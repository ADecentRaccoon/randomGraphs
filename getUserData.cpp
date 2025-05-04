#include <iostream>
#include <cstdlib>
using namespace std;

struct UsersData{
    short int typeOfModel;
    float PorVec;
    int unsigned nodes;
};

UsersData getUserRequest() {
    UsersData datauser;
    cout << "Select type of model:\n";
    cout << "G(n,p)[1]" << '\t' << "G(n,m)[2]" << '\t' << "Demo[3]\n";
    cout << "Ender number of model: ";
    cin >> datauser.typeOfModel;
    if (datauser.typeOfModel == 1){
        cout << "Enter probability (0 <= P <= 1): ";
        cin >> datauser.PorVec;
    }else if (datauser.typeOfModel == 2)
    {
        cout << "Enter number of edges (m): ";
        cin >> datauser.PorVec;
    }else if (datauser.typeOfModel == 3){
        return datauser;
    }else{
        cout << "Wrong number.\n";
        exit(0);
    }
    cout << "Enter quantity of nodes: ";
    cin >> datauser.nodes;
    return datauser;
}
