#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    try {
      cout << "Before throwing exception" << endl;
    //   throw 42;
      cout << "Shouldn't ever see this" << endl;
    }  

    catch( int error ) {
      cout << "Error: caught exception " << error << endl;
    }

    return 0;
}