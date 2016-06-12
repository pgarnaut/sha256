#ifndef _SHA256_H
#define _SHA256_H
//
//    Author: patrick garnaut
//        Date: AUG-2010
//        
//    SHA256 message digest implementation.
//    Probably slow, buggy and bloated, but this was a learning exercise. 
//
#define SHA256_LENGTH 32 // in bytes

#include "types.h"

class Sha256Digest
{
public:
    Sha256Digest() {
        reset();
    }
    void reset();
    void update(uint8 *input, uint32 length);
    void finalise();
    void getHash(uint8 digest[32]);
private:
    void process();
    void padAndFinalize();
    uint32 m_total[2]; // a 128bit unsigned integer
    uint32 m_state[8];
    uint8 m_buffer[64];
    uint32 m_bufferFilled;
    uint64 m_msgLength;
};
#endif // SHA256_H.h

