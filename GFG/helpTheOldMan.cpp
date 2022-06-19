

//n is number of plate and m is the mth move. we need to print the mth move is from which rod to which rod
#include<iostream>
using namespace std;
static int c, m;
void towerOfHanoi(int n, int r1, int r2, int r3){
     if(n == 0)
        return;
    towerOfHanoi(n - 1, r1, r3, r2); //move from_rod to aux_rod using to_rod
    c++;
    if(m == c){
        cout << r1 << " " << r2 << endl;
    }
    towerOfHanoi(n-1, r3, r2, r1);// move aux_rod to to_rod using from_rod
}

int main(){
    int c = 0;
    m = 4;
    towerOfHanoi(3, 1, 3, 2);// toh(move, from_rod, to_rod, aux_rod)
    return 0;
}