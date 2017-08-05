#include<vector>
#include<cmath>


namespace MatricialAlgebra {
	template<typename T>
	class Vector {
	private:
		size_t m_Size=0;			//current size of the vector
		std::vector<T>m_Vector;		//std::vector containing the data for this vector
		bool m_isNULL = false;		//whether or not the vector is a null object
		bool m_isAsync = false;		//whether or not threading should be used to facilitate with larger vectors
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

		/*
		returns a vector that is the difference of the first vector with the second

		@param val - the vector to calculate difference with
		@return vector that is the difference of both vectors
		*/
		constexpr Vector<T> operator-(const Vector<T>&val)const;

		/*
		returns a vector that is the product of a vector by a scalar

		@param scalar - value of the scalar to multiply vector with
		*/
		constexpr Vector<T> operator*(const T& scalar)const;

		/*
		cross product
		*/
		constexpr Vector<T> operator*(const Vector<T>& val)const;

		/*
		assignment operator for the vecotr

		@param val - vector whom´s information will be copied into this one
		*/
		void operator=(const Vector<T> &val);
		
		/*
		returns the null flag value for this vector

		@return returns whether or not this vector is a null object
		*/
		constexpr bool isNUll()const;

		/*
		returns whether or not thread scaling technology is being used

		@return whether or not threading is being used
		*/
		constexpr bool isAsync()const;

		constexpr double Norm()const;//tentative name
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

		/*	If the mathematical vectors are not of the same size
			the operation cannot be executed and therefore a NULL
			object is returned
			if one of the objects is null the sum can not proceed
			either returning a null object 
		*/

		if (this->m_Size != val.m_Size) {
			return Vector<T>();
		}else if (this->m_isNULL || val.m_isNULL) {
			return Vector<T>();
		}

		/*
			if we reach this point we have accessed that the vectors
			in question are valid candidates to be summed , take into
			account that if the data inside the vectors is not valid
			errors will still take place.
		*/

		Vector<T> ret(this->m_Size);	//vector where the sum of the vectors will be kept

		if (this->m_isAsync) {

			/*
				if we are not going to use threading technology we merely 
				need to go over all the elements in both vector and sum the
				ones with matching indexes.
				So say we have 2 vectors with 4 elements we will go over 
				each of the 4 elements of both vectors , atributing to the
				0th index of the resulting vector the value of the sum of the 
				values in the 0th index of the original vectors.
			*/

			for (size_t i = 0;i < this->m_Size;++i) {
				ret[i] = this->at(i) + val.at(i);
			}
		}
		else {// we are going to use threading technology

		}

		//	we finnally return the resulting vector
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

	template<typename T>
	inline constexpr double Vector<T>::Norm() const
	{
		double ret;
		double sum=0;

		for (size_t i = 0;i < this->m_Size;++i) {
			sum += this->at(i)*this->at(i);
		}
		ret = sqrt(sum);

		return ret;
	}
}