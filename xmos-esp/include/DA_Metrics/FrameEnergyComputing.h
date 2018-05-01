/** @file */

#ifndef FRAMEENERGYCLASS_H
#define FRAMEENERGYCLASS_H

#include "common/fixed_pt.h"

/**
 * An Amazon AVS SDK compatible interface class to the XMOS Echo Spatial Perception library that 
 * runs directly on the Vocalfusion device. This class provides a C++ wrapper around the XMOS
 * lib-esp library specifically to allow direct linking to the Amazon Alexa Voice Service SDK and 
 * has been tested with version 1.6 of that SDK.
 */
class FrameEnergyClass
{
public:
    /**
     * This method invokes I<SUP>2</SUP>C startup code. Calls to other methods before this method 
     * has been called are likely to yield incorrect results. 
     * \param frameSize is ignored as the library only supports 8ms frames (128 samples 
     * at 16k Samples/s).
     */
    FrameEnergyClass(unsigned int frameSize);

    /**
     * This method closes I<SUP>2</SUP>C link. Calls to other methods after the destructor has 
     * been called are likely to fail or give incorrect results.
     */
    ~FrameEnergyClass();

    /**
     * The process function is unused and data sent to it
     * is discarded. The XMOS ESP software on the vocalfusion device takes energy values 
     * and voice detection indicators direct from the modified Amazon reference code also 
     * running on the deivce.
     * \param GVAD is intended by the Amazon SDK to indicate that voice activity has been 
     * detected. However, since the XMOS Vocalfusion device calculates voice activity 
     * directly, this parameter is ignored.
     * \param currentFrameEnergy is the calculated energy in the current frame of audio 
     * samples. As the energy is calculated within the XMOS Vocalfusion device's ESP 
     * processing block, this value is ignored.
     */
    void process(const bool GVAD, const Word64 currentFrameEnergy);

    /**
     * The block reset method is ignored by the XMOS VocalFusion board.
     */
    void blkReset(void);

    /**
     * Get level of audio energy in the ambient environment from the XMOS VocalFusion board via the I<SUP>2</SUP>C link.
     * \return The energy value as a 32 bit signed integer. The algorithm used is a statically allocated memory version of the Amazon reference design for Echo Spatial Perception.
     */
    int getAmbientEnergy(void);

    /**
     * Get the energy associated with detected speaking from the XMOS VocalFusion board via the I<SUP>2</SUP>C link.
     * \return The energy value as a 32 bit signed integer. The algorithm used is a statically allocated memory version of the Amazon reference design for Echo Spatial Perception.
     */
    int getVoicedEnergy(void);
};

#endif // FRAMEENERGYCLASS_H
