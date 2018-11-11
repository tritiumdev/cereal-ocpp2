#pragma once

#include <experimental/optional>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

// See https://github.com/USCiLab/cereal/pull/328

namespace cereal
{
    using schema_boolean=bool;  // temporary 
    template<typename Type>
    using optional=std::experimental::optional<Type>;

    template <class T> inline
    void nvp( cereal::JSONOutputArchive& archive, const char* name, optional<T>& value )
    {
        if (!value)
            archive.setNextName(nullptr);
        else
            archive(make_nvp(name, value.value()));
    }

    template <class T> inline
    void nvp( cereal::JSONInputArchive& archive, const char* name, optional<T>& value )
    {
        T t;
        try
        {
            archive(make_nvp(name, t));
            value = t;
        }
        catch(cereal::Exception&)
        {
            archive.setNextName(nullptr);
        }
    }

    ///
    /// This function is supplied as a counterpart to optional_nvp
    /// api above. This basically causes all code to use a consistent
    /// API, regardless of whether values are optional or not.
    ///
    template <class Archive, class T> inline
    void nvp( Archive& archive, const char* name, T& value )
    {
        archive(make_nvp(name, value));
    }

} // namespace cereal

