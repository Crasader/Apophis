// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_REFLECTION_REFLECTION_H_
#define FLATBUFFERS_GENERATED_REFLECTION_REFLECTION_H_

#include "flatbuffers/flatbuffers.h"

namespace reflection {

    struct Type;

    struct KeyValue;

    struct EnumVal;

    struct Enum;

    struct Field;

    struct Object;

    struct Schema;

    enum BaseType {
        None = 0,
        UType = 1,
        Bool = 2,
        Byte = 3,
        UByte = 4,
        Short = 5,
        UShort = 6,
        Int = 7,
        UInt = 8,
        Long = 9,
        ULong = 10,
        Float = 11,
        Double = 12,
        String = 13,
        Vector = 14,
        Obj = 15,
        Union = 16
    };

    inline const char** EnumNamesBaseType() {
        static const char* names[] = { "None", "UType", "Bool", "Byte", "UByte", "Short", "UShort", "Int", "UInt", "Long", "ULong", "Float", "Double", "String", "Vector", "Obj", "Union", nullptr };
        return names;
    }

    inline const char* EnumNameBaseType(BaseType e) { return EnumNamesBaseType()[static_cast<int>(e)]; }

    struct Type FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_BASE_TYPE = 4,
            VT_ELEMENT = 6,
            VT_INDEX = 8
        };
        BaseType base_type() const { return static_cast<BaseType>(GetField<int8_t>(VT_BASE_TYPE, 0)); }
        BaseType element() const { return static_cast<BaseType>(GetField<int8_t>(VT_ELEMENT, 0)); }
        int32_t index() const { return GetField<int32_t>(VT_INDEX, -1); }
        bool Verify(flatbuffers::Verifier & verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyField<int8_t>(verifier, VT_BASE_TYPE) &&
                VerifyField<int8_t>(verifier, VT_ELEMENT) &&
                VerifyField<int32_t>(verifier, VT_INDEX) &&
                verifier.EndTable();
        }
    };

    struct TypeBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_base_type(BaseType base_type) { fbb_.AddElement<int8_t>(Type::VT_BASE_TYPE, static_cast<int8_t>(base_type), 0); }
        void add_element(BaseType element) { fbb_.AddElement<int8_t>(Type::VT_ELEMENT, static_cast<int8_t>(element), 0); }
        void add_index(int32_t index) { fbb_.AddElement<int32_t>(Type::VT_INDEX, index, -1); }
        TypeBuilder(flatbuffers::FlatBufferBuilder & _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        TypeBuilder& operator=(const TypeBuilder&);
        flatbuffers::Offset<Type> Finish() {
            auto o = flatbuffers::Offset<Type>(fbb_.EndTable(start_, 3));
            return o;
        }
    };

    inline flatbuffers::Offset<Type> CreateType(flatbuffers::FlatBufferBuilder& _fbb,
        BaseType base_type = None,
        BaseType element = None,
        int32_t index = -1) {
        TypeBuilder builder_(_fbb);
        builder_.add_index(index);
        builder_.add_element(element);
        builder_.add_base_type(base_type);
        return builder_.Finish();
    }

    struct KeyValue FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_KEY = 4,
            VT_VALUE = 6
        };
        const flatbuffers::String* key() const { return GetPointer<const flatbuffers::String*>(VT_KEY); }
        bool KeyCompareLessThan(const KeyValue* o) const { return *key() < *o->key(); }
        int KeyCompareWithValue(const char* val) const { return strcmp(key()->c_str(), val); }
        const flatbuffers::String* value() const { return GetPointer<const flatbuffers::String*>(VT_VALUE); }
        bool Verify(flatbuffers::Verifier& verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_KEY) &&
                verifier.Verify(key()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUE) &&
                verifier.Verify(value()) &&
                verifier.EndTable();
        }
    };

    struct KeyValueBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_key(flatbuffers::Offset<flatbuffers::String> key) { fbb_.AddOffset(KeyValue::VT_KEY, key); }
        void add_value(flatbuffers::Offset<flatbuffers::String> value) { fbb_.AddOffset(KeyValue::VT_VALUE, value); }
        KeyValueBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        KeyValueBuilder& operator=(const KeyValueBuilder&);
        flatbuffers::Offset<KeyValue> Finish() {
            auto o = flatbuffers::Offset<KeyValue>(fbb_.EndTable(start_, 2));
            fbb_.Required(o, KeyValue::VT_KEY);  // key
            return o;
        }
    };

    inline flatbuffers::Offset<KeyValue> CreateKeyValue(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<flatbuffers::String> key = 0,
        flatbuffers::Offset<flatbuffers::String> value = 0) {
        KeyValueBuilder builder_(_fbb);
        builder_.add_value(value);
        builder_.add_key(key);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<KeyValue> CreateKeyValueDirect(flatbuffers::FlatBufferBuilder& _fbb,
        const char* key = nullptr,
        const char* value = nullptr) {
        return CreateKeyValue(_fbb, key ? _fbb.CreateString(key) : 0, value ? _fbb.CreateString(value) : 0);
    }

    struct EnumVal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_NAME = 4,
            VT_VALUE = 6,
            VT_OBJECT = 8
        };
        const flatbuffers::String* name() const { return GetPointer<const flatbuffers::String*>(VT_NAME); }
        int64_t value() const { return GetField<int64_t>(VT_VALUE, 0); }
        bool KeyCompareLessThan(const EnumVal* o) const { return value() < o->value(); }
        int KeyCompareWithValue(int64_t val) const { return value() < val ? -1 : value() > val; }
        const Object* object() const { return GetPointer<const Object*>(VT_OBJECT); }
        bool Verify(flatbuffers::Verifier& verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
                verifier.Verify(name()) &&
                VerifyField<int64_t>(verifier, VT_VALUE) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBJECT) &&
                verifier.VerifyTable(object()) &&
                verifier.EndTable();
        }
    };

    struct EnumValBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(EnumVal::VT_NAME, name); }
        void add_value(int64_t value) { fbb_.AddElement<int64_t>(EnumVal::VT_VALUE, value, 0); }
        void add_object(flatbuffers::Offset<Object> object) { fbb_.AddOffset(EnumVal::VT_OBJECT, object); }
        EnumValBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        EnumValBuilder& operator=(const EnumValBuilder&);
        flatbuffers::Offset<EnumVal> Finish() {
            auto o = flatbuffers::Offset<EnumVal>(fbb_.EndTable(start_, 3));
            fbb_.Required(o, EnumVal::VT_NAME);  // name
            return o;
        }
    };

    inline flatbuffers::Offset<EnumVal> CreateEnumVal(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<flatbuffers::String> name = 0,
        int64_t value = 0,
        flatbuffers::Offset<Object> object = 0) {
        EnumValBuilder builder_(_fbb);
        builder_.add_value(value);
        builder_.add_object(object);
        builder_.add_name(name);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<EnumVal> CreateEnumValDirect(flatbuffers::FlatBufferBuilder& _fbb,
        const char* name = nullptr,
        int64_t value = 0,
        flatbuffers::Offset<Object> object = 0) {
        return CreateEnumVal(_fbb, name ? _fbb.CreateString(name) : 0, value, object);
    }

    struct Enum FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_NAME = 4,
            VT_VALUES = 6,
            VT_IS_UNION = 8,
            VT_UNDERLYING_TYPE = 10,
            VT_ATTRIBUTES = 12
        };
        const flatbuffers::String* name() const { return GetPointer<const flatbuffers::String*>(VT_NAME); }
        bool KeyCompareLessThan(const Enum* o) const { return *name() < *o->name(); }
        int KeyCompareWithValue(const char* val) const { return strcmp(name()->c_str(), val); }
        const flatbuffers::Vector<flatbuffers::Offset<EnumVal>>* values() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<EnumVal>>*>(VT_VALUES); }
        bool is_union() const { return GetField<uint8_t>(VT_IS_UNION, 0) != 0; }
        const Type* underlying_type() const { return GetPointer<const Type*>(VT_UNDERLYING_TYPE); }
        const flatbuffers::Vector<flatbuffers::Offset<KeyValue>>* attributes() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<KeyValue>>*>(VT_ATTRIBUTES); }
        bool Verify(flatbuffers::Verifier& verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
                verifier.Verify(name()) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_VALUES) &&
                verifier.Verify(values()) &&
                verifier.VerifyVectorOfTables(values()) &&
                VerifyField<uint8_t>(verifier, VT_IS_UNION) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_UNDERLYING_TYPE) &&
                verifier.VerifyTable(underlying_type()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ATTRIBUTES) &&
                verifier.Verify(attributes()) &&
                verifier.VerifyVectorOfTables(attributes()) &&
                verifier.EndTable();
        }
    };

    struct EnumBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Enum::VT_NAME, name); }
        void add_values(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<EnumVal>>> values) { fbb_.AddOffset(Enum::VT_VALUES, values); }
        void add_is_union(bool is_union) { fbb_.AddElement<uint8_t>(Enum::VT_IS_UNION, static_cast<uint8_t>(is_union), 0); }
        void add_underlying_type(flatbuffers::Offset<Type> underlying_type) { fbb_.AddOffset(Enum::VT_UNDERLYING_TYPE, underlying_type); }
        void add_attributes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> attributes) { fbb_.AddOffset(Enum::VT_ATTRIBUTES, attributes); }
        EnumBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        EnumBuilder& operator=(const EnumBuilder&);
        flatbuffers::Offset<Enum> Finish() {
            auto o = flatbuffers::Offset<Enum>(fbb_.EndTable(start_, 5));
            fbb_.Required(o, Enum::VT_NAME);  // name
            fbb_.Required(o, Enum::VT_VALUES);  // values
            fbb_.Required(o, Enum::VT_UNDERLYING_TYPE);  // underlying_type
            return o;
        }
    };

    inline flatbuffers::Offset<Enum> CreateEnum(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<flatbuffers::String> name = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<EnumVal>>> values = 0,
        bool is_union = false,
        flatbuffers::Offset<Type> underlying_type = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> attributes = 0) {
        EnumBuilder builder_(_fbb);
        builder_.add_attributes(attributes);
        builder_.add_underlying_type(underlying_type);
        builder_.add_values(values);
        builder_.add_name(name);
        builder_.add_is_union(is_union);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<Enum> CreateEnumDirect(flatbuffers::FlatBufferBuilder& _fbb,
        const char* name = nullptr,
        const std::vector<flatbuffers::Offset<EnumVal>>* values = nullptr,
        bool is_union = false,
        flatbuffers::Offset<Type> underlying_type = 0,
        const std::vector<flatbuffers::Offset<KeyValue>>* attributes = nullptr) {
        return CreateEnum(_fbb, name ? _fbb.CreateString(name) : 0, values ? _fbb.CreateVector<flatbuffers::Offset<EnumVal>>(*values) : 0, is_union, underlying_type, attributes ? _fbb.CreateVector<flatbuffers::Offset<KeyValue>>(*attributes) : 0);
    }

    struct Field FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_NAME = 4,
            VT_TYPE = 6,
            VT_ID = 8,
            VT_OFFSET = 10,
            VT_DEFAULT_INTEGER = 12,
            VT_DEFAULT_REAL = 14,
            VT_DEPRECATED = 16,
            VT_REQUIRED = 18,
            VT_KEY = 20,
            VT_ATTRIBUTES = 22
        };
        const flatbuffers::String* name() const { return GetPointer<const flatbuffers::String*>(VT_NAME); }
        bool KeyCompareLessThan(const Field* o) const { return *name() < *o->name(); }
        int KeyCompareWithValue(const char* val) const { return strcmp(name()->c_str(), val); }
        const Type* type() const { return GetPointer<const Type*>(VT_TYPE); }
        uint16_t id() const { return GetField<uint16_t>(VT_ID, 0); }
        uint16_t offset() const { return GetField<uint16_t>(VT_OFFSET, 0); }
        int64_t default_integer() const { return GetField<int64_t>(VT_DEFAULT_INTEGER, 0); }
        double default_real() const { return GetField<double>(VT_DEFAULT_REAL, 0.0); }
        bool deprecated() const { return GetField<uint8_t>(VT_DEPRECATED, 0) != 0; }
        bool required() const { return GetField<uint8_t>(VT_REQUIRED, 0) != 0; }
        bool key() const { return GetField<uint8_t>(VT_KEY, 0) != 0; }
        const flatbuffers::Vector<flatbuffers::Offset<KeyValue>>* attributes() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<KeyValue>>*>(VT_ATTRIBUTES); }
        bool Verify(flatbuffers::Verifier& verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
                verifier.Verify(name()) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_TYPE) &&
                verifier.VerifyTable(type()) &&
                VerifyField<uint16_t>(verifier, VT_ID) &&
                VerifyField<uint16_t>(verifier, VT_OFFSET) &&
                VerifyField<int64_t>(verifier, VT_DEFAULT_INTEGER) &&
                VerifyField<double>(verifier, VT_DEFAULT_REAL) &&
                VerifyField<uint8_t>(verifier, VT_DEPRECATED) &&
                VerifyField<uint8_t>(verifier, VT_REQUIRED) &&
                VerifyField<uint8_t>(verifier, VT_KEY) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ATTRIBUTES) &&
                verifier.Verify(attributes()) &&
                verifier.VerifyVectorOfTables(attributes()) &&
                verifier.EndTable();
        }
    };

    struct FieldBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Field::VT_NAME, name); }
        void add_type(flatbuffers::Offset<Type> type) { fbb_.AddOffset(Field::VT_TYPE, type); }
        void add_id(uint16_t id) { fbb_.AddElement<uint16_t>(Field::VT_ID, id, 0); }
        void add_offset(uint16_t offset) { fbb_.AddElement<uint16_t>(Field::VT_OFFSET, offset, 0); }
        void add_default_integer(int64_t default_integer) { fbb_.AddElement<int64_t>(Field::VT_DEFAULT_INTEGER, default_integer, 0); }
        void add_default_real(double default_real) { fbb_.AddElement<double>(Field::VT_DEFAULT_REAL, default_real, 0.0); }
        void add_deprecated(bool deprecated) { fbb_.AddElement<uint8_t>(Field::VT_DEPRECATED, static_cast<uint8_t>(deprecated), 0); }
        void add_required(bool required) { fbb_.AddElement<uint8_t>(Field::VT_REQUIRED, static_cast<uint8_t>(required), 0); }
        void add_key(bool key) { fbb_.AddElement<uint8_t>(Field::VT_KEY, static_cast<uint8_t>(key), 0); }
        void add_attributes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> attributes) { fbb_.AddOffset(Field::VT_ATTRIBUTES, attributes); }
        FieldBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        FieldBuilder& operator=(const FieldBuilder&);
        flatbuffers::Offset<Field> Finish() {
            auto o = flatbuffers::Offset<Field>(fbb_.EndTable(start_, 10));
            fbb_.Required(o, Field::VT_NAME);  // name
            fbb_.Required(o, Field::VT_TYPE);  // type
            return o;
        }
    };

    inline flatbuffers::Offset<Field> CreateField(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<flatbuffers::String> name = 0,
        flatbuffers::Offset<Type> type = 0,
        uint16_t id = 0,
        uint16_t offset = 0,
        int64_t default_integer = 0,
        double default_real = 0.0,
        bool deprecated = false,
        bool required = false,
        bool key = false,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> attributes = 0) {
        FieldBuilder builder_(_fbb);
        builder_.add_default_real(default_real);
        builder_.add_default_integer(default_integer);
        builder_.add_attributes(attributes);
        builder_.add_type(type);
        builder_.add_name(name);
        builder_.add_offset(offset);
        builder_.add_id(id);
        builder_.add_key(key);
        builder_.add_required(required);
        builder_.add_deprecated(deprecated);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<Field> CreateFieldDirect(flatbuffers::FlatBufferBuilder& _fbb,
        const char* name = nullptr,
        flatbuffers::Offset<Type> type = 0,
        uint16_t id = 0,
        uint16_t offset = 0,
        int64_t default_integer = 0,
        double default_real = 0.0,
        bool deprecated = false,
        bool required = false,
        bool key = false,
        const std::vector<flatbuffers::Offset<KeyValue>>* attributes = nullptr) {
        return CreateField(_fbb, name ? _fbb.CreateString(name) : 0, type, id, offset, default_integer, default_real, deprecated, required, key, attributes ? _fbb.CreateVector<flatbuffers::Offset<KeyValue>>(*attributes) : 0);
    }

    struct Object FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_NAME = 4,
            VT_FIELDS = 6,
            VT_IS_STRUCT = 8,
            VT_MINALIGN = 10,
            VT_BYTESIZE = 12,
            VT_ATTRIBUTES = 14
        };
        const flatbuffers::String* name() const { return GetPointer<const flatbuffers::String*>(VT_NAME); }
        bool KeyCompareLessThan(const Object* o) const { return *name() < *o->name(); }
        int KeyCompareWithValue(const char* val) const { return strcmp(name()->c_str(), val); }
        const flatbuffers::Vector<flatbuffers::Offset<Field>>* fields() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Field>>*>(VT_FIELDS); }
        bool is_struct() const { return GetField<uint8_t>(VT_IS_STRUCT, 0) != 0; }
        int32_t minalign() const { return GetField<int32_t>(VT_MINALIGN, 0); }
        int32_t bytesize() const { return GetField<int32_t>(VT_BYTESIZE, 0); }
        const flatbuffers::Vector<flatbuffers::Offset<KeyValue>>* attributes() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<KeyValue>>*>(VT_ATTRIBUTES); }
        bool Verify(flatbuffers::Verifier& verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
                verifier.Verify(name()) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_FIELDS) &&
                verifier.Verify(fields()) &&
                verifier.VerifyVectorOfTables(fields()) &&
                VerifyField<uint8_t>(verifier, VT_IS_STRUCT) &&
                VerifyField<int32_t>(verifier, VT_MINALIGN) &&
                VerifyField<int32_t>(verifier, VT_BYTESIZE) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ATTRIBUTES) &&
                verifier.Verify(attributes()) &&
                verifier.VerifyVectorOfTables(attributes()) &&
                verifier.EndTable();
        }
    };

    struct ObjectBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(Object::VT_NAME, name); }
        void add_fields(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Field>>> fields) { fbb_.AddOffset(Object::VT_FIELDS, fields); }
        void add_is_struct(bool is_struct) { fbb_.AddElement<uint8_t>(Object::VT_IS_STRUCT, static_cast<uint8_t>(is_struct), 0); }
        void add_minalign(int32_t minalign) { fbb_.AddElement<int32_t>(Object::VT_MINALIGN, minalign, 0); }
        void add_bytesize(int32_t bytesize) { fbb_.AddElement<int32_t>(Object::VT_BYTESIZE, bytesize, 0); }
        void add_attributes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> attributes) { fbb_.AddOffset(Object::VT_ATTRIBUTES, attributes); }
        ObjectBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        ObjectBuilder& operator=(const ObjectBuilder&);
        flatbuffers::Offset<Object> Finish() {
            auto o = flatbuffers::Offset<Object>(fbb_.EndTable(start_, 6));
            fbb_.Required(o, Object::VT_NAME);  // name
            fbb_.Required(o, Object::VT_FIELDS);  // fields
            return o;
        }
    };

    inline flatbuffers::Offset<Object> CreateObject(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<flatbuffers::String> name = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Field>>> fields = 0,
        bool is_struct = false,
        int32_t minalign = 0,
        int32_t bytesize = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> attributes = 0) {
        ObjectBuilder builder_(_fbb);
        builder_.add_attributes(attributes);
        builder_.add_bytesize(bytesize);
        builder_.add_minalign(minalign);
        builder_.add_fields(fields);
        builder_.add_name(name);
        builder_.add_is_struct(is_struct);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<Object> CreateObjectDirect(flatbuffers::FlatBufferBuilder& _fbb,
        const char* name = nullptr,
        const std::vector<flatbuffers::Offset<Field>>* fields = nullptr,
        bool is_struct = false,
        int32_t minalign = 0,
        int32_t bytesize = 0,
        const std::vector<flatbuffers::Offset<KeyValue>>* attributes = nullptr) {
        return CreateObject(_fbb, name ? _fbb.CreateString(name) : 0, fields ? _fbb.CreateVector<flatbuffers::Offset<Field>>(*fields) : 0, is_struct, minalign, bytesize, attributes ? _fbb.CreateVector<flatbuffers::Offset<KeyValue>>(*attributes) : 0);
    }

    struct Schema FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_OBJECTS = 4,
            VT_ENUMS = 6,
            VT_FILE_IDENT = 8,
            VT_FILE_EXT = 10,
            VT_ROOT_TABLE = 12
        };
        const flatbuffers::Vector<flatbuffers::Offset<Object>>* objects() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Object>>*>(VT_OBJECTS); }
        const flatbuffers::Vector<flatbuffers::Offset<Enum>>* enums() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Enum>>*>(VT_ENUMS); }
        const flatbuffers::String* file_ident() const { return GetPointer<const flatbuffers::String*>(VT_FILE_IDENT); }
        const flatbuffers::String* file_ext() const { return GetPointer<const flatbuffers::String*>(VT_FILE_EXT); }
        const Object* root_table() const { return GetPointer<const Object*>(VT_ROOT_TABLE); }
        bool Verify(flatbuffers::Verifier& verifier) const {
            return VerifyTableStart(verifier) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_OBJECTS) &&
                verifier.Verify(objects()) &&
                verifier.VerifyVectorOfTables(objects()) &&
                VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_ENUMS) &&
                verifier.Verify(enums()) &&
                verifier.VerifyVectorOfTables(enums()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_FILE_IDENT) &&
                verifier.Verify(file_ident()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_FILE_EXT) &&
                verifier.Verify(file_ext()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ROOT_TABLE) &&
                verifier.VerifyTable(root_table()) &&
                verifier.EndTable();
        }
    };

    struct SchemaBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_objects(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Object>>> objects) { fbb_.AddOffset(Schema::VT_OBJECTS, objects); }
        void add_enums(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Enum>>> enums) { fbb_.AddOffset(Schema::VT_ENUMS, enums); }
        void add_file_ident(flatbuffers::Offset<flatbuffers::String> file_ident) { fbb_.AddOffset(Schema::VT_FILE_IDENT, file_ident); }
        void add_file_ext(flatbuffers::Offset<flatbuffers::String> file_ext) { fbb_.AddOffset(Schema::VT_FILE_EXT, file_ext); }
        void add_root_table(flatbuffers::Offset<Object> root_table) { fbb_.AddOffset(Schema::VT_ROOT_TABLE, root_table); }
        SchemaBuilder(flatbuffers::FlatBufferBuilder& _fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
        SchemaBuilder& operator=(const SchemaBuilder&);
        flatbuffers::Offset<Schema> Finish() {
            auto o = flatbuffers::Offset<Schema>(fbb_.EndTable(start_, 5));
            fbb_.Required(o, Schema::VT_OBJECTS);  // objects
            fbb_.Required(o, Schema::VT_ENUMS);  // enums
            return o;
        }
    };

    inline flatbuffers::Offset<Schema> CreateSchema(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Object>>> objects = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Enum>>> enums = 0,
        flatbuffers::Offset<flatbuffers::String> file_ident = 0,
        flatbuffers::Offset<flatbuffers::String> file_ext = 0,
        flatbuffers::Offset<Object> root_table = 0) {
        SchemaBuilder builder_(_fbb);
        builder_.add_root_table(root_table);
        builder_.add_file_ext(file_ext);
        builder_.add_file_ident(file_ident);
        builder_.add_enums(enums);
        builder_.add_objects(objects);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<Schema> CreateSchemaDirect(flatbuffers::FlatBufferBuilder& _fbb,
        const std::vector<flatbuffers::Offset<Object>>* objects = nullptr,
        const std::vector<flatbuffers::Offset<Enum>>* enums = nullptr,
        const char* file_ident = nullptr,
        const char* file_ext = nullptr,
        flatbuffers::Offset<Object> root_table = 0) {
        return CreateSchema(_fbb, objects ? _fbb.CreateVector<flatbuffers::Offset<Object>>(*objects) : 0, enums ? _fbb.CreateVector<flatbuffers::Offset<Enum>>(*enums) : 0, file_ident ? _fbb.CreateString(file_ident) : 0, file_ext ? _fbb.CreateString(file_ext) : 0, root_table);
    }

    inline const reflection::Schema* GetSchema(const void* buf) {
        return flatbuffers::GetRoot<reflection::Schema>(buf);
    }

    inline const char* SchemaIdentifier() {
        return "BFBS";
    }

    inline bool SchemaBufferHasIdentifier(const void* buf) {
        return flatbuffers::BufferHasIdentifier(buf, SchemaIdentifier());
    }

    inline bool VerifySchemaBuffer(flatbuffers::Verifier& verifier) {
        return verifier.VerifyBuffer<reflection::Schema>(SchemaIdentifier());
    }

    inline const char* SchemaExtension() { return "bfbs"; }

    inline void FinishSchemaBuffer(flatbuffers::FlatBufferBuilder& fbb, flatbuffers::Offset<reflection::Schema> root) {
        fbb.Finish(root, SchemaIdentifier());
    }

}  // namespace reflection

#endif  // FLATBUFFERS_GENERATED_REFLECTION_REFLECTION_H_
