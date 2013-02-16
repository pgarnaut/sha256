//
// author: patrick garnaut
// date: AUG 2010
//
// small piece of rubbish code to read a file and run the sha256 over it
// 
// 

#include "sha256.h"
#include "types.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 256



void usage(int argc, char **argv)
{
    printf("%s <filename>    (optionally -v)\n", argv[0]);
    exit(1);
}

int main(int argc, char **argv)
{
    FILE *f;
    char *fname = 0;
    uint8 buf[CHUNK_SIZE];
    uint8 hash[32];
    uint32 res;
    uint64 fileSize = 0;
    Sha256Digest sha;
    int verbose = 0;
    
#ifdef uint32
    printf("defined\n");
#endif
    
    if(argc < 2)
        usage(argc, argv);
    
    for(int i=1; i<argc; i++)
        if(!strcasecmp(argv[i], "-v"))
            verbose = 1;
        else
            fname = argv[i];

    if((f = fopen(fname, "rb")))
    {
        while( (res = fread(buf, 1, CHUNK_SIZE, f)) > 0 && (fileSize += res))
            sha.update(buf, res);
        sha.finalise();
        sha.getHash(hash);
        
        for(int i=0; i<32; i++)
            printf("%.2x", hash[i]);
        
        if(verbose)
            printf(" %s %lld\n", argv[1], fileSize);
        else
            printf("\n");
    }
    else
    {
        printf("error opening: %s\n", argv[1]);
        return 1;
    }
    
    return 0;
}