#include <iostream>
#include <stdint.h>
using namespace std;

class DiaStackLatencyStats
{
public:
    uint32_t maxAnsLatency;
    static uint32_t curAnsLatency;
};

uint32_t DiaStackLatencyStats::curAnsLatency;

int main()
{
    DiaStackLatencyStats dia;
    dia.maxAnsLatency = 100;
    dia.curAnsLatency = 120;
    
    cout << dia.maxAnsLatency << endl;
    cout << dia.curAnsLatency << endl;

    return 0;
}
