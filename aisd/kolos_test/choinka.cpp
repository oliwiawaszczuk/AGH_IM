#include <iostream>
using namespace std;

void choinka(int N) {
    char znak1 = '=', znak2 = '*';
    char znakTeraz = znak2;
    for (int i=N; i>0; i--) {
        for (int j=0; j<N-i+1; j++) {
            cout << znakTeraz;
        }
        znakTeraz = (znakTeraz == znak1) ? znak2 : znak1;
        cout << endl;
    }
}

int main() {
    choinka(5);
    return 0;
}
