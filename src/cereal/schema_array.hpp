#pragma once

#include <vector>
#include <cereal/types/vector.hpp>

namespace cereal {

/**
 * Schema array is a thin wrapping around a std::vector that 
 * enforces size constraints. Note that the minium size constraint
 * is only ever enforced in the load/save functions, but that the 
 * maximum size constraint is enforced often, for example on copy 
 * and assignment, and in the push_back function.
 *
 * NOTE: please, never expose the underlying vector to the outside
 * world - instead, if a function is required from the std::vector
 * class, write a wrapper function that exposes it, and enforces
 * any size constraints if necessary. 
 */
template<typename Type, std::size_t MaxSize=65536, std::size_t MinSize=0>
struct schema_array  
{
    static_assert(MinSize <= MaxSize, "MinSize must be less than or equal to MaxSize");
    using exception=cereal::Exception;

    schema_array()
        : array_{}
    {}

    /// throws if max size is violated
    schema_array(const schema_array& that)
    {
        operator=(that);
    }

    /// throws if max size is violated
    schema_array& operator=(const schema_array& that)
    {
        enforce_max_size_constraint(that.size());
        array_ = that.array_;
        return *this;
    }

    /// throws if max size is violated
    schema_array(schema_array&& that)
    {
        operator=(std::forward<schema_array>(that));
    }

    /// throws if max size is violated
    schema_array& operator=(schema_array&& that)
    {
        enforce_max_size_constraint(that.size());
        array_ = std::move(that.array_);
        return *this;
    }

    /// cereal required function
    template<class Archive>
    void save(Archive & archive) const
    {
        enforce_size_constraints(array_.size());
        archive( cereal::make_size_tag( static_cast<cereal::size_type>(array_.size()) ) ); // number of elements
        for(auto && v : array_)
          archive( v );
    }

    /// cereal required function
    template<class Archive>
    void load(Archive & archive)
    {
        cereal::size_type size;
        archive( cereal::make_size_tag( size ) );
        enforce_size_constraints(static_cast<std::size_t>(size));

        array_.resize( static_cast<std::size_t>( size ) );
        for(auto && v : array_)
          archive( v );
    }

    /// Wraps vector::clear
    void clear() { array_.clear(); }

    /// Wraps vector::push_back, throws if max size is violated
    void push_back(const Type& value)
    {
        enforce_max_size_constraint(array_.size()+1);
        array_.push_back(value);
    }

    /// Wraps vector::push_back, throws if max size is violated
    void push_back(Type&& value)
    {
        enforce_max_size_constraint(array_.size()+1);
        array_.push_back(std::forward<Type>(value));
    }

    /// Wraps vector::size
    std::size_t size() const { return array_.size(); }

    /// Wraps vector::resize, throws if size  restrictions are violated
    void resize(const std::size_t& size) 
    { 
        enforce_size_constraints(size);
        array_.resize(size); 
    }

    /// Wraps vector::operator[]
    Type& operator[](const std::size_t& idx) { return array_.at(idx); }

    /// Wraps vector::operator[]
    const Type& operator[](const std::size_t& idx) const { return array_.at(idx); }

    private:

    void enforce_min_size_constraint(const std::size_t size) const
    {
        if (size < MinSize)
        {
            throw exception(std::string{"schema_array too small"});
        }
    }

    void enforce_max_size_constraint(const std::size_t size) const
    {
        if (size > MaxSize)
        {
            throw exception(std::string{"schema_array large"});
        }
    }

    void enforce_size_constraints(const std::size_t size) const
    {
        enforce_min_size_constraint(size);
        enforce_max_size_constraint(size);
    }
    
    std::vector<Type> array_;
};

}
