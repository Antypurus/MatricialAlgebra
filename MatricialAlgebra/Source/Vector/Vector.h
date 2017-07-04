#include<vector>


namespace MatricialAlgebra {
	template<typename T>
	class Vector {
	private:
		size_t m_Size=0;//current size of the vector
		std::vector<T>m_Vector;//std::vector containing the data for this vector
		bool m_isNULL = false;//whether or not the vector is a null object
	public:
		/*
		Standard Constructor For the Vector ,the number of values 
		of the vector is passed as an argument

		@param size - size of the mathematical vector
		*/
		Vector(size_t size);

		/*
		Returns the size of the vector object

		@return - the number of values in the vector
		*/
		size_t getSize()const;

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

		T operator+(const T& val)const;
	};

	template<typename T>
	inline Vector<T>::Vector(size_t size)
	{
		this->m_Size = size;
		this->m_Vector = std::vector<T>(size);
	}

	template<typename T>
	inline size_t Vector<T>::getSize() const
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
}