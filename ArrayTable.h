#pragma once
#include <iostream>
#include "Table.h"
#define maxtabsize 25
class ArrayTable :public Table{
public:
	TabRecord* Recs;
	int pos;
	int FirstPos=0;
	int LastPos=DataCount-1;
	int TabSize=0;
	int CurrPos;
public:
	ArrayTable(int size = maxtabsize)
	{
		Recs = new TabRecord[size];
		for (int i = 0; i < size; i++)
		{
			Recs[i].key = "";
			Recs[i].cnt_rpt = 0;
		}
		DataCount = CurrPos = 0;
		TabSize = size;
	}

	~ArrayTable()
	{
		/*for ( int i = 0; i < DataCount; i++)
		{
			delete (&Recs[i]);
		}*/
		delete[]Recs;
	}
	virtual int IsFull()const{
		return DataCount >= TabSize;
	}
	int GetTabSize()const{
		return TabSize;
	}
	virtual Key GetKey(void)const{
		return GetKey(CurrPos);
	}
	virtual Key GetKey(int pos) const
	{
		Key res;
		if (!IsEmpty())
		{
			if (pos == FirstPos)
				res = Recs[FirstPos].key;
			else if (pos == LastPos)
				res = Recs[LastPos].key;
			else res = Recs[pos].key;
		}
		else res = "";
		return res;
	}
	virtual int GetCntRpt(void)const{
		return GetCntRpt(CurrPos);
	}
	virtual int GetCntRpt(int pos)const{
		int res;
		if (!IsEmpty())
		{
			if (pos == FirstPos)
				res = Recs[FirstPos].cnt_rpt;
			else if (pos == LastPos)
				res = Recs[LastPos].cnt_rpt;
			else res = Recs[pos].cnt_rpt;
		}
		else res = 0;
		return res;
	}
	virtual int FindRecord(Key k) = 0;
	virtual void InsRecord(Key k, int cntrpt) = 0;
	virtual void DelRecord(Key k) = 0;
	virtual int Reset()
	{
		CurrPos = 0;
		return IsTableEnded();
	}
	virtual int IsTableEnded()const
	{
		return CurrPos >= DataCount;
	}
	virtual int GoNext()
	{
		if (!IsTableEnded())
			CurrPos++;
		return IsTableEnded();
	}
	virtual int SetCurrPos(int pos){
		if ((pos<DataCount) && (pos>-1))
			CurrPos = pos;
		else CurrPos = 0;
		return IsTableEnded();
	}
	virtual int GetCurrPos(){
		return CurrPos;
	}
	void ClearTab()
	{
		for (int i = 0; i < DataCount; i++)
		{
			Recs[i].key = "";
			Recs[i].cnt_rpt = 0;
		}
		DataCount = 0;
	}
};

