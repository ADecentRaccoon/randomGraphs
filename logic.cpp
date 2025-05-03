// #include "getUserData.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<pair<int, int>> createGnp(int quantityOfNodes, float probability){
    vector<pair<int, int>> ans;
    srand(time(0));
    for(int i = 0; i < quantityOfNodes; i++){
        for(int p = i + 1; p < quantityOfNodes; p++){
            float prob = static_cast<float>(rand()) / RAND_MAX;
            if (prob > probability){
                ans.push_back(make_pair(i, p));
            } else continue;
        }
    }
    return ans;
}

vector<pair<int, int>> createGnm(int quantityOfNodes, int quantityOfEdges){
    vector<pair<int, int>> ans;
    for(int i = 0; i < quantityOfNodes; i++){
        for(int p = i + 1; p < quantityOfNodes; p++){
            ans.push_back(make_pair(i, p));
        }
    }
    random_device rd;
    mt19937 gen(rd());

    shuffle(ans.begin(), ans.end(), gen);

    vector<pair<int, int>> selectedEdges(ans.begin(), ans.begin() + quantityOfEdges);
    return selectedEdges;
}




void printVector(const std::vector<pair<int, int>>& vec) {
    for (const pair<int, int>& val : vec) {
        std::cout << "(" << val.first << ", " << val.second << ") ";
    }
    std::cout << std::endl;
}

int main(){
    vector<pair<int,int>> gnp = createGnp(7, 0.5);
    printVector(gnp);
    cout << '\n';
    vector<pair<int,int>> gnm = createGnm(7, 3);
    printVector(gnm);
    return 0;
}