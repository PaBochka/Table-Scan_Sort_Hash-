#pragma once
#include "Table.h"
#include "HashLine.h"
#include <vector>
#define maxtabsize 52
class HashTable : public Table {
private:
	static int multiply[100];
public:
	HashLine *HRecs;
	int pos;
	int FirstPos = 0;
	int LastPos = DataCount - 1;
	int TabSize = 0;
	int CurrPos; // для записей в таблице
	int CurrPosLine; //для записей в списке
public:
	static void fillmult();
	virtual int HashFunc(const Key k);
	HashTable(int size = maxtabsize);
	virtual int IsFull() const;
	virtual int IsEmpty() const;
	virtual Key GetKey(void) const;
	virtual int GetCntRpt(void) const;
	HashLine FindRecord(Key k);
	virtual void InsRecord(Key k, int cnt_rpt);
	virtual void DelRecord(Key k);
	virtual int GoNext(void);
	virtual int Reset(void);
	virtual int IsTableEnded(void) const;
	void printtable(std::ostream &os);
	void re_size(Key k);
};

