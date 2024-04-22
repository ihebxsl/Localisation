//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/localisation/LocalisationHello.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "LocalisationHello_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

Register_Class(WhereIam)

WhereIam::WhereIam() : ::inet::FieldsChunk()
{
}

WhereIam::WhereIam(const WhereIam& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

WhereIam::~WhereIam()
{
}

WhereIam& WhereIam::operator=(const WhereIam& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void WhereIam::copy(const WhereIam& other)
{
    this->srcAddress = other.srcAddress;
}

void WhereIam::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
}

void WhereIam::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
}

const L3Address& WhereIam::getSrcAddress() const
{
    return this->srcAddress;
}

void WhereIam::setSrcAddress(const L3Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

class WhereIamDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddress,
    };
  public:
    WhereIamDescriptor();
    virtual ~WhereIamDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(WhereIamDescriptor)

WhereIamDescriptor::WhereIamDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::WhereIam)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

WhereIamDescriptor::~WhereIamDescriptor()
{
    delete[] propertyNames;
}

bool WhereIamDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WhereIam *>(obj)!=nullptr;
}

const char **WhereIamDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WhereIamDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WhereIamDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int WhereIamDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *WhereIamDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int WhereIamDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *WhereIamDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **WhereIamDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *WhereIamDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int WhereIamDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WhereIamDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WhereIam'", field);
    }
}

const char *WhereIamDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WhereIamDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        default: return "";
    }
}

void WhereIamDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WhereIam'", field);
    }
}

omnetpp::cValue WhereIamDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WhereIam' as cValue -- field index out of range?", field);
    }
}

void WhereIamDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WhereIam'", field);
    }
}

const char *WhereIamDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr WhereIamDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WhereIamDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WhereIam *pp = omnetpp::fromAnyPtr<WhereIam>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WhereIam'", field);
    }
}

Register_Class(AckitementFindMe)

AckitementFindMe::AckitementFindMe() : ::inet::FieldsChunk()
{
}

AckitementFindMe::AckitementFindMe(const AckitementFindMe& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

AckitementFindMe::~AckitementFindMe()
{
}

AckitementFindMe& AckitementFindMe::operator=(const AckitementFindMe& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void AckitementFindMe::copy(const AckitementFindMe& other)
{
    this->srcAddress = other.srcAddress;
}

void AckitementFindMe::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
}

void AckitementFindMe::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
}

const L3Address& AckitementFindMe::getSrcAddress() const
{
    return this->srcAddress;
}

void AckitementFindMe::setSrcAddress(const L3Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

class AckitementFindMeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddress,
    };
  public:
    AckitementFindMeDescriptor();
    virtual ~AckitementFindMeDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(AckitementFindMeDescriptor)

AckitementFindMeDescriptor::AckitementFindMeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::AckitementFindMe)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

AckitementFindMeDescriptor::~AckitementFindMeDescriptor()
{
    delete[] propertyNames;
}

bool AckitementFindMeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AckitementFindMe *>(obj)!=nullptr;
}

const char **AckitementFindMeDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AckitementFindMeDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AckitementFindMeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int AckitementFindMeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *AckitementFindMeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int AckitementFindMeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *AckitementFindMeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **AckitementFindMeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AckitementFindMeDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AckitementFindMeDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AckitementFindMeDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AckitementFindMe'", field);
    }
}

const char *AckitementFindMeDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AckitementFindMeDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        default: return "";
    }
}

void AckitementFindMeDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AckitementFindMe'", field);
    }
}

omnetpp::cValue AckitementFindMeDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AckitementFindMe' as cValue -- field index out of range?", field);
    }
}

void AckitementFindMeDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AckitementFindMe'", field);
    }
}

const char *AckitementFindMeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr AckitementFindMeDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AckitementFindMeDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AckitementFindMe *pp = omnetpp::fromAnyPtr<AckitementFindMe>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AckitementFindMe'", field);
    }
}

Register_Class(helloAnchor)

helloAnchor::helloAnchor() : ::inet::FieldsChunk()
{
}

helloAnchor::helloAnchor(const helloAnchor& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

helloAnchor::~helloAnchor()
{
}

helloAnchor& helloAnchor::operator=(const helloAnchor& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void helloAnchor::copy(const helloAnchor& other)
{
    this->srcAddress = other.srcAddress;
}

void helloAnchor::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
}

void helloAnchor::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
}

