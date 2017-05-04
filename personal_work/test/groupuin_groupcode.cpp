#define TMP_GROUP_START_UIN     201000000
#define TMP_GROUP_END_UIN       202000000

#define GROUP_START_UIN_1		202000000
#define	GROUP_END_UIN_1			213000000
#define GROUP_START_CODE_1		0
#define GROUP_END_CODE_1		(GROUP_START_CODE_1 + (GROUP_END_UIN_1 - GROUP_START_UIN_1))

#define GROUP_START_UIN_2		480000000
#define	GROUP_END_UIN_2			489000000
#define GROUP_START_CODE_2		GROUP_END_CODE_1
#define GROUP_END_CODE_2		(GROUP_START_CODE_2 + (GROUP_END_UIN_2 - GROUP_START_UIN_2))

#define GROUP_START_UIN_3		2100000000
#define GROUP_END_UIN_3			2147000000
#define GROUP_START_CODE_3		GROUP_END_CODE_2
#define GROUP_END_CODE_3		(GROUP_START_CODE_3 + (GROUP_END_UIN_3 - GROUP_START_UIN_3))

#define GROUP_START_UIN_4		2010000000
#define GROUP_END_UIN_4			2100000000
#define GROUP_START_CODE_4		GROUP_END_CODE_3
#include<iostream>
using namespace std;


#define GROUP_END_CODE_4		(GROUP_START_CODE_4 + (GROUP_END_UIN_4 - GROUP_START_UIN_4))

#define GROUP_START_UIN_5		2147000000	
#define GROUP_END_UIN_5			( (unsigned long) 2147483647 + 52516353)	//2200000000
#define GROUP_START_CODE_5		GROUP_END_CODE_4
#define GROUP_END_CODE_5		(GROUP_START_CODE_5 + ( GROUP_END_UIN_5 - GROUP_START_UIN_5))

#define GROUP_START_UIN_6		4100000000UL
#define GROUP_END_UIN_6			4200000000UL
#define GROUP_START_CODE_6		GROUP_END_CODE_5
#define GROUP_END_CODE_6		(GROUP_START_CODE_6 + ( GROUP_END_UIN_6 - GROUP_START_UIN_6))

#define GROUP_START_UIN_7		3800000000UL
#define GROUP_END_UIN_7			4000000000UL
#define GROUP_START_CODE_7		GROUP_END_CODE_6
#define GROUP_END_CODE_7		(GROUP_START_CODE_7 + ( GROUP_END_UIN_7 - GROUP_START_UIN_7))

int main()
{
	cout<<TMP_GROUP_START_UIN<<" "<<TMP_GROUP_END_UIN<<endl;
	cout<<GROUP_START_CODE_1<<" "<<GROUP_END_CODE_1<<endl;
	cout<<GROUP_START_CODE_2<<" "<<GROUP_END_CODE_2<<endl;
	cout<<GROUP_START_CODE_3<<" "<<GROUP_END_CODE_3<<endl;
	cout<<GROUP_START_CODE_4<<" "<<GROUP_END_CODE_4<<endl;
	cout<<GROUP_START_CODE_5<<" "<<GROUP_END_CODE_5<<endl;
	cout<<GROUP_START_CODE_6<<" "<<GROUP_END_CODE_6<<endl;
	cout<<GROUP_START_CODE_7<<" "<<GROUP_END_CODE_7<<endl;
	
	return 0;
}


int GroupUinToCode(unsigned long lGroupUin, unsigned long *plGroupCode)
{
	if (lGroupUin >= GROUP_START_UIN_1 && lGroupUin < GROUP_END_UIN_1) {
		*plGroupCode = lGroupUin - GROUP_START_UIN_1 + GROUP_START_CODE_1; return 0;
	}
	if (lGroupUin >= GROUP_START_UIN_2 && lGroupUin < GROUP_END_UIN_2) {
		*plGroupCode = lGroupUin - GROUP_START_UIN_2 + GROUP_START_CODE_2; return 0;
	}
	if (lGroupUin >= GROUP_START_UIN_3 && lGroupUin < GROUP_END_UIN_3) {
		*plGroupCode = lGroupUin - GROUP_START_UIN_3 + GROUP_START_CODE_3; return 0;
	}
	if (lGroupUin >= GROUP_START_UIN_4 && lGroupUin < GROUP_END_UIN_4) {
		*plGroupCode = lGroupUin - GROUP_START_UIN_4 + GROUP_START_CODE_4; return 0;
	}
	if (lGroupUin >= GROUP_START_UIN_5 && lGroupUin < GROUP_END_UIN_5) {
		*plGroupCode = lGroupUin - GROUP_START_UIN_5 + GROUP_START_CODE_5; return 0;
	}
	if (lGroupUin >= GROUP_START_UIN_6 && lGroupUin < GROUP_END_UIN_6) {
		*plGroupCode = lGroupUin - GROUP_START_UIN_6 + GROUP_START_CODE_6; return 0;
	}
	if (lGroupUin >= GROUP_START_UIN_7 && lGroupUin < GROUP_END_UIN_7) {            
		*plGroupCode = lGroupUin - GROUP_START_UIN_7 + GROUP_START_CODE_7; return 0;
	}                                                                               
	
	return -1;
}

int GroupCodeToUin(unsigned long *plGroupUin, unsigned long lGroupCode)
{
	if (lGroupCode >= GROUP_START_CODE_1 && lGroupCode < GROUP_END_CODE_1) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_1 + GROUP_START_UIN_1; return 0;
	}
	if (lGroupCode >= GROUP_START_CODE_2 && lGroupCode < GROUP_END_CODE_2) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_2 + GROUP_START_UIN_2; return 0;
	}
	if (lGroupCode >= GROUP_START_CODE_3 && lGroupCode < GROUP_END_CODE_3) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_3 + GROUP_START_UIN_3; return 0;
	}
	if (lGroupCode >= GROUP_START_CODE_4 && lGroupCode < GROUP_END_CODE_4) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_4 + GROUP_START_UIN_4; return 0;
	}
	if (lGroupCode >= GROUP_START_CODE_5 && lGroupCode < GROUP_END_CODE_5) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_5 + GROUP_START_UIN_5; return 0;
	}
	if (lGroupCode >= GROUP_START_CODE_6 && lGroupCode < GROUP_END_CODE_6) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_6 + GROUP_START_UIN_6; return 0;
	}
	if (lGroupCode >= GROUP_START_CODE_7 && lGroupCode < GROUP_END_CODE_7) {
		*plGroupUin = lGroupCode - GROUP_START_CODE_7 + GROUP_START_UIN_7; return 0;
	}
	return -1;
}

