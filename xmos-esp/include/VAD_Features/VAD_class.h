/** @file */

#ifndef VADCLASS_H
#define VADCLASS_H

#include "common/fixed_pt.h"

/**
 *
 * An Amazon Alexa Voice Service (AVS) SDK compatible interface class to the XMOS Echo Spatial 
 * Perception (ESP)library that runs directly on the Vocalfusion device. This class provides a 
 * C++ stub for methods that the Amazon AVS SDK assumes will be present in an ESP implementation. 
 * Since the XMOS vocalfusion implementation runs on the vocalfusion device rather than the host 
 * these methods are all stubs and do not cause any operations within the library. They are 
 * provided only to permit use of the library with an unmodified Amazon AVS SDK and have been 
 * tested with version 1.6 of that SDK.
 */
class VADClass
{
public:

    /**
     * This method does nothing for reasons explained above. 
     * \param frameSize is ignored as the library only supports 8ms frames (128 samples 
     * at 16k Samples/s).
     */
    VADClass(unsigned int frameSize);

    /**
     * Destructor. This method does nothing for reasons explained above.
     */
    ~VADClass();

    /**
     * This method does nothing for reasons explained above. In the Amazon AVS implementation,
     * this method computes the energy contained in the frame and 
     * \param sampleBuffer a set of signed 16 bit samples to process. The XMOS ESP library 
     * library does not use these samples as it sources the audio from earlier in the signal
     * path.
     * \param voiceActivityDetected this variable is NOT updated by the XMOS ESP library as 
     * the Amazon AVS SDK (v1.6) uses this solely for updating values within the 
     * frameEnergyComputing class object which is also implemented on the Vocalfusion device.
     */
    void process(Word16* sampleBuffer, bool& voiceActivityDetected, Word64& frameEnergy);

    /**
     * The block reset method is ignored by the XMOS VocalFusion board.
     */
    void blkReset(void);
};

#endif // VADCLASS_H