const L3Address& helloAnchor::getSrcAddress() const
{
    return this->srcAddress;
}

void helloAnchor::setSrcAddress(const L3Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

class helloAnchorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddress,
    };
  public:
    helloAnchorDescriptor();
    virtual ~helloAnchorDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(helloAnchorDescriptor)

helloAnchorDescriptor::helloAnchorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::helloAnchor)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

helloAnchorDescriptor::~helloAnchorDescriptor()
{
    delete[] propertyNames;
}

bool helloAnchorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<helloAnchor *>(obj)!=nullptr;
}

const char **helloAnchorDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *helloAnchorDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int helloAnchorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int helloAnchorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *helloAnchorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int helloAnchorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *helloAnchorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **helloAnchorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *helloAnchorDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int helloAnchorDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void helloAnchorDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'helloAnchor'", field);
    }
}

const char *helloAnchorDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string helloAnchorDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        default: return "";
    }
}

void helloAnchorDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'helloAnchor'", field);
    }
}

omnetpp::cValue helloAnchorDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'helloAnchor' as cValue -- field index out of range?", field);
    }
}

void helloAnchorDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'helloAnchor'", field);
    }
}

const char *helloAnchorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr helloAnchorDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void helloAnchorDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    helloAnchor *pp = omnetpp::fromAnyPtr<helloAnchor>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'helloAnchor'", field);
    }
}

Register_Class(helloTarget)

helloTarget::helloTarget() : ::inet::FieldsChunk()
{
}

helloTarget::helloTarget(const helloTarget& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

helloTarget::~helloTarget()
{
}

helloTarget& helloTarget::operator=(const helloTarget& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void helloTarget::copy(const helloTarget& other)
{
    this->srcAddress = other.srcAddress;
}

void helloTarget::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
}

void helloTarget::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
}

const L3Address& helloTarget::getSrcAddress() const
{
    return this->srcAddress;
}

void helloTarget::setSrcAddress(const L3Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

class helloTargetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddress,
    };
  public:
    helloTargetDescriptor();
    virtual ~helloTargetDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(helloTargetDescriptor)

helloTargetDescriptor::helloTargetDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::helloTarget)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

helloTargetDescriptor::~helloTargetDescriptor()
{
    delete[] propertyNames;
}

bool helloTargetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<helloTarget *>(obj)!=nullptr;
}

const char **helloTargetDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *helloTargetDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int helloTargetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int helloTargetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *helloTargetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int helloTargetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *helloTargetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_srcAddress
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **helloTargetDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *helloTargetDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int helloTargetDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void helloTargetDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'helloTarget'", field);
    }
}

const char *helloTargetDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string helloTargetDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        default: return "";
    }
}

void helloTargetDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'helloTarget'", field);
    }
}

omnetpp::cValue helloTargetDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'helloTarget' as cValue -- field index out of range?", field);
    }
}

void helloTargetDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'helloTarget'", field);
    }
}

const char *helloTargetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr helloTargetDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void helloTargetDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    helloTarget *pp = omnetpp::fromAnyPtr<helloTarget>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'helloTarget'", field);
    }
}

Register_Class(CalculatedPos)

CalculatedPos::CalculatedPos() : ::inet::FieldsChunk()
{
}

CalculatedPos::CalculatedPos(const CalculatedPos& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

CalculatedPos::~CalculatedPos()
{
}

CalculatedPos& CalculatedPos::operator=(const CalculatedPos& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void CalculatedPos::copy(const CalculatedPos& other)
{
    this->srcAddress = other.srcAddress;
    this->rank = other.rank;
    this->x = other.x;
    this->y = other.y;
}

void CalculatedPos::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->rank);
    doParsimPacking(b,this->x);
    doParsimPacking(b,this->y);
}

void CalculatedPos::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->rank);
    doParsimUnpacking(b,this->x);
    doParsimUnpacking(b,this->y);
}

const L3Address& CalculatedPos::getSrcAddress() const
{
    return this->srcAddress;
}

