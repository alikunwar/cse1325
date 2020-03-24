#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern void writeU32(uint32_t* p, uint32_t x);
extern uint32_t readU32(uint32_t* p);
extern void writeS32(int32_t* p, int32_t x);
extern int32_t readS32(int32_t* p);
extern void writeU16(uint16_t* p, uint16_t x);
extern uint16_t readU16(uint16_t* p);
extern void writeS16(int16_t* p, int16_t x);
extern int16_t readS16(int16_t* p);
extern void writeU8(uint8_t* p, uint8_t x);
extern uint8_t readU8(uint8_t* p);
extern void writeS8(int8_t* p, int8_t x);
extern int8_t readS8(int8_t* p);

/*
void writeU32(uint32_t* p, uint32_t x)
{
    *p = x;
}
uint32_t readU32(uint32_t* p)
{
    return *p;
}
*/

int main()
{
    uint32_t a;
    printf("&a = %p\n", &a);
    writeU32(&a, 1000000);
    printf("a = %u\n", readU32(&a));
    int32_t d;
    writeS32(&d, -1000000);
    printf("d = %d\n", readS32(&d));
    uint16_t b;
    writeU16(&b, 10000);
    printf("b = %hu\n", readU16(&b));
    int16_t e;
    writeS16(&e, -10000);
    printf("e = %hd\n", readS16(&e));
    uint8_t c;
    writeU8(&c, 100);
    printf("c = %hhu\n", readU8(&c));
    int8_t f;
    writeS8(&f, -100);
    printf("f = %hhd\n", readS8(&f));
    return EXIT_SUCCESS;
}

