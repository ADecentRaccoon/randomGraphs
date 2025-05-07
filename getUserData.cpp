#include <iostream>
#include <cstdlib>
#include <cmath>
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
    if (datauser.typeOfModel == 1)
    {
        cout << "Enter quantity of nodes: ";
        cin >> datauser.nodes;

        cout << "Enter probability (0 <= P <= 1): \t" << "connectivity threshold: " <<log(datauser.nodes)/datauser.nodes << endl;
        cin >> datauser.PorVec;
    }else if (datauser.typeOfModel == 2)
    {
        cout << "Enter quantity of nodes: ";
        cin >> datauser.nodes;

        cout << "Enter number of edges (m): \t" << "connectivity threshold: " << datauser.nodes * log(datauser.nodes)/2 << endl;
        cin >> datauser.PorVec;
    }else if (datauser.typeOfModel == 3){
        return datauser;
    }else{
        cout << "Wrong number.\n";
        exit(0);
    }
    return datauser;
}
