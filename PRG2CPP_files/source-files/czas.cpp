#include <iostream>
#include <cmath>         // sin, cos
#include <sys/timeb.h>   // ftime
using namespace std;

int main() {
    timeb start, teraz;
    double res = 0;

    ftime(&start);

    for (int i = 0; i <= 90000000; ++i) {
        if (i%10000000 == 0) {
            ftime(&teraz);
            time_t sec = teraz.time - start.time;
            int msec = teraz.millitm;
            msec -=  start.millitm;
            if (msec < 0) {
                --sec;
                msec += 1000;
            }
            cout << "Po " << i << " iteracjach: "
                 << sec << "s and " << msec << "ms\n";
        }
        res = cos(res+sin(i));
    }
    cout << "Bezuzyteczny wynik: " << res << endl;
}
