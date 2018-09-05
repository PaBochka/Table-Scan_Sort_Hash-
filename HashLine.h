#include <string>
#include <iostream>
#include <iomanip>
typedef std::string Key;
class HashLine
{
public:
	Key key;
	int maxwordsize = 50;
	int cnt_rpt;//количество повторов слова
	HashLine* Next;
public:
	HashLine(Key k = "", int _cnt_rpt = 0, HashLine *_Next = NULL)
	{
		key = k;
		cnt_rpt = _cnt_rpt;
		Next = _Next;
	}
	void SetKey(Key k)
	{
		key = k;
	}
	Key GetKey(void)
	{
		return key;
	}
	HashLine *Getptr(void)
	{
		return Next;
	}
	void Setptr(HashLine *_Next)
	{
		Next = _Next;
	}
	void SetCntRpt(int _cnt_rpt)
	{
		cnt_rpt = _cnt_rpt;
	}
	int GetCntRpt(void)
	{
		return cnt_rpt;
	}
	HashLine & operator = (HashLine &r)
	{
		key = r.key;
		cnt_rpt = r.cnt_rpt;
		Next = r.Next;
		return *this;
	}
	/*TabRecord& operator = (int &tmp){
	key = tmp;
	cnt_rpt = tmp;
	return *this;
	}*/
	virtual int operator == (const HashLine &r)
	{
		return key == r.key;
	}
	virtual int operator < (const HashLine &r)
	{
		return key < r.key;
	}
	virtual int operator >(const HashLine &r)
	{
		return key > r.key;
	}
	void printline(std::ostream &os){

		os << std::setw(maxwordsize) << key;
		os << char(179) << std::setw(5) << cnt_rpt << std::endl;
	}
};

