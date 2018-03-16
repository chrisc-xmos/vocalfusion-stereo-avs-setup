#ifndef FRAMEENERGYCLASS_H
#define FRAMEENERGYCLASS_H

#define Word16 int16_t
#define Word64 int64_t

class FrameEnergyClass
{
public:
    // constructor with framelength passed
    FrameEnergyClass(unsigned int);

    ~FrameEnergyClass();

    // process function
    void process(const bool, const Word64);

    // block reset function
    void blkReset(void);

    // Get Ambient Energy
    int getAmbientEnergy();

    // Get Voiced Energy
    int getVoicedEnergy();
};

#endif // FRAMEENERGYCLASS_H