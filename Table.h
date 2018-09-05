#include <iostream>
#pragma once
#include "TabRecord.h"
class Table
{
public:
	int DataCount;
	int Efectivity = 0;
public:
	Table()
	{
		DataCount = 0;
	}
	virtual ~Table(){}
	int GetDataCount() const{
		return DataCount;
	}
	int IsEmpty()const{
		return DataCount == 0;
	}
	virtual int IsFull()const = 0;
	virtual Key GetKey()const = 0;
	virtual int GetCntRpt()const = 0;
	TabRecord FindRecord(Key k);
	virtual void InsRecord(Key k, int cntrpt) = 0;
	virtual void DelRecord(Key k) = 0;
	virtual int Reset() = 0;
	virtual int IsTableEnded()const = 0;
	virtual int GoNext() = 0;
};

