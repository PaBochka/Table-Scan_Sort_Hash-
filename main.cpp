#include "ScanTable.h"
#include "SortTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "HashTable.h"
#include <conio.h>
void read(HashTable &tab, ScanTable &tabl, SortTable &table)
{
	int cnt_rtp = 1;
	int index;
	std::string key1;
	std::ifstream fin("File.txt");
	while (!fin.eof())
	{
		fin >> key1;
		index = tab.HashFunc(key1);
		tab.InsRecord(key1, cnt_rtp);
		tabl.InsRecord(key1, cnt_rtp);
	}
	table = tabl;
}
int main(){
	int cnt_rtp = 1;
	int index;
	int cnt = 0;
	std::string key1;
	HashTable tab(maxtabsize);
	ScanTable tabl(maxtabsize);
	SortTable table(maxtabsize);
	tab.fillmult();
	do {
		std::cout << "Work with HashTable - press: 1" << std::endl;
		std::cout << "Work with ScanTable - press: 2" << std::endl;
		std::cout << "Work with SortTable - press: 3" << std::endl;
		std::cout << "Read from file in all tables - press: 4" << std::endl;
		std::cout << "EXIT - press: 0" << std::endl;
		std::cin >> cnt;
		switch (cnt)
		{
		case 1:{
			system("cls");
			int tmp;
			do {
				
				std::cout << "Insert in HashTable - press: 1" << std::endl;
				std::cout << "Delete from HashTable - press: 2" << std::endl;
				std::cout << "Find record in HashTable - press: 3" << std::endl;
				std::cout << "Print HashTable - press: 4" << std::endl;
				std::cout << "Out from HashTable - press: 0" << std::endl;
				std::cin >> tmp;
				switch (tmp)
				{
				case 1:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					int cntrpt = 1; 
					tab.InsRecord(key, cntrpt);
					system("cls");
				}
				break;
				case 2:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					tab.DelRecord(key);
					system("cls");
				}
				break;
				case 3:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					tab.FindRecord(key).printline(std::cout);
					std::cout << tab.Efectivity << std::endl;
					_getch();
					system("cls");
				}
				break;
				case 4:
				
				{
					system("cls");
					tab.printtable(std::cout);
					_getch();
					system("cls");
				}
					break;
				}
			} while (tmp != 0);
			system("cls");
		}
			   break;
		case 2:{
			system("cls");
			int tmp;
			
			do {
				std::cout << "Insert in ScanTable - press: 1" << std::endl;
				std::cout << "Delete from ScanTable - press: 2" << std::endl;
				std::cout << "Find record in ScanTable - press: 3" << std::endl;
				std::cout << "Print ScanTable - press: 4" << std::endl;
				std::cout << "Out from ScanTable - press: 0" << std::endl;
				std::cin >> tmp;
				switch (tmp)
				{
				case 1:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					int cntrpt = 1;
					tabl.InsRecord(key, cntrpt);
					system("cls");
				}
				break;
				case 2:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					tabl.DelRecord(key);
					system("cls");
				}
				break;
				case 3:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					int index = tabl.FindRecord(key);
					std::cout << index << " ";
					tabl.Recs[index].Print(std::cout);
					std::cout << tabl.Efectivity << std::endl;
					_getch();
					system("cls");
				}
				break;
				case 4:
				{
					system("cls");
					tabl.PrintScanTab(std::cout);
					_getch();
					system("cls");
				}
					break;
				}
			} while (tmp != 0);
			system("cls");
		}
			   break;
		case 3:{
			system("cls");
			int tmp;
			do {
				std::cout << "Insert in SortTable - press: 1" << std::endl;
				std::cout << "Delete from SortTable - press: 2" << std::endl;
				std::cout << "Find record in SortTable - press: 3" << std::endl;
				std::cout << "Print SortTable - press: 4" << std::endl;
				std::cout << "Out from SortTable - press: 0" << std::endl;
				std::cin >> tmp;
				switch (tmp)
				{
				case 1:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					int cntrpt = 1;
					table.InsRecord(key, cntrpt);
					system("cls");
				}
				break;
				case 2:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					table.DelRecord(key);
					system("cls");
				}
				break;
				case 3:
				{
					system("cls");
					std::string key;
					std::cin >> key;
					int index = table.FindRecord(key);
					std::cout << index << " ";
					table.Recs[index].Print(std::cout);
					std::cout << table.Efectivity << std::endl;
					_getch();
					system("cls");
				}
				break;
				case 4:
				{
					system("cls");
					table.PrintSortTab(std::cout);
					_getch();
					system("cls");
				}
					break;	
				}
			} while (tmp != 0);
			system("cls");
		}
			   break;
		case 4:
			read(tab, tabl, table);
			break;
		}
	} while (cnt != 0);
	//----------
	system("PAUSE");
 	return 0;
}