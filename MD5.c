#ifndef _MD5_H_
#define _MD5_H_

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define RL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))

#define PP(x) (x<<24)|((x<<8)&0xff0000)|((x>>8)&0xff00)|(x>>24)

#define FF(a, b, c, d, x, s, ac) a = b + (RL((a + F(b,c,d) + x + ac),s))
#define GG(a, b, c, d, x, s, ac) a = b + (RL((a + G(b,c,d) + x + ac),s))
#define HH(a, b, c, d, x, s, ac) a = b + (RL((a + H(b,c,d) + x + ac),s))
#define II(a, b, c, d, x, s, ac) a = b + (RL((a + I(b,c,d) + x + ac),s))

//	1MB
long long int blockSize = 1024 * 1024 * 18;

void md5(unsigned int *pA, unsigned int *pB, unsigned int *pC, unsigned int *pD, unsigned int *x)
{
	unsigned int a,b,c,d;
	a = *pA;
	b = *pB;
	c = *pC;
	d = *pD;
	/**//* Round 1 */
	FF (a, b, c, d, x[ 0],  7, 0xd76aa478); /**//* 1 */
	FF (d, a, b, c, x[ 1], 12, 0xe8c7b756); /**//* 2 */
	FF (c, d, a, b, x[ 2], 17, 0x242070db); /**//* 3 */
	FF (b, c, d, a, x[ 3], 22, 0xc1bdceee); /**//* 4 */
	FF (a, b, c, d, x[ 4],  7, 0xf57c0faf); /**//* 5 */
	FF (d, a, b, c, x[ 5], 12, 0x4787c62a); /**//* 6 */
	FF (c, d, a, b, x[ 6], 17, 0xa8304613); /**//* 7 */
	FF (b, c, d, a, x[ 7], 22, 0xfd469501); /**//* 8 */
	FF (a, b, c, d, x[ 8],  7, 0x698098d8); /**//* 9 */
	FF (d, a, b, c, x[ 9], 12, 0x8b44f7af); /**//* 10 */
	FF (c, d, a, b, x[10], 17, 0xffff5bb1); /**//* 11 */
	FF (b, c, d, a, x[11], 22, 0x895cd7be); /**//* 12 */
	FF (a, b, c, d, x[12],  7, 0x6b901122); /**//* 13 */
	FF (d, a, b, c, x[13], 12, 0xfd987193); /**//* 14 */
	FF (c, d, a, b, x[14], 17, 0xa679438e); /**//* 15 */
	FF (b, c, d, a, x[15], 22, 0x49b40821); /**//* 16 */

	/**//* Round 2 */
	GG (a, b, c, d, x[ 1],  5, 0xf61e2562); /**//* 17 */
	GG (d, a, b, c, x[ 6],  9, 0xc040b340); /**//* 18 */
	GG (c, d, a, b, x[11], 14, 0x265e5a51); /**//* 19 */
	GG (b, c, d, a, x[ 0], 20, 0xe9b6c7aa); /**//* 20 */
	GG (a, b, c, d, x[ 5],  5, 0xd62f105d); /**//* 21 */
	GG (d, a, b, c, x[10],  9, 0x02441453); /**//* 22 */
	GG (c, d, a, b, x[15], 14, 0xd8a1e681); /**//* 23 */
	GG (b, c, d, a, x[ 4], 20, 0xe7d3fbc8); /**//* 24 */
	GG (a, b, c, d, x[ 9],  5, 0x21e1cde6); /**//* 25 */
	GG (d, a, b, c, x[14],  9, 0xc33707d6); /**//* 26 */
	GG (c, d, a, b, x[ 3], 14, 0xf4d50d87); /**//* 27 */
	GG (b, c, d, a, x[ 8], 20, 0x455a14ed); /**//* 28 */
	GG (a, b, c, d, x[13],  5, 0xa9e3e905); /**//* 29 */
	GG (d, a, b, c, x[ 2],  9, 0xfcefa3f8); /**//* 30 */
	GG (c, d, a, b, x[ 7], 14, 0x676f02d9); /**//* 31 */
	GG (b, c, d, a, x[12], 20, 0x8d2a4c8a); /**//* 32 */

	/**//* Round 3 */
	HH (a, b, c, d, x[ 5],  4, 0xfffa3942); /**//* 33 */
	HH (d, a, b, c, x[ 8], 11, 0x8771f681); /**//* 34 */
	HH (c, d, a, b, x[11], 16, 0x6d9d6122); /**//* 35 */
	HH (b, c, d, a, x[14], 23, 0xfde5380c); /**//* 36 */
	HH (a, b, c, d, x[ 1],  4, 0xa4beea44); /**//* 37 */
	HH (d, a, b, c, x[ 4], 11, 0x4bdecfa9); /**//* 38 */
	HH (c, d, a, b, x[ 7], 16, 0xf6bb4b60); /**//* 39 */
	HH (b, c, d, a, x[10], 23, 0xbebfbc70); /**//* 40 */
	HH (a, b, c, d, x[13],  4, 0x289b7ec6); /**//* 41 */
	HH (d, a, b, c, x[ 0], 11, 0xeaa127fa); /**//* 42 */
	HH (c, d, a, b, x[ 3], 16, 0xd4ef3085); /**//* 43 */
	HH (b, c, d, a, x[ 6], 23, 0x04881d05); /**//* 44 */
	HH (a, b, c, d, x[ 9],  4, 0xd9d4d039); /**//* 45 */
	HH (d, a, b, c, x[12], 11, 0xe6db99e5); /**//* 46 */
	HH (c, d, a, b, x[15], 16, 0x1fa27cf8); /**//* 47 */
	HH (b, c, d, a, x[ 2], 23, 0xc4ac5665); /**//* 48 */

	/**//* Round 4 */
	II (a, b, c, d, x[ 0],  6, 0xf4292244); /**//* 49 */
	II (d, a, b, c, x[ 7], 10, 0x432aff97); /**//* 50 */
	II (c, d, a, b, x[14], 15, 0xab9423a7); /**//* 51 */
	II (b, c, d, a, x[ 5], 21, 0xfc93a039); /**//* 52 */
	II (a, b, c, d, x[12],  6, 0x655b59c3); /**//* 53 */
	II (d, a, b, c, x[ 3], 10, 0x8f0ccc92); /**//* 54 */
	II (c, d, a, b, x[10], 15, 0xffeff47d); /**//* 55 */
	II (b, c, d, a, x[ 1], 21, 0x85845dd1); /**//* 56 */
	II (a, b, c, d, x[ 8],  6, 0x6fa87e4f); /**//* 57 */
	II (d, a, b, c, x[15], 10, 0xfe2ce6e0); /**//* 58 */
	II (c, d, a, b, x[ 6], 15, 0xa3014314); /**//* 59 */
	II (b, c, d, a, x[13], 21, 0x4e0811a1); /**//* 60 */
	II (a, b, c, d, x[ 4],  6, 0xf7537e82); /**//* 61 */
	II (d, a, b, c, x[11], 10, 0xbd3af235); /**//* 62 */
	II (c, d, a, b, x[ 2], 15, 0x2ad7d2bb); /**//* 63 */
	II (b, c, d, a, x[ 9], 21, 0xeb86d391); /**//* 64 */

	*pA += a;
	*pB += b;
	*pC += c;
	*pD += d;

}

