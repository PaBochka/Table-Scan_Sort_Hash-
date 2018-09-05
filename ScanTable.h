#pragma once
#include <iostream>
#include "ArrayTable.h"
class ScanTable: public ArrayTable
{
public:
	ScanTable(int size = maxtabsize) :ArrayTable(size){};
	virtual int FindRecord(Key k );
	virtual void InsRecord(Key k, int cnt_rpt);
	virtual void DelRecord(Key k);
	void PrintScanTab(std::ostream &os);
};

