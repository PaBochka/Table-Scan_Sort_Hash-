#pragma once
#include <string>
#include <iostream>
#include <iomanip>
typedef std::string Key;
class TabRecord
{
protected:
	Key key;
	int cnt_rpt; //количество повторов слова 
public:
	int maxwordlength = 25;
	TabRecord(Key k = "", int _cnt_rpt = 0)
	{
		key = k;
		cnt_rpt = _cnt_rpt;
	}
	void SetKey(Key k)
	{
		key = k;
	}
	Key GetKey(void)
	{
		return key;
	}
	void SetCntRpt(int _cnt_rpt)
	{
		cnt_rpt = _cnt_rpt;
	}
	int GetCntRpt(void)
	{
		return cnt_rpt;
	}
	TabRecord & operator = (TabRecord &r)
	{
		key = r.key;
		cnt_rpt = r.cnt_rpt;
		return *this;
	}
	/*TabRecord& operator = (int &tmp){
		key = tmp;
		cnt_rpt = tmp;
		return *this;
	}*/
	virtual int operator == (const TabRecord &r)
	{
		return key == r.key;
	}
	virtual int operator < (const TabRecord &r)
	{
		return key < r.key; 
	}
	virtual int operator > (const TabRecord &r)
	{
		return key > r.key;
	}
	virtual void Print(std::ostream &os)
	{
		os << std::setw(maxwordlength) << key;
		os << char(179) << std::setw(5) << cnt_rpt << std::endl;
	}
	friend class ArrayTable;
	friend class ScanTable;
	friend class SortTable;
	friend class TreeTable;
	friend class TreeNode;
};

