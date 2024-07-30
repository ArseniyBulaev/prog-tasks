#include<iostream>
#include<algorithm>

int uniformPartition(int x, int y){

    int min_side;
    int max_side;

    if (x> y){
        max_side = x;
        min_side = y;
    }
    else{
        max_side = y;
        min_side = x;
    }
    
    if (max_side % min_side == 0){
        return min_side;
    }

    return uniformPartition(min_side, max_side%min_side);
}

int main(){

    int x = 400, y = 640;
    std::cout << uniformPartition(x, y);
    return 0;
}