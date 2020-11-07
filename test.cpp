#include <iostream>
using namespace std;

bool isalphaNum(char c) {
    return (c>= '0' && c <= '9') ;
}

int myAtoI(char arr[]) {

int i = 0;

bool flag = false;

if (arr[i] == '-') {
    i++;
    flag = true;
}

int res = 0;
for (; arr[i] ; i++) {

if(isalphaNum(arr[i])) {
        res = res*10 + arr[i] - '0';
}
else
{
    cout << "invalid";
    break;
}


}

if(flag) {
    res = 0 - res;
}

return res;

}


int main() {

    char arr[] = "-1231";
    int ans = myAtoI(arr);
    cout << ans << endl;

    return 0;
}


