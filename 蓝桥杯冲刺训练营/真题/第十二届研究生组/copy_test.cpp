#include <iostream>
#include <cstring>
using namespace std;

void print_arr(string arr_name, int* a, int len){
    cout << arr_name << ":" << endl;
    for (int i = 0; i < len; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr1[] = {1,2,3,4,5};
    int arr2[] = {0,0,0,0,0};
    int arr3[] = {0,0,0,0,0};

    print_arr("arr1", arr1, 5);
    print_arr("arr2", arr2, 5);

    // //copy begin, end
    // copy(begin(arr1),end(arr1), begin(arr2));
    // print_arr("arr1", arr1, 5);
    // print_arr("arr2", arr2, 5);

    // //copy begin+x
    // copy(begin(arr1), begin(arr1)+3, begin(arr2));
    // print_arr("arr1", arr1, 5);
    // print_arr("arr2", arr2, 5);

    // //copy arr+len
    // copy(arr1, arr1+3, arr2);
    // print_arr("arr1", arr1, 5);
    // print_arr("arr2", arr2, 5);

    // //memcpy
    // memcpy(arr2, arr1, 3*sizeof(int));
    // print_arr("arr1", arr1, 5);
    // print_arr("arr2", arr2, 5);

    //memmove
    memmove(arr1+2, arr1+1, 3*sizeof(int));
    print_arr("arr1", arr1, 5);
    print_arr("arr2", arr2, 5);


    return 0;
}