void CalculatedPos::setSrcAddress(const L3Address& srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

int CalculatedPos::getRank() const
{
    return this->rank;
}

void CalculatedPos::setRank(int rank)
{
    handleChange();
    this->rank = rank;
}

double CalculatedPos::getX() const
{
    return this->x;
}

void CalculatedPos::setX(double x)
{
    handleChange();
    this->x = x;
}

double CalculatedPos::getY() const
{
    return this->y;
}

void CalculatedPos::setY(double y)
{
    handleChange();
    this->y = y;
}

class CalculatedPosDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddress,
        FIELD_rank,
        FIELD_x,
        FIELD_y,
    };
  public:
    CalculatedPosDescriptor();
    virtual ~CalculatedPosDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(CalculatedPosDescriptor)

CalculatedPosDescriptor::CalculatedPosDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CalculatedPos)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

CalculatedPosDescriptor::~CalculatedPosDescriptor()
{
    delete[] propertyNames;
}

bool CalculatedPosDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CalculatedPos *>(obj)!=nullptr;
}

const char **CalculatedPosDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CalculatedPosDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CalculatedPosDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int CalculatedPosDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddress
        FD_ISEDITABLE,    // FIELD_rank
        FD_ISEDITABLE,    // FIELD_x
        FD_ISEDITABLE,    // FIELD_y
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *CalculatedPosDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
        "rank",
        "x",
        "y",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int CalculatedPosDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "rank") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "x") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "y") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *CalculatedPosDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_srcAddress
        "int",    // FIELD_rank
        "double",    // FIELD_x
        "double",    // FIELD_y
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **CalculatedPosDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CalculatedPosDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CalculatedPosDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CalculatedPosDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CalculatedPos'", field);
    }
}

const char *CalculatedPosDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CalculatedPosDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return pp->getSrcAddress().str();
        case FIELD_rank: return long2string(pp->getRank());
        case FIELD_x: return double2string(pp->getX());
        case FIELD_y: return double2string(pp->getY());
        default: return "";
    }
}

void CalculatedPosDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        case FIELD_rank: pp->setRank(string2long(value)); break;
        case FIELD_x: pp->setX(string2double(value)); break;
        case FIELD_y: pp->setY(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CalculatedPos'", field);
    }
}

omnetpp::cValue CalculatedPosDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        case FIELD_rank: return pp->getRank();
        case FIELD_x: return pp->getX();
        case FIELD_y: return pp->getY();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CalculatedPos' as cValue -- field index out of range?", field);
    }
}

void CalculatedPosDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        case FIELD_rank: pp->setRank(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_x: pp->setX(value.doubleValue()); break;
        case FIELD_y: pp->setY(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CalculatedPos'", field);
    }
}

const char *CalculatedPosDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr CalculatedPosDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddress: return omnetpp::toAnyPtr(&pp->getSrcAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CalculatedPosDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CalculatedPos *pp = omnetpp::fromAnyPtr<CalculatedPos>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CalculatedPos'", field);
    }
}

Register_Class(AnchorData)

AnchorData::AnchorData() : ::inet::FieldsChunk()
{
}

AnchorData::AnchorData(const AnchorData& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

AnchorData::~AnchorData()
{
}

AnchorData& AnchorData::operator=(const AnchorData& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void AnchorData::copy(const AnchorData& other)
{
    this->targetAddress = other.targetAddress;
    this->encryptedMsg = other.encryptedMsg;
    this->signature = other.signature;
    this->rank = other.rank;
    this->x = other.x;
    this->y = other.y;
}

void AnchorData::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->encryptedMsg);
    doParsimPacking(b,this->signature);
    doParsimPacking(b,this->rank);
    doParsimPacking(b,this->x);
    doParsimPacking(b,this->y);
}

void AnchorData::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->encryptedMsg);
    doParsimUnpacking(b,this->signature);
    doParsimUnpacking(b,this->rank);
    doParsimUnpacking(b,this->x);
    doParsimUnpacking(b,this->y);
}

const L3Address& AnchorData::getTargetAddress() const
{
    return this->targetAddress;
}

void AnchorData::setTargetAddress(const L3Address& targetAddress)
{
    handleChange();
    this->targetAddress = targetAddress;
}

const char * AnchorData::getEncryptedMsg() const
{
    return this->encryptedMsg.c_str();
}

