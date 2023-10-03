#include <iostream>


namespace Stack
{
	template<typename T>
	class ADT abstract 
	{
	public:
		virtual void Push(T const) abstract;
		virtual void Pop(void) abstract;
		virtual T Top(void) const abstract;
	};

	namespace Implementation
	{
		template<typename T>
		class Array:
			public Stack::ADT<T>
		{
		public:
			Array(void):
				Capacity(Stack::Implementation::Array<T>::InitCapacity),
				Size(0)
			{
				this->Ptr_StackBottom = new T[this->Capacity];
				this->Ptr_StackSizeTop = nullptr;
				this->Ptr_StackCapacityTop = this->Ptr_StackBottom + (this->Capacity - 1);
				return;
			}
			Array(int InInitialCapacity, T InitValue=0):
				Capacity(InInitialCapacity),
				Size(0)
			{
				this->Ptr_StackBottom = new T[this->Capacity];
				this->Ptr_StackSizeTop = nullptr;
				for (std::size_t i = 0; i < this->Capacity; ++i)
				{
					*(this->Ptr_StackBottom) = InitValue;
				}
				this->Ptr_StackCapacityTop = this->Ptr_StackBottom + (this->Capacity - 1);
				return;
			}
			Array(T* InitializeArray, int InitializeArraySize):
				Size(InitializeArraySize)
			{
				// Validate InitializeArray
				if (!InitializeArray)
				{
					return;
				}
				// Capacity
				if (InitializeArraySize > Stack::Implementation::Array<T>::InitCapacity)
				{
					this->Capacity = InitializeArraySize * 2;
				}
				else
				{
					this->Capacity = Stack::Implementation::Array<T>::InitCapacity;
				}
				this->Ptr_StackBottom = new T[this->Capacity];
				for (std::size_t i = 0; i < this->Capacity; ++i)
				{
					if (i <= InitializeArraySize - 1)
					{
						this->Ptr_StackBottom[i] = InitializeArray[i];
					}
					else
					{
						this->Ptr_StackBottom[i] = InitializeArray[InitializeArraySize - 1];
					}
				}
				this->Ptr_StackSizeTop = this->Ptr_StackBottom + (InitializeArraySize - 1);
				return;
			}
		public:
			virtual void Push(T const Value) final 
			{
				int const NewSize = this->Size + 1;
				if (this->Ptr_StackSizeTop == nullptr)
				{
					this->Ptr_StackSizeTop = this->Ptr_StackBottom;
					this->Ptr_StackBottom[NewSize - 1] = Value;
					this->Size++;
					return;
				}
				if (NewSize < this->Capacity)
				{
					this->Ptr_StackBottom[NewSize - 1] = Value;
					this->Size += 1;
					this->Ptr_StackSizeTop += 1;
				}
				else
				{
					int const NewStackCapacity = this->Capacity + Stack::Implementation::Array<T>::InitCapacity;
					T* tPtr_StackBottom = new T[NewStackCapacity];
					for (std::size_t i = 0; i < NewStackCapacity; ++i)
					{
						if (i <= this->Capacity - 1)
						{
							tPtr_StackBottom[i] = this->Ptr_StackBottom[i];
						}
						else
						{
							tPtr_StackBottom[i] = this->Ptr_StackBottom[this->Capacity - 1];
						}
					}
					this->Ptr_StackSizeTop = nullptr;
					delete this->Ptr_StackBottom;
					this->Ptr_StackBottom = tPtr_StackBottom;
					this->Ptr_StackSizeTop = this->Ptr_StackBottom + (NewSize - 1);
					this->Capacity = NewStackCapacity;
					++this->Size;
				}
				return;
			}
			virtual void Pop(void) final 
			{
				if (this->Size == 0)
				{
					return;
				}
				--this->Ptr_StackSizeTop;
				--this->Size;
				return;
			}
			virtual T Top(void) const final
			{
				if (this->Size == 0)
				{
					return T();
				}
				return *(this->Ptr_StackSizeTop);
			}
			int GetSize(void) const
			{
				return this->Size;
			}
			int GetCapacity(void) const
			{
				return this->Capacity;
			}
		private:
			T* Ptr_StackBottom;
			T* Ptr_StackSizeTop;
			T* Ptr_StackCapacityTop;
			int Capacity;
			int Size;
			static int const InitCapacity = 10;
		};
	}
}

int main(void)
{
	typedef Stack::Implementation::Array<int> RStack;

	int* InitArr = new int[11] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	RStack IntegerStackInstance = RStack(InitArr, 11);
	for (std::size_t i = 0; i < 95; ++i)
	{
		IntegerStackInstance.Push(i * 100);
	}


	std::cout << IntegerStackInstance.Top() << std::endl;
	std::cout << IntegerStackInstance.GetSize() << std::endl;
	std::cout << IntegerStackInstance.GetCapacity() << std::endl;


	return 0;
}