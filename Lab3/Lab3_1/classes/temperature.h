#include "mbed.h"
// temperature class
class TMP36{
    public:
        TMP36(PinName pin);
        TMP36();
        float read(){
            return ((_pin.read()*3.3)-0.500)*100.0;
        }
    private:
        AnalogIn _pin;
};