#include "SortTable.h"
#include <iostream>
void SortTable::QuickSort(int beg, int end)
{
	//int pivot;//ведущий
	int left, right;
	left = beg;
	right = end;
	std::string mid = Recs[(left+right)/2].key;
	std::string tmp;
	while (left <= right)
	{
		while ((Recs[left].key < mid)/* && (left!=last)*/) left++;
		while ((Recs[right].key > mid)/*&&(right!=0)*/) right--;
		if (left <= right)
		{
			std::swap(Recs[left++].key, Recs[right--].key);
		}
	} 
	if (beg < right) QuickSort(beg, right);
	if (end > left) QuickSort(left, end);
}
SortTable::SortTable(const ScanTable &tab)
{
	*this = tab;
}
SortTable &SortTable::operator = (const ScanTable &tab)
{
	if (Recs != NULL)
	{
		delete[] Recs;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	if (TabSize<DataCount)
	Recs = new TabRecord[DataCount];
	else
		Recs = new TabRecord[TabSize];
	for (int i = 0; i < DataCount; i++)
	{
		Recs[i] = (TabRecord)tab.Recs[i];
	}
	CurrPos = 0;
	QuickSort(0, (DataCount-1));
	return *this;
}
void SortTable::InsRecord(Key k, int cnp_rpt)
{
	TabRecord *RecsS = NULL;
	bool flag = true;
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
				int temp = 0;
				while ((temp<DataCount) && (Recs[temp].key<k))
					temp++;
				if (temp == DataCount)
				{
					Recs[DataCount].key = k;
					Recs[DataCount].cnt_rpt = cnp_rpt;
					DataCount++;
				}
				else
				{
					for (int i = DataCount; i > temp; i--)
						Recs[i] = Recs[i - 1];
					Recs[temp].key = k;
					Recs[temp].cnt_rpt = cnp_rpt;
					DataCount++;
				}
			}
		}
	}
	else{
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
			int temp = 0;
			while ((temp<DataCount)&&(RecsS[temp].key < k))
				temp++;
			if (temp == DataCount)
			{
				RecsS[DataCount].key = k;
				RecsS[DataCount].cnt_rpt = cnp_rpt;
				DataCount++;
			}
			else
			{
				for (int i = DataCount; i > temp; i--)
					RecsS[i] = RecsS[i - 1];
				RecsS[temp].key = k;
				RecsS[temp].cnt_rpt = cnp_rpt;
				DataCount++;
			}
			Recs = RecsS;
		}
	}
	flag = true;
}
void SortTable::DelRecord(Key k)
{
	TabRecord res = Recs[FindRecord(k)];
	int SrchPos = CurrPos;
	Recs[SrchPos].key = "";
	Recs[SrchPos].cnt_rpt = NULL;
	//int temp = DataCount - SrchPos;
	for (int i = SrchPos; i < DataCount-1; i++)
		Recs[i] = Recs[i + 1];
	DataCount--;
}
int SortTable::FindRecord(Key k)
{
	int mid = 0;
	TabRecord res;
	int left, right;
	left = 0;
	int i = 0;
	right = DataCount-1;
	while (left<=right)
	{
		Efectivity = i + 1;
		mid = (left + right) / 2;
		if (k < Recs[mid].key)
			right = mid - 1;
		if (k>Recs[mid].key)
			left = mid + 1;
		if (k == Recs[mid].key)
		{
			res = Recs[mid];
			CurrPos = mid;
			return mid;
		}
		i++;
	}
	return -1;
}
void SortTable::PrintSortTab(std::ostream &os){
	for (Reset(); !IsTableEnded(); GoNext())
	{
		os << std::setw(5) << CurrPos;
		Recs[CurrPos].Print(os);
	}
}
