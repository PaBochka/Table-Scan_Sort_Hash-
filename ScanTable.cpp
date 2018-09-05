#include "ScanTable.h"

int ScanTable::FindRecord(Key k)
{
	int i;
	TabRecord res;
	for (i = 0; i < DataCount; i++)
	{
		Efectivity = i + 1;
		if (Recs[i].key == k)
			break;
	}
	if (i < DataCount){
		CurrPos = i;
		res.key = Recs[i].key;
		res.cnt_rpt = Recs[i].cnt_rpt;
	}
	else return NULL;
	return i;		
}
void ScanTable::DelRecord(Key k)
{
	int LastPos = DataCount - 1;
	TabRecord res = Recs[FindRecord(k)];
	Recs[CurrPos].key = Recs[LastPos].key;
	Recs[CurrPos].cnt_rpt= Recs[LastPos].cnt_rpt;
	Recs[LastPos].key="";
	Recs[LastPos].cnt_rpt = NULL;
	DataCount--;
}
void ScanTable::InsRecord(Key k, int cnp_rpt)
{
	int i;
	bool flag = true;
	TabRecord *RecsS = NULL;
	if (k.length() > Recs->maxwordlength)
		Recs->maxwordlength = k.length();
	if (!IsFull())
	{
		if (IsEmpty())
		{
			Recs[DataCount].key = k;
			Recs[DataCount].cnt_rpt = cnp_rpt;
			DataCount++;
		}
		else {
			for (int cnt = 0; cnt < DataCount; cnt++)
				if (Recs[cnt].key == k)
				{
					Recs[cnt].cnt_rpt++;
					flag = false;
				}
			if (flag == true)
			{
				Recs[DataCount ].key = k;
				Recs[DataCount ].cnt_rpt = cnp_rpt;
				DataCount++;
			}
		}
	}
	else
	{
		for (int cnt = 0; cnt < DataCount; cnt++)
			if (Recs[cnt].key == k)
			{
				Recs[cnt].cnt_rpt++;
				flag = false;
			}
		if (flag == true)
		{
			RecsS = new TabRecord[DataCount + 1];
			for (int tmp = 0; tmp < DataCount + 1; tmp++)
			{
				RecsS[tmp].key = "";
				RecsS[tmp].cnt_rpt = 0;
			}
			for (int cnt = 0; cnt < DataCount; cnt++)
				RecsS[cnt] = Recs[cnt];
			delete[]Recs;
			RecsS[DataCount ].key = k;
			RecsS[DataCount ].cnt_rpt = cnp_rpt;
			Recs = RecsS;
			DataCount++;
		}
	}
	flag = true;
	
}
void ScanTable::PrintScanTab(std::ostream &os){
	for (Reset(); !IsTableEnded(); GoNext())
	{
		os << std::setw(5) << CurrPos;
		Recs[CurrPos].Print(os);
	}
}
