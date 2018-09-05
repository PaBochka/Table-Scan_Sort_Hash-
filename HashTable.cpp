#include "HashTable.h"
#include <iostream>
static int mul = 31;
int HashTable::multiply[100];
int cnt = 0;
HashTable::HashTable(int size)
{
	HRecs = new HashLine[size];
	for (int i = 0; i < size; i++)
	{
		HRecs[i].key = "";
		HRecs[i].cnt_rpt = 0;
		HRecs[i].Next = NULL;
	}
	DataCount = CurrPos = 0;
	TabSize = size;
}
int HashTable::IsFull() const 
{
	return DataCount >= TabSize;
}
int HashTable::IsEmpty() const
{
	return DataCount == 0;
}
Key HashTable::GetKey(void) const 
{
	Key res = "";
	if ((CurrPos >= 0) && (CurrPos < DataCount))
		res = HRecs[CurrPos].key;
	return res;
}

int HashTable::GetCntRpt(void) const
{
	int res = 0;
	if ((CurrPos>=0) && (CurrPos < DataCount))
		res = HRecs[CurrPos].cnt_rpt;
	return res;
}
int HashTable::GoNext(void)
{
	CurrPos++;
	return IsTableEnded();
}
int HashTable::Reset(void)
{
	CurrPos = CurrPosLine = 0;
	return IsTableEnded();
}
int HashTable::IsTableEnded(void) const
{
	return CurrPos >= TabSize;
}
void HashTable::fillmult()
{
	multiply[0] = 1;
	for (int i = 1; i < 100; i++)
	{
		multiply[i] = multiply[i - 1] * mul;
	}
}
int HashTable::HashFunc(const Key k)
{
	int index = 0;
	for (size_t i = 0; i < k.size(); i++)
	{
		index += int(k[i])*multiply[i];
	}
	return abs(index) % maxtabsize;
}
void HashTable::InsRecord(Key k, int cnt_rpt)
{
	int index = HashFunc(k);
	HashLine *line = &HRecs[index];
	if (k.size() + 1 > line->maxwordsize)
		line->maxwordsize = k.size() + 1;
	while (line != NULL){
		if (line->key == k)
		{
			line->cnt_rpt += cnt_rpt;
			return;
		}
		line = line->Next;
	}
	line = &HRecs[index];
	HashLine *tmpptr = line;
	while (line != NULL){
		if (line->cnt_rpt == 0){
			line->key = k;
			line->cnt_rpt = cnt_rpt;
			++DataCount;
			return;
		}
		tmpptr = line;
		line = line->Next;
	}
	++DataCount;
	tmpptr->Next = new HashLine(k, cnt_rpt, NULL);
}
HashLine HashTable::FindRecord(Key k)
{
	int index = HashFunc(k);
	HashLine *line = &HRecs[index];
	int i = 0;
	while (line != NULL){
		Efectivity = i + 1;
		if (line->key == k)
			return *line;
		line = line->Next; 
		i++;
	}
}
void HashTable::DelRecord(Key k)
{
	//int LastPos = DataCount - 1;
	int index = HashFunc(k);
	if (HRecs[index].key == k){
		HRecs[index].cnt_rpt = 0;
		--DataCount;
		std::cout << "element was deleted" << std::endl;
		return;
	}
	HashLine *line = &HRecs[index];
	while (line->Next != NULL){
		if (line->Next->key == k){
			HashLine *tmpptr = line->Next;
			tmpptr->key = "";
			tmpptr->cnt_rpt = 0;
			line->Next = tmpptr->Next;
			delete tmpptr;
			--DataCount;
			std::cout << "element was deleted" << std::endl;
			return;
		}
		line = line->Next;
	}
	std::cout << "element not found" << std::endl;
}
void HashTable::printtable(std::ostream &os){
	for (Reset(); !IsTableEnded(); CurrPos++){
		HashLine *line = &HRecs[CurrPos];
		int index = HashFunc(line->key);
		while (line != NULL)
		{
			if (line->cnt_rpt != 0){
				os << std::setw(5) << index;
				line->printline(os);
			}
			line = line->Next;
		}
	}
}
