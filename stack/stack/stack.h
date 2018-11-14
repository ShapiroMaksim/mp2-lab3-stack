#pragma once
template <class T>
class TStack
{
	int MaxSize, Size;
	T *mas;
public:
	TStack(int MS)
	{
		MaxSize=MS;
		mas=new T[MaxSize];
		Size=0;
	}

	TStack(const TStack &v)
	{
		MaxSize=v.MaxSize;
		Size=v.Size;
		mas=new T[MaxSize];
		for(int i=0; i<Size; i++)
			mas[i]=v.mas[i];
	}

	void Push(const T&v)
	{
		if(Size==MaxSize)
			throw Size;
		else
		{
			mas[size]=v;
			Size++;
		}
	}

	T Pop()
	{
		if(Size==0)
			throw Size;
		else
		{
			Size--;
	        return mas[Size];
		}
	}

	T Top()
	{
		if(Size==0)
			throw Size;
		else
			return mas[Size-1];
	}

	bool IsEmpty() const
	{
		return(Size==0);
	}

	bool IsFull() const
	{
		return(Size==MaxSize);
	}

	bool check(char *str)
	{
		TStack<char> chk(10);
		for(int i=0; i<len(str); i++)
		{
			if(str[i]=='(')
				chk.Push(str[i]);
			if(str[i]==')')
				if(chk.IsEmpty())
					return false;
				else
					chk.Pop();
		}
		return true;
	}
}