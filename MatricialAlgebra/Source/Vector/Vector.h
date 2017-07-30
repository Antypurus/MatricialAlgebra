#include<vector>


namespace MatricialAlgebra {
	template<typename T>
	class Vector {
	private:
		size_t m_Size=0;//current size of the vector
		std::vector<T>m_Vector;//std::vector containing the data for this vector
		bool m_isNULL = false;//whether or not the vector is a null object
		bool m_isAsync = false;//whether or not threading should be used to facilitate with larger vectors
	public:
		/*
		Standard Constructor For the Vector ,the number of values 
		of the vector is passed as an argument

		@param size - size of the mathematical vector
		*/
		Vector(size_t size=0,bool async = false);

		/*
		Returns the size of the vector object

		@return - the number of values in the vector
		*/
		constexpr size_t getSize()const;

		/*
		Overload of the operator[] for acces to the data
		@return a reference to the object in the data vector
		*/
		T& operator[](const size_t val);

		/*
		constant version of the operator[] overload
		@return a constant reference to the object in the data vector
		*/
		const T& at(const size_t val)const;

		/*
		returns a vector that is the sum of both vectors
		@param val - the vector to sum with
		@return vector that is the sum of both vectors
		*/
		constexpr Vector<T> operator+(const Vector<T>& val)const;
		
		constexpr bool isNUll()const;
	};

	template<typename T>
	inline Vector<T>::Vector(size_t size,bool async)
	{
		this->m_isAsync = async;
		this->m_Size = size;
		this->m_Vector = std::vector<T>(size);

		if (size == 0) {
			this->m_isNULL = true;
		}
	}

	template<typename T>
	inline constexpr size_t Vector<T>::getSize() const
	{
		return this->m_Size;
	}

	template<typename T>
	inline T& Vector<T>::operator[](const size_t val)
	{
		return this->m_Vector[val];
	}

	template<typename T>
	inline const T& Vector<T>::at(const size_t val)const
	{
		return this->m_Vector.at(val);
	}

	template<typename T>
	constexpr inline Vector<T> Vector<T>::operator+(const Vector<T> & val) const
	{
		//If the mathematical vectors are not of the same size
		//the operation cannot be executed and therefore a NULL
		//object is returned
		if (this->m_Size != val.getSize()) {
			return Vector<T>();
		}

		Vector<T> ret(this->m_Size);
		for (int i = 0;i < this->m_Size;++i) {
			ret[i] = this->at(i) + val.at(i);
		}
		return ret;
	}
	template<typename T>
	inline constexpr bool Vector<T>::isNUll() const
	{
		return this->m_isNULL;
	}
}