int BufferRemindMD5(unsigned int *x, int i,
	unsigned int A,unsigned int B,unsigned int C,unsigned int D,
	unsigned int md5value[4], int len, int flen[2],unsigned char* buffer)
{
	memset(x,0,64);

	memcpy(x,buffer,len%64);

	((char*)x)[len%64]=128;
	if(len%64>55)
	{
		md5(&A,&B,&C,&D,x);
		memset(x,0,64);
	}
	memcpy(x+14,flen,8);
	md5(&A,&B,&C,&D,x);
	md5value[0] = PP(A);
	md5value[1] = PP(B);
	md5value[2] = PP(C);
	md5value[3] = PP(D);
	return len;
}

int BufferMD5Blocks(unsigned char *buffer,
	unsigned int *A,unsigned int *B, unsigned int *C, unsigned int *D,
	unsigned int *x, int starti, int endi)
{
    int i;
	memset(x,0,64);

	for(i=starti; i<endi; i++)
	{
		memcpy(x,buffer+i*64,64);
		md5(A,B,C,D,x);
	}
	return 0;
}

int BufferMD5(unsigned char *buffer, int len, unsigned int md5value[4])
{
	if(len == 0)
		return 0;

	int i = 0;
	unsigned int flen[2];
	unsigned int A,B,C,D;
	unsigned int x[16];
	A=0x67452301,B=0xefcdab89,C=0x98badcfe,D=0x10325476;

	BufferMD5Blocks(buffer, &A, &B, &C, &D, x, 0, len/64);

	flen[1]=len/0x20000000;
	flen[0]=(len%0x20000000)*8;
	memset(md5value,0,4*sizeof(unsigned int));

	return BufferRemindMD5(x, len / 64, A, B, C, D, md5value, len, flen, buffer);
}

