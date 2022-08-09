#include <iostream>
using namespace std;

int main(){

    int arr[5] = {300,350,200,400,250};
    int max = arr[0];

    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    {
        if (max < arr[i+1])
        {
            max = arr[i+1];
        }
        
    }
    
    cout << "小猪最重为：" << max << endl;

    return 0;
}