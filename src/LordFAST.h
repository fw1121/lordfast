/*
 * Author: Ehsan Haghshenas (ehaghshe AT sfu DOT ca)
 */

#ifndef __PACFAST_BWT__
#define __PACFAST_BWT__

#include <string>
#include "Reads.h"

typedef struct
{
	uint32_t tPos;
	uint32_t qPos : 20;
	uint32_t len  : 12;
} Seed_t;

typedef struct
{
	Seed_t *list;
	uint32_t num; // size of the list
} SeedList;

typedef struct
{
	uint32_t tStart;
	uint32_t tEnd;
	uint8_t isReverse;
	float score;
} Win_t;

typedef struct
{
	Win_t *list;
	uint32_t num; // size of the list
} WinList;

typedef struct
{
	int readIdx;
	uint32_t cnt;
} WinCount_t;

bool compareWin(const Win_t& w1, const Win_t& w2);
bool compareSeed(const Seed_t& s1, const Seed_t& s2);

typedef struct
{
	Seed_t *seeds; // list of seeds contained in the chain
	uint32_t chainLen; // chain length
	float score;
} Chain_t;

typedef struct
{
	Chain_t *list;
	uint32_t num; // size of the list
} ChainList;

// bool compareChain(const Chain_t& c1, const Chain_t& c2);

typedef struct  
{
	char *qName;
	uint16_t flag;
	// char *rName;
	uint32_t pos;
	uint32_t posEnd;
	// uint8_t mapQ;
	// std::string cigar;
	char *cigar;
	int32_t tLen;
	char *seq;
	char *qual;
	int32_t alnScore;
} Sam_t;

bool compareSam(const Sam_t& s1, const Sam_t& s2);

void initializeFAST();
void finalizeFAST();
void initFASTChunk(Read *seqList, int seqListSize);
void finalizeFASTChunk();
void mapSeqMT();

#endif /*__PACFAST_BWT__*/