void AnchorData::setEncryptedMsg(const char * encryptedMsg)
{
    handleChange();
    this->encryptedMsg = encryptedMsg;
}

const char * AnchorData::getSignature() const
{
    return this->signature.c_str();
}

void AnchorData::setSignature(const char * signature)
{
    handleChange();
    this->signature = signature;
}

int AnchorData::getRank() const
{
    return this->rank;
}

void AnchorData::setRank(int rank)
{
    handleChange();
    this->rank = rank;
}

double AnchorData::getX() const
{
    return this->x;
}

void AnchorData::setX(double x)
{
    handleChange();
    this->x = x;
}

double AnchorData::getY() const
{
    return this->y;
}

void AnchorData::setY(double y)
{
    handleChange();
    this->y = y;
}

class AnchorDataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_targetAddress,
        FIELD_encryptedMsg,
        FIELD_signature,
        FIELD_rank,
        FIELD_x,
        FIELD_y,
    };
  public:
    AnchorDataDescriptor();
    virtual ~AnchorDataDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(AnchorDataDescriptor)

AnchorDataDescriptor::AnchorDataDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::AnchorData)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

AnchorDataDescriptor::~AnchorDataDescriptor()
{
    delete[] propertyNames;
}

bool AnchorDataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AnchorData *>(obj)!=nullptr;
}

const char **AnchorDataDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AnchorDataDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AnchorDataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int AnchorDataDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_targetAddress
        FD_ISEDITABLE,    // FIELD_encryptedMsg
        FD_ISEDITABLE,    // FIELD_signature
        FD_ISEDITABLE,    // FIELD_rank
        FD_ISEDITABLE,    // FIELD_x
        FD_ISEDITABLE,    // FIELD_y
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *AnchorDataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "targetAddress",
        "encryptedMsg",
        "signature",
        "rank",
        "x",
        "y",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int AnchorDataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "targetAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "encryptedMsg") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "signature") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "rank") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "x") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "y") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *AnchorDataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_targetAddress
        "string",    // FIELD_encryptedMsg
        "string",    // FIELD_signature
        "int",    // FIELD_rank
        "double",    // FIELD_x
        "double",    // FIELD_y
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **AnchorDataDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AnchorDataDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AnchorDataDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AnchorDataDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AnchorData'", field);
    }
}

const char *AnchorDataDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AnchorDataDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        case FIELD_targetAddress: return pp->getTargetAddress().str();
        case FIELD_encryptedMsg: return oppstring2string(pp->getEncryptedMsg());
        case FIELD_signature: return oppstring2string(pp->getSignature());
        case FIELD_rank: return long2string(pp->getRank());
        case FIELD_x: return double2string(pp->getX());
        case FIELD_y: return double2string(pp->getY());
        default: return "";
    }
}

void AnchorDataDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        case FIELD_encryptedMsg: pp->setEncryptedMsg((value)); break;
        case FIELD_signature: pp->setSignature((value)); break;
        case FIELD_rank: pp->setRank(string2long(value)); break;
        case FIELD_x: pp->setX(string2double(value)); break;
        case FIELD_y: pp->setY(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AnchorData'", field);
    }
}

omnetpp::cValue AnchorDataDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        case FIELD_targetAddress: return omnetpp::toAnyPtr(&pp->getTargetAddress()); break;
        case FIELD_encryptedMsg: return pp->getEncryptedMsg();
        case FIELD_signature: return pp->getSignature();
        case FIELD_rank: return pp->getRank();
        case FIELD_x: return pp->getX();
        case FIELD_y: return pp->getY();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AnchorData' as cValue -- field index out of range?", field);
    }
}

void AnchorDataDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        case FIELD_encryptedMsg: pp->setEncryptedMsg(value.stringValue()); break;
        case FIELD_signature: pp->setSignature(value.stringValue()); break;
        case FIELD_rank: pp->setRank(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_x: pp->setX(value.doubleValue()); break;
        case FIELD_y: pp->setY(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AnchorData'", field);
    }
}

const char *AnchorDataDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr AnchorDataDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        case FIELD_targetAddress: return omnetpp::toAnyPtr(&pp->getTargetAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AnchorDataDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AnchorData *pp = omnetpp::fromAnyPtr<AnchorData>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AnchorData'", field);
    }
}

Register_Class(EncryptedTargetData)

