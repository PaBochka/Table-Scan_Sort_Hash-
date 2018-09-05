#pragma once
#include "ScanTable.h"
#include <iostream>
class SortTable:public ScanTable
{
public:
	void QuickSort(int beg, int end);
	SortTable(int size = maxtabsize) :ScanTable(size){};
	SortTable(const ScanTable &tab);
	SortTable &operator =(const ScanTable &tab);
	virtual int FindRecord(Key k);
	virtual void InsRecord(Key k, int cnt_rpt);
	virtual void DelRecord(Key k);
	void PrintSortTab(std::ostream &os);
};

