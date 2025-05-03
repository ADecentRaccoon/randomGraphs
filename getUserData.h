#ifndef GETUSERDATA
#define GETUSERDATA

struct UsersData{
    short int typeOfModel;
    float PorVec;
    int unsigned nodes;
};

UsersData getUserRequest();

#endif