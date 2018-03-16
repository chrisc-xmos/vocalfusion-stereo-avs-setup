/* VAD_class.h
 *
 * Not required on host side in XMOS implementation. Minimal stub set required to make Amazon example compile
 */
#ifndef VADCLASS_H
#define VADCLASS_H


#define Word16 int16_t
#define Word64 int64_t

class VADClass
{
public:

    // constructor with framelength passed
    VADClass(unsigned int);

    ~VADClass();

     // process function
    void process(Word16*, bool&, Word64);

    // VAD block reset function
    void blkReset(void);
};

#endif // VADCLASS_H