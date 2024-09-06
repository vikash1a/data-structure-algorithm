#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(int k: v){
        cout<<k;
    }cout<<endl;
}

vector<int> convertToBinary(int n){
    int count = 32;
    vector<int> bitV(32,0);
    while(count--){
        int lastBit = n&1;
        bitV[count] = lastBit;
        n = n>>1;
    }
    return bitV;
}

bool isEven(int n){
    return !(n&1);
}

int multiplyBy2(int n) {
    return n << 1;
}

int divideBy2(int n) {
    return n >> 1;
}

int setBit(int n, int position) {
    return n | (1 << position);
}

int clearBit(int n, int position) {
    return n & ~(1 << position);
}

int toggleBit(int n, int position) {
    return n ^ (1 << position);
}

bool isBitSet(int n, int position) {
    return (n & (1 << position)) != 0;
}

int rightmostSetBit(int n) {
    return n & -n;
}

bool oppositeSign(int a, int b) {
    return (a ^ b) < 0;
}


int main() {
    int n = 34;
    // vector<int> binV = convertToBinary(n);
    // print(binV);
    // n = setBit(n, 34);
    // print(convertToBinary(n));
    print(convertToBinary(34));
    print(convertToBinary(-34));
    std::cout << "Hello World!\n";
}