int main(int argc, char *argv[])
{
	unsigned int MD5value[4];
	FILE * fp;
	long long int len;
	unsigned char * buf;
	clock_t start, end;

	unsigned int flen[2];
	unsigned int A,B,C,D;
	unsigned int x[16];
	A=0x67452301,B=0xefcdab89,C=0x98badcfe,D=0x10325476;


	memset(MD5value,0,4*sizeof(unsigned int));


    if(argc<2)
    {
    	printf("md5.exe inputfilename\n");
    	return 1;
    }
    start = clock();
	fp = fopen(argv[1],"rb");

	fseeko64(fp, 0, SEEK_END);
	len = ftello64(fp);
	flen[1]=len/0x20000000;
	flen[0]=(len%0x20000000)*8;
	if(len == -1)
	{
		printf("Can not calculate md5 of the file %s since it is too large!\n",argv[1]);
		fclose(fp);
		return 0;
	}
	fseek(fp, 0, SEEK_SET);
        int blockNumber = len/64/blockSize;

//        int mid = len / 64 / 2;
//        buf = (unsigned char *)calloc(mid,1);
//        fread(buf,1,mid,fp);
//        BufferMD5Blocks(buf, &A, &B, &C, &D, x, 0, mid/64);
//        free(buf);
//        buf = (unsigned char *)calloc((len-mid),1);
//        fread(buf,1,(len-mid),fp);
//        BufferMD5Blocks(buf,&A,&B,&C,&D,x,0,(len-mid)/64);
        buf=(unsigned char *)calloc(blockSize*64,1);
        while(blockNumber){
            fread(buf,1,(blockSize*64),fp);
            BufferMD5Blocks(buf, &A, &B, &C, &D, x ,0, blockSize);
            blockNumber--;
        }
        free(buf);

        long long int others=
len-(len/64/blockSize)*blockSize*64-len%64;
        buf=(unsigned char *)calloc(others,1);
        fread(buf,1,others,fp);
        BufferMD5Blocks(buf, &A, &B, &C, &D, x ,0, others/64);
        free(buf);
        buf = (unsigned char *)calloc(len%64,0);
        fread(buf,1,len%64,fp);
        memset(MD5value,0,16);
        BufferRemindMD5(x, 0, A, B, C, D, MD5value, len, flen, buf);


	fclose(fp);

	end   = clock();
	free(buf);
	printf("%s\t%lld\t",argv[1],len);
	printf("%08X%08X%08X%08X\t",MD5value[0],MD5value[1],MD5value[2],MD5value[3]);

	FILE* log =    fopen("2014060101017.log", "a+");
	fprintf(log, "%08X%08X%08X%08X\n",MD5value[0],MD5value[1],MD5value[2],MD5value[3]);

	printf("%.3f\n",1.0*(end - start) / CLOCKS_PER_SEC);

	return 0;
}

#endif
