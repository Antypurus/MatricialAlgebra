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

		constexpr Vector<T> operator-(const Vector<T>&val)const;

		constexpr Vector<T> operator*(const T& scalar)const;

		constexpr Vector<T> operator*(const Vector<T>& val)const;

		void operator=(const Vector<T> &val);
		
		/*
		returns the null flag value for this vector
		@return returns whether or not this vector is a null object
		*/
		constexpr bool isNUll()const;

		constexpr bool isAsync()const;
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

	//TODO: need to update this with the async flag
	template<typename T>
	constexpr inline Vector<T> Vector<T>::operator+(const Vector<T> & val) const
	{
		//If the mathematical vectors are not of the same size
		//the operation cannot be executed and therefore a NULL
		//object is returned
		if (this->m_Size != val.m_Size) {
			return Vector<T>();
		}else if (this->m_isNULL || val.m_isNULL) {
			return Vector<T>();
		}

		Vector<T> ret(this->m_Size);
		for (size_t i = 0;i < this->m_Size;++i) {
			ret[i] = this->at(i) + val.at(i);
		}
		return ret;
	}

	//TODO: need to update this with the asaync flag
	template<typename T>
	inline constexpr Vector<T> Vector<T>::operator-(const Vector<T>& val) const
	{
		if (this->m_Size != val.m_Size) {
			return Vector<T>();
		}else if (this->m_isNULL || val.m_isNULL) {
			return Vector<T>();
		}

		Vector<T> ret(this->m_Size, this->m_isAsync);
		for (size_t i = 0;i < this->m_Size;++i) {
			ret[i] = this->at(i) - val.at(i);
		}
		return ret;
	}

	//The product of a scalar by a vector
	template<typename T>
	inline constexpr Vector<T> Vector<T>::operator*(const T & scalar) const
	{
		if(this->m_isNULL){
			return Vector<T>();
		}
		
		Vector<T> ret(this->m_Size);
		for (size_t i = 0;i < this->m_Size;++i) {
			ret[i] = this->at(i) * scalar;
		}
		return ret;
	}

	//The dot product
	template<typename T>
	inline constexpr Vector<T> Vector<T>::operator*(const Vector<T>& val) const
	{
		return Vector<T>();
	}

	template<typename T>
	inline void Vector<T>::operator=(const Vector<T>& val)
	{
		this->m_isAsync = val.m_isAsync;
		this->m_isNULL = val.m_isNULL;
		this->m_Size = val.m_Size;
		this->m_Vector = val.m_Vector;
	}

	template<typename T>
	inline constexpr bool Vector<T>::isNUll() const
	{
		return this->m_isNULL;
	}
	template<typename T>
	inline constexpr bool Vector<T>::isAsync() const
	{
		return this->m_isAsync;
	}
}