EncryptedTargetData::EncryptedTargetData() : ::inet::FieldsChunk()
{
}

EncryptedTargetData::EncryptedTargetData(const EncryptedTargetData& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EncryptedTargetData::~EncryptedTargetData()
{
}

EncryptedTargetData& EncryptedTargetData::operator=(const EncryptedTargetData& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EncryptedTargetData::copy(const EncryptedTargetData& other)
{
    this->targetAddress = other.targetAddress;
    this->encryptedMsg = other.encryptedMsg;
    this->signature = other.signature;
}

void EncryptedTargetData::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->encryptedMsg);
    doParsimPacking(b,this->signature);
}

void EncryptedTargetData::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->encryptedMsg);
    doParsimUnpacking(b,this->signature);
}

const L3Address& EncryptedTargetData::getTargetAddress() const
{
    return this->targetAddress;
}

void EncryptedTargetData::setTargetAddress(const L3Address& targetAddress)
{
    handleChange();
    this->targetAddress = targetAddress;
}

const char * EncryptedTargetData::getEncryptedMsg() const
{
    return this->encryptedMsg.c_str();
}

void EncryptedTargetData::setEncryptedMsg(const char * encryptedMsg)
{
    handleChange();
    this->encryptedMsg = encryptedMsg;
}

const char * EncryptedTargetData::getSignature() const
{
    return this->signature.c_str();
}

void EncryptedTargetData::setSignature(const char * signature)
{
    handleChange();
    this->signature = signature;
}

class EncryptedTargetDataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_targetAddress,
        FIELD_encryptedMsg,
        FIELD_signature,
    };
  public:
    EncryptedTargetDataDescriptor();
    virtual ~EncryptedTargetDataDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EncryptedTargetDataDescriptor)

EncryptedTargetDataDescriptor::EncryptedTargetDataDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EncryptedTargetData)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EncryptedTargetDataDescriptor::~EncryptedTargetDataDescriptor()
{
    delete[] propertyNames;
}

bool EncryptedTargetDataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EncryptedTargetData *>(obj)!=nullptr;
}

const char **EncryptedTargetDataDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EncryptedTargetDataDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EncryptedTargetDataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int EncryptedTargetDataDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_targetAddress
        FD_ISEDITABLE,    // FIELD_encryptedMsg
        FD_ISEDITABLE,    // FIELD_signature
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *EncryptedTargetDataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "targetAddress",
        "encryptedMsg",
        "signature",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int EncryptedTargetDataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "targetAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "encryptedMsg") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "signature") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *EncryptedTargetDataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_targetAddress
        "string",    // FIELD_encryptedMsg
        "string",    // FIELD_signature
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **EncryptedTargetDataDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EncryptedTargetDataDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EncryptedTargetDataDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EncryptedTargetDataDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EncryptedTargetData'", field);
    }
}

const char *EncryptedTargetDataDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EncryptedTargetDataDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        case FIELD_targetAddress: return pp->getTargetAddress().str();
        case FIELD_encryptedMsg: return oppstring2string(pp->getEncryptedMsg());
        case FIELD_signature: return oppstring2string(pp->getSignature());
        default: return "";
    }
}

void EncryptedTargetDataDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        case FIELD_encryptedMsg: pp->setEncryptedMsg((value)); break;
        case FIELD_signature: pp->setSignature((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EncryptedTargetData'", field);
    }
}

omnetpp::cValue EncryptedTargetDataDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        case FIELD_targetAddress: return omnetpp::toAnyPtr(&pp->getTargetAddress()); break;
        case FIELD_encryptedMsg: return pp->getEncryptedMsg();
        case FIELD_signature: return pp->getSignature();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EncryptedTargetData' as cValue -- field index out of range?", field);
    }
}

void EncryptedTargetDataDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        case FIELD_encryptedMsg: pp->setEncryptedMsg(value.stringValue()); break;
        case FIELD_signature: pp->setSignature(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EncryptedTargetData'", field);
    }
}

const char *EncryptedTargetDataDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr EncryptedTargetDataDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        case FIELD_targetAddress: return omnetpp::toAnyPtr(&pp->getTargetAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EncryptedTargetDataDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EncryptedTargetData *pp = omnetpp::fromAnyPtr<EncryptedTargetData>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EncryptedTargetData'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

