#include <iostream>
#include "vector"


bool inRange(int val,int range){
    if (val>=0&&val<=range) return true;
    else {
        std::cout << "Not in range. Try again!"<< std::endl;
        return false;
    }
}
std::vector<std::vector<int>> inputMatrix(std::string prompt,int size){
    std::cout << prompt;
    std::vector<std::vector<int>> a(size);
    for (int i=0;i<a.size();++i){
        a[i].resize(size);
        for(int k=0;k<a[i].size();++k){
            do {
                std::cout << "["<<i<<"]["<< k<<"]:";
                std::cin >> a[i][k];
            }while(!inRange(a[i][k],9));
        }
    }
return a;
}
int inputInt(std::string prompt,int range){
    int val;
    do {
        std::cout << prompt;
        std::cin >> val;
        if (val==-1) return -1;
    } while (!inRange(val,range));
    return val;
}

void printSlice(std::vector<std::vector<int>> a,int slice) {
    if (slice >= 0 && slice < 10) {
        for (int i = 0; i < a.size(); ++i) {
            for (int k = 0; k < a[i].size(); ++k)
                std::cout << (a[i][k]>=slice?"1":"0") << " ";
            std::cout << std::endl;
        }
    }
}


int main() {
    std::vector<std::vector<int>> heights = inputMatrix("Input heights 5x5:\n",5);
    int slice=0;
    while(slice!=-1) {
        slice =inputInt("Input slice (-1 for exit)[0..9]:",9);
        if (slice==-1) break;
        printSlice(heights, slice);
    }
}
