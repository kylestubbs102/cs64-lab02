#include "stdio.h"
#include "stdlib.h"
#include "RandomCode.h"

int multiplyBy8(int v)
{
        // TODO: multiply the number by 8
        return v << 3;
}

int setBit6to1(int v)
{
        // TODO: set bit 6 to 1
        return v | 0x40;
}

int setBit3to0(int v)
{
        // TODO: set bit 3 to 0
        return v & ~(0x8);
}

int flipBit5(int v)
{
        // TODO: flip bit 5 (if it is 0, make it 1.  If 0, make 1)
        return v ^ 0x20;
}

int ifBit7is0(int v)
{
        // TODO: check to see if bit 7 is a 0 - return 1 if true, 0 if false
        if ( (v & 0x80) != 0x80 )
                return 1;
        return 0;
}

int ifBit3is1(int v)
{
        // check to see if bit 3 is a 1 - return 1 if true, 0 if false
        if ( (v | 0x8) != v )
                return 0;
        return 1;
}

int unsignedBits0through5(int v)
{
        // return the unsigned value in bits 0 through 5
        //my guess is to use bitwise operations and add each one together
        int temp = 0;
        temp = v & 0x1;
        temp += ( v & 0x2 );
        temp += ( v & 0x4 );
        temp += ( v & 0x8 );
        temp += ( v & 0x10 );
        temp += ( v & 0x20 );
        return temp;
}

int unsignedBits6through9(int v)
{
        // return the unsigned value in bits 6 through 9
        v = v >> 6;
        int temp = 0;
        temp = v & 0x1;
        temp += ( v & 0x2 );
        temp += ( v & 0x4 );
        temp += ( v & 0x8 );
        return temp;
}

int signedBits0through5(int v)
{
        // return the signed value in bits 0 through 5
        int temp = 0;
        if ( (v | 0x20) == v ) {
                v = v ^ 0x1;
                v = v ^ 0x2;
                v = v ^ 0x4;
                v = v ^ 0x8;
                v = v ^ 0x10;
                v = v ^ 0x20;
                v++;
                temp = v & 0x1;
                temp += ( v & 0x2 );
                temp += ( v & 0x4 );
                temp += ( v & 0x8 );
                temp += ( v & 0x10 );
                temp += ( v & 0x20 );
                return -temp;
        }
        else {
                temp = v & 0x1;
                temp += ( v & 0x2 );
                temp += ( v & 0x4 );
                temp += ( v & 0x8 );
                temp += ( v & 0x10 );
                temp += ( v & 0x20 );
                return temp;
        }
}

int signedBits6through9(int v)
{
        // return the signed value in bits 6 through 9
        v = v >> 6;
        int temp = 0;
        if ( (v | 0x8) == v ) {
                v = v ^ 0x1;
                v = v ^ 0x2;
                v = v ^ 0x4;
                v = v ^ 0x8;
                v++;
                temp = v & 0x1;
                temp += ( v & 0x2 );
                temp += ( v & 0x4 );
                temp += ( v & 0x8 );
                return -temp;
        }
        else {
                temp = v & 0x1;
                temp += ( v & 0x2 );
                temp += ( v & 0x4 );
                temp += ( v & 0x8 );
                return temp;
        }
}

int setBits4through9(int v, int setValue)
{
        // set bits 4 through 9 in v to become setValue
        //v = v | (setValue << 4);
        int mask1 = setValue & 0x1;
        int mask2 = setValue & 0x2;
        int mask3 = setValue & 0x4;
        int mask4 = setValue & 0x8;
        int mask5 = setValue & 0x10;
        int mask6 = setValue & 0x20;
        v = v & ~(0x10);
        v = v & ~(0x20);
        v = v & ~(0x40);
        v = v & ~(0x80);
        v = v & ~(0x100);
        v = v & ~(0x200);
        v = v | (mask1 << 4);
        v = v | (mask2 << 4);
        v = v | (mask3 << 4);
        v = v | (mask4 << 4);
        v = v | (mask5 << 4);
        v = v | (mask6 << 4);
        return v;
}
