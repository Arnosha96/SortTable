#pragma once
#include<string>
#include <iomanip>

using namespace std;
class TRecord
{
public:
	string Key;
	int Data;
	TRecord()
	{
		int Key = 0;

	}

	TRecord(string _Key, int _Data)
	{
		Key = _Key;
		Data = _Data;
	}

	TRecord operator= (const TRecord&Rec)
	{
		Key = Rec.Key;
		Data = Rec.Data;
		return *this;
	}
};
	class TTable
	{
	private:
		int Size;
		TRecord *List;
		int Count;
	public:
		TTable(int _Size = 100)
		{
			Size = _Size;
			List = new TRecord[Size];
			Count = 0;
		}
		~TTable()
		{
			delete[]List;
		}

		TRecord &operator[](int pos)
		{
			if ((pos >= 0) && (pos < Count))
				return List[pos];
		}
		int SeachRecord(string RecKey)
		{
			int First = 0;
			int Last = Count - 1;
			int Middle;
			int pos = -1;

			bool Result = false;
			while ((First <= Last) && (Result == false))
			{
				Middle = (First + Last) / 2;
				if (RecKey == List[Middle].Key)
				{
					First = Last = Middle;
					Result = true;
				}


				else if (RecKey < List[Middle].Key) Last = Middle - 1;
				else First = Middle + 1;
			}
			pos = First;
			Result = false;
			if ((pos < Count) && (List[pos].Key == RecKey)) Result = true;
			if (List[pos].Key == RecKey) return List[pos].Data;
			else
			{
				return -1;
			}
		}

		int Seachpos(string RecKey)
		{
			int First = 0;
			int Last = Count - 1;
			int Middle;
			int pos = -1;

			bool Result = false;
			while ((First <= Last) && (Result == false))
			{
				Middle = (First + Last) / 2;
				if (RecKey == List[Middle].Key)
				{
					First = Last = Middle;
					Result = true;
				}


				else if (RecKey < List[Middle].Key) Last = Middle - 1;
				else First = Middle + 1;
			}
			pos = First;
			Result = false;
			if ((pos < Count) && (List[pos].Key == RecKey)) Result = true;
			if (List[pos].Key == RecKey) return pos;
			else
			{
				return -1;
			}
		}

		int AddRecord(TRecord &Rec)
		{
			int pos; //����� ������� ��� �������			
			{   if (Count == 0)	{ pos=0;} // ������� � ������
			else if (Count == Size) { cout << "������� ���������"<<endl; return 0; } 
			else if (SeachRecord(Rec.Key) != -1) // �������� �� ������������� ������ 
			{
				cout << "������ � " << Rec.Key << " ������ ��� ����������" << endl; return 0;
			}
			else
				{
					for (int i(0); i < Count; i++) //���� �� ������� ��� ������ ����� ������� ������, ����� �� ���������� ���������� �������
						if (Rec.Key<List[i].Key) 
							{  
							  pos = i;	//������� �������					
								for (int j = Count; j > pos; j--)
								{
									List[j].Key = List[j-1].Key;
									List[j].Data = List[j-1].Data;
								}		
								break;
							}						
						else
							pos = Count;	//������� � �����		
					}
			List[pos].Key = Rec.Key;
			List[pos].Data = Rec.Data;
			Count++;					
			}		
			return 0;
		}
		bool DelRecord(string RecKey)
		{
			int pos;
			pos = Seachpos(RecKey);
			if (pos == -1) return false;
			else
			{
				for (int i = pos; i < Count - 1; i++)
					List[i] = List[i + 1];
				Count--;
				return true;
			}
		}
		
		void Sort(int lo, int hi)
		{
			int h, l;
			string p;

			if (lo < hi)
			{
				l = lo;
				h = hi;
				p = List[h].Key;

				while (l < h)
				{
					while ((l < h) && (List[l].Key <= p)) l++;
					while ((l < h) && (List[l].Key >= p)) h--;

					if (l < h) swap(List[l], List[h]);

				}

				swap(List[l], List[hi]);

				Sort(lo, l - 1);
				Sort(l + 1, hi);
			}
		}
		void Print()
		{
			for (int i(0); i < Count; i++)
			{
				cout <<setw(10)<< List[i].Key << " " <<List[i].Data << endl;
			}
		}
	
	};